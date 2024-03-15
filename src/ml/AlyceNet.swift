// Copyright 2021 The TensorFlow Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// =============================================================================
//

import Accelerate
import AlycePoseCore
import Foundation
import TensorFlowLite

/// A wrapper to run pose estimation using AlyceNet models
public final class AlycePose: PoseDetector {
    private static let TAG = "AlycePose"
    
    // MARK: - Properties

    // TensorFlow Lite `Interpreter` object for performing inference on a given model.
    private var interpreter: Interpreter
    
    // TensorFlow Lite `Tensor` of model input and output.
    private var inputTensor: Tensor
    private var outputTensor: Tensor
    
    // Model config
    private var torsoExpansionRatio = 1.9
    private var bodyExpandsionRatio = 1.2
    private let imageMean: Float = 0
    private let imageStd: Float = 1
    private let minCropKeyPointScore: Float32 = 0.2
    private var cropRegion: RectF?
    private var isProcessing = false
    
    // Model files
    private let alyceNetLightFile = FileInfo(name: "alycenet_light", ext: "tflite")
    private let alyceNetFile = FileInfo(name: "alycenet", ext: "tflite")
    
    private var evaluator: Evaluator? = nil
    private var distanceEvaluator: DistanceEvaluator? = nil
    private let bodyPartArray: [BodyPart] = BodyPart.companion.valuesArray()
    
    // Status
    public private(set) var mode: Mode = .Live
    
    internal let apiClient = ApiClient(apiKey: "RWRATFdaUTZDNmNEeU5kOlM5WXVoQytINGFERnp0S2ElVHYhW3k5dkJjaG5mKw==", baseUrlString: nil)
    
    // MARK: - Public
    
    /// A failable initializer for `AlycePose`. A new instance is created if the model is
    /// successfully loaded from the app's main bundle. Default `threadCount` is 4.
    public init(threadCount: Int = 4, delegate: Device = .gpu, modelType: ModelType = .Normal) throws {
        // Construct the path to the model file.
        let fileInfo: FileInfo!
        switch modelType {
        case .Normal:
            fileInfo = alyceNetFile
        case .Light:
            fileInfo = alyceNetLightFile
        }
        let bundlePath = Bundle(for: AlycePose.self)//.path(forResource: "AlycePoseUiRes", ofType: "bundle")
//        let resBundle = Bundle(url: URL(fileURLWithPath: bundlePath!))
        guard
            let modelPath = bundlePath.path(forResource: fileInfo.name, ofType: fileInfo.ext)
        else {
            fatalError("Failed to load the model file with name: \(fileInfo.name).")
        }
        
        // Specify the options for the `Interpreter`.
        var options = Interpreter.Options()
        options.threadCount = threadCount
        
        // Specify the delegates for the `Interpreter`.
        var delegates: [Delegate]?
        switch delegate {
        case .gpu:
            delegates = [MetalDelegate()]
        default: // case .cpu:
            delegates = nil
        }
        
        // Create the `Interpreter`.
        interpreter = try Interpreter(modelPath: modelPath, options: options, delegates: delegates)
        
        // Initialize input and output `Tensor`s.
        // Allocate memory for the model's input `Tensor`s.
        try interpreter.allocateTensors()
        
        // Get allocated input and output `Tensor`s.
        inputTensor = try interpreter.input(at: 0)
        outputTensor = try interpreter.output(at: 0)
    }
    
