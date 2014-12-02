//  OCMockito by Jon Reid, http://qualitycoding.org/about/
//  Copyright 2014 Jonathan M. Reid. See LICENSE.txt

#import "MKTReturnValueSetter.h"


@interface MKTUnsignedCharReturnSetter : MKTReturnValueSetter

- (instancetype)initWithSuccessor:(MKTReturnValueSetter *)successor;

@end
