#include "stm32f10x.h"                  // Device header

void Buzzer_Init() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitTypeDef GPIO_InitClass;
	
	GPIO_InitClass.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitClass.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitClass);
}

void Buzzer_Switch(uint16_t open) {
	if (open == 1) GPIO_SetBits(GPIOB, GPIO_Pin_8);
	if (open == 0) GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}
