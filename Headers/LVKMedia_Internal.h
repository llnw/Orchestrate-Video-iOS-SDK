//
//  LVKChannel
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

@class LVKMedia;


@interface LVKMedia ()

/**
* The sources that are found locally on disk.
*
* This property, if non-nil, will override the -sources and be returned
* instead. In the future, the results will be interwoven.
*/
@property(nonatomic, readwrite) NSArray *localSources;

@end
