//
//  _VKSourceWidevineStream.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import "LVKMediaSource.h"

/**
 * Widevine Streaming (HD & SD). To ensure Widevine is properly configured,
 * remember to view playback past the 10 second clear lead.
 *
 * For simple playback, LVKPlayerController will automatically decode the source.
 * For more advanced use cases, see LVKDRMDecoder.
 */
@interface LVKMediaSourceWidevine : LVKMediaSource

@end
