//
//  FaceBlobManager.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/6/29.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "BlobManager.h"
#import "ToygerFaceFrame.h"

@interface FaceBlobManager : BlobManager
/**
 对于算法不支持的类型，需要组装数据, 此处用于 9 连 Blob 的数据

 @param image 传入的图片
 @return 返回要上传的内容
 */
- (NSData *)dataWithSurveillance:(NSArray<UIImage *> *)surveillance bisToken:(NSString *)bisToken extraInfo:(NSDictionary *)extraInfo;

- (NSData *)generateBlob:(ToygerFaceFrame *)frame
      withAlgoResultInfo:(NSDictionary *)algoResultInfo
                withType:(NSString *)invtpType
             withExtInfo:(NSDictionary *)extInfo;

- (NSData *)generateBlob:(ToygerFaceFrame *)frame
               withVideo:(NSString *)videoPath
                withExif:(NSString *)exifPath
      withAlgoResultInfo:(NSDictionary *)algoResultInfo
                withType:(NSString *)invtpType
             withExtInfo:(NSDictionary *)extInfo;
@end
