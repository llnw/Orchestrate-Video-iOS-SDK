//
//  WViPhoneAPI_Stub.m
//  WViOSDemo
//
//  Created by Tony Seaward on 9/9/13.
//  Copyright 2011 Google Inc. All rights reserved.
//

// This is a stub to make it possible to run the project within the simulator
// because the Widevine library is compiled for arm6/7 architecture.


#import "WViPhoneAPI.h"

#if TARGET_IPHONE_SIMULATOR

WViOsApiStatus WV_Initialize(const WViOsApiStatusCallback callback,
                             NSDictionary *settings) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_Terminate() {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_SetUserData(NSString *userData) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_SetCredentials(NSDictionary *settings) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_RegisterAsset(NSString *asset) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_UnregisterAsset(NSString *asset) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_QueryAssetsStatus() {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_QueryAssetStatus(NSString *asset) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_NowOnline() {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_Play(NSString *asset,
                       NSMutableString *url,
                       NSData *authentication) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_Stop() {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_SelectBitrateTrack(int trackNumber) {
    return WViOsApiStatus_OK;
}

WViOsApiStatus WV_SelectAudioTrack(int trackNumber) {
    return WViOsApiStatus_OK;
}

NSString *WV_GetDeviceId() {
    return @"";
}

NSString *NSStringFromWViOsApiEvent(WViOsApiEvent x) {
    return @"";
}

#endif