    /// Runs PoseEstimation model with given image with given source area to destination area.
    /// This pose detector can process only one frame at each moment.
    ///
    /// - Parameters:
    ///   - on: Input image to run the model.
    /// - Returns: Result of the inference and the times consumed in every steps.
    public func feedImage(on pixelBuffer: CVPixelBuffer) throws -> ProcessResult {
        // Check if this AlycePose instance is already processing a video frame.
        // Return an empty detection result if it's currently busy.
        guard !isProcessing else {
            throw PoseEstimationError.modelBusy
        }
        isProcessing = true
        defer {
            isProcessing = false
        }
        
        // Start times of each process.
        let preprocessingStartTime: Date
        let inferenceStartTime: Date
        let postprocessingStartTime: Date
        
        // Processing times in seconds.
        let preprocessingTime: TimeInterval
        let inferenceTime: TimeInterval
        let postprocessingTime: TimeInterval
        
        // run pre-process
        preprocessingStartTime = Date()
        guard let data = preProcess(pixelBuffer) else {
            l(AlycePose.TAG, "Preprocessing failed")
            throw PoseEstimationError.preprocessingFailed
        }
        preprocessingTime = Date().timeIntervalSince(preprocessingStartTime)
        
        // Run inference with the TFLite model
        inferenceStartTime = Date()
        do {
            // Copy the initialized `Data` to the input `Tensor`.
            try interpreter.copy(data, toInputAt: 0)
            
            // Run inference by invoking the `Interpreter`.
            try interpreter.invoke()
            // Get the output `Tensor` to process the inference results.
            outputTensor = try interpreter.output(at: 0)
        } catch {
            os_log(
                "Failed to invoke the interpreter with error: %s", type: .error,
                error.localizedDescription)
            throw PoseEstimationError.inferenceFailed
        }
        inferenceTime = Date().timeIntervalSince(inferenceStartTime)
        
        // run post-process
        postprocessingStartTime = Date()
        guard let person = postProcess(imageSize: pixelBuffer.size, modelOutput: outputTensor) else {
            os_log("Postprocessing failed.", type: .error)
            throw PoseEstimationError.postProcessingFailed
        }
        
        postprocessingTime = Date().timeIntervalSince(postprocessingStartTime)
        
        let image = UIImage(ciImage: CIImage(cvPixelBuffer: pixelBuffer))
        
        // evaluate
        switch mode {
        case .Exercise:
            evaluator?.evaluate(keyPoints: person.keyPoints, personScore: person.score)
        case .DistanceCheck:
            distanceEvaluator?.evaluate(inputImageWidthPx: Float(image.size.width), inputImageHeightPx: Float(image.size.height), keyPoints: person.keyPoints, personScore: person.score)
        default:
            ()
        }
        
        return ProcessResult(image: image, person: person)
    }
    
    public func setMode(mode: Mode,
                        exerciseId: Int? = nil,
                        exerciseListener: AlyceposeListener? = nil,
                        distanceListener: DistanceCheckListener? = nil) throws
    {
        switch mode {
        case .Exercise:
            guard exerciseId != nil && exerciseListener != nil else {
                l(AlycePose.TAG, "setMode() failed: to set .Exercise mode, `exerciseId` and `exerciseListener` are required.")
                throw PoseEstimationError.invalidModeParam
            }
            
            if let exerciseId, let exerciseListener {
                self.apiClient.getPosture(exerciseId: Int32(exerciseId)) { poseDefinition, error in
                    DispatchQueue.main.async {
                        if let poseDefinition = poseDefinition {
                            self.mode = mode
                            self.reset()
                            self.evaluator = Evaluator(exerciseId: Int32(exerciseId), exercise: poseDefinition, listener: exerciseListener)
                        } else {
                            l(AlycePose.TAG, "setMode(): failed")
                        }
                    }
                }
            }
            
        case .DistanceCheck:
            guard let _distanceListener = distanceListener else {
                l(AlycePose.TAG, "to set .Distancecheck mode, `distanceListener` is required.")
                throw PoseEstimationError.invalidModeParam
            }
            
            self.mode = mode
            reset()
            distanceEvaluator = DistanceEvaluator(listener: _distanceListener)
            
        case .Live:
            self.mode = mode
            reset()
        }
    }
    
    private func reset() {
        evaluator?.terminate()
        evaluator = nil
        distanceEvaluator = nil
    }
    
