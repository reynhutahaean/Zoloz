//
//  ToygerFrame.h
//  ToygerAlgorithm
//
//  Created by 王伟伟 on 2018/1/22.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToygerPublicDefine.h"
typedef NSString* const ToygerServiceEventKey;
typedef NSNumber* const ToygerServiceSerializeType;
typedef NSString* const ToygerFaceFrameTypeKey;


@interface ToygerFrame : NSObject<NSCopying>

@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

@end
