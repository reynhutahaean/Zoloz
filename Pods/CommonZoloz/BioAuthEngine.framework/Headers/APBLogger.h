//
//  APBLogger.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 12/8/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBConfig.h"

#define __FILE_NAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef DEBUG            //debug
    #define BIOAUTH_LOG(fmt, ...) { \
                NSString *__log = [NSString stringWithFormat:fmt, ##__VA_ARGS__];\
                __log = [NSString stringWithFormat:@"[ZOLOZ]:%@, function:%s, file:%s, line:%d, date:%s, time:%s\n",__log, __PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, __DATE__, __TIME__]; \
                NSLog(@"%@", __log);\
                [[APBLogMonitor sharedInstance]write:__log]; \
            }
    #define LOG_DBG(fmt, ...)       BIOAUTH_LOG(fmt, ##__VA_ARGS__);
#else                   //release
    #define BIOAUTH_LOG(fmt, ...) { \
                NSString *__log = [NSString stringWithFormat:fmt, ##__VA_ARGS__];\
                __log = [NSString stringWithFormat:@"[ZOLOZ]:%@, function:%s, file:%s, line:%d, date:%s, time:%s\n", __log, __PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, __DATE__, __TIME__]; \
                [[APBLogMonitor sharedInstance]write:__log]; \
                }
    #define LOG_DBG(fmt, ...)      
#endif


@interface APBLogMonitor : NSObject

/**
 * 该类讲debug日志写入本地文件，文件放在Documents目录下，以时间戳方式命名
 * `setup`:     创建日志文件以及handle,设置当前环境，这个方法不必在setup之前调用，在这个方法调用之前，日志会在内存进行缓存（最多1MB）
                这个方法调用以后，如果env是1，则将缓存写入磁盘，如果env是0，则清除内存缓存，后续`write`方法都不再生效
 * `cleanup`:   将关闭handle
 * `write`:     将日志写入本地
 * `setEnv`:
 */
+ (instancetype)sharedInstance;

- (void)setupWithEnv:(NSInteger)env;

- (void)cleanup;

- (void)write:(NSString *)log;

@end

