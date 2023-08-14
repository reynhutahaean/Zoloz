//
//  ZLZException.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 2019/1/7.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZLZException:NSObject

@property(nonatomic, copy, readonly)NSString *code;
@property(nonatomic, copy, readonly)NSString *message;

+(ZLZException *)createInstanceWithCode:(NSString *)code
                                message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
