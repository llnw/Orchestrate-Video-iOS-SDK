//
//  NSString(LVKAdditions)
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
* Additional methods added to NSString used by the Limelight iOS SDK.
*/
@interface NSString (LVKAdditions)

/**
* Returns a parameter string, which can optionally be alphabetized.
*
* The array is expected to mirror the format returned from calls to
* lvk_convertParameterStringToSortedArray, namely that it is a two-dimensional
* array with the first element being the key and the second element being an
* array of value strings.
*
* @param array The two-dimensional array to convert.
* @param sort Whether or not to sort the array.
*
* @return A new string instance formatted as a parameter string.
*/
+ (NSString *)lvk_parameterStringFromArray:(NSArray *)array sort:(BOOL)sort;


/**
* Returns an array with two elements, a string and another sorted array.
*
* The first element will be a the key, and those strings are sorted. The second
* element is an array, which contains the sorted values for that key.
*
* This matches the URL specification where it is possible to have two entries
* for one key. For instance, this is legit:
*
* > `"foo=baz&foo=bar"`
*
* In this case, the returned array would be:
*
* >    <code>&#91;"foo", &#91;"bar", "baz"]]</code>
*
* If the string is simple in nature, then the outer data structure returned is
* identical, but the values array is empty:
*
* >    <code>&#91;"foo", []]</code>
*
* @return A new two-dimensional array built from parsing the string.
*/
- (NSArray *)lvk_convertParameterStringToSortedArray;


/**
* Returns a new string that represents the string canonicalized (alphabetized).
*
* Canonicalized parameter strings are suitable to be used to sign for
* authentication.
*
* @return A parameter string where keys are alphabetized (as well as values).
*/
- (NSString *)lvk_canonicalizeParameterString;


/**
* Returns the MD5 hash for the string.
*
* @return A 32 digit hexadecimal representation of the string.
*/
- (NSString *)lvk_MD5;

@end
