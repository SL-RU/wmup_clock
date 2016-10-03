#ifndef APP_H
#define APP_H
#include "controls.h"
#include <stdio.h>
#include "clock.h"
#include "hd44780.h"

#define APPS_ENCODER_TIME60 1
#define APPS_ENCODER_TIME24 2


typedef struct
{
    uint8_t id;
    void (*open)();
    void (*update)();
    void (*draw)();
    void (*encoder)(int16_t, int16_t);
    void (*buttons)(uint8_t, uint8_t);
    uint8_t (*can_close)(); //if 1 then system can switch app to clock & turn off backlight
    uint8_t (*close)();
} App_Struct;


#define APP_COUNT 2
#define APP_CLOCK_ID 0
#include "app_clock.h"
#define APP_SET_TIME_ID 1
#include "app_set_time.h"



void apps_init(void);

App_Struct * app_get_current();

void apps_update(void);

void apps_draw(void);

void app_switch(uint8_t appid);

void apps_preset_encoder(int16_t val, uint8_t preset);

void apps_input_buttons(uint8_t button, uint8_t event);

void apps_input_encoder(int16_t value, int16_t delta);
#endif
