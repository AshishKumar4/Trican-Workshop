#pragma once 

#include "common.h"

uint32_t tick = 0;
uint32_t rtc_timer = 0;

 /**REAL TIMER RTC, might not work**/
 void init_timer_RTC();
 /**PIT TIMER, working**/
void init_timer_PIT(uint32_t frequency);