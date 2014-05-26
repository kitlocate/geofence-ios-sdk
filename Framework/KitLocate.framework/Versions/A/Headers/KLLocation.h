//
//  KLLocationServices.h
//  LocationServices
//
//  Created by Ron Miller on 10/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <KitLocate/KLLocationValue.h>
#import "KLGeofence.h"


//////////////////////////////
// Params Dictionary's keys //
//////////////////////////////

// Default interval of features

#define KL_START_PARAM_INT_GEOFENCE_DEFAULT_INTERVAL     @"PoiDefaultInterval"
#define KL_START_PARAM_INT_DRIVING_DEFAULT_INTERVAL @"DrivingDefaultInterval"
#define KL_START_PARAM_INT_PLACE_REC_DEFAULT_INTERVAL @"PlaceDefaultInterval"
#define KL_START_PARAM_INT_PARKING_DEFAULT_INTERVAL @"ParkingDefaultInterval"

// Single Location

#define KL_SP_DBL_DESIRED_ACCURACY         @"MaxAccuracy"
#define KL_SP_INT_MAX_SECONDS_WAIT         @"MaxSecondsWait"
//#define KL_START_PARAM_INT_MAX_PREVIOUS_TIME        @"MaxPreviousTime"
//unused #define KL_START_PARAM_BOOL_ALSO_RUN_ON_FOREGROUND  @"RunAlsoOnForeGround"

// New Parking

#define KL_SP_FLOAT_PARKING_LATITUDE                @"parkingLatitude"
#define KL_SP_FLOAT_PARKING_LONGITUDE               @"parkingLongitude"
#define KL_SP_INT_PARKING_RADIUS                    @"parkingRadius" //TODO: int or float?
#define KL_SP_INT_PARKING_TIMEOUT                   @"parkingTimeout" // at least 1
#define KL_SP_INT_PARKING_VERIFICATION_COUNT        @"parkingVerifyCount" // at least 1
#define KL_SP_INT_PARKING_VERIFICATION_TIME         @"parkingVerifyTime" // at least 1
#define KL_SP_FLOAT_PARKING_OUT_PERCENT             @"parkingOutPercent" // Between 0 to 1
#define KL_SP_BOOL_PARKING_AUTO_STOP                @"parkingAutoStop"

//unused #define KL_START_PARAM_BOOL_DETECT_DRIVING          @"DetectDriving"
//unused #define KL_PARKING_START                            @"ActualStart"
//unused #define KL_PARKING_STOP                             @"ActualStop"

// Place Recognition

#define KL_START_PARAM_INT_PLACE_RECOGNIZE_MIN_SECONDS       @"PlaceRecognizeMinTime"
#define KL_START_PARAM_INT_PLACE_RECOGNIZE_MIN_SAMPLES       @"PlaceRecognizeMinSamples"
#define KL_START_PARAM_INT_PLACE_RECOGNIZE_RADIUS            @"PlaceRecognizeRadius"
#define KL_START_PARAM_FLOAT_PLACE_RECOGNIZE_ACCURACY_FACTOR @"PlaceRecognizeAccuracyFactor"

///////////////////////////////////
// Exported Events Nofitications //
///////////////////////////////////

#define KL_NOTIFICATION_USER_INFO_LOCATION          @"KL_NOTIFICATION_USER_INFO_LOCATION"
#define KL_NOTIFICATION_USER_INFO_GEOFENCE_ARRAY    @"KL_NOTIFICATION_USER_INFO_GEOFENCE_ARRAY"

#define KL_NOTIFICATION_NAME_START_DRIVING          @"KL_NOTIFICATION_NAME_START_DRIVING"
#define KL_NOTIFICATION_NAME_STOP_DRIVING           @"KL_NOTIFICATION_NAME_STOP_DRIVING"
#define KL_NOTIFICATION_NAME_PLACE_RECOGNITION      @"KL_NOTIFICATION_NAME_PLACE_RECOGNITION"
#define KL_NOTIFICATION_NAME_PERIODIC_LOCATION      @"KL_NOTIFICATION_NAME_PERIODIC_LOCATION"
#define KL_NOTIFICATION_NAME_SINGLE_LOCATION        @"KL_NOTIFICATION_NAME_SINGLE_LOCATION"
#define KL_NOTIFICATION_NAME_GEOFENCE_IN            @"KL_NOTIFICATION_NAME_GEOFENCE_IN"
#define KL_NOTIFICATION_NAME_GEOFENCE_OUT           @"KL_NOTIFICATION_NAME_GEOFENCE_OUT"


