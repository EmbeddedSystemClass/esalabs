/*
 * led_switch.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: Revthy
 */

#include <labs/lab2_led_switch.hpp>
#include "printf_lib.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "../L2_Drivers/eint.h"
#include "../L4_IO/gpio.hpp"

#if LAB2_LEDSWTICH

/*Global variables*/
volatile uint8_t switch_pressed=0;
GPIO pin20(P2_0);
SemaphoreHandle_t xsemaphore_switch_press = NULL;

extern "C"
{

/* Function definition*/
void switch_press_callback(void)
{
    //u0_dbg_printf("switch_press_callback \n");
    if(xsemaphore_switch_press)
    {
        if( pdTRUE == xSemaphoreGiveFromISR(xsemaphore_switch_press,NULL))
        {
          //u0_dbg_printf("semaphore given \n");
        }
    }
    switch_pressed = 1;
}

bool init_switch_board(void)
{
    /* Initialize port 2 pins 0 and 2
     * pin 2 : Detects external interrupt from switch and sets switch_pressed variable
     * pin 0 : sets pin 2.0 of LED board to high to turn on the LED
     */
     //u0_dbg_printf("initialize switch board\n");
     eint3_enable_port2(2, eint_rising_edge,switch_press_callback);

     /*GPIO pin initialization*/
     pin20.setAsOutput();
     pin20.setLow();

     /*create binary semaphore*/
     return (xsemaphore_switch_press = xSemaphoreCreateBinary());
}

void process_switch_input(void)
{
   static uint8_t cyclecnt=0;
   ++cyclecnt;

   if(switch_pressed && (cyclecnt%5==0))
   {
       //u0_dbg_printf("called from period_10Hz\n");
       pin20.setLow();
       switch_pressed =0;
       cyclecnt=0;
   }

   if(xSemaphoreTake(xsemaphore_switch_press, 0) == pdTRUE )
   {
       //u0_dbg_printf("xsemaphore_switch_press taken\n");
       pin20.toggle();
   }
}


}
#endif


