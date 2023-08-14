//
//  ToygerFaceUploadConfig.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/6/28.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "ToygerUploadConfig.h"

@interface ToygerFaceUploadConfig : ToygerUploadConfig

- (instancetype)initWithConfig:(NSDictionary *)cfg;

@property (nonatomic, copy) NSString *mode;
@property (nonatomic, copy) NSString *log_classifier;
@property (nonatomic, copy) NSArray *collection;

@end