typedef enum klResponseTime : NSInteger {
    KL_RESPONSE_TIME_SHORT = 0,
    KL_RESPONSE_TIME_MEDIUM,
    KL_RESPONSE_TIME_LONG,
    KL_RESPONSE_UNDEFINED
} klResponseTime;

typedef enum klDesiredAccuracyType : NSInteger {
    KL_DESIRED_ACCURACY_TYPE_HUNDRED_METERS = 0,
    KL_DESIRED_ACCURACY_TYPE_BEST = 1,
    KL_DESIRED_ACCURACY_TYPE_BEST_FOR_NAVIGATION = 2
} klDesiredAccuracyType;


@class KLDelegateManager;

@protocol KitLocateDelegate <NSObject>
@optional

- (void)didSuccessInitKitLocate:(int)status;
- (void)didFailInitKitLocate:(int)error;

- (void)onChangeKitLocateUserID:(NSString*)userId;

- (void)gotPeriodicLocation:(KLLocationValue*)location;
- (void)geofencesIn:(NSArray*)arrGeofenceList;
- (void)geofencesOut:(NSArray*)arrGeofenceList;
- (void)startDrivingDetected;
- (void)stopDrivingDetected;
- (void)recognizedNewPlace:(KLLocationValue*)location;
- (void)gotOutOfParking:(KLLocationValue*)location;

/*!
 This callback method will be invoked after addGeofence function is finished with a failure.
 If you call (addGeofence:) this method will be invoked in the delegate you've set in initKitLocateWithDelegate.
 If you call (addGeofence:withDelegate:) this method will be invoked in the given delegate.
 * \param The geofence that was failed to be added
 */
- (void)didFailAddGeofence:(KLGeofence*)geofence;
/*!
 This callback method will be invoked after addGeofence function is finished successfully.
 If you call (addGeofence:) this method will be invoked in the delegate you've set in initKitLocateWithDelegate.
 If you call (addGeofence:withDelegate:) this method will be invoked in the given delegate.
 * \param The geofence that was added
 */
- (void)didSuccessAddGeofence:(KLGeofence*)geofence;

@end


@protocol KitLocateSingleDelegate <NSObject>
@optional
- (void)gotSingleLocation:(KLLocationValue*)location;
@end


@protocol KitLocateForegroundDelegate <NSObject>
@optional
- (void)gotForegroundLocation:(KLLocationValue*)location;
@end

@interface KLLocation : NSObject
{
}


/*! Set the frequency of KitLocate's locations monitoring: more short is more accurate, but consume more battery
 * \param responseTimeType The desirable time of type klResponseTime (default KL_RESPONSE_TIME_MEDIUM)
 */
+ (void)setKitLocateAverageResponseTime:(klResponseTime)responseTimeType;

//+ (void)setForceStopAndRestartFunctionalityToOn:(bool)bOn;
//+ (void)setLocationAccuracyRequiredLevel:(klDesiredAccuracyType)AccuracyLevel; // TO DO: Check if it proper used
////+ (void)SetLocationUseAccuracyFactor:(float)fAccuracyFactor;

/*! Allows to synchronize geofences with KitLocate's server. Add geofences through the Dashboard and they will automatically synchronized.
 * \param bFlag true will allow the sync. false will disable it (in that case you should add the geofences using addGeofence function)
 */
+ (void)setSyncGeofencesWithServer:(bool)bFlag;



/*! Monitor device's locations periodically. To handle the locations at the moment they gathered, you have to implement the callback function gotBackgroundLocation in your <KitLocateDelegate> class. To control the frequency of the nofitications, use setPeriodicMinimumTimeInterval
 */
+ (void)registerPeriodicLocation;

/*! Stop monitoring device's locations. This function will cancel registerPeriodicLocation's action.
 */
+ (void)unregisterPeriodicLocation;

/*! Manually change the interval between location delegates. (It's recommended to do it from the Dashboard)
 * \param interval The minimum number of seconds between getting the periodic nofitications (default 300)
 */
+ (void)setPeriodicMinimumTimeInterval:(int)interval;


/*! Monitor geofences and get notified when device gets in/out (depend of each geofence's properties). Implement at least one of the callback functions: geofencesIn,geofencesOut. Make sure you add Geofences to KitLocate to make this feature relevant
 */
