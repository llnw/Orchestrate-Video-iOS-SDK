//
//  LVKChannel
//  LimelightVideoKit
//
//  Created by Daniel Thompson on 2012-12-20
//  Copyright (c) 2012 Limelight Networks, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>

@class LVKLibrary;
@class RACSignal;
@class RACDisposable;
@class UIImage;
@class UIImageView;

/**
 * A model encapsulating Limelight Orchestrate Video media channels.
 */
@interface LVKChannel : NSObject

@property(nonatomic, readonly) NSString *channelId;

@property(nonatomic, readonly) NSString *title;

@property(nonatomic, readonly) NSString *summary;

/**
 * The collection of media contained in this channel.
 */
@property(nonatomic, readonly) NSArray *media;

@property(nonatomic, readonly) NSString *thumbnailURL;

@property(nonatomic, readonly) LVKLibrary* library;


/**
 * Asynchronously retrieve the thumbnail for the channel.
 *
 * @return A RACSignal completing to a UIImage of the thumbnail.
 */
- (RACSignal *)thumbnail;


/**
 * Convenience method for placing a thumbnail into an existing view with a
 * custom placeholder while the thumbnail is retrieved.
 *
 * @param view The view to place the image in.
 * @param image A placeholder to use while the thumbnail is retrieved.
 *        The thumbnail will also be scaled and letter/pillar-boxed as necessary
 *        to the size of the placeholder.
 */
- (RACDisposable *)setThumbnailForView:(UIImageView*)view placeholderImage:(UIImage *)image;

@end




