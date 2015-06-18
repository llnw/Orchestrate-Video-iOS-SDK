//
//  _VKWidevine
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WViPhoneAPI.h"

@class LVKMediaSource;
@class RACSignal;
@class RACSubject;


typedef NS_ENUM(NSUInteger, _VKWidevineStatusEvents) {
  _VKWidevineStatusEventsNone = 0,
  _VKWidevineStatusEventsStarted,
  _VKWidevineStatusEventsLicensed,
};


@interface _VKWidevine : NSObject

+ (RACSignal *)initializeWidevine:(NSDictionary *)authParams;
+ (RACSignal *)terminateWidevine;
+ (BOOL)isWidevineInitialized;

- (id)initWithSource:(LVKMediaSource *)source;

@property(nonatomic, readonly) BOOL isRegistered;
@property(nonatomic, readonly) RACSubject *statusEvents;
@property(nonatomic, strong, readonly) LVKMediaSource *source;
@property(nonatomic, strong, readonly) NSURL *loopbackURL;
@property(nonatomic, strong, readonly) NSDictionary *license;

- (RACSignal *)register;
- (RACSignal *)unregister;
- (RACSignal *)start;
- (RACSignal *)stop;

@end
