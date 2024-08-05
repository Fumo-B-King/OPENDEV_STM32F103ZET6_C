#include "stm32f10x.h"                  // Device header

void LED_Init() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

	GPIO_InitTypeDef GPIOB_InitClass;
	GPIOB_InitClass.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOB_InitClass.GPIO_Pin = GPIO_Pin_5;
	GPIOB_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitClass);
	
	GPIO_InitTypeDef GPIOE_InitClass;
	GPIOE_InitClass.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOE_InitClass.GPIO_Pin = GPIO_Pin_5;
	GPIOE_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIOE_InitClass);

}

void LedSwitch_1(uint8_t open) {
	if (open == 1) GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	else if (open == 0) GPIO_SetBits(GPIOB, GPIO_Pin_5);
}

void LedSwitch_2(uint8_t open) {
	if (open == 1) GPIO_ResetBits(GPIOE, GPIO_Pin_5);
	else if (open == 0) GPIO_SetBits(GPIOE, GPIO_Pin_5);
}

void LED1_PWM_Init() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);

	GPIO_InitTypeDef GPIOB_InitClass;
	GPIOB_InitClass.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOB_InitClass.GPIO_Pin = GPIO_Pin_5;
	GPIOB_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitClass);

}

