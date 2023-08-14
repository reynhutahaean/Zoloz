//
//  APBDeviceInfo.h
//  BioAuthEngine
//
//  Created by 晗羽 on 28/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APBDeviceInfo : NSObject

/**
 *每一个属性都开放三个函数
 * `defaultProperty`    用于解决方案层设置默认属性
 * `setProperty`        用于在运行时设置属性，会覆盖默认属性【不要复写】
 * `property`           用于调用方在运行时获取属性【不要复写】
 */
+ (instancetype)getInstance;

- (NSInteger)defaultLanguageCode;
- (void)setLanguageCode:(NSInteger)code;
- (NSInteger)languageCode;

- (NSString *)defaultLanguageName;
- (void)setLanguageName:(NSString *)name;
- (NSString *)languageName;

- (NSString *)defaultApdidToken;
- (void)setApdidToken:(NSString *)token;
- (NSString *)apdidToken;

-(void) initDeviceInfo;

@end
