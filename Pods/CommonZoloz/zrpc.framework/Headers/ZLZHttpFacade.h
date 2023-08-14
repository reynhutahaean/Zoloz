//
//  ZLZHttpFacade.h
//  zrpc
//
//  Created by Wangshi on 2022/1/26.
//  Copyright © 2022 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZLZHttpFacade : NSObject
- (BOOL) doRealHttpRequest:(NSString *) url
         withOperationType:(NSString *) optype
               withHeaders:(NSDictionary *) headers
                  withData:(NSData *)requestBody
              withCallback:(void (^)(NSData * _Nullable data, NSInteger httpCode))completionHandler;
@end

NS_ASSUME_NONNULL_END
