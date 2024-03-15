//
//  Logger.swift
//  Alycepose
//
//  Created by Ryan Cha on 2023/03/27.
//

import Foundation

public func l(_ tag: String, _ msg: String) {
    #if DEBUG
    NSLog("[\(tag)] \(msg)")
    #endif
}
