//
//  LVKLibrary
//  lvk-ios-sdk
//
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol LVKIdentifiable;


/**
 * The domain for all errors originating in LVKLibrary.
 */
extern NSString *const kLVKLibraryErrorDomain;


/**
 * There is not enough free space to save the file
 */
extern const NSInteger LVKLibraryInsufficientSpaceError;


/**
 * JSON parsing failed, or a model object could not be created from the JSON.
 */
extern const NSInteger LVKLibraryJSONParsingFailedError;

/**
 * The type of source is unsupported for the current operation.
 */
extern const NSInteger LVKLibraryUnsupportedMediaSourceTypeError;


/**
 * The local facilities can't read from disk.
 */
extern const NSInteger LVKLibraryReadFileError;


/**
 * The local facilities can't write to disk.
 */
extern const NSInteger LVKLibraryWriteFileError;


/**
 * The file did not pass checksum validation
 */
extern const NSInteger LVKLibraryChecksumError;


/**
 * The entrypoint for fetching Channel and Media objects from a
 * Limelight Orchestrate Video account.
 *
 * Must be initialized with an Organization's API credentials, and **it is strongly
 * recommended to use read-only keys**, as long as the keys are coded into the app.
 * Alternately, to keep API keys off of a device, an implementation should have
 * its own authenticated means of getting API keys from an Orchestrate customer's
 * personal server infrastructure.
 */
@interface LVKLibrary : NSObject


/**
 * The organization ID given to the library at initialization.
 */
@property(readonly, copy, nonatomic) NSString *organizationId;


/**
 * The access key given to the library at initialization.
 */
@property(readonly, copy, nonatomic) NSString *accessKey;


/**
 * The secret key given to the library at initialization.
 */
@property(readonly, copy, nonatomic) NSString *secret;


/**
 * The base URL used by the library to perform Limelight Orchestrate Video API requests.
 *
 * The base URL is the part of the URL before the path, which can encompass
 * several, optional parts of the URL before the path. It includes the protocol
 * and authority (which includes user info (if any), hostname, and port).
 *
 * @note You should not need to set this unless you wish to proxy the Limelight
 * Video API.
 */
@property(readonly, copy, nonatomic) NSString *baseURL;


/// ---------------------------------------------------------------------------
/// @name Creating Library Instances
/// ---------------------------------------------------------------------------

/**
 * Get a library instance configured with your organization's credentials.
 *
 * If you leverage sub-accounts, then you can create multiple libraries, one for
 * each sub-organization.
 *
 * @param organizationId Your Limelight Video Platform organization ID.
 * @param accessKey Your Limelight Video Platform access key.
 * @param secret Your Limelight Video Platform secret key.
 */
+ (LVKLibrary *)libraryWithOrganizationId:(NSString *)organizationId
                                accessKey:(NSString *)accessKey
                                   secret:(NSString *)secret;


/**
 * Get a library instance configured with your organization's credentials while
 * also setting the baseURL.
 *
 * @see libraryWithOrganizationId:accessKey:secret:
 *
 * @param organizationId Your Limelight Video Platform organization ID.
 * @param accessKey Your Limelight Video Platform access key.
 * @param secret Your Limelight Video Platform secret key.
 * @param baseURL String URL for the host to use for the content API. You should
 *        only need to change this in testing scenarios, if at all.
 */
+ (LVKLibrary *)libraryWithOrganizationId:(NSString *)organizationId
                                accessKey:(NSString *)accessKey
                                   secret:(NSString *)secret
                                  baseURL:(NSString *)baseURL;


/**
 * Access the LVKLibrary instance that retrieved an object. Useful for
 * accessing related data from the same Orchestrate Video account without having
 * to keep the instance in a global register or pass it around excessively.
 *
 * @param anIdentifiableObject Any object implementing <LVKIdentifiable>, most notably Media and MediaSource objects.
 * @return The LVKLibrary instance associated with the LVKIdentifiable object.
 */
+ (LVKLibrary *)libraryForIdentifiable:(id<LVKIdentifiable>)anIdentifiableObject;

@end
