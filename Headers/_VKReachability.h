//
//  _VKReachability.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 12/17/13.
//
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
