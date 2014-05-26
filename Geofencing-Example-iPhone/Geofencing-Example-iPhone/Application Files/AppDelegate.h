//
//  AppDelegate.h
//  CouponExample
//

#import <UIKit/UIKit.h>

#import <KitLocate/KitLocate.h>

@class ViewController;
@class LocationHandler;

@interface AppDelegate :  UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) LocationHandler *kitLocateTasker;
@property (strong, nonatomic) ViewController *viewController;

@end
