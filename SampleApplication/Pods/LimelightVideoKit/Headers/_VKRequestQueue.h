//
//  _VKRequestQueue.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface _VKRequestQueue : NSOperationQueue

+ (void)postToUrl:(NSString*)url withJson:(NSDictionary*)json;
+ (void)enqueueRequest:(NSURLRequest*)request;

+ (_VKRequestQueue*)requestQueue;

@end
