//
//  LVKLibrary(Channel)
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LVKLibrary.h"

@class LVKChannel;
@class RACSignal;

@interface LVKLibrary (Channel)

/**
 * Retrieves all channels for the configured organization via a RACSignal.
 *
 * @return A RACSignal providing all LVKChannel objects for the organization.
 */
- (RACSignal *)fetchAllChannels;


/**
 * Retrieves all channels for the configured organization via success/failure callbacks.
 *
 * @param success Callback block receiving all LVKChannel instances in an organization.
 * @param failure Callback block receiving an NSError on fetch failure.
 */
- (void)fetchAllChannelsWithSuccess:(void (^)(NSArray *channels))success
                            failure:(void (^)(NSError *error))failure;


/**
 * Retrieves the LVKChannel instance for a given ID via a RACSignal.
 *
 * @param channelId The ID of the desired channel.
 * @return A RACSignal providing the LVKChannel instance,
 *         or signalling an error on fetch failure.
 */
- (RACSignal *)fetchChannelForId:(NSString *)channelId;


/**
 * Retrieves the LVKChannel instance for a given ID via success/failure callbacks.
 *
 * @param channelId The ID of the desired channel.
 * @param success Callback block receiving the LVKChannel instance for the provided ID.
 * @param failure Callback block receiving an NSError on fetch failure.
 */
- (void)fetchChannelForId:(NSString *)channelId
        success:(void (^)(LVKChannel *channel))success
        failure:(void (^)(NSError *error))failure;

@end
