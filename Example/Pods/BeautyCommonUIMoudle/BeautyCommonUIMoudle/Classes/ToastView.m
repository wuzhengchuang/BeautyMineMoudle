//
//  ToastView.m
//  BeautyCommonUIMoudle_Example
//
//  Created by 吴闯 on 2020/9/1.
//  Copyright © 2020 1244775319@qq.com. All rights reserved.
//

#import "ToastView.h"
@interface ToastView()
@property (weak, nonatomic) IBOutlet UILabel *descLbl;
@end
@implementation ToastView

-(instancetype)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
        [self setUpUI];
    }
    return self;
}
-(instancetype)initWithCoder:(NSCoder *)coder{
    self = [super initWithCoder:coder];
    if (self) {
        [self setUpUI];
    }
    return self;
}
-(void)setUpUI{
    
}
#pragma mark public
+(ToastView *)viewForXib{
   return [[[NSBundle bundleForClass:[self class]]loadNibNamed:NSStringFromClass([self class]) owner:nil options:nil]lastObject];
}
#pragma mark setter
-(void)setDesc:(NSString *)desc{
    _desc=desc;
    self.descLbl.text=desc;
}
@end
