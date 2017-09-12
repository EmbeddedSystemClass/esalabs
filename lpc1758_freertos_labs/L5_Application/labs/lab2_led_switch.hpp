/*
 * led_switch.hpp
 *
 *  Created on: Sep 11, 2017
 *      Author: Revthy
 */

#ifndef L5_APPLICATION_LABS_LAB2_LED_SWITCH_HPP_
#define L5_APPLICATION_LABS_LAB2_LED_SWITCH_HPP_

#include "labs.h"
#include <stdint.h>

extern volatile uint8_t switch_pressed;

extern "C"{
void switch_press_callback(void);
bool init_switch_board(void);
void process_switch_input(void);
}


#endif /* L5_APPLICATION_LABS_LAB2_LED_SWITCH_HPP_ */
