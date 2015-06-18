//
//  LVKModel
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MTLModel.h"
#import "MTLJSONAdapter.h"


@protocol LVKIdentifiable

- (NSString *)identifier;

@end


/**
 * Base model class implementing basic initialization and serialization.
 */
@interface LVKModel : MTLModel <MTLJSONSerializing>

+ (instancetype)modelWithProperties:(NSDictionary *)properties;


@end
