//
//  Toast.h
//  BeautyCommonUIMoudle_Example
//
//  Created by 吴闯 on 2020/9/1.
//  Copyright © 2020 1244775319@qq.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface Toast : NSObject
+(instancetype)manager;
-(void)show:(NSString *)text;
@end

NS_ASSUME_NONNULL_END
