//
//  ZNTransactionEntity.h
//  ZincWallet
//
//  Created by Aaron Voisine on 8/22/13.
//  Copyright (c) 2013 Aaron Voisine <voisine@gmail.com>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class ZNTxInputEntity;
@class ZNTxOutputEntity;
@class ZNTransaction;

@interface ZNTransactionEntity : NSManagedObject

@property (nonatomic, retain) NSData *txHash; // little endian
@property (nonatomic) int32_t blockHeight;
@property (nonatomic) NSTimeInterval timeStamp;
@property (nonatomic, retain) NSOrderedSet *inputs;
@property (nonatomic, retain) NSOrderedSet *outputs;
@property (nonatomic) int32_t lockTime;

+ (void)setBlockHeight:(int32_t)blockHeight forTxHashes:(NSArray *)txHashes;

- (instancetype)setAttributesFromTx:(ZNTransaction *)tx;
- (ZNTransaction *)transaction;

@end

// These generated accessors are all broken because NSOrderedSet is not a subclass of NSSet.
// This known core data bug has remained unaddressed for over two years: http://openradar.appspot.com/10114310
// Per core data release notes, use [NSObject<NSKeyValueCoding> mutableOrderedSetValueForKey:] instead.
@interface ZNTransactionEntity (CoreDataGeneratedAccessors)

- (void)insertObject:(ZNTxInputEntity *)value inInputsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromInputsAtIndex:(NSUInteger)idx;
- (void)insertInputs:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeInputsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInInputsAtIndex:(NSUInteger)idx withObject:(ZNTxInputEntity *)value;
- (void)replaceInputsAtIndexes:(NSIndexSet *)indexes withInputs:(NSArray *)values;
- (void)addInputsObject:(ZNTxInputEntity *)value;
- (void)removeInputsObject:(ZNTxInputEntity *)value;
- (void)addInputs:(NSOrderedSet *)values;
- (void)removeInputs:(NSOrderedSet *)values;
- (void)insertObject:(ZNTxOutputEntity *)value inOutputsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromOutputsAtIndex:(NSUInteger)idx;
- (void)insertOutputs:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeOutputsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInOutputsAtIndex:(NSUInteger)idx withObject:(ZNTxOutputEntity *)value;
- (void)replaceOutputsAtIndexes:(NSIndexSet *)indexes withOutputs:(NSArray *)values;
- (void)addOutputsObject:(ZNTxOutputEntity *)value;
- (void)removeOutputsObject:(ZNTxOutputEntity *)value;
- (void)addOutputs:(NSOrderedSet *)values;
- (void)removeOutputs:(NSOrderedSet *)values;
@end
