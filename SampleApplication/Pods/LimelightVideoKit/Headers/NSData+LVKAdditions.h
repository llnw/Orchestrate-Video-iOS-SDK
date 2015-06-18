//
//  NSData(LVKAdditions)
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
* Provides additions to the NSData class.
*/
@interface NSData (LVKAdditions)

/**
* Computes the SHA-256 checksum of the instance.
*/
- (NSString *)lvk_SHA256;

@end
