#ifndef APP_SET_TIME_H
#define APP_SET_TIME_H 1
#include "app.h"


App_Struct * app_set_time();

void app_set_time_init();

void app_set_time_open();

void app_set_time_update();

void app_set_time_draw();

void app_set_time_encoder(int16_t, int16_t);

void app_set_time_buttons(uint8_t, uint8_t);

uint8_t app_set_time_can_close();

uint8_t app_set_time_close();
#endif
