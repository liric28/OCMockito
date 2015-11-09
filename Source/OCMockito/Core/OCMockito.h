//  OCMockito by Jon Reid, http://qualitycoding.org/about/
//  Copyright 2015 Jonathan M. Reid. See LICENSE.txt

#import <Foundation/Foundation.h>

#import "MKTClassObjectMock.h"
#import "MKTObjectMock.h"
#import "MKTObjectAndProtocolMock.h"
#import "MKTOngoingStubbing.h"
#import "MKTProtocolMock.h"
#import "NSInvocation+OCMockito.h"


static inline id MKTMock(Class classToMock)
{
    return [MKTObjectMock mockForClass:classToMock];
}

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates mock object of given class.
 * @param classToMock The class for which to mock instance methods.
 * @discussion The mock object will handle all instance methods of <code>classToMock</code>. Methods
 * return 0 by default.<br />
 * Use <code>given</code> to stub different return values or behaviors.<br />
 * Use <code>givenVoid</code> to stub behaviors of void methods.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTMock instead.
 */
static inline id mock(Class classToMock)
{
    return MKTMock(classToMock);
}
#endif


static inline id MKTMockClass(Class classToMock)
{
    return [MKTClassObjectMock mockForClass:classToMock];
}

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates mock class object of given class.
 * @param classToMock The class for which to mock class methods.
 * @discussion The mock object will handle all class methods of <code>classToMock</code>. Methods
 * return 0 by default.<br />
 * Use <code>given</code> to stub different return values or behaviors.<br />
 * Use <code>givenVoid</code> to stub behaviors of void methods.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTMockClass instead.
 */
static inline id mockClass(Class classToMock)
{
    return MKTMockClass(classToMock);
}
#endif


static inline id MKTMockProtocol(Protocol *protocolToMock)
{
    return [MKTProtocolMock mockForProtocol:protocolToMock];
}

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates mock object of given protocol.
 * @param protocolToMock The protocol to mock.
 * @discussion The mock object will handle all methods of <code>protocolToMock</code>. Methods
 * return 0 by default.<br />
 * Use <code>given</code> to stub different return values or behaviors.<br />
 * Use <code>givenVoid</code> to stub behaviors of void methods.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTMockProtocol instead.
 */
static inline id mockProtocol(Protocol *protocolToMock)
{
    return MKTMockProtocol(protocolToMock);
}
#endif


static inline id MKTMockProtocolWithoutOptionals(Protocol *protocolToMock)
{
    return [MKTProtocolMock mockForProtocol:protocolToMock includeOptionalMethods:NO];
}

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates mock object of given protocol, but without optional methods.
 * @param protocolToMock The protocol to mock.
 * @discussion The mock object will handle only required methods of <code>protocolToMock</code>. It
 * will <b>not</b> respond to the protocol's optional methods. Methods return 0 by default.<br />
 * Use <code>given</code> to stub different return values or behaviors.<br />
 * Use <code>givenVoid</code> to stub behaviors of void methods.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTMockProtocolWithoutOptionals instead.
*/
static inline id mockProtocolWithoutOptionals(Protocol *protocolToMock)
{
    return MKTMockProtocolWithoutOptionals(protocolToMock);
}
#endif


static inline id MKTMockObjectAndProtocol(Class classToMock, Protocol *protocolToMock)
{
    return [MKTObjectAndProtocolMock mockForClass:classToMock protocol:protocolToMock];
}

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates mock object of given class that also implements given protocol.
 * @param classToMock The class to mock.
 * @param protocolToMock The protocol to mock.
 * @discussion The mock object will handle all instance methods of <code>classToMock</code>, along
 * with all methods of <code>protocolToMock</code>. Methods return 0 by default.<br />
 * Use <code>given</code> to stub different return values or behaviors.<br />
 * Use <code>givenVoid</code> to stub behaviors of void methods.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTMockObjectAndProtocol instead.
 */
