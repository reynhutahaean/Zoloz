//
//  ZimValidateResponse.h
//  ZolozIdentityManager
//
//  Created by richard on 27/08/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZimValidateResponse;
@class PBMapStringString;


@interface ZimValidateResponse:NSObject
@property (nonatomic) SInt32 validationRetCode ;
@property (nonatomic) SInt32 productRetCode ;
@property (nonatomic) BOOL pb_hasNext ;
@property (nonatomic,strong) NSString* nextProtocol ;
@property (nonatomic,strong) NSDictionary* extParams ;
@property (nonatomic,strong) NSString* retCodeSub ;
@property (nonatomic,strong) NSString* retMessageSub ;
+ (Class)extParamsElementClass;

+ (ZimValidateResponse *)fromJsonString:(NSString *)str;
+ (ZimValidateResponse *)pbDeserialize:(NSData *)data;
@end




