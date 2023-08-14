//
//  APBProtocol.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 3/15/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBConfig.h"

@interface BisClientConfigContent : NSObject
@property (nonatomic,strong) NSString* token;
@property (nonatomic) SInt32 type ;
@property (nonatomic) SInt32 sampleMode ;
@property (nonatomic,strong) NSString* androidcfg;
@property (nonatomic,strong) NSString* ioscfg;
@property (nonatomic,strong) NSString* h5cfg;
@end

@interface BisClientConfig : NSObject
@property (nonatomic,strong) BisClientConfigContent* contentBytes ;
@property (nonatomic,strong) NSString* sign;
@end

