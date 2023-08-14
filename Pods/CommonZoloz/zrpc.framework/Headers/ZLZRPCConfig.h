//
//  ZLZRPCConfig.h
//  zrpc
//
//  Created by yukun.tyk on 2019/5/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZLZRPCConfig : NSObject

@property(nonatomic, copy)NSString *gateway;
@property(nonatomic, copy)NSString *operationType;
@property(nonatomic, copy)NSString *workspaceId;
@property(nonatomic, copy)NSString *appId;
@property(nonatomic, copy)NSString *returnType;
@property(nonatomic, copy)NSString *enablePB;
@property(nonatomic, copy)NSDictionary *customHeader;
@property(nonatomic, copy)NSString *pubkey;
@property(nonatomic, copy)NSString *merchantid;

@end

NS_ASSUME_NONNULL_END
