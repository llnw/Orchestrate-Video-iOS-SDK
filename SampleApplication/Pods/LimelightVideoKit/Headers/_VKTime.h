//
//  _VKTime.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CFDate.h>
#import <CoreMedia/CoreMedia.h>


extern NSString *LVKTimeCodeForCMTime(CMTime);


@interface _VKTime : NSObject

+ (_VKTime *) instance;
+ (void) useMock;

- (CFTimeInterval) now;

@end

@interface _VKMockTime : _VKTime {
    CFTimeInterval elapsed;
}

- (void) tick: (CFTimeInterval)seconds;
- (void) reset;

@end

@interface _VKTrueTime : _VKTime

@end

