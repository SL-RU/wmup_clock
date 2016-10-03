#include "rtc.h"

#define CLOCK_ALARM_REG 3

typedef struct {
    uint8_t enabled : 1;
    uint8_t hour : 5;
    uint8_t minute : 5;
    
}Clock_AlarmReg;

void clock_init(void);

void clock_update(void);

RTC_TimeTypeDef * clock_get_time();

RTC_TimeTypeDef * clock_set_time(uint8_t h, uint8_t m, uint8_t s);

uint32_t clock_reg_read(uint32_t reg);

void clock_reg_write(uint32_t reg, uint32_t data);

void clock_alarm_read(void);

Clock_AlarmReg * clock_alarm_get(void);

void clock_alarm_set(uint8_t en, uint8_t hour, uint8_t minute);
