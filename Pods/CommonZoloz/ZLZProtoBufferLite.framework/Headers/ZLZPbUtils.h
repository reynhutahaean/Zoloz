//
//  ZLZPbUtils.h
//  pbTest
//
//  Created by vincentbao on 2019/8/7.
//  Copyright © 2019 vincentbao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZLZPbCallbacks.hpp"
#import "ZLZProtoBuf.pb.h"

#define NONE_NIL_STRING_PB(str)        (str ? str : @"")
#define PB_IS_VALID_STRING(str)        (str && (![str isEqualToString:@""]))


@interface ZLZPbUtils : NSObject

+ (void)ZLZPbFillString:(NSString *)str
                 target:(pb_callback_t *)callback;

+ (void)ZLZPbFillSubField:(NSData *)data
                  encoder:(rawBytesEncoder *)encoder
                    field:(const pb_field_t *)field
                   target:(pb_callback_t *)callback;

+ (NSData *)ZLZPbGetData:(const void *)target
                   field:(const pb_field_t *)field;

@end
