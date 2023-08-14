//
//  ZLZLogService.h
//  APLogLite
//
//  Created by vincentbao on 2019/7/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZLZLogService : NSObject

/**Logger单例*/
+(ZLZLogService *)sharedInstance;

/**Logger初始化
 * @param serverUrl: log服务器的url
 * @param appId    : 客户端ID
 */
- (void)initServiceWithUrl:(NSString *)serverUrl
                     appId:(NSString *)appId;

/**Log记录接口
 * @param seedId: [data objectForKey:@"logSeedID"]
 * @param   info: [data objectForKey:@"logMessage"]
 */
- (void)appendLog:(NSString*)seedId
        info:(NSDictionary*)extParams;

/**手动触发上传
 */
- (void)triggerUpload;

/**设置userId
 */
- (void)setUserId:(NSString *)userId;

/**设置deviceId
 */
- (void)setDeviceId:(NSString *)deviceId;

/**设置bizType
 */
- (void)setBizType:(NSString *)bizType;

/** 获取 bizType */
- (NSString *) getBizType;

- (NSString *) getAppId;

- (void) setBizCode:(NSString *) bizCode;

- (NSString *) getBizCode;
/**释放所有对象实例
 */
+ (void)destroy;

@end
