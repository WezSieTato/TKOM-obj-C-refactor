#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#define IMPLEMENTATION_FILE "// \n\
//  DeviceForMapA.m \n\
//  Automonitoring \n\
// \n\
//  Created by Marcin Stepnowski on 15.03.2014. \n\
//  Copyright (c) 2014 siema. All rights reserved. \n\
// \n\
 \n\
#import \"DeviceForMapA.h\" \n\
#import \"LowTypeSerialization.h\" \n\
 \n\
@implementation DeviceForMapA \n\
@synthesize icon, color; \n\
 \n\
-(id)initWithDictionary:(NSDictionary *)dictionary{ \n\
    self = [super init]; \n\
    if (self) { \n\
        icon = (NSString*)[dictionary valueForKey:@\"Icon\"]; \n\
 \n\
        color = [LowTypeSerialization colorFromInt:[[dictionary valueForKey:@\"Color\"] intValue]]; \n\
    } \n\
    return self; \n\
} \n\
 \n\
@end"

#endif // IMPLEMENTATION_H
