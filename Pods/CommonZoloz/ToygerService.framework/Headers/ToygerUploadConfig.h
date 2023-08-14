//
//  ToygerUploadConfig.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/7/5.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToygerUploadConfig : NSObject

@property (nonatomic, copy) NSString *pubKey;
@property (nonatomic, copy) NSString *upload_compress_rate;
@property (nonatomic, strong) NSNumber *desiredWidth;
@property(nonatomic, assign) CGRect roi;
@property (nonatomic, strong) NSString *bisToken;
@property (nonatomic,assign) BOOL needAES;

@end
