//
//  _VKReachability.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

@class Reachability;

@interface _VKReachability : NSObject

+ (void)observeHost:(NSString*)hostName
      whenReachable:(void (^)(Reachability* reach))reachableBlock
    whenUnreachable:(void (^)(Reachability* reach))unreachableBlock;

#ifdef DEBUG
+ (SCNetworkReachabilityFlags)currentReachabilityFlags;
+ (NSString*)currentReachabilityFlagsString;
+ (void)reachabilityChanged:(SCNetworkReachabilityFlags)flags;
#endif

@end
