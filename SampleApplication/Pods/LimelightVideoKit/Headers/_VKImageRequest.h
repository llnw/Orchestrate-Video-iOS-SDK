//
//  _VKImageRequest.h
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

@interface _VKImageRequest : NSObject

+ (RACSignal *)requestImage:(NSURL *)url;
+ (UIImage *)scaleImage:(UIImage *)image forView:(UIImageView *) view;

@end



