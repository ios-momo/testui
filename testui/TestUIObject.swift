//
//  TestUIObject.swift
//  testui
//
//  Created by Momo Jo on 3/15/24.
//

import Foundation
import Alamofire

public class TestUIObject {

    public init() {

    }

    public func show() {
        print("show")
        Session.default.request("https://m.naver.com").response { res in
            print("res \(res.result)")
        }
    }
}
