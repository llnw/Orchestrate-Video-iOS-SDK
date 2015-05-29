//
//  NSURLRequest(LVKAdditions)
//  LimelightVideoKit
//
//  Created by Daniel Thompson on 2012-12-09
//  Copyright (c) 2012 Limelight Networks, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>

@class LVKLibrary;

extern NSString *const GET;
extern NSString *const POST;
extern NSString *const PUT;
extern NSString *const DELETE;

static NSTimeInterval const kDefaultExpiryTimeInterval = 300;


/**
* Additional methods used by the Limelight iOS SDK.
*/
@interface NSURLRequest (LVKAdditions)

/**
* Returns a new NSURLRequest that is signed.
*
* @param library The library who should supply the credentials for signing.
*
* @return A new NSURLRequest.
*/
- (NSURLRequest *)lvk_sign:(LVKLibrary *)library;



/**
* Returns Signed URL
*
* @param httpVerb GET, POST, etc... It will be converted to lowercase.
* @param resourceURL The URL the REST request will be sent to.
* @param accessKey An organization's access key.
* @param secret The secret to use to sign the request.
* @param params The name-value pairs that will be appended to the query-string.
*
* @return An NSString URL representation that has been signed.
*/

NSString *authenticateRequest(NSString *httpVerb, NSString *resourceURL, NSString *accessKey, NSString *secretKey, NSDictionary *params);


@end
