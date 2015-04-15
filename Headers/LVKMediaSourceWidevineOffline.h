//
//  _VKSourceWidevineOffline.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 1/19/14.
//
//

#import "LVKMediaSource.h"

/**
 * Widevine Offline. To ensure Widevine is properly configured,
 * remember to view playback past the 10 second clear lead.
 *
 * For simple playback, LVKPlayerController will automatically decode the source.
 * For more advanced use cases, see LVKDRMDecoder.
 *
 * Note: a media license will be asynchronously aquired as soon as downloading is started.
 * see LVKLibrary saveMedia:withSource:
 */
@interface LVKMediaSourceWidevineOffline : LVKMediaSource

@end
