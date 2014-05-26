//
//  AppDelegate.m
//  CouponExample
//

#import "AppDelegate.h"

#import "ViewController.h"
#import "LocationHandler.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Init KitLocate delegate tasker
    self.kitLocateTasker = [[LocationHandler alloc] init];
 
    // Init KitLocate framework
#warning put your api key replace ENTER_YOUR_API_KEY with @"XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX"
    [KitLocate initKitLocateWithDelegate:self.kitLocateTasker APIKey:ENTER_YOUR_API_KEY];

    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.viewController = [[ViewController alloc] initWithNibName:@"ViewController" bundle:nil];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    
    return YES;
}




@end
