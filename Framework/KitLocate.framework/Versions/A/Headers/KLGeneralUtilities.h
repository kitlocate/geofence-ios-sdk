//
//  KLGeneralUtilities.h
//  KitLocate
//
//  Created by Hadar Dubin on 10/8/13.
//
//

#import <Foundation/Foundation.h>

@interface KLGeneralUtilities : NSObject


// Local Push creation

/*! Create and show local notification immediatly. The app should not be in foreground to show the nofitication.
 * \param strPushText The message will be shown in the nofitication
 * \param strImage dentifies the image used as the launch image when the user taps (or slides) the action button (or slider). Can be @""
 * \param nBadge the number to show in the badge. 0 - Don't show anything
 * \param strSound The name of the file containing the sound to play when an alert is displayed. Can be @""
 */
+(void) createPushWithText:(NSString*) strPushText ImageName:(NSString *)strImage IconBadge:(int)nBadge SoundName:(NSString *)strSound;
+(void) createPushWithText:(NSString*) strPushText ImageName:(NSString *)strImage IconBadge:(int)nBadge SoundName:(NSString *)strSound UserInfo:(NSDictionary *)dicUserInfo TimeIntervalSinceNowInSeconds:(NSTimeInterval)timeInterval;
+(void) createPushWithText: (NSString*) strPushText ImageName:(NSString *)strImage IconBadge:(int)nBadge SoundName:(NSString *)strSound UserInfo:(NSDictionary *)dicUserInfo TimeIntervalSinceNowInSeconds:(NSTimeInterval)timeInterval withAlertTitle:(NSString *)strAlertTitile AlertButtonTitle:(NSString *)strAlertButtonTitle AlertCancelButtonTitle:(NSString *)strAlertCancelButton AlertDelegate:(id)delegate;

// Push Managment Approval

+(NSArray *)requestPushManagementApprovalWithGeofences:(NSArray *)arrGeofences; //#
+(NSArray *)requestDebugManagementWithStringParametersArray:(NSArray *)arrStringParams; //#

+(NSArray *)getLastPushManagementApprovalWithGeofences;

// APP STATE

/*! Tells you the app's state
 * \return true if app in background or suspended mode. false if active.
*/
+ (bool)isOnBackground;



@end
