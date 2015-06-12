//
//  NSDate(LVKAdditions)
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
* Provides additions to the NSDate class.
*
* Adding some utility to the NSDate is important for the SDK so that we
* can improve the chances of being able to cache resources.
*/
@interface NSDate (LVKAdditions)

/**
* Creates a new date object that is at least the interval given in the future.
*
* The next date will be between now plus the interval and two times the interval.
*
* @param interval The time interval to use while clamping.
*/
- (NSDate *)lvk_dateClampedToNextTimeInterval:(NSTimeInterval)interval;

@end
