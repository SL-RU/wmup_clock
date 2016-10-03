#include "speaker.h"

uint8_t speaker_en = 0;
uint16_t speaker_t = 0;
void speaker_update(void)
{
    if(speaker_en)
    {
	if((HAL_GetTick() / 1000) % 2 == 0)
	{
	    speaker_t ++;
	    if(speaker_t >= 11)
	    {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
		speaker_t = 0;
	    }
	}
	else
	{
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);    
	}
    }
    else
    {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    }
}

void speaker_start(void)
{
    speaker_en = 1;
}

void speaker_stop(void)
{
    speaker_en = 0;
}
