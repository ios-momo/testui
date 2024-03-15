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

import UIKit
import AlycePoseCore

// MARK: Detection result
/// Time required to run pose estimation on one frame.
public struct Times {
    public var preprocessing: TimeInterval
    public var inference: TimeInterval
    public var postprocessing: TimeInterval
    public var total: TimeInterval { preprocessing + inference + postprocessing }
}

// export types
public typealias BodyPart = AlycePoseCore.BodyPart
public typealias KeyPoint = AlycePoseCore.KeyPoint
public typealias Person = AlycePoseCore.Person
public typealias Device = AlycePoseCore.Device
public typealias AlyceposeListener = AlycePoseCore.AlyceposeListenerInternal
public typealias Constant = AlycePoseCore.Constant
public typealias PoseDecoder = AlycePoseCore.PoseDecoder
public typealias SampleExercise = AlycePoseCore.SampleExercise
public typealias ExerciseType = AlycePoseCore.ExerciseType
public typealias Pose = AlycePoseCore.Pose
