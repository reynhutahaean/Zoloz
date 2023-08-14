//
//  ToygerDocAlgConfig.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/7/5.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToygerDocAlgConfig : NSObject

//证件类型
@property (nonatomic, copy) NSString * docType;

//证件页码
@property (nonatomic, assign) NSInteger pageNo;

//当前的扫描模式
@property (nonatomic, strong) NSNumber *captureMode;

//摄像头图片旋转角度
@property (nonatomic, assign) NSInteger rotation;

/**
 * 算法参数，由于每个算法的参数不固定，所以用map表示
 * HK防伪
 * @key subType, @value [docimage|flashimage|angleimage]
 * @key boundaryThreshold: @value [0-1] as float
 * @key thickness: @value [0-100] as int
 * @key faceThreshold: @value[0-100] as int
 * @key corners: @value [0-1.] as NSArray<NSNumber *> tl.x tl.y, tr.x, tr.y, br.x br.y bl.x bl.y
 * @key flash: @value as @(NSInteger) 闪光灯计时器，ms单位
 * @key faceroi: @value CGRect
 * @key stackTime: @value [0 - ] as int, 证件4条边对齐以后，累积最佳证件的时间
 */
@property (nonatomic, copy) NSDictionary *algParam;

@end
