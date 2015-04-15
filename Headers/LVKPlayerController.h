//
//  LVKPlayerController.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 1/7/14.
//
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>

@class LVKMedia;
@class LVKMediaSource;
@class LVKDRMDecoder;
@class LVKAnalyticsReporter;
@class MPMoviePlayerController;


/**
 * The core video player of the Orchestrate Video SDK.
 *
 * Analagous to MPMoviePlayerController, LVKPlayerController is responsible for
 * controlling video playback of content hosted on the Orchestrate Video platform.
 * This player does not manage a playback view, so one must be provided to it.
 *
 * Provides automatic support for Closed Captions, DRM, and analytics, and is
 * a drop-in replacement for anything expecting an <MPMediaPlayback> interface.
 *
 * See LVKPlayerViewController for automatic full-screen view management.
 */
@interface LVKPlayerController : NSObject <MPMediaPlayback>

// Ultimately overridden & delegated;
// these declarations silence a warning from the MPMediaPlayback protocol.

@property (nonatomic) float currentPlaybackRate;
@property (nonatomic) NSTimeInterval currentPlaybackTime;
@property (readonly, nonatomic) BOOL isPreparedToPlay;


/**
 * The output of video playback will be sent to the provided view.
 */
@property (nonatomic) UIView* view;

/**
 * The media to play back.
 *
 * Note that a media by itself isn't enough information
 * to initiate playback, but a MediaSource will be automatically selected based
 * on the following criteria, in the following order of preference:
 *
 * - A media source downloaded locally to disk
 * - DRM-protected sources (indicated by `isProtected == true`)
 * - HLS sources
 * - Mobile H.264 sources
 *
 * If multiple sources fulfil the same criteria outlined above, which one
 * is chosen is not specified. If more control is needed, select the source
 * ahead of time and set `mediaSource` directly.
 *
 * @see mediaSource
 */
@property (nonatomic) LVKMedia* media;

/**
 * The specific LVKMediaSource to play back.
 *
 * Use this to specify a media source, as opposed to the autoselect method
 * provided by setMedia.
 */
@property (nonatomic) LVKMediaSource* mediaSource;

/**
 * Provides access to the drmDecoder instance in use by the player.
 *
 * Especially handy for diagnosing DRM-related playback errors.
 *
 * @see LVKDRMDecoder
 */
@property (readonly, nonatomic) LVKDRMDecoder* drmDecoder;

/**
 * Provides access to the analytics reporter instance in use by the player.
 *
 * The player automatically invokes the related analytics callbacks, so no
 * direct use of the reporter should be necessary. However, we provide access
 * in case custom calls to our analytics backend (in addition to the existing
 * functionality) is needed.
 *
 * @see LVKAnalyticsReporter
 */
@property (readonly, nonatomic) LVKAnalyticsReporter* analyticsReporter;

/**
 * Provides access to the underlying MPMoviePlayerController instance.
 *
 * This should be accessed sparingly, as any behavior triggered on the
 * underlying player directly can have undefined behavior on the LVKPlayerController
 * that owns it.
 */
@property (readonly, nonatomic) MPMoviePlayerController* mpPlayer;


/**
 * Convenience initializer to set the view immediately.
 */
+ (LVKPlayerController *)playerWithView:(UIView *)aView;

/**
 * Convenience initializer to set the view and media immediately.
 */
+ (LVKPlayerController *)playerWithView:(UIView *)aView forMedia:(LVKMedia *)aMedia;

/**
 * Convenience initializer to set the view and media source immediately.
 */
+ (LVKPlayerController *)playerWithView:(UIView *)aView forMediaSource:(LVKMediaSource *)aMediaSource;


- (LVKPlayerController *)initWithView:(UIView *)aView;
- (LVKPlayerController *)initWithView:(UIView *)aView forMedia:(LVKMedia *)aMedia;
- (LVKPlayerController *)initWithView:(UIView *)aView forMediaSource:(LVKMediaSource *)aMediaSource;


@end