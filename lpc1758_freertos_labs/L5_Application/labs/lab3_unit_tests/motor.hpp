/*
 * motor.hpp
 *
 *  Created on: Sep 24, 2017
 *      Author: Revthy
 */

#ifndef MOTOR_HPP_
#define MOTOR_HPP_

extern "C"{
extern int readSensorValue(void);
int getMotorPWM(void);
}



#endif /* MOTOR_HPP_ */
