//
//  ToastView.h
//  BeautyCommonUIMoudle_Example
//
//  Created by 吴闯 on 2020/9/1.
//  Copyright © 2020 1244775319@qq.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastView : UIView
@property(nonatomic,strong)NSString *desc;
+(ToastView *)viewForXib;
@end

NS_ASSUME_NONNULL_END