static inline id mockObjectAndProtocol(Class classToMock, Protocol *protocolToMock)
{
    return MKTMockObjectAndProtocol(classToMock, protocolToMock);
}
#endif


/*!
 * @abstract Enables method stubbing.
 * @discussion
 * Use "given" when you want the mock to return particular value when particular method
 * is called.
 *
 * Example:
 * <pre>[given([mockObject methodReturningString]) willReturn:\@"foo"];</pre>
 *
 * See MKTOngoingStubbing for other methods to stub different types of return values.
 *
 * See <code>givenVoid</code> for stubbing methods returning void.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTGiven instead.
 */
FOUNDATION_EXPORT MKTOngoingStubbing *MKTGivenWithLocation(id testCase, const char *fileName, int lineNumber, ...);
#define MKTGiven(methodCall) MKTGivenWithLocation(self, __FILE__, __LINE__, methodCall)

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Enables method stubbing.
 * @discussion Use "given" when you want the mock to return particular value when particular method
 * is called.
 *
 * Example:
 * <pre>[given([mockObject methodReturningString]) willReturn:\@"foo"];</pre>
 *
 * See MKTOngoingStubbing for other methods to stub different types of return values.
 *
 * See <code>givenVoid</code> for stubbing methods returning void.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTGiven instead.
 */
#define given(methodCall) MKTGiven(methodCall)
#endif


FOUNDATION_EXPORT MKTOngoingStubbing *MKTGivenVoidWithLocation(id testCase, const char *fileName, int lineNumber, void(^methodCallWrapper)());
#define MKTGivenVoid(methodCall) MKTGivenVoidWithLocation(self, __FILE__, __LINE__, ^{ methodCall; })

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Enables method stubbing of methods returning <code>void</code>.
 * @discussion Use "givenVoid" in combination with <code>willDo:</code> when you want the mock to
 * execute arbitrary code when a method is called.
 *
 * Example:
 * <pre>[givenVoid([mockObject methodReturningVoid]) willDo:^{ magic(); }];</pre>
 *
 * See <code>given</code> for stubbing non-void methods in order to return a particular value.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTGiven instead.
 */
#define givenVoid(methodCall) MKTGivenVoid(methodCall)
#endif


