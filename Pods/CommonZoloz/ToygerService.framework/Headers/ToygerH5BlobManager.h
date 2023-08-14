//
//  ToygerH5BlobManager.h
//  ToygerService
//
//  Created by xuejiapeng on 2019/5/23.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BlobManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToygerH5BlobManager : BlobManager

+ (void)generateDocMonitorBlob:(NSArray<UIImage *> *)imageArray
                           env:(NSNumber*)env
                         ratio:(CGFloat)ratio
                  desiredWidth:(NSNumber*)desiredWidth
               completionBlock:(void(^)(NSData *content, NSData *key, BOOL isUTF8))callback;

+ (NSDictionary*)getH5BehaveLog:(NSString*)logJson env:(NSNumber*)env;

@end

NS_ASSUME_NONNULL_END