    // MARK: - Private functions to run the model

    /// Preprocesses given rectangle image to be `Data` of desired size by cropping and resizing it.
    ///
    /// - Parameters:
    ///   - of: Input image to crop and resize.
    /// - Returns: The cropped and resized image. `nil` if it can not be processed.
    private func preProcess(_ pixelBuffer: CVPixelBuffer) -> Data? {
        let sourcePixelFormat = CVPixelBufferGetPixelFormatType(pixelBuffer)
        assert(
            sourcePixelFormat == kCVPixelFormatType_32BGRA
                || sourcePixelFormat == kCVPixelFormatType_32ARGB)
        // Resize `targetSquare` of input image to `modelSize`.
        let dimensions = inputTensor.shape.dimensions
        let inputWidth = Float(dimensions[1])
        let inputHeight = Float(dimensions[2])
        let imageWidth = Float(pixelBuffer.size.width)
        let imageHeight = Float(pixelBuffer.size.height)
        
        let cropRegion = self.cropRegion ?? initCropRegion(imageWidth: imageWidth, imageHeight: imageHeight)
        self.cropRegion = cropRegion
        
        let rectF = RectF(
            left: cropRegion.left * imageWidth,
            top: cropRegion.top * imageHeight,
            right: cropRegion.right * imageWidth,
            bottom: cropRegion.bottom * imageHeight)
        
        // Detect region
        let modelSize = CGSize(width: CGFloat(inputWidth), height: CGFloat(inputHeight))
        guard let thumbnail = pixelBuffer.cropAndResize(fromRect: rectF.rect, toSize: modelSize) else {
            return nil
        }
        
        // Remove the alpha component from the image buffer to get the initialized `Data`.
        guard
            let inputData = thumbnail.rgbData(
                isModelQuantized: inputTensor.dataType == .uInt8, imageMean: imageMean, imageStd: imageStd)
        else {
            os_log("Failed to convert the image buffer to RGB data.", type: .error)
            return nil
        }
        
        return inputData
    }
    
