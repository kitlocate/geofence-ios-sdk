
#import "LocationHandler.h"
#import <KitLocate/KitLocate.h>


@implementation LocationHandler

#pragma mark -
#pragma mark Callback functions

-(void)geofencesIn:(NSArray *)arrGeofenceList
{
    for(KLGeofence *currGeofence in arrGeofenceList)
    {

        NSString *strMessage;
         
#warning Add your code here to handle the geofence Enter
        // EXAMPLE - we will give local push notification on Enter
        
        if (![[currGeofence getIDUser] isEqualToString:@""])
        {
            strMessage = [NSString stringWithFormat:@"Enter %@",[currGeofence getIDUser]];
        } else {
            
            // Get Additional information about the geofence (else than URL): Latitude / Longitude / Radius / Type
            float fLatitude = [currGeofence getLatitude];
            float fLongitude = [currGeofence getLongitude];
            int nRadius = [currGeofence getPushRadiusInMeters];
            klGeofenceType typeGeofence = [currGeofence getTypeGeofence];
            
            strMessage = [NSString stringWithFormat:@"Enter Lat:%g Lon:%g Rad:%d Type:%d", fLatitude, fLongitude, nRadius, typeGeofence];
        }
        
        // Call Local Push Notification
        [KLGeneralUtilities createPushWithText:strMessage ImageName:@"" IconBadge:0 SoundName:UILocalNotificationDefaultSoundName];
    }

}

-(void)geofencesOut:(NSArray *)arrGeofenceList
{
    
    for(KLGeofence *currGeofence in arrGeofenceList)
    {
        
        NSString *strMessage;
        
#warning Add your code here to handle the geofence Exit
        // EXAMPLE - we will give local push notification on Exit
        
        if (![[currGeofence getIDUser] isEqualToString:@""])
        {
            strMessage = [NSString stringWithFormat:@"Exit %@",[currGeofence getIDUser]];
        } else {
            
            // Get Additional information about the geofence (else than URL): Latitude / Longitude / Radius / Type
            float fLatitude = [currGeofence getLatitude];
            float fLongitude = [currGeofence getLongitude];
            int nRadius = [currGeofence getPushRadiusInMeters];
            klGeofenceType typeGeofence = [currGeofence getTypeGeofence];
            
            strMessage = [NSString stringWithFormat:@"Exit Lat:%g Lon:%g Rad:%d Type:%d", fLatitude, fLongitude, nRadius, typeGeofence];
        }
        
        // Call Local Push Notification
        [KLGeneralUtilities createPushWithText:strMessage ImageName:@"" IconBadge:0 SoundName:UILocalNotificationDefaultSoundName];
    }
    
}



@end
