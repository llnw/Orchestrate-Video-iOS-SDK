//
//  LVKMediaSource_Internal
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "LVKMediaSource.h"


@interface LVKMediaSource ()

/**
* The encodings that make up this source.
*/
@property(readonly, nonatomic) NSArray *encodings;


/**
* Allows internal users to set where the source is on disk.
*
* @param url The file system URL of the source.
*/
- (void)setLocalURL:(NSURL *)url;


/**
* Creates a source from an array of encodings.
*
* Cursory checks are done on the encodings to ensure that the URL is the same
* for each one. If they are not, a NSInternalInconsistencyException is thrown.
*
* @param encodings A group of encodings that comprise this source.
*/
+ (instancetype)sourceForMedia:(LVKMedia *)aMedia withEncodings:(NSArray *)encodings;

@end
