//
//  UIMacro.h
//  BeautyMacroMoudle
//
//  Created by 吴闯 on 2020/9/1.
//  Copyright © 2020 1244775319@qq.com. All rights reserved.
//

#ifndef UIMacro_h
#define UIMacro_h

//屏幕相关
#define SCREEN_BOUNDS          [[UIScreen mainScreen] bounds]
#define SCREEN_HEIGHT          SCREEN_BOUNDS.size.height
#define SCREEN_WIDTH           SCREEN_BOUNDS.size.width
#define kUI_WidthS(a) (((a) / 375.0) * SCREEN_WIDTH)
#define kUI_HeightS(a) (((a) / 667.0) * SCREEN_WIDTH/9*16)
#define kScaleX [UIScreen mainScreen].bounds.size.width / 375
#define kScaleY [UIScreen mainScreen].bounds.size.height / 667

//判断是否是ipad
#define isPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
//判断iPhoneX
#define IS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPHoneXr
#define IS_IPHONE_Xr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs
#define IS_IPHONE_Xs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs Max
#define IS_IPHONE_Xs_Max ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)

#define iPhoneXSeries \
({BOOL iPhoneXSeries = NO;\
if (@available(iOS 11.0, *)) {\
iPhoneXSeries = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(iPhoneXSeries);})

#define  STATUS_BAR_HEIGHT      ((iPhoneXSeries==YES) ? 44.0 : 20.0)

#define TAB_BAR_HEIGHT    [(AppDelegate *)[UIApplication sharedApplication].delegate tabbar].tabBar.size.height//TabBar相关
#define NAV_BAR_HEIGHT    44 //NavBar相关（不包含状态栏的高度的）
#define kTopHeight (NAV_BAR_HEIGHT + STATUS_BAR_HEIGHT) // 导航栏高
// Tabbar safe bottom margin.
#define  LL_TabbarSafeBottomMargin         ((IS_IPHONE_X==YES || IS_IPHONE_Xr ==YES || IS_IPHONE_Xs== YES || IS_IPHONE_Xs_Max== YES) ? 34.f : 0.f)

#endif /* UIMacro_h */
