//
//  Toyger.h
//  ToygerAlgorithm
//
//  Created by 王伟伟 on 2018/1/22.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToygerPublicDefine.h"
#import "ToygerConfig.h"
#import <CoreMedia/CoreMedia.h>
#import "ToygerFaceFrame.h"

@class ToygerServiceInstance;
@class ToygerFrame;

@protocol ToygerServiceInstanceDelegate<NSObject>

/**
 ToygerService处理完一帧后的状态更新的回调

 @param instance 算法实例
 @param frame 返回的帧
 */
- (void)toygerService:(ToygerServiceInstance *)instance frameDidUpdate:(ToygerFrame *)frame;

/**
 ToygerService事件触发

 @param instance 算法实例
 @param eventDict 触发的事件Dictionary
 */
- (void)toygerService:(ToygerServiceInstance *)instance triggerEvent:(NSDictionary *)eventDict;

/**
 ToygerService采集结束

 @param instance 算法实例
 @param infos    算法采集的图片集
 @param extInfo  算法层返回的扩展参数
 */
- (void)toygerService:(ToygerServiceInstance *)instance withResult:(BOOL)success handleFinish:(NSArray<ToygerFaceFrame *> *)infos withExtInfo:(NSDictionary *)extInfo;

@end

@interface ToygerServiceInstance : NSObject

/**
 设置算法的配置
 */
@property (nonatomic, strong) ToygerConfig *config;

/**
 ToygerInstace的代理
 */
@property (nonatomic, assign) id<ToygerServiceInstanceDelegate> delegate;

/**
 初始化Toyger算法.
 提前初始化可以加快算法的启动速度

 @return Toyger算法实例
 */
- (instancetype)initWithModelPath:(NSString *) modelPath;
/**
 Toyger算法处理图片

 @param sampleBuffer 摄像头传入的SampleBuffer
 */
- (void)processImage:(CMSampleBufferRef)sampleBuffer byOrientation:(UIImageOrientation)orientation extraInfo:(NSDictionary *)extra;



/**
 重置算法的状态
 */
- (void)reset;



@end
