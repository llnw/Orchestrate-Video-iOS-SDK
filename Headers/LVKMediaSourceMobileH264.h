//
//  _VKSourceMobileH264.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 1/19/14.
//
//

#import "LVKMediaSource.h"

/**
 * A legacy format with a single bitrate, therefore no adaptive bitrates.
 * Still supported by iOS, but HLS is much preferred.
 */
@interface LVKMediaSourceMobileH264 : LVKMediaSource

@end
