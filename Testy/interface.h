#ifndef INTERFACE_H
#define INTERFACE_H

#define INTERFACE_FILE "// \n\
//  DeviceForMapA.h \n\
//  Automonitoring \n\
// \n\
//  Created by Marcin Stepnowski on 15.03.2014. \n\
//  Copyright (c) 2014 siema. All rights reserved. \n\
// \n\
 \n\
#import <Foundation/Foundation.h> \n\
#import \"DictionaryEntity.h\" \n\
\n\
@interface DeviceForMapA : NSObject <DictionaryEntity> \n\
\n\
@property (nonatomic, readonly) UIColor* color;\n\
@property (nonatomic, readonly) NSString* icon;\n\
\n\
\n\
@end"

#endif // INTERFACE_H
