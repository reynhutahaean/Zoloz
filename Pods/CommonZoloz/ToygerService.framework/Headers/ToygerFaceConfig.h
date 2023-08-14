//
//  ToygerFaceConfig.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/7/5.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <ToygerService/ToygerService.h>
#import "ToygerFaceUploadConfig.h"
@class ToygerFaceAlgConfig;

@interface ToygerFaceConfig : ToygerConfig

- (instancetype)initWithConfig:(NSDictionary *)configDict;

@property(nonatomic, strong) ToygerFaceUploadConfig *uploadConfig;
@property(nonatomic, strong) ToygerFaceAlgConfig *algConfig;
@property(nonatomic) int ui_type;

@end
