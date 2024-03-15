//
//  AlycePoseUi.swift
//  AlycePoseUi
//
//  Created by Ryan Cha on 3/5/24.
//

import Foundation
import os

public enum AlycePoseUiError: String, Error {
    case SDKNotInitialized = "AlycePoseUi SDK is not initialized. Call AlycePoseUi.init(...) first."
}

public class AlycePoseUi {
    private static let TAG = "AlycePoseUi"
    private static var secretKey: String? = nil
    private static var isInitialized: Bool {
        get { secretKey != nil }
    }

    public static func initialize(secretKey: String) {
        AlycePoseUi.secretKey = secretKey
    }
    
    public static var showLog: Bool {
        get { L.isEnabled ?? false }
        set { L.isEnabled = newValue }
    }
    
    public static func start(vc: UIViewController ,exerciseId: Int) throws {
        guard isInitialized else {
            throw AlycePoseUiError.SDKNotInitialized
        }
        
        let libStoryBoard = UIStoryboard(name: "LibMain", bundle: Bundle(url: URL(fileURLWithPath: Bundle(for: AlycePose.self).path(forResource: "AlycePoseUiRes", ofType: "bundle")!)))
        let libVC = libStoryBoard.instantiateInitialViewController() as? SampleViewViewController
        if let _targetVc = libVC {
            _targetVc.exerciseId = exerciseId
            _targetVc.modalPresentationStyle = .fullScreen
            vc.show(_targetVc, sender: nil)
        } else {
            L.e(TAG, "Failed to start SDK")
        }
    }
}

internal struct L {
    public static var isEnabled: Bool? = nil
    
    private static let logger = Logger(
            subsystem: Bundle.main.bundleIdentifier!,
            category: String(describing: AlycePose.self)
        )
    
    private static func formatMessage(tag: String, msg: String) -> String {
        return "[\(tag)] \(msg)"
    }
    
    public static func v(_ tag: String, _ msg: String) {
        if L.isEnabled == true {
            L.logger.trace("\(L.formatMessage(tag: tag, msg: msg))")
        }
    }
    public static func d(_ tag: String, _ msg: String) {
        if L.isEnabled == true {
            L.logger.debug("\(L.formatMessage(tag: tag, msg: msg))")
        }
    }
    public static func i(_ tag: String, _ msg: String) {
        if L.isEnabled == true {
            L.logger.info("\(L.formatMessage(tag: tag, msg: msg))")
        }
    }
    public static func w(_ tag: String, _ msg: String) {
        if L.isEnabled == true {
            L.logger.warning("\(L.formatMessage(tag: tag, msg: msg))")
        }
    }
    public static func e(_ tag: String, _ msg: String) {
        if L.isEnabled == true {
            L.logger.critical("\(L.formatMessage(tag: tag, msg: msg))")
        }
    }
}
