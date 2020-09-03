//
//  Toast.m
//  BeautyCommonUIMoudle_Example
//
//  Created by 吴闯 on 2020/9/1.
//  Copyright © 2020 1244775319@qq.com. All rights reserved.
//

#import "Toast.h"
#import "ToastView.h"
@interface Toast()
@property(nonatomic,retain)dispatch_queue_t queue;
@property(nonatomic,retain)dispatch_semaphore_t sema;
@property(nonatomic,strong)ToastView *toastView;
@end

@implementation Toast
-(instancetype)init{
    self = [super init];
    if (self) {
        [self setUpUI];
    }
    return self;
}
-(void)setUpUI{
    UIWindow *window = [UIApplication sharedApplication].delegate.window;
    [window addSubview:self.toastView];
    [self.toastView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(window).mas_offset(10);
        make.right.mas_equalTo(window).mas_offset(-10);
        make.top.mas_equalTo(window).mas_offset(-44);
        make.height.mas_equalTo(44);
    }];
    [window layoutIfNeeded];
    _queue = dispatch_queue_create("com.beauty.commonUI", DISPATCH_QUEUE_SERIAL);
    _sema = dispatch_semaphore_create(0);
}
#pragma mark public
+(instancetype)manager{
    static dispatch_once_t onceToken;
    static Toast *toast;
    dispatch_once(&onceToken, ^{
        toast=[[[self class]alloc]init];
    });
    return toast;
}
-(void)show:(NSString *)text{
    UIWindow *window = [UIApplication sharedApplication].delegate.window;
    __weak typeof(self) weakSelf = self;
    dispatch_async(_queue, ^{
        dispatch_async(dispatch_get_main_queue(), ^{
            self.toastView.desc=text;
            [self.toastView mas_updateConstraints:^(MASConstraintMaker *make) {
                make.top.mas_equalTo(window).mas_offset(STATUS_BAR_HEIGHT);
            }];
            [UIView animateWithDuration:0.25 animations:^{
                [window layoutIfNeeded];
            } completion:^(BOOL finished) {
                [self performSelector:@selector(dismiss) withObject:nil afterDelay:2.f];
            }];
        });
        dispatch_semaphore_wait(weakSelf.sema, DISPATCH_TIME_FOREVER);
    });
}
-(void)dismiss{
    __weak typeof(self) weakSelf = self;
    UIWindow *window = [UIApplication sharedApplication].delegate.window;
    [self.toastView mas_updateConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(window).mas_offset(-44);
    }];
    [UIView animateWithDuration:0.25 animations:^{
        [window layoutIfNeeded];
    }completion:^(BOOL finished) {
        dispatch_semaphore_signal(weakSelf.sema);
    }];
}
#pragma mark getter
-(ToastView *)toastView{
    if (_toastView==nil) {
        _toastView=[ToastView viewForXib];
    }
    return _toastView;
}
@end
