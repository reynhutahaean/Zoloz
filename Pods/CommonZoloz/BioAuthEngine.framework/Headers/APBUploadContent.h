//
//  APBUploadContent.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 8/26/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "APBConfig.h"

@interface BisFaceContent : NSObject

@property(nonatomic, strong)NSString * content;
@property(nonatomic, strong)NSString * rectx;
@property(nonatomic, strong)NSString * recty;
@property(nonatomic, strong)NSString * width;
@property(nonatomic, strong)NSString * height;
@property(nonatomic, strong)NSString * quality;
@property(nonatomic, strong)NSString * taskidx;

@end
