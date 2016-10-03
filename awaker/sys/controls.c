#include "controls.h"

Controls_ButtonState controls_buttons[ButtonsCount];
Controls_EncoderState* controls_encoder;
Controls_EncoderState controls_encoder_default;

void (*Controls_ButtonsHandler)(uint8_t, uint8_t) = 0;
void (*Controls_EncoderHandler)(uint16_t, int16_t) = 0;


void controls_init(void)
{
    //buttons
    controls_buttons[BIFrontGreen] = (Controls_ButtonState) {BFrontGreen, 1, 0, 0};
    controls_buttons[BIFrontRed] = (Controls_ButtonState) {BFrontRed, 1, 0, 0};
    controls_buttons[BITopBig] = (Controls_ButtonState) {BTopBig, 0, 0, 0};
    controls_buttons[BITopSmall] = (Controls_ButtonState) {BTopSmall, 0, 0, 0};

    //encoder
    controls_encoder_default = (Controls_EncoderState){0};
    controls_init_encoder_state(&controls_encoder_default, 0, 60, 0, 1);
    controls_encoder = &controls_encoder_default;
    
}

void controls_init_encoder_state(Controls_EncoderState* st, 
				     int16_t val,
				     int16_t max,
				     int16_t min,
				     uint8_t acceleration_en)
{
    st->tim = TIM4;
    st->val = val;
    st->max = max;
    st->min = min;
    st->acceleration_en = acceleration_en;
}

void _controls_button_handle(uint8_t b, uint8_t e)
{
    if(Controls_ButtonsHandler != 0)
	Controls_ButtonsHandler(b, e);
}
void _controls_encoder_handle(uint16_t b, int16_t e)
{
    if(Controls_EncoderHandler != 0)
	Controls_EncoderHandler(b, e);
}

void controls_update(void)
{
    for(uint8_t i = 0; i < ButtonsCount; i++)
    {
	Controls_ButtonState* b = &(controls_buttons[i]);
	if(HAL_GPIO_ReadPin(controls_buttons[i].gpio, b->pin) == (b->polarity_pressed) ? GPIO_PIN_SET : GPIO_PIN_RESET)
	{
	    if(b->pressed == 0)
	    {
		b->pressed = 1;
		b->press_start_time = controls_millis();
	    }
	    else
	    {
		if(controls_millis() - b->press_start_time > CONTROLS_LongClickTime)
		{
		    _controls_button_handle(i, CONTROLS_LONG_PRESSING);
		}
		else if(controls_millis() - b->press_start_time > CONTROLS_ClickTime)
		{
		    _controls_button_handle(i, CONTROLS_PRESSING);
		}
	    }
	}
	else
	{
	    if(b->pressed == 1)
	    {
		if(controls_millis() - b->press_start_time > CONTROLS_LongClickTime)
		{
		    _controls_button_handle(i, CONTROLS_LONG_CLICK);
		}
		else if(controls_millis() - b->press_start_time > CONTROLS_ClickTime)
		{
		    _controls_button_handle(i, CONTROLS_CLICK);
		}
	    }
	    b->press_start_time = b->pressed = 0;
	}
    }

    if(controls_encoder != 0)
    {
	Controls_EncoderState *en = controls_encoder;
	if(en->period_start_time == 0)
	{
	    en->tim->CNT = CONTROLS_EncoderDefault;
	}
	uint32_t dt = (controls_millis() - en->period_start_time);
	if(dt > CONTROLS_EncoderPeriodTime)
	{
	    int16_t dv = (en->tim->CNT - CONTROLS_EncoderDefault);
	    if(en->acceleration_en)
	    {
		int16_t s = dv * (int)1000 / (int)dt;
		s = (int16_t)abs(s);
		if(s >= CONTROLS_EncoderDSpeed)
		    dv *= CONTROLS_EncoderDAccel;
		else if(s >= CONTROLS_EncoderCSpeed)
		    dv *= CONTROLS_EncoderCAccel;
		else if(s >= CONTROLS_EncoderBSpeed)
		    dv *= CONTROLS_EncoderBAccel;
		else if(s >= CONTROLS_EncoderASpeed)
		    dv *= CONTROLS_EncoderAAccel;
		else if(s >= CONTROLS_Encoder1Speed)
		    dv += CONTROLS_Encoder1Accel;
		//printf("speed %d\n", dv * (int)1000 / (int)dt);
	    }
	    int16_t v = en->val + dv;

	    if(v > en->max && en->max != 0)
		v = en->min;
	    if(v < en->min && en->max != 0)
		v = en->max;

	    en->val = v;

	    _controls_encoder_handle(v, dv);
	    
	    en->tim->CNT = CONTROLS_EncoderDefault;
	    en->period_start_time = controls_millis();
	}
    }
}
int16_t en_gv()
{
    if(controls_encoder != 0)
    {
	Controls_EncoderState *en = controls_encoder;
	return en->val;
    }
    return 0;
}

void controls_set_buttons_handler(void (*handler)(uint8_t, uint8_t))
{
    Controls_ButtonsHandler = handler;
}

void controls_set_encoder_handler(Controls_EncoderState* conf, void (*handler)(int16_t, int16_t))
{
    if(conf != 0)
	controls_encoder = conf;
    else
	controls_encoder = &controls_encoder_default;
    Controls_EncoderHandler = handler;
}

uint32_t controls_millis(void)
{
    return HAL_GetTick();
}
