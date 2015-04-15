//
//  LVKLibrary(Media)
//  lvp-ios-sdk
//
//  Created by Daniel Thompson on 2014-01-31
//  Copyright (c) 2014 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LVKLibrary.h"

@class RACSignal;
@class LVKMedia;

@interface LVKLibrary (Media)

/**
 * Retrieves the media model for a given ID via a RACSignal.
 *
 * @param mediaId The ID of the desired media.
 * @return RACSignal providing the LVKMedia instance for the given ID,
 *         or an error on fetch failure.
 */
- (RACSignal *)fetchMediaForId:(NSString *)mediaId;


/**
 * Retrieves the media model for a given ID via success/failure callbacks.
 *
 * @param mediaId The ID of the desired media.
 * @param success Callback block receiving the LVKMedia instance for the given media ID.
 * @param failure Callback block receiving an NSError on fetch failure.
 */
- (void)fetchMediaForId:(NSString *)mediaId
        success:(void (^)(LVKMedia *media))success
        failure:(void (^)(NSError *error))failure;


/**
 * Retrieves all the media for a given channel via a RACSignal.
 *
 * @param channelId The Channel ID for which to retrieve media.
 * @return RACSignal providing all LVKMedia instances for the given channel ID,
 *         or an error on fetch failure.
 */
- (RACSignal *)fetchAllMediaForChannelId:(NSString *)channelId;


/**
 * Retrieves all the media for a given channel via success/failure callbacks.
 *
 * @param channelId The Channel ID for which to retrieve media.
 * @param success Callback block receiving all LVKMedia instances for the given channel ID.
 * @param failure Callback block receiving an NSError on fetch failure.
 */
- (void)fetchAllMediaForChannelId:(NSString *)channelId
        success:(void (^)(NSArray *channels))success
        failure:(void (^)(NSError *error))failure;

@end