    /// Postprocesses the output `Tensor` of TFLite model to the `Person` type
    ///
    /// - Parameters:
    ///   - imageSize: Size of the input image.
    ///   - modelOutput: Output tensor from the TFLite model.
    /// - Returns: Postprocessed `Person`. `nil` if it can not be processed.
    private func postProcess(imageSize: CGSize, modelOutput: Tensor) -> Person? {
        let imageWidth = Float(imageSize.width)
        let imageHeight = Float(imageSize.height)
        
        let cropRegion = self.cropRegion ??
            initCropRegion(imageWidth: imageWidth, imageHeight: imageHeight)
        
        let minX: Float = cropRegion.left * imageWidth
        let minY: Float = cropRegion.top * imageHeight
        
        let output = modelOutput.data.toArray(type: Float32.self)
        let dimensions = modelOutput.shape.dimensions
        let numKeyPoints = dimensions[2]
        let inputWidth = Float(inputTensor.shape.dimensions[1])
        let inputHeight = Float(inputTensor.shape.dimensions[2])
        
        let widthRatio = (cropRegion.width * imageWidth / inputWidth)
        let heightRatio = (cropRegion.height * imageHeight / inputHeight)
        
        // Translate the coordinates from the model output's [0..1] back to that of
        // the input image
        var totalScoreSum: Float32 = 0
        var keyPoints = [KeyPoint](repeatElement(KeyPoint(coordinate: Coordinate(x: -1.0, y: -1.0), score: -1.0), count: bodyPartArray.count))
        
        for idx in 0 ..< numKeyPoints {
            let x = ((Float(output[idx * 3 + 1]) * inputWidth) * widthRatio) + minX
            let y = ((Float(output[idx * 3 + 0]) * inputHeight) * heightRatio) + minY
            let score = output[idx * 3 + 2]
            
            let originalBodyPart: String = OriginalBodyPart.companion.fromInt(position: Int32(idx)).name
            guard let targetBodyPartIdx = bodyPartArray.firstIndex(where: { $0.name == originalBodyPart }) else { return nil }
            
            // convert original body part in Alycepose body part order
            keyPoints[targetBodyPartIdx] = KeyPoint(coordinate: Coordinate(x: Float(x), y: Float(y)).freezeMe() as! Coordinate, score: score).freezeMe() as! KeyPoint
            
            totalScoreSum += score
        }
        
        // add neck
        let leftShoulder = keyPoints[Int(BodyPart.leftShoulder.position)]
        let rightShoulder = keyPoints[Int(BodyPart.rightShoulder.position)]
        keyPoints[Int(BodyPart.neck.position)] = KeyPoint(
            coordinate: Coordinate(
                x: (leftShoulder.coordinate.x + rightShoulder.coordinate.x) / 2,
                y: (leftShoulder.coordinate.y + rightShoulder.coordinate.y) / 2).freezeMe() as! Coordinate, score: (leftShoulder.score + rightShoulder.score) / 2).freezeMe() as! KeyPoint
        
        // add hip
        let leftHip = keyPoints[Int(BodyPart.leftHip.position)]
        let rightHip = keyPoints[Int(BodyPart.rightHip.position)]
        keyPoints[Int(BodyPart.midHip.position)] = KeyPoint(
            coordinate: Coordinate(
                x: (leftHip.coordinate.x + rightHip.coordinate.x) / 2,
                y: (leftHip.coordinate.y + rightHip.coordinate.y) / 2).freezeMe() as! Coordinate, score: (leftHip.score + rightHip.score) / 2).freezeMe() as! KeyPoint
        
        // add palm
        setPalmPoints(keyPoints: &keyPoints, imageWidth: imageWidth, imageHeight: imageHeight)
        
        // Calculate the crop region for the subsequent frame.
        self.cropRegion = nextFrameCropRegion(keyPoints: keyPoints, imageWidth: imageWidth, imageHeight: imageHeight)
        
        // Calculates total confidence score of each key position.
        let totalScore = totalScoreSum / Float32(numKeyPoints)
        
        // mirror keypoints for front-facing camera
        let mirroredKeyPoints = EvaluateUtil.companion.switchBodyPartHor(keyPoints: NSMutableArray(array: keyPoints))
        
        // Make `Person` from `keypoints'. Each point is adjusted to the coordinate of the input image.
        return Person(keyPoints: mirroredKeyPoints, score: totalScore).freezeMe() as! Person?
    }
    
    private func setPalmPoints(keyPoints: inout [KeyPoint], imageWidth: Float, imageHeight: Float) {
        // Left palm
        let leftElbow = keyPoints[Int(BodyPart.leftElbow.position)]
        let leftWrist = keyPoints[Int(BodyPart.leftWrist.position)]
        var distance = AlycePose.getCoordinatesDistance(a: leftElbow.coordinate, b: leftWrist.coordinate)
        var beta = distance * 0.4
        var ratio = (distance + beta) / distance
        var x = (leftWrist.coordinate.x - leftElbow.coordinate.x) * ratio + leftElbow.coordinate.x
        var y = (leftWrist.coordinate.y - leftElbow.coordinate.y) * ratio + leftElbow.coordinate.y
        var palm = Coordinate(x: x, y: y)
        var isOutOfBound = !(0...imageWidth ~= x) || !(0...imageHeight ~= y)
        keyPoints[Int(BodyPart.leftPalm.position)] = KeyPoint(coordinate: palm, score: isOutOfBound ? 0 : min(leftElbow.score, leftWrist.score))
        
        // Right palm
        let rightElbow = keyPoints[Int(BodyPart.rightElbow.position)]
        let rightWrist = keyPoints[Int(BodyPart.rightWrist.position)]
        distance = AlycePose.getCoordinatesDistance(a: rightElbow.coordinate, b: rightWrist.coordinate)
        beta = distance * 0.4
        ratio = (distance + beta) / distance
        x = (rightWrist.coordinate.x - rightElbow.coordinate.x) * ratio + rightElbow.coordinate.x
        y = (rightWrist.coordinate.y - rightElbow.coordinate.y) * ratio + rightElbow.coordinate.y
        palm = Coordinate(x: x, y: y)
        isOutOfBound = !(0...imageWidth ~= x) || !(0...imageHeight ~= y)
        keyPoints[Int(BodyPart.rightPalm.position)] = KeyPoint(coordinate: palm, score: isOutOfBound ? 0 : min(rightElbow.score, rightWrist.score))
    }
    
