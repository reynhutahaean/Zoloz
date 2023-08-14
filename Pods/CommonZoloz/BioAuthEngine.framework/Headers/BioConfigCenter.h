//
//  BioConfigCenter.h
//  BioAuthEngine
//
//  Created by xuejiapeng on 2019/7/4.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BioConfigCenter : NSObject


+ (instancetype)sharedInstance;

- (NSString *)unzipChameleonFile:(NSString*)filePath;

- (NSString *)unzipOfflinePackageFile:(NSString*)filePath;

- (id)getValueByKey:(NSString*)key;

- (NSString*)chameleonFilePath;
@end

NS_ASSUME_NONNULL_END
