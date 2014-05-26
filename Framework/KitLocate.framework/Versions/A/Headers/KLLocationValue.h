//
//  LocationValue.h
//  WeBuy
//
//  Created by Yoav Cafri on 2/23/12.
//  Copyright (c) 2012 yoav@webuy.co.il. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface KLLocationValue : NSObject
{
    float       fLatitude;
    float       fLongitude;
    float       fAccuracy;
    float       fSpeed;
    NSTimeInterval    secondsSince1970;
    bool        bIsOnBackground;

}

@property(readwrite) float       fLatitude;
@property(readwrite) float       fLongitude;
@property(readwrite) float       fAccuracy;
@property(readwrite) float       fSpeed;
@property(readwrite) bool        bIsOnBackground;
@property(readwrite) NSTimeInterval    secondsSince1970; // If this property equal 0 it means it is not initialized
@property(readwrite,strong,getter = dtCurrentDate, setter = setDtCurrentDate:)     NSDate*     dtCurrentDate;

// Initializers
// ============
- (id)initWithLocationValue:(KLLocationValue *)location;
+ (id)locationValueWithLocationValue:(KLLocationValue *)location;
- (id)initWithLocation:(CLLocation *)location;
+ (id)locationValueWithLocation:(CLLocation *)location;

// More Logics
// ===========
- (BOOL)isWIFI;

@end
