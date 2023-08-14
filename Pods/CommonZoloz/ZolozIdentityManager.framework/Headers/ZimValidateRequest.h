//
//  ZimValidateRequest.h
//  ZolozIdentityManager
//
//  Created by richard on 27/08/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZimValidateRequest;


@interface ZimValidateRequest:NSObject
@property (nonatomic,strong) NSString* zimId ;
@property (nonatomic,copy) NSData* zimData ;
- (NSString *)toJSON;
- (NSData *)pbSerialize;
@end


