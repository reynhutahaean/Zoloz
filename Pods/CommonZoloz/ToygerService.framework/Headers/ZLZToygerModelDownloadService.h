//
//  ZLZToygerModelInfo.h
//  ToygerDocScan
//
//  Created by Wangshi on 2021/1/26.
//  Copyright © 2021 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToygerServiceAlgo/ToygerServiceMeta.h>
typedef void(^ZLZModelDownloadSuccess)(NSString *fileMd5, NSString *filePath);
typedef void(^ZLZModelDownloadError)(NSString *);

@interface ZLZToygerModelDownloadService : NSObject

+ (id) shareInstance;

-(void) realDownload:(NSString *) md5 need:(BOOL) need
          success:(ZLZModelDownloadSuccess) success
               error:(ZLZModelDownloadError) error;


+ (void) downloadAll;
+ (void) downloadDoc:(ZLZModelDownloadSuccess) success
             onError:(ZLZModelDownloadError) error;
+(void) downloadFace:(ZLZModelDownloadSuccess) success
             onError:(ZLZModelDownloadError) error;
+ (void) download:(NSString *)fileMd5
        onSuccess:(ZLZModelDownloadSuccess) success
          onError:(ZLZModelDownloadError) error;
@end
