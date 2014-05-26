//
//  StatisticsServices.h
//  KitLocate
//
//  Created by Ron Miller on 12/16/12.
//
//

#import <Foundation/Foundation.h>


@interface KLStatisticsServices : NSObject
{
}

/*! Allows you add events at chosen places in your code. You can later watch it on KitLocate's dashboard
 * \param eventName Name of the event. Must containts charecters
 * \param Param String param with additional information. can be @"". for multi-parameter message use the overloaded function
 */
+ (void)logEvent:(NSString*)eventName withParam:(NSString*)Param;

/*! Allows you add events at chosen places in your code. You can later watch it on KitLocate's dashboard
 * \param eventName Name of the event. Must containts charecters
 * \param arrParams Array of string params
 */
+ (void)logEvent:(NSString*)eventName withParams:(NSArray *)arrParams;

/*! Allows you add events at chosen places in your code. You can later watch it on KitLocate's dashboard
 * \param eventName Name of the event. Must containts charecters
 * \param Param String param with additional information. can be @"". for multi-parameter message use the overloaded function
 * \param shouldSendNow Set true if you want to send this event immediately to the server. default is 'false'. WARNING: calling logEvent many times with this param as 'true' may affect battery performance. It's recommended to set this parameter to 'true' only when it's crucial.
 */
+ (void)logEvent:(NSString*)eventName withParam:(NSString*)Param sendNow:(bool)shouldSendNow;

/*! Allows you add events at chosen places in your code. You can later watch it on KitLocate's dashboard
 * \param eventName Name of the event. Must containts charecters
 * \param arrParams Array of string params
 * \param shouldSendNow Set true if you want to send this event immediately to the server. default is 'false'. WARNING: calling logEvent many times with this param as 'true' may affect battery performance. It's recommended to set this parameter to 'true' only when it's crucial.
 */
+ (void)logEvent:(NSString*)eventName withParams:(NSArray *)arrParams sendNow:(bool)shouldSendNow;





/*! Generates a list of places visited by the device's user: A place is a location that the device stayed around and not just passed by.
 * \param startTime the earliest date/time for places
 * \param endTime the latest date/time for places
 * \param dicParams more parameters for advanced usage
 */
+ (NSArray*)getPlacesHistorySince:(NSDate*)startTime Until:(NSDate*)endTime AdditionalParams:(NSDictionary*)dicParams;

@end
