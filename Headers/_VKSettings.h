//
//  LVKSettings.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 11/25/13.
//
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
