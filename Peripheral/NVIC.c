#include "stm32.h"

void NVIC_TIM2(void) {

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
    NVIC_InitTypeDef NVIC_Timer2InitClass;
    NVIC_Timer2InitClass.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_Timer2InitClass.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Timer2InitClass.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_Timer2InitClass.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_Timer2InitClass);

}

void NVIC_USART1(void) {

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);					

}

void NVIC_Key_Up(void) {

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitTypeDef Key_UP_NVIC_Class;
	Key_UP_NVIC_Class.NVIC_IRQChannel = EXTI0_IRQn;
	Key_UP_NVIC_Class.NVIC_IRQChannelCmd = ENABLE;
	Key_UP_NVIC_Class.NVIC_IRQChannelPreemptionPriority = 2;
	Key_UP_NVIC_Class.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&Key_UP_NVIC_Class);

}

