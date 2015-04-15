//
//  LVKPlayerViewController.h
//  lvk-ios
//
//  Created by Woody Peterson on 11/6/14.
//
//

@class LVKMedia;
@class LVKMediaSource;
@class LVKPlayerController;
@class MPMoviePlayerController;

/**
 * A convenience class analagous to MPMoviePlayerViewController capable of
 * being directly inserted into the view stack.
 *
 * Responsible primarily for initializing an LVKPlayerController instance,
 * hooking the player output to its view, and stopping playback when the
 * view is no longer visible. Good for simple full-screen use cases.
 *
 * Playback control, events, etc, are accessed via the
 * `player` property of LVKPlayerViewController.
 */
@interface LVKPlayerViewController : UIViewController

@property (readonly, nonatomic) LVKPlayerController *player;

/**
 * Initializes a LVKPlayerViewController for the given media.
 * A MediaSource will be auto-selected based on the rules
 * defined in LVKPlayerController.
 *
 * @see LVKPlayerController
 * @see UIViewController
 */
+ (LVKPlayerViewController *)playerForMedia:(LVKMedia *)aMedia;

/**
 * Initializes a LVKPlayerViewController for the given media source.
 *
 * @see LVKPlayerController
 * @see UIViewController
 */
+ (LVKPlayerViewController *)playerForMediaSource:(LVKMediaSource *)aMediaSource;


- (id)initWithMedia:(LVKMedia *)aMedia;

- (id)initWithMediaSource:(LVKMediaSource *)aMediaSource;

@end