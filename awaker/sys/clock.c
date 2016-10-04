#include "clock.h"
#include <string.h>
#include <stdio.h>
#include "hd44780.h"

RTC_TimeTypeDef clock_time;
Clock_AlarmReg clock_alarm;

void clock_init(void)
{
    clock_alarm_read();
    //printf("%lu $ %lu\n", sizeof(Clock_AlarmReg), sizeof(uint32_t));
}

uint32_t _clock_cnt = 0;
void clock_update(void)
{
    _clock_cnt++;
    if(_clock_cnt == 500)
    {
	_clock_cnt = 0;
	clock_get_time();
	if(clock_alarm.enabled)
	{
	    if(clock_alarm.hour == clock_time.Hours)
	    {
		if(clock_alarm.minute <= clock_time.Minutes)
		{
		    speaker_start();
		    hd44780_brightness(1);
		}
	    }
	    else if (clock_alarm.hour <= clock_time.Hours)
	    {
		speaker_start();
		hd44780_brightness(1);
	    }
	}
    }
}

void clock_button(uint8_t b)
{
    if(b == BITopBig)
    {
	speaker_stop();
	clock_alarm_set(0, clock_alarm.hour, clock_alarm.minute);
    }
    if(b == BITopSmall)
    {
	speaker_stop();
	if(clock_time.Minutes >= 54)
	    clock_alarm_set(1, clock_time.Hours + 1, 3); //TODO: !!!
	else
	    clock_alarm_set(1, clock_time.Hours, clock_time.Minutes + 5); //TODO: !!!
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
