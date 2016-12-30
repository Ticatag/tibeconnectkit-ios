//
//  BLELocationManager.h
//  tirun
//
//  Created by frederic Visticot on 19/10/2016.
//  Copyright © 2016 ticatag. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>


typedef NS_ENUM(NSInteger, TBCBeaconButtonAction) {
    TBCBeaconButtonActionSimpleClick,
    TBCBeaconButtonActionDoubleClick,
    TBCBeaconButtonActionLongPressed,
    TBCBeaconButtonActionUnknown
};

#define TBCBeaconDidDisconnectNotification                  @"TBCBeaconDidDisconnectNotification"
#define TBCBeaconDidConnectNotification                     @"TBCBeaconDidConnectNotification"
#define TBCBeaconDidTemperatureChangeNotification           @"TBCBeaconDidTemperatureChangeNotification"
#define TBCBeaconDidAccelerometerAxisXChangeNotification    @"TBCBeaconDidAccelerometerAxisXChangeNotification"
#define TBCBeaconDidAccelerometerAxisYChangeNotification    @"TBCBeaconDidAccelerometerAxisYChangeNotification"
#define TBCBeaconDidAccelerometerAxisZChangeNotification    @"TBCBeaconDidAccelerometerAxisZChangeNotification"
#define TBCBeaconButtonModeNotification                     @"TBCBeaconButtonModeNotification"
#define TBCBeaconFirmwareVersionNotification                @"TBCBeaconFirmwareVersionNotification"
#define TBCBeaconDidRSSIChangeNotification                  @"TBCBeaconDidRSSIChangeNotification"

@class TBCBeacon;
@class TBCManager;
@protocol TBCManagerDelegate <NSObject>
@optional
//return every second the list of beacon in range
- (void)tiBeConnectManager:(TBCManager *)manager didRangeBeacon:(NSArray<TBCBeacon*>*)beacons;
//bluetooth state changed
- (void)tiBeConnectManager:(TBCManager *)manager didBluetoothStateChanged: (CBManagerState)state;
- (void)tiBeConnectManager:(TBCManager *)manager didBatteryValueChanged: (NSInteger)value forBeacon: (TBCBeacon*)beacon;
- (void)tiBeConnectManager:(TBCManager *)manager didTemperatureValueChanged: (NSInteger)value forBeacon: (TBCBeacon*)beacon;
- (void)tiBeConnectManager:(TBCManager *)manager didButtonActionChanged: (TBCBeaconButtonAction)action forBeacon: (TBCBeacon*)beacon;
- (void)tiBeConnectManager:(TBCManager *)manager didBeaconConnected: (TBCBeacon*)beacon;
- (void)tiBeConnectManager:(TBCManager *)manager didBeaconDisconnected: (TBCBeacon*)beacon withError: (NSError*)error;
@end;




typedef void(^TBCManagerCompletionBlock)(TBCManager *manager,TBCBeacon *beacon, NSError *error);


@interface TBCManager : NSObject
+ (id)shared;
-(void)startMonitoring;
-(void)stopMonitoring;
-(BOOL)isMonitoring;

-(void)connectBeacon: (TBCBeacon*)beacon;
-(void)connectBeacon: (TBCBeacon*)beacon withCompletion: (TBCManagerCompletionBlock)completion;

-(void)disconnectBeacon: (TBCBeacon*)beacon;
-(void)disconnectBeacon: (TBCBeacon*)beacon withCompletion: (TBCManagerCompletionBlock)completion;




-(void)pingBeacon: (TBCBeacon*)beacon;

-(void)setAccelerometerNotifications: (BOOL)enabled forBeacon: (TBCBeacon*)beacon;
-(void)setBatteryNotifications: (BOOL)enabled forBeacon: (TBCBeacon*)beacon;
-(void)setTemperatureNotifications: (BOOL)enabled forBeacon: (TBCBeacon*)beacon;
-(void)setButtonActionsNotifications: (BOOL)enabled forBeacon: (TBCBeacon*)beacon;
-(void)setButtonMode: (BOOL)enabled forBeacon: (TBCBeacon*)beacon;
-(void)buttonModeForBeacon: (TBCBeacon*)beacon withCompletion: (TBCManagerCompletionBlock)completion;
-(void)temperatureForBeacon: (TBCBeacon*)beacon withCompletion: (TBCManagerCompletionBlock)completion;
-(void)firmwareVersionForBeacon:(TBCBeacon*)beacon withCompletion: (TBCManagerCompletionBlock)completion;
-(void)RSSIForBeacon:(TBCBeacon*)beacon withCompletion: (TBCManagerCompletionBlock)completion;
-(void)startRSSIMonitoringForBeacon: (TBCBeacon*)beacon interval: (NSTimeInterval)interval withCompletion: (TBCManagerCompletionBlock)completion;
-(void)stopRSSIMonitoringForBeacon: (TBCBeacon*)beacon;
@property(nonatomic, weak) id<TBCManagerDelegate> delegate;
@end
