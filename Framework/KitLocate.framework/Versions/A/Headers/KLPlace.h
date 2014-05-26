//
//  KLPlace.h
//  KitLocate
//
//  Created by Hadar Dubin on 11/7/13.
//
//

#import <Foundation/Foundation.h>

@interface KLPlace : NSObject

@property(readwrite) float       fLatitude;
@property(readwrite) float       fLongitude;
@property(readwrite) NSDate*     visitedTimeStart;
@property(readwrite) NSDate*     visitedTimeEnd;


@end
