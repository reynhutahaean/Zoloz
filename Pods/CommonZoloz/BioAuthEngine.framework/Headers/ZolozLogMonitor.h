//
//  ZolozLogMonitor.h
//  BioAuthEngine
//
//  Created by richard on 22/03/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozLogMonitor : NSObject

- (instancetype)initWithBizInfo:(NSDictionary *)bizInfo;

- (void)setURL:(NSString *)url;

- (void)addPublicLog:(NSDictionary *)logDic;
/*
 *  添加埋点, param1为MD5(bis_token), param2=sequence_id
 *  param3: 第二个埋点数据, NSString或者NSNumber
 *  param4: 第三个埋点数据, NSString或者NSNumber
 *  seed:   埋点seesId
 *  ucid:   埋点ucid
 *  formattedParam: 附加参数
 */
- (void)addMonitorLoagWithActionId:(NSString *)actionId
                            param3:(NSObject *)p3
                            param4:(NSDictionary *)p4
                            seedId:(NSString *)seed
                              ucid:(NSString *)ucid
                    formattedParam:(NSDictionary *)param;

/**
 * [请勿直接调用]
 * 其他埋点接口都会调用到该方法进行埋点，该方法的默认实现是反射调用APRemoteLogger进行埋点
 * 如果输出渠道不支持APRemoteLogger，可以覆盖该方法自己实现
 */
+(void)writeLogWithActionId:(NSString *)actionId
                  extParams:(NSArray *)extParams
                      appId:(NSString *)appId
                       seed:(NSString *)seed
                       ucId:(NSString *)ucId;

@end
