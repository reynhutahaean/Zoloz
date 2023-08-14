//
//  APBBase64.h
//  BioAuthService
//
//  Created by yukun.tyk on 12/24/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APBBase64 : NSObject

+(NSString *)encodeData:(NSData *)data;

+(NSData *)decodeString:(NSString *)str;

+(NSString *)stringByWebSafeEncodingData:(NSData *)data padded:(BOOL)pad;

@end
