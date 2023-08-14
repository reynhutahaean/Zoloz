//
//  ZLZWebService.h
//  WebContainerLite
//
//  Created by yukun.tyk on 2019/2/25.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>

NS_ASSUME_NONNULL_BEGIN

/**容器配置参数key值，url地址*/
extern NSString *const kZLZURLKey;

/**context中viewController key值*/
extern NSString *const kZLZViewControllerKey;

/**自定义titleBar背景颜色*/
extern NSString *const kZLZTitleBarColorKey;

/**自定义titleBar是否显示*/
extern NSString *const kZLZTitleBarKey;

/**自定义状态栏风格 status_bar_style_light*/
extern NSString *const kZLZStatusBarStyleLightKey;

/**自定义导航栏title颜色*/
extern NSString *const kZLZTitleColorKey;

/**是否disable离线包*/
extern NSString *const kZLZOffDisableKey;

/**是否支持手势返回*/
extern NSString *const kZLZGestureBackKey;

/**返回键图片*/
extern NSString *const KZLZBackImageKey;

/**外部传入H5离线包路径*/
extern NSString *const KZLZH5OfflinePackagePath;

/**Webview背景是否透明*/
extern NSString *const kZLZTransparencyKey;

/*是否首页导航栏不显示（demo用）*/
extern NSString *const KZLZHideNavBarInMainView;

/**JsApi结果回调处理*/
typedef void (^ZLZJsApiResponseCallback)( NSDictionary * responseData);

/**
 * JsApi处理x协议，所有JsApi实现类需要实现该协议
 */
@protocol ZLZJsApiHandler <NSObject>
@required
- (void)handle:(NSDictionary *)data context:(NSDictionary *)context callback:(ZLZJsApiResponseCallback)callback;
@end

@interface ZLZWebService : NSObject

/**容器单例*/
+(ZLZWebService *)sharedInstance;

/**容器初始化，注册JSAPI插件*/
- (void)startService;

/**释放容器单例*/
- (void)cleanup;
/**
 * 设置容器参数
 * kZLZOffDisableKey:是否关闭离线包
 */
- (void)setConfig:(NSDictionary *)config;

/**
 * 注册JsApi
 * @bundleName: 包含Config.plist配置文件的bundle
 */
- (void)registerJsApi:(NSString *)bundleName;

/**
 * 根据配置创建viewController
 * @config: viewcontroller配置，url为必选参数
 */
- (UIViewController *)viewControllerWithConfig:(NSDictionary *)config;

@end

NS_ASSUME_NONNULL_END
