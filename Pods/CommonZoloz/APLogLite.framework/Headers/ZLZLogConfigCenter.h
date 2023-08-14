//
//  ZLZLogConfigCenter.h
//  APLogLite
//
//  Created by vincentbao on 2019/7/10.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZLZLogConfigCenter : NSObject

+ (instancetype)sharedInstance;

// 是否启用服务
- (BOOL)getEnable;
- (void)setEnable:(BOOL) enable;

// 启动时是否上传历史log
- (BOOL)getStartup;
- (void)setStartup:(BOOL) startup;

// 切后台时是否上传log
- (BOOL)getBackground;
- (void)setBackground:(BOOL) background;

// 是否加密
- (BOOL)getEncrypt;
- (void)setEncrypt:(BOOL) encrypt;

// 上传条数阈值
- (NSInteger)getLogCount;
- (void)setLogCount:(NSInteger) count;

// 内存缓存条数阈值
- (NSInteger)getMemCacheCount;
- (void)setMemCacheCount:(NSInteger) count;

// 最大允许累计文件大小
- (NSInteger)getCacheFileSize;
- (void)setCacheFileSize:(NSInteger) size;

// 最大文件数量
- (NSInteger)getFileCount;
- (void)setFileCount:(NSInteger) count;

// 获取密钥
- (NSString *)getRsaPub;
- (void)setRsaPub:(NSString*) rsaPub;

+ (void)destroy;

@end
