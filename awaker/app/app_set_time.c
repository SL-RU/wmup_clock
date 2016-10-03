#include "app_set_time.h"

App_Struct _app_set_time = {
    APP_SET_TIME_ID,
    &app_set_time_open,
    &app_set_time_update,
    &app_set_time_draw,
    &app_set_time_encoder,
    &app_set_time_buttons,
    &app_set_time_can_close,
    &app_set_time_close
};

App_Struct * app_set_time(){ return &_app_set_time; }

void app_set_time_init()
{
}

uint8_t stage,
    sec, min, hour;

void app_set_time_open()
{
    RTC_TimeTypeDef * tm = clock_get_time();
    stage = 0;
    sec = tm->Seconds;
    min = tm->Minutes;
    hour = tm->Hours;
}

void app_set_time_update()
{
    if(stage == 0)
    {
	RTC_TimeTypeDef * tm = clock_get_time();
	sec = tm->Seconds;
	min = tm->Minutes;
	hour = tm->Hours;
    }
}

void app_set_time_draw()
{
    hd44780_position(0, 0);
    hd44780_printf("Time settings");
    hd44780_position(1, 0);
    switch(stage)
    {
    case 0: hd44780_printf("%02d:%02d:%02d",  hour, min, sec); break;
    case 1: hd44780_printf(">%02d:%02d:%02d", hour, min, sec); break;
    case 2: hd44780_printf("%02d:>%02d:%02d", hour, min, sec); break;
    case 3: hd44780_printf("%02d:%02d:>%02d", hour, min, sec); break;
    case 4: hd44780_printf("ok %02d:%02d:%02d canc", hour, min, sec); break;
    }
}

void app_set_time_encoder(int16_t val , int16_t d)
{
    switch(stage)
    {
    case 1: hour = val; break;
    case 2: min = val; break;
    case 3: sec = val; break;
    }
}

void app_set_time_buttons(uint8_t b, uint8_t e)
{
    if(e == CONTROLS_CLICK)
    {
	if(stage < 4)
	{
	    stage += (b == BIFrontGreen && stage != 0) * (-1) + (b == BIFrontRed);
	    if(stage == 1)	
		apps_preset_encoder(hour, APPS_ENCODER_TIME24);
	    if(stage == 2)	
		apps_preset_encoder(min, APPS_ENCODER_TIME60);
	    if(stage == 3)	
		apps_preset_encoder(sec, APPS_ENCODER_TIME60);	
	}
	else if (stage == 4)
	{
	    if(b == BIFrontGreen)
	    {
		stage = 0;
		clock_set_time(hour, min, sec);
	    }
	    else
		stage = 0;
	}
	hd44780_clear();
    }
}

uint8_t app_set_time_can_close() { return 1; }

uint8_t app_set_time_close() { return 1; }
