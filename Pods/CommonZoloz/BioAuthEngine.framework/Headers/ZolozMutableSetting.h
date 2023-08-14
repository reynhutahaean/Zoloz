//
//  ZolozMutableSetting.h
//  BioAuthEngine
//
//  Created by richard on 24/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozMutableSetting : NSObject
/**
 *每一个属性都开放三个函数
 * `defaultProperty`    用于解决方案层设置默认属性
 * `setProperty`        用于在运行时设置属性，会覆盖默认属性【不要复写】
 * `property`           用于调用方在运行时获取属性【不要复写】
 */
+ (instancetype)getInstance;

- (NSString *)defaultGatewayURL;
- (void) setGatewatURL:(NSString *)url;
- (NSString *)gatewayURL;

- (NSDictionary *)defaultHeaderConfig;
- (void) setHeadConfig:(NSDictionary *)config;
- (NSDictionary *)headConfig;

- (NSString *)defaultZolozInitRequestOperationType;
- (void)setZolozInitRequestOperationType:(NSString *)operationType;
- (NSString *)zolozInitRequestOperationType;

- (NSString *)defaultValidateRequestOperationType;
- (void)setValidateRequestOperationType:(NSString *)operationType;
- (NSString *)validateRequestOperationType;

- (NSString *)defaultBioAuthEngineVersion;
- (void)setBioAuthEngineVersion:(NSString *)version;
- (NSString *)bioAuthEngineVersion;

- (NSString *)defaultTestPubKey;
- (void)setTestPubkey:(NSString *)key;
- (NSString *)testPubKey;

- (NSString *)defaultOnlinePubKey;
- (void)setOnlinePubkey:(NSString *)key;
- (NSString *)onlinePubKey;

- (void)setEnvironment:(NSInteger)env;
- (NSString*)pubkey;
- (void)setMid:(NSString *)mid;
- (NSString*)getMid;
- (void)setChameleon: (NSString *) chameleonPath;
- (NSString *)getChameleon;
- (void)setDocModelFilePath:(NSString *)docModelFilePath;
- (NSString*)getdocModelFilePath;
- (NSString*)huobanBuildVersion;

/**
 * 为容器添加y初始化配置，由于依赖的容器不同，该方法由解决方案层实现
 */
- (void)setWebContainerConfig:(NSDictionary *)config;


@end
