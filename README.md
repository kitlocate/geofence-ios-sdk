geofence-ios-sdk
================

iOS geofence monitoring in three lines of code.


In order to start monitoring for geofences please call:

    '''' 
    [KLLocation registerGeofencing];
    ''''
    
In order to add a geofence please use this code:

    ''''
    KLGeofence *myGeofence = [KLGeofence createNewGeofenceWithLatitude:latitude Longitude:longitude PushRadius:pushRadius];
    ''''
    
After that just add the callback method at your delegate class:


    ''''
    - (void)geofencesIn:(NSArray*)arrGeofenceList
    {
    }
    ''''
    
    
    
    
