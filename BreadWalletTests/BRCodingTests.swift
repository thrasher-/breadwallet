//
//  BRCodingTests.swift
//  BreadWallet
//
//  Created by Samuel Sutch on 8/14/16.
//  Copyright © 2016 Aaron Voisine. All rights reserved.
//

import XCTest
@testable import breadwallet

class TestObject: BRCoding {
    var string: String
    var int: Int
    var date: NSDate
    
    init(string: String, int: Int, date: NSDate) {
        self.string = string
        self.int = int
        self.date = date
    }
    
    required init?(coder decoder: BRCoder) {
        string = decoder.decode("string")
        int = decoder.decode("int")
        date = decoder.decode("date")
    }
    
    func encode(coder: BRCoder) {
        coder.encode(string, key: "string")
        coder.encode(int, key: "int")
        coder.encode(date, key: "date")
    }
}

class BRCodingTests: XCTestCase {
    override func setUp() {
        super.setUp()
    }
    
    override func tearDown() {
        super.tearDown()
    }

    func testBasicEncodeAndDecode() {
        let orig = TestObject(string: "hello", int: 823483, date: NSDate(timeIntervalSince1970: 872347))
        let dat = BRKeyedArchiver.archivedDataWithRootObject(orig)
        
        guard let new: TestObject = BRKeyedUnarchiver.unarchiveObjectWithData(dat) else {
            XCTFail("unarchived a nil object")
            return
        }
        XCTAssertEqual(orig.string, new.string)
        XCTAssertEqual(orig.int, new.int)
        XCTAssertEqual(orig.date, new.date)
    }
}
