//com.alipay.bis.common.service.facade.gw.model.upload.BisJsonUploadGwRequest
/*
 *generation date:Mon Mar 14 10:35:56 CST 2016
 *tool version:5.0.2
 *template version:4.1.1
 */

#import "APBConfig.h"

@interface APBBisUploadGwRequest : NSObject


@property(nonatomic, strong) NSData *content;
@property(nonatomic, strong) NSData *contentSig;

- (NSString *)toJsonString;
- (NSData *)pbSerialize;

+ (APBBisUploadGwRequest *)buildRequestWithContent:(NSData*)uploadContent andSig:(NSData*)contentSig;
@end
