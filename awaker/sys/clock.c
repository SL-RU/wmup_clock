#include "clock.h"
#include <string.h>
#include <stdio.h>

RTC_TimeTypeDef clock_time;
Clock_AlarmReg clock_alarm;

void clock_init(void)
{
    clock_alarm_read();
    //printf("%lu $ %lu\n", sizeof(Clock_AlarmReg), sizeof(uint32_t));
}

void clock_update(void)
{
    if((HAL_GetTick()/500)%2 == 0)
    {
	clock_get_time();
	if(clock_alarm.enabled)
	{
	    if(clock_alarm.hour == clock_time.Hours)
	    {
		
	    }
	}
    }
}

RTC_TimeTypeDef * clock_get_time()
{
    HAL_RTC_GetTime(&hrtc, &clock_time, RTC_FORMAT_BIN);
    return &clock_time;
}

RTC_TimeTypeDef * clock_set_time(uint8_t h, uint8_t m, uint8_t s)
{
    clock_time.Hours = h;
    clock_time.Minutes = m;
    clock_time.Seconds = s;
    HAL_RTC_SetTime(&hrtc, &clock_time, RTC_FORMAT_BIN);
    return &clock_time;
}

uint32_t clock_reg_read(uint32_t reg)
{
    return HAL_RTCEx_BKUPRead(&hrtc, reg);
}
void clock_reg_write(uint32_t reg, uint32_t data)
{
    HAL_RTCEx_BKUPWrite(&hrtc, reg, data);
}

void clock_alarm_read(void)
{
    uint32_t a = clock_reg_read(CLOCK_ALARM_REG);
    memcpy(&clock_alarm, &a, sizeof(Clock_AlarmReg));
}

Clock_AlarmReg * clock_alarm_get()
{
    return &clock_alarm;
}

void clock_alarm_set(uint8_t en, uint8_t hour, uint8_t minute)
{
    clock_alarm.enabled = en;
    clock_alarm.hour = hour;
    clock_alarm.minute = minute;
    
    uint32_t a;
    memcpy(&a, &clock_alarm, sizeof(Clock_AlarmReg));
    clock_reg_write(CLOCK_ALARM_REG, a);
}
