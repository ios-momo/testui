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

import AVFoundation
import UIKit
import os
import AlycePoseCore

final class SampleViewViewController: UIViewController{
    
    // MARK: Storyboards Connections
    @IBOutlet private weak var txtCount: UILabel!
    @IBOutlet private weak var scoreLabel: UILabel!
//    @IBOutlet private weak var txtFeedback: UILabel!
    @IBOutlet private weak var overlayView: OverlayView!
    @IBOutlet private weak var videoView: UIView!
    
    private let minimumScore = Constant.shared.MIN_PERSON_SCORE
    
    internal var exerciseId: Int?
    
    // MARK: Visualization
    private var imageViewFrame: CGRect?
    private var overlayImage: OverlayView?
    
    // MARK: Controllers that manage functionality
    private var alycepose: AlycePose?
    private var cameraFeedManager: CameraFeedManager!
    
    // Serial queue to control all tasks related to the TFLite model.
    private let queue = DispatchQueue(label: "serial_queue")
    
    // Flag to make sure there's only one frame processed at each moment.
    private var isRunning = false
    
    // video
    private var player:AVQueuePlayer?
    private var playerLayer: AVPlayerLayer?
    private var playerLooper:AVPlayerLooper?
    
    // exercise state
    private var currentCount:Int = 0
    
    // MARK: View Handling Methods
    override func viewDidLoad() {
        super.viewDidLoad()
        loadModel()
        configCameraCapture()
        
//        configVideoPlayer()
        self.txtCount.layer.masksToBounds = true
        self.txtCount.layer.cornerRadius = 50
        
        NSLog("AlycePose version=\(AlycePoseInfo().VERSION_NAME)")
        
        // reset counter
        self.currentCount = 0
        self.txtCount.text = "0"
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        player?.rate = 1.0
        DispatchQueue.global().async {
            self.cameraFeedManager?.startRunning()
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        player?.rate = 0.0
        DispatchQueue.global().async {
            self.cameraFeedManager?.stopRunning()
        }
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        imageViewFrame = overlayView.frame
        playerLayer?.frame = videoView.bounds
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        return [.landscapeLeft, .landscapeRight]
    }

    private func configVideoPlayer() {
        L.i("main", "configVideoPlayer()")
        
        DispatchQueue.main.async {
            guard let exId = self.exerciseId else {
                L.i("main", "getExercise(exerciseId) failed: exerciseId is not set")
                return
            }

            self.alycepose?.apiClient.getExercise(exerciseId: Int32(exId)) { exerciseDef, error in
                DispatchQueue.main.async {

                    // Play exercise video
                    if let exercise = exerciseDef {
                        L.i("main", "video url = \(exercise.exerciseVideo)")

                        let url = URL(string: exercise.exerciseVideo)!
                        let playerItem = AVPlayerItem(url: url)
                        self.player = AVQueuePlayer(playerItem: playerItem)
                        self.playerLayer = AVPlayerLayer(player: self.player)
                        // Video scale mode
                        self.playerLayer?.videoGravity = .resizeAspectFill
                        self.videoView.layer.addSublayer(self.playerLayer!)
                        // Loop video
                        self.playerLooper = AVPlayerLooper(player: self.player!, templateItem: playerItem)
                        self.player?.play()
                    } else {
                        L.i("main", "getExercise(\(exId)) failed: API error")
                    }
                }
            }
        }
    }
    
    
    private func configCameraCapture() {
        cameraFeedManager = CameraFeedManager()
        cameraFeedManager.delegate = self
        DispatchQueue.global().async {
            self.cameraFeedManager.configureSession()
            self.cameraFeedManager.startRunning()
        }
    }
    
    private func loadModel() {
        // Update the model in the same serial queue with the inference logic to avoid race condition
        DispatchQueue.global().async {
            do {
                self.alycepose = try AlycePose()
            } catch let error {
                os_log("Error: %@", log: .default, type: .error, String(describing: error))
            }
            self.configVideoPlayer()

            DispatchQueue.main.async {
                // setMode: Exercise
                if let exId = self.exerciseId {
                    try? self.alycepose?.setMode(mode: .Exercise,
                                                 exerciseId: exId,
                                                 exerciseListener: self
                    )
                }
            }
        }
    }

}

// MARK: - AlyceposeListener
extension SampleViewViewController: AlyceposeListener {
    func onCount(score: Int32) {
        DispatchQueue.main.async {
            self.currentCount += 1
            self.txtCount.text = String(self.currentCount)
        }
    }
    func onExerciseFetched(exercise: Exercise) {
        //
    }
    func onIntermediateScore(score: Int32) {
        DispatchQueue.main.async {
            self.scoreLabel.text = "판정 점수 : \(score)점"
        }
    }
    func onHoldingTick() {

    }
    func onTimedOut(msg: String) {

    }
}

// MARK: - CameraFeedManagerDelegate Methods
extension SampleViewViewController: CameraFeedManagerDelegate {

    func cameraFeedManager(_ cameraFeedManager: CameraFeedManager, didOutput pixelBuffer: CVPixelBuffer) {
        self.runModel(pixelBuffer)
    }
    

    /// Run pose estimation on the input frame from the camera.
    private func runModel(_ pixelBuffer: CVPixelBuffer) {
        
        // Guard to make sure that there's only 1 frame process at each moment.
        guard !isRunning else { return }
        
        // Guard to make sure that the pose estimator is already initialized.
        guard let estimator = alycepose else { return }
        
        // Run inference on a serial queue to avoid race condition.
        queue.async {
            self.isRunning = true
            defer { self.isRunning = false }
            
            // Run pose estimation
            do {
                let result = try estimator.feedImage(on: pixelBuffer)
                
                // Return to main thread to show detection results on the app UI.
                DispatchQueue.main.async {
                    // Visualize the pose estimation result.
                    self.overlayView.draw(at: result.image, keyPoints: result.person?.keyPoints ?? nil, distanceCheckZone: DistanceEvaluator.companion.boundingBoxRect
                    )
                }
            } catch {
                os_log("Error running pose estimation.", type: .error)
                return
            }
        }
    }
}

extension SampleViewViewController: DistanceCheckListener {
    func onSuccess() {
        NSLog("distance OK")
    }
}

extension SampleViewViewController {
    @IBAction func onTapBack(_ sender: Any) {
        dismiss(animated: true)
    }
}

extension UIColor {
   convenience init(red: Int, green: Int, blue: Int) {
       assert(red >= 0 && red <= 255, "Invalid red component")
       assert(green >= 0 && green <= 255, "Invalid green component")
       assert(blue >= 0 && blue <= 255, "Invalid blue component")

       self.init(red: CGFloat(red) / 255.0, green: CGFloat(green) / 255.0, blue: CGFloat(blue) / 255.0, alpha: 1.0)
   }

   convenience init(rgb: Int) {
       self.init(
           red: (rgb >> 16) & 0xFF,
           green: (rgb >> 8) & 0xFF,
           blue: rgb & 0xFF
       )
   }
}
