//
//  AFEScanViewDelegate.h
//  FaceEyePrint
//
//  Created by yukun.tyk on 12/28/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  扫描界面接口，可以展示扫描动画和提示错误消息，错误消息内部做了平滑处理，
 *  1s内只会显示一条错误消息，在这期间传入的消息会做缓存处理，最多缓存1条消息
 *  如果同时播放声音，声音会与错误消息做同步处理
 */

typedef NS_ENUM(NSInteger, AFEScanViewStatus) {
    AFE_SCAN_SHOWING_ERROR,     //正在显示错误
    AFE_SCAN_SCANNING,          //正在扫描
    AFE_SCAN_HOLDING,           //等待显示缓存信息
    AFE_SCAN_STOPPED,           //停止中
};


@protocol AFEScanViewProtocol <NSObject>



/**
 *  设置扫描框缩放比例
 */
- (void)setScanViewScale:(CGFloat)scale;

/**
 *  设置导航栏透明度
 */
- (void)setNaviBarAlpha:(CGFloat)alpha;

/**
 *  开始扫描动画
 *
 *  @param audioPath 可选的播放声音文件路径，如果不播放声音，传入Nil
 */
- (void)beginScanWithAudio:(NSString *)audioPath;

/**
 *  暂停扫描动画
 *
 *  @param audioPath 可选的播放声音文件路径，如果不播放声音，传入nil
 */
- (void)stopScanWithAudio:(NSString *)audioPath;

/**
 *  设置扫描进度
 */
- (void)showPercent:(CGFloat)stage;

/**
 *  显示错误信息，同时播放声音提示
 *
 *  @param err       错误信息
 *  @param audioName 声音文件路径，不播放声音，传入nil
 */
- (void)showError:(NSString *)err withAudio:(NSString *)audioPath;

/**
 *  清除错误信息,同时暂停声音提示
 */
- (void)clearErrorMessageAndAudio;

/**
 *  设置声音按钮显示状态
 */
- (void)showSoundStatus:(BOOL)status;


@optional
/**
 *  设置左眼球和右眼球坐标
 */
- (void)setLeftEyeCoordinate:(CGRect)left
          rightEyeCoordinate:(CGRect)right;

@end
