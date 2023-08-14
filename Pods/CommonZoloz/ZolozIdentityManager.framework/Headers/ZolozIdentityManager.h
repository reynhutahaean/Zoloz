//
//  ZIMIdentityManager.h
//  ZolozIdentityManager
//
//  Created by richard on 31/10/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


//ext params keys
extern NSString *const kZIMInitOperationTypeKey;        //init operation type
extern NSString *const kZIMValidateOperationTypeKey;    //validate operation type
extern NSString *const kZIMGatewayURLKey;               //rpc gateway url
extern NSString *const kZIMRpcHeaderKey;                //ext rpc header
extern NSString *const kZIMCurrentViewControllerKey;    // current view controller
extern NSString *const kZIMFastUploadKey;
extern NSString *const kZIMBisProtocolKey;
extern NSString *const kZIMResponseKey;
extern NSString *const kZIMDelegateValidate;
@class ZIMResponse;
@class ZimValidateRequest;
@class ZimValidateResponse;
@class ZLZException;

typedef void (^ZIMCallback)(ZIMResponse *response);

typedef void (^ZIMQuitCallback)(BOOL succes, NSDictionary * reason);

typedef void (^ZIMResponseCallback)(BOOL success,ZimValidateResponse *response,ZLZException *error);

@protocol ZIMValidateDelegate <NSObject>

- (void)handleValidateRequest:(ZimValidateRequest*)request
                 onCompletion:(ZIMResponseCallback)callback;

@end


@interface ZolozIdentityManager : NSObject



+ (ZolozIdentityManager *)sharedInstance;

/* standard verification
 * @param ZIMId: unique id to identity one verification transaction
 * @param params: some custom parameter that biz can specify
 * @param callback: block triggered when verification is finished
 */

- (void)verifyWith:(NSString *)zimId
         extParams:(NSDictionary *)params
      onCompletion:(ZIMCallback)callback;


- (void)quit:(NSDictionary *) params
onCompletion:(ZIMQuitCallback)callback;

+ (NSDictionary *)getMetaInfo;

+ (NSString *)version;

- (void)setValidateDelegate:(id<ZIMValidateDelegate>)validateDelegate;


@end

