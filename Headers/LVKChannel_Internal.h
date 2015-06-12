//
//  LVKChannel_Internal
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@class LVKChannel;

@interface LVKChannel ()

/**
* Creates a channel from the current instance, adding the media.
*
* @param theMedia The array of media to add.
*/
- (LVKChannel *)channelWithMedia:(NSArray *)theMedia;


/**
 * Creates a channel from the given JSON string.
 *
 * You should not need to call this method except while testing.
 *
 * @param data The data to parse.
 * @param library The LVKLibrary instance from which the data came from.
 */
- (LVKChannel *)initWithData:(NSData *)data library:(LVKLibrary*)library;


/**
 * Creates a media from a dictionary of attributes, usually API response data.
 *
 * You should not need to call this method except while testing.
 *
 * @param properties The dictionary to pull values for properties from.
 * @param library The LVKLibrary instance from which the properties came from.
 */
- (LVKChannel *)initWithProperties:(NSDictionary *)properties library:(LVKLibrary *)library;

@end
