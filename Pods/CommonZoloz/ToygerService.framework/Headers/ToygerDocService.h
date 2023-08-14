//
//  ToygerDocService.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/6/28.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "ToygerPublicDefine.h"
#import <CoreMedia/CoreMedia.h>

typedef NS_ENUM(NSInteger, ToygerDocMessage) {
    TG_MESSAGE_NO_CARD = 0, // 没有证件
    TG_MESSAGE_TOO_FAR,// 距离手机太远
    TG_MESSAGE_TOO_CLOSE,// 距离手机太近
    TG_MESSAGE_INTEGRITY,// 证件不完整
    TG_MESSAGE_TILTING,//  手机倾斜
    TG_MESSAGE_SHADOW,// 有阴影
    TG_MESSAGE_OCCLUSION,// 证件有遮挡
    TG_MESSAGE_REFLECTION,// 证件有反光
    TG_MESSAGE_BLUR,// blur
    TG_MESSAGE_STACK_TIME,// 请保持
    TG_MESSAGE_WRONG_CARD, // WRONG_CARD
};


@class ToygerUploadConfig,ToygerDocAlgConfig,ToygerDocAttr, ToygerDocState, ToygerDocFrame;

/**
 * Blob封装结束回调
 * @param content: BlobData
 * @param key:秘钥密文
 * @param isUTF8: 是否为UTF8编码
 */
typedef void(^BlobCallback)(NSData *content, NSData *key, BOOL isUTF8);

typedef NS_ENUM(NSInteger, ToygerDocResultCode) {
    TOYGER_DOC_SUCCESS,
    TOYGER_DOC_LIVENESS_FAIL,
    TOYGER_DOC_ERROR
};

@protocol ToygerDocDelegate <NSObject>

/**
 * 当前证件状态更新，每一帧都会回调
 * @param attr:当前证件的属性
 * @param state:当前证件的状态，可以根据状态做交互提示
 */
- (void)onUpdate:(ToygerDocAttr *)attr
           state:(ToygerDocState *)state;

/**
 * 证件扫描结束回调，每个config只调用一次
 * @param code: 证件扫描结果
 * @param frame: 采集的证件图片
 */
- (void)onFinish:(ToygerDocResultCode) code
           frame:(ToygerDocFrame *)frame;

- (void) onTriggerEvent:(NSDictionary *)eventDict;
@end


/**
 * 调用时序 init -> setDelegate -> setConfig -> onFinish -> reset -> setConfig -> onFinish -> reset -> ...  -> generateDocBlob
 */
@interface ToygerDocService : NSObject

@property(nonatomic, weak) id<ToygerDocDelegate> delegate;

// 初始化扫描版证件宝
- (instancetype)initWithScanDoc:(NSString *) modelPath;
/**
 * 设置配置参数
 * @param uploadConfig: 上传参数
 * @param algConfig: 算法参数，拍照模式下可以传空
 */
- (void)setUploadConfig:(ToygerUploadConfig *)uploadConfig
     andAlgorithmConfig:(ToygerDocAlgConfig *)algConfig;

/**
 处理图片
 @param sampleBuffer 摄像头传入的SampleBuffer
 */
- (void)processImage:(CMSampleBufferRef)sampleBuffer byOrientation:(UIImageOrientation)orientation extraInfo:(NSDictionary *)extra;

/**
 * 清除缓存的配置数据
 * @param clearBlobs: 是否清空toyger缓存的blob数据
 */
- (void)reset:(BOOL)clearBlob;

/**
 * 生成证件宝blob，blob会同步回调
 * @param callback: blob封装结束的回调
 */
- (void)generateDocBlobWithCompletionBlock:(BlobCallback)callback;

/**
 * 证件宝手拍模式下，每一帧的摄像头数据不会经过toyger，但是在用户点击拍照以后，需要将照片封装成blob进行上传，可以调用该方法封装blob
 * 该方法是同步方法，调用时不用加锁，由于返回参数比较多，所以放在block里面返回
 * @param frame:用户拍照的图片
 * @param config:和上传相关的参数，压缩比、rsa公钥等
 * @param num: 证件第几页
 * @param type: 证件类型
 * @param callback:结果回调
 *          @content: blob数据
 *          @key: rsa加密后的aes密钥
 *          @isUTF8: content是否是UTF8编码[是否可以强转成NSString *]
 */
+ (void)generateDocBlobWithFrame:(UIImage *)frame
                    uploadConfig:(ToygerUploadConfig *)config
                          pageNo:(NSInteger)num
                         docType:(NSString *)type
                 completionBlock:(BlobCallback)callback;

/**
 * 添加九连拍图片，toygerService内部维护9连拍队列
 * @param image: 需要添加的九连拍的图片
 */
- (void)addMonitorImage:(UIImage*)image;

/**
 * 添加九连拍图片，callback会同步调用
 * @param callback: blob封装结束的回调，同步调用
 */
- (void)generateDocMonitorBlobWithCompletionBlock:(BlobCallback)callback;

/**获取当前toyger内部缓存了几张9连拍图片*/
- (NSInteger)monitorCount;

/**清空9连拍缓存*/
- (void)clearMonitor;

- (void) releaseToyger;

@end

@interface ToygerDocAttr:NSObject
@property(nonatomic, copy)NSString *docType;
@property(nonatomic, copy)NSString *subType;
@property(nonatomic, assign)int page;
//证件四个边的分值
@property(nonatomic, assign) float topLineScore;
@property(nonatomic, assign) float rightLineScore;
@property(nonatomic, assign) float bottomLineScore;
@property(nonatomic, assign) float leftLineScore;
//证件人脸质量分
@property(nonatomic, assign) int faceScore;

// 四个角，8个点的坐标
@property(nonatomic, strong)NSArray<NSNumber *> * points;

@end

@interface ToygerDocState:NSObject
@property(nonatomic, assign)BOOL hasFace;
@property(nonatomic, assign)BOOL hasDoc;
@property(nonatomic, assign)BOOL top;
@property(nonatomic, assign)BOOL right;
@property(nonatomic, assign)BOOL bottom;
@property(nonatomic, assign)BOOL left;
@property(nonatomic, assign)ToygerDocMessage messageCode;
// 四个角，8个点的坐标
@property(nonatomic, strong)NSArray<NSNumber *> * points;
@end

@interface ToygerDocFrame:NSObject
@property(nonatomic, strong)UIImage *image;
@property(nonatomic, strong)ToygerDocAttr *attr;
@property(nonatomic, strong)NSArray <NSNumber *> *region;
@end

