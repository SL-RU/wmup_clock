#ifndef APP_CLOCK_H
#define APP_CLOCK_H
#include "app.h"

App_Struct * app_clock();

void app_clock_init();

void app_clock_open();

void app_clock_update();

void app_clock_draw();

void app_clock_encoder(int16_t, int16_t);

void app_clock_buttons(uint8_t, uint8_t);

uint8_t app_clock_can_close();

uint8_t app_clock_close();
#endif
