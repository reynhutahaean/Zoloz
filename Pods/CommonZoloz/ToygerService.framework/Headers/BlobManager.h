//
//  BlobManager.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/6/28.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToygerUploadConfig.h"

@interface BlobManager : NSObject

@property(nonatomic, strong)ToygerUploadConfig *config;
@property(nonatomic)NSString *aesKey;

- (instancetype)initWithConfig:(ToygerUploadConfig *)config;

/**
 * UploadContent是否是UTF8编码，return true for JSON, false for PB
 * [子类不要复写该方法]
 */
- (BOOL) isUTF8;


/**
 * 返回RSA加密后的AES密钥
 * [子类不要复写该方法]
 */
- (NSData *)getKey;

/**
 * 获取上一个图片压缩以后的size
 */
- (CGSize)getImageSize;
/**
 * 会按照以下流程处理每一张图片：rotate->crop->resize->jpeg compress->encrypt
 * 该方法会读取config里面的参数进行resize以及压缩等操作，默认不进行crop
 * [子类不要复写该方法]
 * @param frame:需要处理的图片数据
 * @return: 处理之后的加密数据
 */
- (NSData *) processImage:(UIImage *)frame;

/**
 * 会按照以下流程处理每一张图片：rotate->crop->resize->jpeg compress->encrypt
 * 该方法会读取config里面的参数进行resize以及压缩等操作
 * [子类不要复写该方法]
 * @param frame:需要处理的图片数据
 * @param roi:图片剪裁区域
 * @return: 处理之后的加密数据
 */
- (NSData *) processImage:(UIImage *)frame
                      roi:(CGRect)roi;

/**
 * 会按照以下流程处理每一张图片：rotate->crop->resize->jpeg compress->encrypt
 * [子类不要复写该方法]
 * @param frame:需要处理的图片数据
 * @param width:图片resize宽度，高度会等比缩放
 * @param ratio:图片jpeg压缩比例
 * @param roi:图片剪裁区域
 * @return: 处理之后的加密数据
 */
- (NSData *) processImage:(UIImage *)frame
             desiredWidth:(NSInteger)width
             comressRatio:(CGFloat)ratio
                      roi:(CGRect)roi;

@end














