#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>
#include "motor.hpp"

int readSensorValue(void)
{
   return mock();
}

Ensure(test_getmotorpwm)
{
    expect(readSensorValue, will_return(101));
    assert_that(getMotorPWM(),is_equal_to(-1));

    expect(readSensorValue, will_return(10));
    assert_that(getMotorPWM(),is_equal_to(8));

    expect(readSensorValue, will_return(60));
    assert_that(getMotorPWM(),is_equal_to(9));

    expect(readSensorValue, will_return(-100));
    assert_that(getMotorPWM(),is_equal_to(-1));

    expect(readSensorValue, will_return(0));
    assert_that(getMotorPWM(),is_equal_to(8));

    expect(readSensorValue, will_return('a'));
    assert_that(getMotorPWM(),is_equal_to(9));
}


TestSuite *motorsuite()
{
    TestSuite *suite = create_test_suite();
    add_test(suite,test_getmotorpwm);
    return suite;
}


