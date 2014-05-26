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
    [KitLocate initKitLocateWithDelegate:self.kitLocateTasker APIKey:@"bd095083-eedc-4d92-b0c8-524feb5ba1f8"];

    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.viewController = [[ViewController alloc] initWithNibName:@"ViewController" bundle:nil];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    
    return YES;
}




@end
