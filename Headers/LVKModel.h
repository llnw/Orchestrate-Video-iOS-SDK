//
//  LVKModel
//  lvp-ios-sdk
//
//  Created by Daniel Thompson on 2014-01-29
//  Copyright (c) 2014 Limelight Networks, Inc. All rights reserved.
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
