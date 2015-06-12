//
//  LVKMedia
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "LVKModel.h"


@class RACSignal;
@class RACDisposable;

/**
 * The broad category of the type of media:
 * audio only, on-demand video, or live video.
 */
typedef NS_ENUM(NSInteger, LVKMediaType) {
  /**
   * No type is associated with the media; most definitely an error if seen
   * in production.
   */
  LVKMediaTypeNone,

  /**
   * On-demand video
   */
  LVKMediaTypeVideo,

  /**
   * Audio-only
   */
  LVKMediaTypeAudio,

  /**
   * Orchestrate Video's legacy live solution, **not** playable on iOS
   */
  LVKMediaTypeLiveStream,

  /**
   * MMD Live (Multi-device Media Streaming), playable on iOS
   */
  LVKMediaTypeLiveEvent
};


/**
 * The primary domain model of the SDK, representing audio, on-demand video,
 * or a live stream. The canonical source of media metadata and information.
 *
 * Note, since a media has many potential playback sources (see LVKMediaSource),
 * a media is not by itself playable, but from an end-users'
 * perspective this is what they are selecting. As a convenience,
 * the LVKPlayerController (and LVKPlayerViewController) will
 * auto-select a reasonable default source to play.
 */
@interface LVKMedia : LVKModel <LVKIdentifiable>

/**
 * The API-provided ID of the media item.
 */
@property(readonly, nonatomic) NSString *mediaId;

/**
 * The name of the media item.
 */
@property(readonly, nonatomic) NSString *title;

/**
 * The description of the media item.
 */
@property(readonly, nonatomic) NSString *summary;

/**
 * The broad category of the media: audio, on-demand video, or live video.
 *
 * @see LVKMediaType
 */
@property(readonly, nonatomic) enum LVKMediaType mediaType;

/**
 * The length of the media, in milliseconds.
 */
@property (assign, nonatomic) CMTime duration;

/**
 * The date when the media was added to the platform.
 */
@property (readonly, nonatomic) NSDate *created;

/**
 * The date the media metadata was last changed.
 */
@property (readonly, nonatomic) NSDate *updated;


/**
 * The URL to retrieve closed captions for this media.
 */
@property (readonly, nonatomic) NSURL *closedCaptionsURL;


/**
 * The thumbnail URL of this media.
 *
 * The thumbnail is a small image representation of the media for use in elements
 * like tables and grids.
 *
 * @see posterURL
 */
@property(nonatomic, readonly) NSString *thumbnailURL;


/**
 * The poster URL of this media.
 *
 * The poster is a large image representation of the media for use in the player
 * when the media has not yet started playback.
 *
 * @see thumbnailURL
 */
@property (nonatomic, readonly) NSString *posterURL;


/**
 * Asynchronously retrieve the media sources for the media.
 *
 * @return A signal providing a stream of LVKMediaSource instances for this media.
 *
 * @see LVKMediaSource
 */
@property (nonatomic, readonly) RACSignal *sources;


/**
 * Asynchronously retrieve the thumbnail for the media.
 *
 * @return A RACSignal completing to a UIImage of the thumbnail.
 */
- (RACSignal *)thumbnail;


/**
 * Convenience method helping to display a thumbnail, but with a
 * custom placeholder while the thumbnail is being retrieved.
 *
 * @param placeholder A placeholder image until the thumbnail is retrieved.
 *
 * @return UIImageView with a placeholder image asynchronously replaced by the
 *         real thumbnail, scaled and letter/pillar-boxed as necessary to fit
 *         the size of the placeholder.
 */
- (UIImageView *)imageViewForThumbnailWithPlaceholder:(UIImage *)placeholder;


/**
 * Convenience method for placing a thumbnail into an existing view with a
 * custom placeholder while the thumbnail is retrieved.
 *
 * @param view The view to place the image in.
 * @param image A placeholder to use while the thumbnail is retrieved. The thumbnail will also be scaled and letter/pillar-boxed as necessary to the size of the placeholder.
 */
- (RACDisposable *)setThumbnailForView:(UIImageView*)view placeholderImage:(UIImage *)image;

@end
