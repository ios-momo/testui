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

import AlycePoseCore
import os
import UIKit

/// Custom view to visualize the pose estimation result on top of the input image.
class OverlayView: UIImageView {
    /// Visualization configs
    private enum Config {
        static let dot = (radius: CGFloat(24), color: UIColor.white)
        static let line = (width: CGFloat(6), color: UIColor.white)
    }
    
    /// CGContext to draw the detection result.
    var context: CGContext!
    
    /// Draw the detected keypoints on top of the input image.
    ///
    /// - Parameters:
    ///     - image: The input image.
    ///     - person: Keypoints of the person detected (i.e. output of a pose estimation model)
    func draw(at image: UIImage, keyPoints: [KeyPoint]?, distanceCheckZone: AlycePoseCore.RectF?) {
        if context == nil {
            UIGraphicsBeginImageContext(image.size)
            guard let context = UIGraphicsGetCurrentContext() else {
                fatalError("set current context faild")
            }
            self.context = context
        }
        
        // Draw background image
        image.draw(at: .zero)
        
        // Draw keypoints
        if let keyPoints {
            guard let strokes = strokes(keyPoints: keyPoints) else { return }
            context.setLineWidth(Config.dot.radius)
            drawLines(at: context, lines: strokes.lines)
            context.setStrokeColor(UIColor.white.cgColor)
            context.strokePath()
            
            drawDots(at: context, dots: strokes.dots, radius: Config.dot.radius / 3)
            context.setStrokeColor(UIColor.white.cgColor)
            context.strokePath()

            drawDots(at: context, dots: strokes.dots, radius: Config.dot.radius)
            context.setStrokeColor(UIColor.white.withAlphaComponent(0.5).cgColor)
            context.strokePath()
        }
        
        // Draw distanceCheckZone
        if let distanceCheckZone {
            let width = Float(context.width)
            let height = Float(context.height)
            context.addRect(CGRect(x: Int(width * distanceCheckZone.left),
                                   y: Int(height * distanceCheckZone.top),
                                   width: Int(width * (distanceCheckZone.right - distanceCheckZone.left)),
                                   height: Int(height * (distanceCheckZone.bottom - distanceCheckZone.top)))
            )
            context.strokePath()
        }
        
        // FIX: image should stretch vertically and be clipped horizontally.
        guard let newImage = UIGraphicsGetImageFromCurrentImageContext() else { fatalError() }
        self.image = newImage
    }
    
    /// Draw the dots (i.e. keypoints).
    ///
    /// - Parameters:
    ///     - context: The context to be drawn on.
    ///     - dots: The list of dots to be drawn.
    private func drawDots(at context: CGContext, dots: [CGPoint], radius: CGFloat) {
        for dot in dots {
            let dotRect = CGRect(
                x: dot.x - radius, 
                y: dot.y - radius,
                width: radius * 2, 
                height: radius * 2
            )
            let path = CGPath(
                roundedRect: dotRect, 
                cornerWidth: radius * 2,
                cornerHeight: radius * 2,
                transform: nil
            )
            context.addPath(path)
        }
    }
    
    /// Draw the lines (i.e. conneting the keypoints).
    ///
    /// - Parameters:
    ///     - context: The context to be drawn on.
    ///     - lines: The list of lines to be drawn.
    private func drawLines(at context: CGContext, lines: [Line]) {
        for line in lines {
            context.move(to: CGPoint(x: line.from.x, y: line.from.y))
            context.addLine(to: CGPoint(x: line.to.x, y: line.to.y))
        }
    }
    
    /// Generate a list of strokes to draw in order to visualize the pose estimation result.
    ///
    /// - Parameters:
    ///     - person: The detected person (i.e. output of a pose estimation model).
    private func strokes(keyPoints: [KeyPoint]) -> Strokes? {
        var strokes = Strokes(dots: [], lines: [])
        
        // MARK: Visualization of detection result
        
        Constant.shared.Visualization.BodyJoints.forEach { joint in
            guard let firstBodyPart = joint.first else { return }
            guard let secondBodyPart = joint.second else { return }
            
            let first = keyPoints[Int(firstBodyPart.position)]
            let second = keyPoints[Int(secondBodyPart.position)]
            
            if first.score > Constant.shared.MIN_PART_SCORE && second.score > Constant.shared.MIN_PART_SCORE {
                let from = CGPoint(x: CGFloat(first.coordinate.x), y: CGFloat(first.coordinate.y))
                let to = CGPoint(x: CGFloat(second.coordinate.x), y: CGFloat(second.coordinate.y))
                
                // add line
                strokes.lines.append(Line(from: from, to: to))
                
                // add dots
                strokes.dots.append(from)
                strokes.dots.append(to)
            }
        }
        strokes.dots.append(CGPoint(x: CGFloat(keyPoints[Int(BodyPart.leftPalm.position)].coordinate.x), y: CGFloat(keyPoints[Int(BodyPart.leftPalm.position)].coordinate.y)))
        strokes.dots.append(CGPoint(x: CGFloat(keyPoints[Int(BodyPart.rightPalm.position)].coordinate.x), y: CGFloat(keyPoints[Int(BodyPart.rightPalm.position)].coordinate.y)))
        
        return strokes
    }
}

/// The strokes to be drawn in order to visualize a pose estimation result.
private struct Strokes {
    var dots: [CGPoint]
    var lines: [Line]
}

/// A straight line.
private struct Line {
    let from: CGPoint
    let to: CGPoint
}
