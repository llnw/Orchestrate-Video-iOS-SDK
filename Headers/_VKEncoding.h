//
//  _VKEncoding.h
//  lvp-ios-sdk
//
//  Created by Daniel Thompson on 2013-02-21.
//  Copyright (c) 2013 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LVKModel.h"


/**
* The type of use the encoding is primarily targeted toward.
*
* The values represent a naive order of precedence to which should be used.
*/
typedef NS_ENUM(NSInteger, _VKPrimaryUse) {
  /// No primary use has been set.
  _VKPrimaryUseNone,
  /// The primary use is intended for mobile H.264.
  _VKPrimaryUseMobileH264,
  /// The primary use is intended for HLS.
  _VKPrimaryUseHTTPLiveStreaming,
  /// The primary use is intended for Widevine.
  _VKPrimaryUseWidevine,
  /// The primary use is intended for Widevine offline.
  _VKPrimaryUseWidevineOffline
};

static NSString *const kPrimaryUse = @"primary_use";
static NSString *const kHTTPLiveStreaming = @"HttpLiveStreaming";
static NSString *const kMobileH264 = @"MobileH264";
static NSString *const kWidevine = @"Widevine";
static NSString *const kWidevineOffline = @"WidevineOffline";

// groups currently in use
static NSString *const kLVKHighDefinitionGroup = @"HD";
static NSString *const kLVKStandardDefinitionGroup = @"SD";
static NSString *const kLVKOfflineGroup = @"Offline";


@interface _VKEncoding : LVKModel

@property(readonly, nonatomic) NSString *mediaId;
@property(readonly, nonatomic) unsigned long long sizeInBytes;
@property(readonly, nonatomic) NSUInteger height;
@property(readonly, nonatomic) NSUInteger width;
@property(readonly, nonatomic) NSUInteger audioBitRate;
@property(readonly, nonatomic) NSUInteger videoBitRate;
@property(readonly, nonatomic) _VKPrimaryUse primaryUse;
@property(readonly, nonatomic) NSString *group;
@property(readonly, nonatomic) NSURL *encodingURL;
@property(readonly, nonatomic) NSURL *playlistURL;
@property(readonly, nonatomic) NSURL *URL;

@end
