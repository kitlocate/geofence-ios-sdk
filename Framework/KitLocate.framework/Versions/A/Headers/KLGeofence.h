//
//  KLGeofence.h
//  KitLocate
//
//  Created by Ron Miller on 10/22/12.
//
//

#import <Foundation/Foundation.h>

#define KL_GEOFENCES_FEATURE_OFF      -1
#define KL_GEOFENCES_UNDEFINED        @""

//==
typedef enum klGeofenceReceive : NSInteger klGeofenceReceive;
enum klGeofenceReceive : NSInteger {
    KL_GEOFENCE_RECEIVE_NONE = 0,
    KL_GEOFENCE_RECEIVE_SERVER = 1,
    KL_GEOFENCE_RECEIVE_USER = 2,
    KL_GEOFENCE_RECEIVE_INTERNAL = 3
};
//==

typedef enum klGeofenceType : NSInteger klGeofenceType;
enum klGeofenceType : NSInteger {
    KL_GEOFENCE_TYPE_NONE = 0,
    KL_GEOFENCE_TYPE_IN = 1,
    KL_GEOFENCE_TYPE_OUT = 2,
};

@interface KLGeofence : NSObject
{
    int             nTrigger;

    //==
    klGeofenceReceive    receivePOI;
    int             ownerFeature; // The type is actually klLocationFeatureType but it can't be written explicitly here
    
    bool            bDirty;
    bool            bDirtyIDServer;
    bool            bDirtyIDUser;
    bool            bDirtyGroup;
    bool            bDirtyLatitude;
    bool            bDirtyLongitude;
    bool            bDirtyPushRadiusInMeters;
    bool            bDirtyNearRadiusInMeters;
    bool            bDirtyTypeGeofence;
    bool            bDirtyVerificationInCounter;
    bool            bDirtyVerificationInTimeInSeconds;
    bool            bDirtyVerificationOutCounter;
    bool            bDirtyVerificationOutTimeInSeconds;
    bool            bDirtyCounterIn;
    bool            bDirtyCounterOut;
    bool            bDirtyCounterIntermediate;
    bool            bDirtyDisposal;
    bool            bDirtyDateForSelfDisposal;
    bool            bDirtyTrigger;
    bool            bDirtyReceiveGeofence;
    bool            bDirtyOwnerFeature;
    
    
    long            lIDPrimary;
    NSString *      strIDServer;
    NSString *      strIDUser;
    
    NSString *      strGroup;
    NSString *      strAdditionalInfo;
    
    float           fLatitude;
    float           fLongitude;
    
    float           fPushRadiusInMeters;
    float           fNearRadiusInMeters;
    
    klGeofenceType       TypeGeofence;
    
    int             nVerificationInCounter;
    int             nVerificationInTimeInSeconds;
    
    int             nVerificationOutCounter;
    int             nVerificationOutTimeInSeconds;
    
    int             nCounterIn;
    int             nCounterOut;
    int             nCounterIntermediate;
    
    int             nDisposal;
    long            lDateForSelfDisposal;

}

@property (nonatomic, readwrite) bool            bDirty;
@property (nonatomic, readwrite) bool            bDirtyIDServer;
@property (nonatomic, readwrite) bool            bDirtyIDUser;
@property (nonatomic, readwrite) bool            bDirtyGroup;
@property (nonatomic, readwrite) bool            bDirtyLatitude;
@property (nonatomic, readwrite) bool            bDirtyLongitude;
@property (nonatomic, readwrite) bool            bDirtyPushRadiusInMeters;
@property (nonatomic, readwrite) bool            bDirtyNearRadiusInMeters;
@property (nonatomic, readwrite) bool            bDirtyTypeGeofence;
@property (nonatomic, readwrite) bool            bDirtyVerificationInCounter;
@property (nonatomic, readwrite) bool            bDirtyVerificationInTimeInSeconds;
@property (nonatomic, readwrite) bool            bDirtyVerificationOutCounter;
@property (nonatomic, readwrite) bool            bDirtyVerificationOutTimeInSeconds;
@property (nonatomic, readwrite) bool            bDirtyCounterIn;
@property (nonatomic, readwrite) bool            bDirtyCounterOut;
@property (nonatomic, readwrite) bool            bDirtyCounterIntermediate;
@property (nonatomic, readwrite) bool            bDirtyDisposal;
@property (nonatomic, readwrite) bool            bDirtyDateForSelfDisposal;
@property (nonatomic, readwrite) bool            bDirtyTrigger;
@property (nonatomic, readwrite) bool            bDirtyReceiveGeofence;
@property (nonatomic, readwrite) bool            bDirtyOwnerFeature;


// Init function to create new POI
-(KLGeofence *)initWithLatitude:(float)latitude Longitude:(float)longitude PushRadius:(float)pushRadius;
-(KLGeofence *)initWithLatitude:(float)latitude Longitude:(float)longitude PushRadius:(float)pushRadius Type:(klGeofenceType)type;
+(KLGeofence *)createNewGeofenceWithLatitude:(float)latitude Longitude:(float)longitude PushRadius:(float)pushRadius;
+(KLGeofence *)createNewGeofenceWithLatitude:(float)latitude Longitude:(float)longitude PushRadius:(float)pushRadius Type:(klGeofenceType)type;

-(bool)isActive;

-(void)setTrigger:(int)nValue;
-(int)getTrigger;

-(void)setDisposal:(int)nValue;
-(int)getDisposal;

-(void)setDateForSelfDisposal:(long)lDate;
-(long)getDateForSelfDisposal;

-(void)setVerificationInCounter:(int)nValue;
-(int)getVerificationInCounter;

-(void)setVerificationInTimeInSeconds:(int)nValue;
-(int)getVerificationInTimeInSeconds;

-(void)setVerificationOutCounter:(int)nValue;
-(int)getVerificationOutCounter;

-(void)setVerificationOutTimeInSeconds:(int)nValue;
-(int)getVerificationOutTimeInSeconds;

-(void)setNearRadiusInMeters:(float)fValue;
-(float)getNearRadiusInMeters;

-(void)setPushRadiusInMeters:(float)fValue;
-(float)getPushRadiusInMeters;

// setter in KLGeofence_protected
-(long)getIDPrimary;

// setter in KLGeofence_protected
-(NSString *)getIDServer;

// setter in KLGeofence_protected
-(klGeofenceType)getTypeGeofence;

-(void)setIDUser:(NSString *)strID;
-(NSString *)getIDUser;

-(void)setGroup:(NSString *)strName;
-(NSString *)getGroup;

-(void)setLatitude:(float)fValue;
-(float)getLatitude;

-(void)setLongitude:(float)fValue;
-(float)getLongitude;


@end
