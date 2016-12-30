//
//  TICBeacon.h
//  tibeacon
//
//  Created by Fred Visticot on 16/02/14.
//  Copyright (c) 2014 ticatag. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "TBCManager.h"

typedef struct
{
    NSInteger axisX;
    NSInteger axisY;
    NSInteger axisZ;
} Accelerometer;


@interface TBCBeacon : NSObject<NSCoding,NSCopying>

@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSString *firmwareVersion;
@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic) NSInteger rssi;
@property (nonatomic, strong) NSNumber *batteryLevel;
@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, strong) NSNumber *advertBatteryLevel;
@property (nonatomic, strong) NSNumber *advertAction;
@property (nonatomic, strong) NSNumber *scanRspVersion;
@property (nonatomic, strong) NSNumber *temperature;
@property (nonatomic) long timestamp;
@property (nonatomic) Accelerometer accelerometer;
@property (nonatomic, strong) TBCManagerCompletionBlock connectionCompletionBlock;
@property (nonatomic, strong) TBCManagerCompletionBlock disconnectionCompletionBlock;
//@property (nonatomic) TICBeaconStatus status;
@end
