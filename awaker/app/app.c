#include "app.h"

App_Struct * app_current;

Controls_EncoderState Apps_encoder60,
    Apps_encoder24;


void apps_init(void)
{
    controls_init_encoder_state(&Apps_encoder60, 0, 60, 0, 1);
    controls_init_encoder_state(&Apps_encoder24, 0, 24, 0, 1);
}

App_Struct* app_get_current()
{
    return app_current;
}

void apps_update()
{
    if(app_current != 0)
	app_current->update();
}

void apps_draw()
{
    if(app_current != 0)
	app_current->draw();
}

void app_set(App_Struct * app)
{
    if(app_current != 0)
    {
	if(!app_current->close())
	    return;
	app_current = 0;
    }
    app_current = app;
    hd44780_clear();
    app->open();
}

void app_switch(uint8_t appid)
{
    App_Struct * s = 0;
    switch (appid) {
    case APP_CLOCK_ID: s = app_clock();	break;
    case APP_SET_TIME_ID: s = app_set_time(); break;
    }
    printf("%d\n", appid);
    if(s != 0)
	app_set(s);
}


void apps_preset_encoder(int16_t val, uint8_t preset)
{
    Controls_EncoderState *st = 0;
   
    if(preset == APPS_ENCODER_TIME24)
	st = &Apps_encoder24;
    else if(preset == APPS_ENCODER_TIME60)
	st = &Apps_encoder60;
    if(st != 0)
	st->val = val;
    controls_set_encoder_handler(st, &apps_input_encoder);
}

void apps_input_buttons(uint8_t button, uint8_t event)
{
    if((button == BITopBig || button == BITopSmall) && event & CONTROLS_CLICK_ALL)
    {
	clock_button(button);
	return;
    }
    if((button == BIFrontRed || button == BIFrontGreen) && event == CONTROLS_LONG_CLICK)
    {
	if(app_current != 0)
	{
	    if(button == BIFrontGreen)
	    {
		if(app_current->id > 0)
		{
		    app_switch(app_current->id - 1);
		}
		else
		{
		    app_switch(APP_COUNT - 1);
		}
	    }
	    if(button == BIFrontRed)
	    {
		if(app_current->id < APP_COUNT - 1)
		{
		    app_switch(app_current->id + 1);
		}
		else
		{
		    app_switch(0);
		}
	    }
	}
	else
	{
	    app_switch(0);
	}
	return;
    }
    if(app_current != 0)
	app_current->buttons(button, event);
}

void apps_input_encoder(int16_t value, int16_t delta)
{
    if(app_current != 0)
	app_current->encoder(value, delta);
}


