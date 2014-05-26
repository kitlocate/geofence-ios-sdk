//
//  ViewController.m
//  CouponExample
//

#import "ViewController.h"
#import <KitLocate/KitLocate.h>
#import "AppDelegate.h"

@implementation ViewController


#pragma mark -
#pragma mark Geofence Managment

-(IBAction)StartGeofencing:(id)sender
{
    // Start
    [KLLocation registerGeofencing];
}

-(IBAction)StopGeofencing:(id)sender
{
    // Stop
    [KLLocation unregisterGeofencing];
}

-(IBAction)onPressAddGeofences:(id)sender
{
    // Remove all the old Geofences
    [KLLocation deleteAllGeofences];
    
    // Add new geofences:
    
    KLGeofence *geofence;
    
#warning Add your Geofences you wish to monitor, we add 2 for example
    
    /*
     Let's add the 1st geofence
     ==========================
     We create the geofence using the init method written below. It contains the following parameters:
     Latitude/Longitude - Coordinates of the center of the geofence
     PushRadius         - The radius around the center that counts as a part of geofence
     Type               - Can be KL_GEOFENCE_TYPE_IN or KL_GEOFENCE_TYPE_OUT:
                            KL_GEOFENCE_TYPE_OUT - You'll be noted when the device will exit the geofence area
                            KL_GEOFENCE_TYPE_IN  - You'll be noted when the device will enter the geofence area
     */
    geofence = [[KLGeofence alloc] initWithLatitude:40.758928f Longitude:-73.98512f PushRadius:200 Type:KL_GEOFENCE_TYPE_OUT];
    
    // Optional parameters
    // -------------------
    
    // Set POI's unique name for your convenience
    [geofence setIDUser:@"TIMES SQUARE"];

    // Add the geofence to KitLocate.
    // Notice: you should set your geofence's properties BEFORE calling addGeofence.
    // any "set" methods will be called after addGeofence won't have any effect on the current geofence (unless you call again addGeofence)
    [KLLocation addGeofence:geofence];
    
    // Now we'll add the 2nd geofence
    // ==============================
    
    // Notice here we use an init method without define type - the default is KL_GEOFENCE_TYPE_IN
    geofence = [[KLGeofence alloc] initWithLatitude:40.748352f Longitude:-73.985552f PushRadius:300];
    
    [geofence setIDUser:@"EMPIRE STATE BUILDING"];

    [KLLocation addGeofence:geofence];
}

-(IBAction)onPressDeleteAllGeofences:(id)sender
{
    // Clean all geofences that were previously added to KitLocate 
    [KLLocation deleteAllGeofences];
}

/*
 KitLocate also helps you tracking your application using simple log reports,
 Soon you'll be able to see those logs from all your users in KitLocate's dashboard.
 */
-(IBAction)ReportOnUserPurchase:(id)sender
{
    float fAmount = 19.99f;
    [KLStatisticsServices logEvent:@"BUY" withParam:[NSString stringWithFormat:@"%f",fAmount]];
}

@end
