#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "gpio.h"

//Buttons
#define BFrontRed    GPIOB, GPIO_PIN_3
#define BFrontGreen  GPIOB, GPIO_PIN_4
#define BTopBig      GPIOB, GPIO_PIN_5
#define BTopSmall    GPIOB, GPIO_PIN_8

#define ButtonsCount  4
#define BIFrontRed    0
#define BIFrontGreen  1
#define BITopBig      2
#define BITopSmall    3

//Leds
#define LTopBig GPIOB, GPIO_PIN_11
#define LTopSmall GPIOB, GPIO_PIN_13

