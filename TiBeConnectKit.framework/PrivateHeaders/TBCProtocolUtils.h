//
//  TBCProtocolUtils.h
//  tibedemo
//
//  Created by frederic Visticot on 29/12/2016.
//  Copyright © 2016 ticatag. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef uint16_t TBCBeaconMinorValue;
typedef uint16_t TBCBeaconMajorValue;

@class TBCBeacon;
@interface TBCProtocolUtils : NSObject
+(NSData*)reverseBytes: (NSData*)data;
+(TBCBeacon*)beaconFromData:(NSData*)data;

@end
