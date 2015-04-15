//
//  _VKRequestQueue.h
//  lvp-ios-sdk
//
//  Created by Woody Peterson on 11/21/13.
//
//

#import <Foundation/Foundation.h>

@interface _VKRequestQueue : NSOperationQueue

+ (void)postToUrl:(NSString*)url withJson:(NSDictionary*)json;
+ (void)enqueueRequest:(NSURLRequest*)request;

+ (_VKRequestQueue*)requestQueue;

@end
