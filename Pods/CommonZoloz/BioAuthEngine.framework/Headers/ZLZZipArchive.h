//
//  ZLZZipArchive.h
//  
//
//  Created by aish on 08-9-11.
//  acsolu@gmail.com
//  Copyright 2008  Inc. All rights reserved.
//
// History: 
//    09-11-2008 version 1.0    release
//    10-18-2009 version 1.1    support password protected zip files
//    10-21-2009 version 1.2    fix date bug

#import <UIKit/UIKit.h>

@protocol ZLZZipArchiveDelegate <NSObject>
@optional
-(void) ErrorMessage:(NSString*) msg;

@end


@interface ZLZZipArchive : NSObject {
//@private
//	zipFile		_zipFile;
//	unzFile		_unzFile;
//	
//	NSString*   _password;
//	id			_delegate;
}

-(BOOL) UnzipOpenFile:(NSString*) zipFile;
-(BOOL) UnzipOpenFile:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite;
-(BOOL) UnzipCloseFile;
@end
