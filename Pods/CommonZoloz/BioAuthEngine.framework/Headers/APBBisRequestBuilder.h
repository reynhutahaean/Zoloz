//
//  APBBisRequestBuilder.h
//  BioAuthEngine
//
//  Created by 晗羽 on 21/04/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBBisUploadGwRequest.h"


@interface APBBisRequestBuilder : NSObject

+(APBBisUploadGwRequest *) buildRequestwithCypherData:(NSData *)aesKeyData
                                          contentData:(NSData *)content;

@end
