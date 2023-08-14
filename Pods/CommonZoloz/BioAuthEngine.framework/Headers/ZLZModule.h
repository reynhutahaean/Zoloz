//
//  ZLZModule.h
//  BioAuthEngine
//
//  Created by xuejiapeng on 2020/5/14.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// metainfo 设计方案 https://yuque.antfin-inc.com/zoloz/client/xc6pqv
@interface ZLZModule : NSObject

/// module name
@property (nonatomic,copy) NSString *name;

/// index  按文档约定，不能错，上层只感知index和version
@property (nonatomic,assign) int index;

/// version 版本号，每个模块需要维护自己的version，0 < version < 8,version无法扩展时应该增加module
@property (nonatomic,assign) int version;


+ (ZLZModule*)ModuleWithName:(NSString*)name index:(int)index andVersion:(int)version;

@end

NS_ASSUME_NONNULL_END
