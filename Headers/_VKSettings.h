//
//  LVKSettings.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


extern int ddLogLevel;

extern const float _VKSettingsDefaultPlayerIdleTimeout;

NSString *_VKSettingsStageStaging;
NSString *_VKSettingsStageProduction;

@interface _VKSettings : NSObject

+ (NSString *)semanticVersion;
+ (NSString *)stage;
+ (void)setStage:(NSString *)stage;
+ (NSString *)metricsEndpoint;
+ (NSString *)contentEndpoint;
+ (NSString *)widevineLicenseProxyEndpoint;
+ (NSString *)widevinePortalKey;
+ (float)playerIdleTimeout;
+ (void)setPlayerIdleTimeout:(float)timeout;

@end