+ (void)registerGeofencing;

/*! Stop monitoring geofences. This function will cancel registerGeofencing's action.
 */
+ (void)unregisterGeofencing;


/*! Detect when device starts and stops driving, and get notified by the callback methods: startDrivingDetected,stopDrivingDetected (Implement at least one of them)
 */
+ (void)registerDrivingDetection;

/*! Stop monitoring for driving. This function will cancel registerDrivingDetection's action.
 */
+ (void)unregisterDrivingDetection;


+ (void)registerParking:(NSDictionary*)params;
+ (void)unregisterParking;
+ (bool)isParkingLogicRunning;

/*
 NOTICE! This feature can't work under Regions Provider in the current design!
 */
+ (void)startPlaceRecognitionWithParams:(NSDictionary*)dctParams;
+ (void)stopPlaceRecognition;


/*!
 Activate the immediate location mechanism. After 8 seconds (configurable), The callback function gotSingleLocation is called with the best location gathered by then.
 * \param delegate An object that implements <KitLocateSingleDelegate> protocol. You should implement gotSingleLocation in this object.
 * \param dctParams A dictionary that contains more parameters. For now supports KL_SP_INT_MAX_SECONDS_WAIT - The number of seconds KitLocate tries to optimize location. Can be nil.
 */
+ (void)startSingleLocationWithDelegate:(id<KitLocateSingleDelegate>)delegate andParams:(NSDictionary*)dctParams;
//+ (void)finishSingleLocation;


// POI Handling

/*! Delete all geofences you have added to KitLocate until now
 */
+ (void) deleteAllGeofences;

/*! Delete the geofence with the specified UserID
 * \param strGeofenceID the UserID of the geofence to delete. The UserID should be set before calling addGeofence.
 */
+ (void) deleteGeofenceWithUserID:(NSString*)strGeofenceID;

/*! Delete the geofence with the specified PrimaryID
 * \param nGeofenceID the ID of the geofence to delete. You got this ID as the return value of addGeofence.
 */
+ (void) deleteGeofenceWithPrimaryID:(long)lGeofenceID;

/*! Add a geofence to KitLocate's database.
 * \param geofenceToAdd The geofence object to add. you should init and set the geofence before calling addGeofence.
 */
+(void)addGeofence:(KLGeofence *)geofenceToAdd;
+(void)addGeofence:(KLGeofence *)geofenceToAdd withDelegate:(id<KitLocateDelegate>)delegate;

/*! Fetch requested geofence from KitLocate's database (This geofence must be added before with addGeofence).
 * \param strGeofenceID the UserID of the geofence to fetch. The UserID should be set before calling addGeofence.
 * \return The requested geofence. If can't found, returns nil.
 */
+ (KLGeofence*)returnGeofenceByUserID:(NSString*)strGeofenceID;

/*! Fetch requested geofence from KitLocate's database (This geofence must be added before with addGeofence).
 * \param nGeofenceID the ID of the geofence to fetch. You got this ID as the return value of addGeofence.
 * \return The requested geofence. If can't found, returns nil.
 */
+ (KLGeofence*)returnGeofenceByPrimaryID:(long)lGeofenceID;

+(void)startForegroundLocationWithDelegate:(id<KitLocateForegroundDelegate>)delegate;
+(void)setForegroundLocationTimeInSeconds:(int)nTime;
+(KLLocationValue *)getForegroundLocation;
+(void)stopForegroundLocation;


// For debug
// =========
//+(KLLocationValue*)getNewestLocation;
//+(KLLocationValue*)getSpecialLocation;
//+(BOOL)setSpecialLocation;
//+(KLGeofence*)returnPOIByServerId:(NSString*)strServerId;
//#warning comment this line
//+(NSArray *) returnAllPOIs;

// Not needed
//+ (int) addGeofenceWithLatitude: (float) fLatitude Longitue:(float) fLongitude POIRadius:(int) nPOIRadius POIType:(klGeofenceType)ptPOIType ;
//+ (int) addGeofenceWithLatitude: (float) fLatitude Longitue:(float) fLongitude POIRadius:(int) nPOIRadius POIType:(klGeofenceType)ptPOIType UniqueId:(NSString*)strUniqueId;
//+(bool) updateExistingPOI:(NSObject*)poiUpdated;

//+(NSString *)getKitLocateUniqueDeviceID;



@end
