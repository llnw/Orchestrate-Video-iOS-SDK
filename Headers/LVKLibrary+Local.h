//
//  LVPLibrary(Local)
//  lvp-ios-sdk
//
//  Created by Daniel Thompson on 2014-01-24
//  Copyright (c) 2014 Limelight Networks, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "LVKLibrary.h"

@class RACSignal;
@class LVKMedia;
@class LVKMediaSource;


@interface LVKLibrary (Local)

/**
 * Saves a downloadable MediaSource to the file system for later playback.
 *
 * Note: a license will be asynchronously saved along with the media as soon
 * as downloading has started.
 *
 * @param media The Media instance owning the source
 * @param source The MediaSource instance to save to disk
 *
 * @return A RACSignal providing download progress as an NSNumber of
 *         the total bytes downloaded so far.
 *
 * @throws LVKLibraryUnsupportedMediaSourceTypeError if the provided source is not downloadable.
 *
 * @see isDownloadable
 */
- (RACSignal *)saveMedia:(LVKMedia *)media withSource:(LVKMediaSource *)source;


/**
 * Retrieve all media stored locally.
 *
 * @return A RACSignal providing on-disk LVKMedia instances, with the relevant
 *         LVKMediaSource instance attached.
 */
- (RACSignal *)savedMedia;

@end
