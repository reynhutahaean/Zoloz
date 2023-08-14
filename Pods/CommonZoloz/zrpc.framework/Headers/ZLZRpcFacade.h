//
//  ZLZRpcFacade.h
//  zrpc
//
//  Created by yukun.tyk on 2019/5/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZLZRPCConfig.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ZRPCCallback)(BOOL, NSError * _Nullable,  NSObject * _Nullable );
static NSString *const kZLZErrorDomain = @"com.zoloz.rpc";
static const NSInteger kZLZClientNetworkUnavailableError = 2;
static const NSInteger kZLZServerUnknowError = 5000;
static const NSInteger kZLZSServerValueInvalid = 3002;
static const NSInteger kZLZServerIllegalArgument = 6005;
static const NSInteger kZLZPpcOperationTypeEmpty = 7004;
static const NSInteger kZLZIlligalRequest = -1;
static const NSInteger kZLZIlligalResponse = -2;

@interface ZLZRpcFacade : NSObject

- (void)send:(NSObject *)request
      config:(ZLZRPCConfig *)config
completionBlock:(ZRPCCallback)callback;

@end

NS_ASSUME_NONNULL_END
