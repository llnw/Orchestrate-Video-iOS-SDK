//
//  LVKMediaSource.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 1/19/14.
//
//

#import <Foundation/Foundation.h>
#import "LVKMedia.h"


/**
 * A LVKMediaSource represents a single, playable resource.
 *
 * The most basic element of a Media is an encoding, but some source mechanisms
 * can package multiple encodings into one URL. As such, the MediaSource
 * represents a collection of one-to-n encodings that are packaged together and
 * playable as a single unit.
 *
 * For example, Widevine streaming and HLS do automatic bit-rate switching,
 * while Widevine offline only has a single bit rate (and, as such,
 * a single encoding). For your convenience, all you need is the MediaSource
 * for the set of encodings you want to play.
 *
 * Note, LVKPlayerController will pick a reasonable media source if given just a media,
 * but for more fine-grained playback control a media source can also be specified.
 */
@interface LVKMediaSource : LVKModel <LVKIdentifiable>


/**
 * A UUID representing the source, in the form of 32 hexadecimal characters.
 */
@property (readonly, nonatomic) NSString *sourceId;


/**
 * The media to which the source belongs.
 */
@property(readonly, nonatomic) LVKMedia *media;


/**
 * URL where the source can be streamed or downloaded.
 */
@property(readonly, nonatomic) NSURL *remoteURL;


/**
 * The URL of the downloaded source, if applicable.
 *
 * Tip: KVO this property to get download completion notifications.
 *
 * @return If the source has been completely downloaded, returns the filesystem URL.
 * If the source has not been downloaded, including being in-progress, returns `nil`.
 */
@property(readonly, nonatomic) NSURL *localURL;


/**
 * For applicable MediaSource subtypes, returns extra delineation between
 * otherwise similar subtypes.
 *
 * Some media sources, most notably all Widevine-related sources, populate this 
 * property to help developers using this SDK to differentiate between
 * SD/HD/Offline without having to check class types or bitrate ranges.
 *
 * Possible values:
 *
 * - HD (high definition streaming)
 * - SD (standard definition streaming)
 * - Offline (non-streaming & configurable bitrates)
 */
@property(readonly, nonatomic) NSString *group;


/**
 * Whether the source is downloadable, ex. Widevine Offline.
 *
 * Technically, a streaming format such as HLS could be downloaded & streamed from disk,
 * but this SDK only provides support for downloading DRM-protected formats
 * designed to be downloaded.
 */
@property (readonly, nonatomic, getter=isDownloadable) BOOL downloadable;


/**
 * Whether the source is protected with DRM.
 *
 * Extra Limelight Orchestrate Video account and SDK configuration is necessary
 * to generate and play back protected files.
 */
@property (readonly, nonatomic, getter=isProtected) BOOL protected;

@end
