//
//  LVKAnalyticsReporter.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An interface to Limelight Video Platform analytics reporting. Use this
 * to implement analytics for a custom iOS player, as LVKPlayerController is
 * already integrated with LVKAnalyticsReporter.
 *
 * To customize analytics reporting, it is possible to subclass this
 * and override reporting methods such as 'appVersion' etc, but discression
 * must be used, as incorrect values could make the analytics nonsensical
 * in the Orchestrate Video dashboard. Consider contacting support to make
 * sure your intended use will work as you expect it to.
 *
 * Note, this reporter will queue requests when the device is offline
 * for later broadcasting.
 */
@interface LVKAnalyticsReporter : NSObject

@property (readonly, nonatomic) NSString* instanceId;
@property (readonly, nonatomic) NSString* userId;
@property (nonatomic) NSString* mediaId;

/**
 * A "session" represents the user interacting with a video player, but not
 * necessarily just one video. Must be called before any other analytics events,
 * but must only be called once per player interaction.
 */
- (void)sendStartSession;

/**
 * Sends a 'play' event for the currently set mediaId at the given position.
 * May be called multiple times per session, and with a varying set of mediaId
 * values. The latter case indicates moving on to a new media in a playlist,
 * using the same player.
 */
- (void)sendPlayWithPosition:(NSNumber*)position;

/**
 * Sends a 'pause' event for the currently set mediaId at the given position.
 * May be called multiple times per session, and with a varying set of mediaId
 * values.
 */
- (void)sendPauseWithPosition:(NSNumber*)position;

/**
 * Sends a 'seek' event for the currently set mediaId, starting from the given
 * position prior to seeking (positionBefore), and ending at the given end position
 * (positionAfter).
 */
- (void)sendSeekWithPositionBefore:(NSNumber*)positionBefore positionAfter:(NSNumber*)positionAfter;

/**
 * Send this event when someone watches a video to the finish. Not intended
 * for when users stop watching, switch to another video, close or background
 * the app, etc. Users can seek to the end of the video, though, to trigger
 * this event.
 */
- (void)sendMediaComplete;

/**
 * Pulls app name from bundle info's CFBundleName
 */
- (NSString *)appName;

/**
 * Pulls app version from bundle info's CFBundleVersion
 */
- (NSString *)appVersion;

/**
 * @"Apple"
 */
- (NSString *)deviceMake;

/**
 * The versioned model of the device, ex. "iPhone5,4"
 */
- (NSString *)deviceModel;

/**
 * UIDevice.currentDevice.systemVersion
 */
- (NSString *)OSVersion;

/**
 * @"iOS"
 */
- (NSString *)platform;

/**
 * @"Limelight Networks"
 */
- (NSString *)playerProviderID;

/**
 * Version of this SDK
 */
- (NSString *)LVKVersion;

/**
 * Time elapsed since sendStartSession was called.
 */
- (NSNumber *)millisecondsElapsed;

@end
