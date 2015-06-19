//
//  LVKLibrary_Internal
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import "LVKLibrary.h"


@class _VKEncoding;
@protocol LVKIdentifiable;


@interface LVKLibrary ()

/**
* Maintains a map from the identifiable to the library that owns it.
*
* @see [LVKLibrary libraryForIdentifiable]
*/
+(void)setLibrary:(LVKLibrary *)library forIdentifiable:(id<LVKIdentifiable>)identifiable;


/**
* The shared map of identifiable to library instance.
*/
+(NSMutableDictionary*)identifiableMap;


/**
* Constructs a URLRequest for a resource by appending to the endpoint.
*
* @param resource A resource format string to be retrieved.
* @param ... The values to interpolate in the resource string.
* @return An NSURLRequest with a fully-formed URL.
*/
- (NSURLRequest *)URLRequestForResource:(NSString *)resource, ...;


/**
* Returns the encodings for the given media.
*
* @param aMediaId The Media ID for which to fetch the encodings.
* @return A signal that will raise an event for each encoding.
*/
- (RACSignal *)fetchEncodingsForMediaId:(NSString *)aMediaId;

@end