    // MARK: AlyceNet's smart cropping logic

    /// Determines the region to crop the image for the model to run inference on.
    /// The algorithm uses the detected joints from the previous frame to estimate
    /// the square region that encloses the full body of the target person and
    /// centers at the midpoint of two hip joints. The crop size is determined by
    /// the distances between each joints and the center point.
    /// When the model is not confident with the four torso joint predictions, the
    /// function returns a default crop which is the full image padded to square.
    private func nextFrameCropRegion(keyPoints: [KeyPoint], imageWidth: Float, imageHeight: Float)
        -> RectF
    {
        let targetKeyPoints = keyPoints.map { keyPoint in
            KeyPoint(coordinate: Coordinate(x: keyPoint.coordinate.x, y: keyPoint.coordinate.y),
                     score: keyPoint.score)
        }
        if torsoVisible(keyPoints) {
            let centerX =
                (targetKeyPoints[Int(BodyPart.leftHip.position)].coordinate.x
                    + targetKeyPoints[Int(BodyPart.rightHip.position)].coordinate.x) / 2.0
            let centerY =
                (targetKeyPoints[Int(BodyPart.leftHip.position)].coordinate.y
                    + targetKeyPoints[Int(BodyPart.rightHip.position)].coordinate.y) / 2.0
            
            let torsoAndBodyDistances =
                determineTorsoAndBodyDistances(
                    keyPoints: keyPoints, targetKeyPoints: targetKeyPoints, centerX: centerX, centerY: centerY)
            
            let list = [
                torsoAndBodyDistances.maxTorsoXDistance * Float(torsoExpansionRatio),
                torsoAndBodyDistances.maxTorsoYDistance * Float(torsoExpansionRatio),
                torsoAndBodyDistances.maxBodyXDistance * Float(bodyExpandsionRatio),
                torsoAndBodyDistances.maxBodyYDistance * Float(bodyExpandsionRatio),
            ]
            
            var cropLengthHalf = list.max() ?? 0.0
            let tmp: [Float] = [
                centerX, Float(imageWidth) - centerX, centerY, Float(imageHeight) - centerY,
            ]
            cropLengthHalf = min(cropLengthHalf, tmp.max() ?? 0.0)
            let cropCornerY = centerY - cropLengthHalf
            let cropCornerX = centerX - cropLengthHalf
            if cropLengthHalf > (Float(max(imageWidth, imageHeight)) / 2.0) {
                return initCropRegion(imageWidth: imageWidth, imageHeight: imageHeight)
            } else {
                let cropLength = cropLengthHalf * 2
                return RectF(
                    left: max(cropCornerX, 0) / imageWidth,
                    top: max(cropCornerY, 0) / imageHeight,
                    right: min((cropCornerX + cropLength) / imageWidth, 1),
                    bottom: min((cropCornerY + cropLength) / imageHeight, 1))
            }
        } else {
            return initCropRegion(imageWidth: imageWidth, imageHeight: imageHeight)
        }
    }
    
