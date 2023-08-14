//
//  ZLZConfigCenter.h
//  ZolozDoc
//
//  Created by yukun.tyk on 2018/9/6.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ZLZChameleonConfig : NSObject


+(ZLZChameleonConfig *)sharedInstance;
+(void) clearAllData;

//chameleon 中 要根据docType来渲染提示文案，暴露此属性
@property (nonatomic,copy,readonly) NSString *currentDocType;
@property (nonatomic,copy) NSNumber *currentPageNo;

//- (void)setConfigPath:(NSString*)path;

//从chameleon配置文件中获取image配置
- (UIImage*)imageWithKey:(NSString*)key;
//从chameleon配置文件中获取color配置
- (UIColor*)colorWithKey:(NSString*)key;
//从chameleon配置文件中获取bool配置
- (BOOL)boolValueWithKey:(NSString*)key;

//从chameleon配置文件中获取bool配置, 如果没有读取到这个配置，使用默认值
- (BOOL)boolValueWithKey:(NSString*)key withDefault:(BOOL) defaultValue;

- (BOOL)hasKey:(NSString *)key withType:(NSString *) type;
//web容器使用，原子产品不要使用这个方法，直接使用- (UIColor*)colorWithKey:(NSString*)key即可
- (NSString*)colorStringWithKey:(NSString*)key;
//从chameleon配置文件中获取int配置
- (NSInteger)integerValueWithKey:(NSString*)key;

- (NSDictionary*)layoutConfig:(NSString*)key;

- (NSDictionary*)innerConfig:(NSString*)key;

- (NSString*)stringConfig:(NSString*)key;
/**销毁单例持有的资源*/
- (void)destroy;

@end
