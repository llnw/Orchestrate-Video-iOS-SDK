//
//  _VKSourceMobileH264.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import "LVKMediaSource.h"

/**
 * A legacy format with a single bitrate, therefore no adaptive bitrates.
 * Still supported by iOS, but HLS is much preferred.
 */
@interface LVKMediaSourceMobileH264 : LVKMediaSource

@end