    /// Defines the default crop region.
    /// The function provides the initial crop region (pads the full image from both
    /// sides to make it a square image) when the algorithm cannot reliably determine
    /// the crop region from the previous frame.
    private func initCropRegion(imageWidth: Float, imageHeight: Float) -> RectF {
        var xMin: Float
        var yMin: Float
        var width: Float
        var height: Float
        if imageWidth > imageHeight {
            height = 1
            width = imageHeight / imageWidth
            yMin = 0
            xMin = ((imageWidth - imageHeight) / 2.0) / imageWidth
        } else {
            width = 1
            height = imageWidth / imageHeight
            xMin = 0
            yMin = ((imageHeight - imageWidth) / 2.0) / imageHeight
        }
        return RectF(left: xMin, top: yMin, right: xMin + width, bottom: yMin + height)
    }
    
    /// Checks whether there are enough torso keypoints.
    /// This function checks whether the model is confident at predicting one of the
    /// shoulders/hips which is required to determine a good crop region.
    private func torsoVisible(_ keyPoints: [KeyPoint]) -> Bool {
        return (keyPoints[Int(BodyPart.leftHip.position)].score > minCropKeyPointScore
            || keyPoints[Int(BodyPart.rightHip.position)].score > minCropKeyPointScore)
            && (keyPoints[Int(BodyPart.leftShoulder.position)].score > minCropKeyPointScore
                || keyPoints[Int(BodyPart.rightShoulder.position)].score > minCropKeyPointScore)
    }
    
    /// Calculates the maximum distance from each keypoints to the center location.
    /// The function returns the maximum distances from the two sets of keypoints:
    /// full 17 keypoints and 4 torso keypoints. The returned information will be
    /// used to determine the crop size. See determineRectF for more detail.
    private func determineTorsoAndBodyDistances(
        keyPoints: [KeyPoint], targetKeyPoints: [KeyPoint], centerX: Float, centerY: Float) -> TorsoAndBodyDistance
    {
        let torsoJoints = [
            Int(BodyPart.leftShoulder.position),
            Int(BodyPart.rightShoulder.position),
            Int(BodyPart.leftHip.position),
            Int(BodyPart.rightHip.position),
        ]
        
        let maxTorsoYRange = torsoJoints.lazy.map { abs(centerY - targetKeyPoints[$0].coordinate.y) }
            .max() ?? 0.0
        let maxTorsoXRange = torsoJoints.lazy.map { abs(centerX - targetKeyPoints[$0].coordinate.x) }
            .max() ?? 0.0
        
        let confidentKeypoints = keyPoints.lazy.filter { $0.score < self.minCropKeyPointScore }
        let maxBodyYRange = confidentKeypoints.map { abs(centerY - $0.coordinate.y) }.max() ?? 0.0
        let maxBodyXRange = confidentKeypoints.map { abs(centerX - $0.coordinate.x) }.max() ?? 0.0
        
        return TorsoAndBodyDistance(
            maxTorsoYDistance: maxTorsoYRange,
            maxTorsoXDistance: maxTorsoXRange,
            maxBodyYDistance: maxBodyYRange,
            maxBodyXDistance: maxBodyXRange)
    }
    
    private static func getCoordinatesDistance(a: Coordinate, b: Coordinate) -> Float {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))
    }
}

/// Size of a detected person.
struct TorsoAndBodyDistance {
    var maxTorsoYDistance: Float
    var maxTorsoXDistance: Float
    var maxBodyYDistance: Float
    var maxBodyXDistance: Float
}

/// A rectangle with calculated properties for convenient access.
struct RectF {
    var left: Float
    var top: Float
    var right: Float
    var bottom: Float
    var width: Float { right - left }
    var height: Float { bottom - top }
    
    var rect: CGRect { .init(x: CGFloat(left), y: CGFloat(top), width: CGFloat(width), height: CGFloat(height)) }
}

public struct ProcessResult {
    public let image: UIImage
    public let person: Person?
}

/// Type of the pose estimation model to be used.
public enum Mode {
    case Live
    case Exercise
    case DistanceCheck
}
