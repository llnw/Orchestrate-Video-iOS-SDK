//
//  _VKImageRequest.h
//  lvp-ios-sdk
//
//  Created by Jared Roberts on 1/21/14.
//
//
#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

@interface _VKImageRequest : NSObject

+ (RACSignal *)requestImage:(NSURL *)url;
+ (UIImage *)scaleImage:(UIImage *)image forView:(UIImageView *) view;

@end



