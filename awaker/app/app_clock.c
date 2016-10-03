#include "app_clock.h"
#include "speaker.h"

App_Struct _app_clock = {
    APP_CLOCK_ID,
    &app_clock_open,
    &app_clock_update,
    &app_clock_draw,
    &app_clock_encoder,
    &app_clock_buttons,
    &app_clock_can_close,
    &app_clock_close
};

App_Struct * app_clock() { return &_app_clock; }

void app_clock_open()
{
    
}

void app_clock_update()
{
}
void app_clock_draw()
{
    RTC_TimeTypeDef * tm = clock_get_time();
    Clock_AlarmReg * ar = clock_alarm_get();
    hd44780_position(0, 0);
    hd44780_printf("time: %02d:%02d:%02d",  tm->Hours, tm->Minutes, tm->Seconds);

    hd44780_position(1, 0);
    hd44780_printf("alarm:%d %02d:%02d", ar->enabled, ar->hour, ar->minute);
}
void app_clock_encoder(int16_t val, int16_t del)
{
}
void app_clock_buttons(uint8_t b, uint8_t e)
{
    if(b == BITopBig && e == CONTROLS_LONG_PRESSING)
    {
	speaker_start();
    }
    else
	speaker_stop();

    if(b == BITopSmall && e == CONTROLS_CLICK)
    {
	clock_alarm_set(0, 11, 47);
    }
    
    if(b == BITopSmall && e == CONTROLS_LONG_CLICK)
    {
	clock_alarm_set(1, 20, 13);
    }
}

uint8_t app_clock_can_close() { return 1; }
uint8_t app_clock_close() { return 1; }
