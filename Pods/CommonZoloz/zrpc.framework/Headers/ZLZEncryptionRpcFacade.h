//
//  ZLZEncryptionRpcFacade.h
//  zrpc
//
//  Created by zhaocheng on 2019/12/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZLZRPCConfig.h"
#import "ZLZRpcFacade.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZLZEncryptionRpcFacade : NSObject

- (void)send:(NSObject *)request
      config:(ZLZRPCConfig *)config
completionBlock:(ZRPCCallback)callback;

@end

NS_ASSUME_NONNULL_END
