//
//  ToygerAlgorithmPublicDefine.h
//  ToygerAlgorithm
//
//  Created by 王伟伟 on 2018/1/22.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#ifndef ToygerAlgorithmPublicDefine_h
#define ToygerAlgorithmPublicDefine_h

//#define SUPPORT_PB
//#define USE_FPP
//#define USE_SENSOR

#import <Foundation/Foundation.h>
//#import "ToygerBlobElem.h"

#if defined(__cplusplus)
#define TOYGER_EXPORT extern "C"
#else
#define TOYGER_EXPORT extern
#endif

typedef NSData* (^buildCipherUploadContentBlock)(BOOL nano, NSInteger retryCnt, NSString* invType, NSString* bisToken);
//typedef void(^generateBlobElementBlock)(BOOL nano, ToygerBlobElem* elem);

typedef NSString* const ToygerServiceEventKey;
typedef NSNumber* const ToygerServiceSerializeType;
typedef NSString* const ToygerFaceFrameTypeKey;

static NSString *const kPhotinusVideoUrlKey = @"photinusVideoUrl";
static NSString *const kPhotiunsMetaUrlKey = @"photinusMetaUrl";

static NSString *const kOtherBlobElementsKey = @"otherBlobElements";

typedef NS_ENUM(NSUInteger, ToygerFrameFormat) {
    ToygerFrameFormat_NV21,
    ToygerFrameFormat_BGRA,
    ToygerFrameFormat_BGR,
};

typedef NS_ENUM(NSUInteger, ToygerFrameType) {
    ToygerFrameType_Light,
    ToygerFrameType_Unknown,
    ToygerFrameType_Dark,
};

TOYGER_EXPORT ToygerServiceEventKey ToygerServiceEventDarkScreen;
TOYGER_EXPORT ToygerServiceEventKey ToygerServiceEventHighQualityImage;
TOYGER_EXPORT ToygerServiceEventKey ToygerServiceEventUserInfo;
TOYGER_EXPORT ToygerServiceEventKey ToygerServiceEvent;
TOYGER_EXPORT ToygerFaceFrameTypeKey ToygerServiceFrameTypeLight;
TOYGER_EXPORT ToygerFaceFrameTypeKey ToygerServiceFrameTypeDark;

TOYGER_EXPORT ToygerServiceSerializeType ToygerServiceEventSerializeJson;
TOYGER_EXPORT ToygerServiceSerializeType ToygerServiceEventSerializePb;

#endif /* ToygerAlgorithmPublicDefine_h */
