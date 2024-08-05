#include "stm32.h"


void Key_Init() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIOA_InitClass;
	GPIOA_InitClass.GPIO_Mode = GPIO_Mode_IPD;
	GPIOA_InitClass.GPIO_Pin = GPIO_Pin_0;
	GPIOA_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_InitClass);
	
	GPIO_InitTypeDef GPIOE_InitClass;
	GPIOE_InitClass.GPIO_Mode = GPIO_Mode_IPU;
	GPIOE_InitClass.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIOE_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIOE_InitClass);

	NVIC_Key_Up();
	Key_Up_EXTI_Init();
	
}

