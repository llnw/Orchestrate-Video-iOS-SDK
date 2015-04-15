//
//  LVKDRMDecoder.h
//  lvk-ios
//
//  Created by Woody Peterson on 11/6/14.
//
//

#import <Foundation/Foundation.h>

@class LVKMediaSource;

/**
 * Class to turn a DRM-protected LVKMediaSource into a playable HLS stream.
 *
 * Use by initializing with a media source, and watching the playbackURL and error
 * fields (likely via KVO) for decoding success and failure, respectively. Note that
 * you could get both a playbackURL initially, then an error during the 10
 * second clear lead if license acquisition fails.
 */
@interface LVKDRMDecoder : NSObject

/**
 * The media source given on decoder initialization
 */
@property (nonatomic, readonly) LVKMediaSource *mediaSource;

/**
 * The URL for unencrypted playback returned by the underlying DRM strategy.
 *
 * This will initially be nil, and will be set on successful authorization/decryption.
 * It is recommended to use KVO to monitor authorization success.
 */
@property (nonatomic, readonly) NSURL *playbackURL;

/**
 * If there is an error while authorizing, decoding, or a DRM-related playback issue,
 * this error field will store the last error encountered for playing back the
 * attached media source. It is recommended to use KVO to monitor playback failures,
 * but checking this field after a playback failure is detected might suffice as well.
 */
@property (nonatomic, readonly) NSError *error;

/**
 * Initialize a new DRMDecoder instance.
 *
 * Note: depending on the DRM implementation, only one instance at
 * a time may play back. If this is the case, initializing a new LVKDRMDecoder
 * instance may stop or alter playback from another LVKDRMDecoder instance
 * currently in use.
 */
+ (LVKDRMDecoder *)decoderForMediaSource:(LVKMediaSource *)aMediaSource;

@end
