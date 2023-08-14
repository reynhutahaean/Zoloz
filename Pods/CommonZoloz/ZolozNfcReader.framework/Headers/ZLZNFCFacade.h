//
//  ZLZNFCFacade.h
//  ZBaseDemo
//
//  Created by 薛佳鹏 on 2022/10/14.
//  Copyright © 2022 zoloz. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * key for first name
 */
extern NSString *const kZNfcFirstName;

/**
 * key for last name
 */
extern NSString *const kZNfcLastName;

/**
 * key for gender
 */
extern NSString *const kZNfcGender;

/**
 * key for  issuing state
 */
extern NSString *const kZNfcIssuingState;

/**
 * key for  face image
 */
extern NSString *const kZNfcfaceImage;

/**
 * [optional] key for custom request header , must be set in bizparam before start eKYC
 */
extern NSString *const kZLZCustomHeaderKey;
@interface ZLZNfcConfig : NSObject

/// passport number,string length is 9
@property (nonatomic,copy) NSString *idNmuber;

/// date of birth, format yyyy/MM/dd
@property (nonatomic,copy) NSString *dateOfBirth;

/// passport expire date,format yyyy/MM/dd
@property (nonatomic,copy) NSString *expiryDate;

@end


@interface ZLZNfcResponse : NSObject


/// retcode
/// 1000- success     2001 - config wrong
/// 2002 - invalid MRZ key
/// 2003 - system error
/// 2004 - nfc switch disabled
/// 2005 - device not support nfc
/// 3000 - user cancel
@property (nonatomic,assign) NSInteger retCode;


/// user info read from passport
@property (nonatomic,copy) NSDictionary *cardInfo;
@end

typedef void(^ZLZNfcCallback)(ZLZNfcResponse *);

@interface ZLZNfcFacade : NSObject


/**get the singlton instance of ZLZNfcFacade*/
+ (ZLZNfcFacade *)sharedInstance;



/// start read nfc tag from passport
/// - Parameters:
///   - config:refer to ZLZNfcConfig
///   - zcallback: refer to ZLZNfcCallback
- (void)startNFCWithConfig:(ZLZNfcConfig*)config onCompletion:(ZLZNfcCallback)zcallback;

@end




NS_ASSUME_NONNULL_END
