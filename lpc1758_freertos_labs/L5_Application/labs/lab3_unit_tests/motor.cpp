/*
 * motor.c
 *
 *  Created on: Sep 24, 2017
 *      Author: Revthy
 */

#include "motor.hpp"

extern "C"{
int getMotorPWM(void)
{
    int sensorValue = readSensorValue();
    int ret =0;
    if((sensorValue >100) || (sensorValue < 0))
    {
        ret = -1;

    }
    else if(((sensorValue >= 0) && (sensorValue <= 50)))
    {
        ret = 8;

    }
    else if(((sensorValue > 50) && (sensorValue <= 100)))
    {
       ret = 9;

    }

    return ret;

}

}