#define MKTStubProperty(instance, property, value)                          \
    do {                                                                    \
        [MKTGiven([instance property]) willReturn:value];                   \
        [MKTGiven([instance valueForKey:@#property]) willReturn:value];     \
        [MKTGiven([instance valueForKeyPath:@#property]) willReturn:value]; \
    } while(0)

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Stubs given property and its related KVO methods.
 * @discussion
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTStubProperty instead.
 */
#define stubProperty(instance, property, value) MKTStubProperty(instance, property, value)
#endif


FOUNDATION_EXPORT id MKTVerifyWithLocation(id mock, id testCase, const char *fileName, int lineNumber);
#define MKTVerify(mock) MKTVerifyWithLocation(mock, self, __FILE__, __LINE__)

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
#undef verify
/*!
 * @abstract Verifies certain behavior happened once.
 * @discussion verify checks that a method was invoked once, with arguments that match given
 * OCHamcrest matchers. If an argument is not a matcher, it is implicitly wrapped in an
 * <code>equalTo</code> matcher to check for equality.
 *
 * Examples:
 * <pre>[verify(mockObject) someMethod:startsWith(\@"foo")];</pre>
 * <pre>[verify(mockObject) someMethod:\@"bar"];</pre>
 *
 * <code>verify(mockObject)</code> is equivalent to <code>verifyCount(mockObject, times(1))</code>
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTVerify instead.
 */
#define verify(mock) MKTVerify(mock)
#endif


FOUNDATION_EXPORT id MKTVerifyCountWithLocation(id mock, id mode, id testCase, const char *fileName, int lineNumber);
#define MKTVerifyCount(mock, mode) MKTVerifyCountWithLocation(mock, mode, self, __FILE__, __LINE__)

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Verifies certain behavior happened a given number of times.
 * @discussion Examples:
 * <pre>[verifyCount(mockObject, times(5)) someMethod:\@"was called five times"];</pre>
 * <pre>[verifyCount(mockObject, never()) someMethod:\@"was never called"];</pre>
 * verifyCount checks that a method was invoked the given number of times, with arguments that
 * match given OCHamcrest matchers. If an argument is not a matcher, it is implicitly wrapped in an
 * <code>equalTo</code> matcher to check for equality.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTVerifyCount instead.
 */
#define verifyCount(mock, mode) MKTVerifyCount(mock, mode)
#endif


FOUNDATION_EXPORT id MKTTimes(NSUInteger wantedNumberOfInvocations);

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates <code>verifyCount</code> mode to verify the given exact number of
 * invocations.
 * @discussion Example:
 * <pre>[verifyCount(mockObject, times(2)) someMethod:\@"some arg"];</pre>
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTTimes instead.
 */
static inline id times(NSUInteger wantedNumberOfInvocations)
{
    return MKTTimes(wantedNumberOfInvocations);
}
#endif


FOUNDATION_EXPORT id MKTNever(void);

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates <code>verifyCount</code> mode to verify that an interaction did not happen.
 * @discussion Example:
 * <pre>[verifyCount(mockObject, never()) someMethod:\@"some arg"];</pre>
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTNever instead.
 */
static inline id never(void)
{
    return MKTNever();
}
#endif


FOUNDATION_EXPORT id MKTAtLeast(NSUInteger minNumberOfInvocations);

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates <code>verifyCount</code> mode to verify the specified minimum number of
 * invocations.
 * @discussion The verification will succeed if the specified invocation happened the number of
 * times specified or more.
 *
 * Example:
 * <pre>[verifyCount(mockObject, atLeast(2)) someMethod:\@"some arg"];</pre>
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTAtLeast instead.
 */
static inline id atLeast(NSUInteger minNumberOfInvocations)
{
    return MKTAtLeast(minNumberOfInvocations);
}
#endif


FOUNDATION_EXPORT id MKTAtLeastOnce(void);

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates <code>verifyCount</code> mode to verify that an interaction happened once or
 * more.
 * @discussion Example:
 * <pre>[verifyCount(mockObject, atLeastOnce()) someMethod:\@"some arg"];</pre>
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTAtLeastOnce instead.
 */
static inline id atLeastOnce(void)
{
    return MKTAtLeastOnce();
}
#endif


FOUNDATION_EXPORT id MKTAtMost(NSUInteger maxNumberOfInvocations);

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Creates <code>verifyCount</code> mode to verify the specified  maximum number of
 * invocations.
 * @discussion The verification will succeed if the specified invocation happened the number of
 * times specified or less.
 *
 * Example:
 * <pre>[verifyCount(mockObject, atMost(2)) someMethod:\@"some arg"];</pre>
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTAtLeast instead.
 */
static inline id atMost(NSUInteger maxNumberOfInvocations)
{
    return MKTAtMost(maxNumberOfInvocations);
}
#endif


FOUNDATION_EXPORT void MKTStopMockingWithLocation(id mock, id testCase, const char *fileName, int lineNumber);
#define MKTStopMocking(mock) MKTStopMockingWithLocation(mock, self, __FILE__, __LINE__)

#ifndef MOCKITO_DISABLE_SHORT_SYNTAX
/*!
 * @abstract Stops mocking and releases arguments.
 * @discussion Mock objects normally retain all message arguments. This is not a problem for most
 * tests, but can sometimes cause retain cycles. In such cases, call stopMocking to tell the mock
 * to release its arguments, and to stop accepting messages. See StopMockingTests.m for an example.
 *
 * <b>Name Clash</b><br />
 * In the event of a name clash, <code>#define MOCKITO_DISABLE_SHORT_SYNTAX</code> and use the synonym
 * MKTStopMocking instead.
 */
#define stopMocking(mock) MKTStopMocking(mock)
#endif
