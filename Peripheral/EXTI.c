#include "stm32.h"

void Key_Up_EXTI_Init() {

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	EXTI_InitTypeDef EXTI0_InitClass;
	EXTI0_InitClass.EXTI_Line = EXTI_Line0;
	EXTI0_InitClass.EXTI_LineCmd = ENABLE;
	EXTI0_InitClass.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI0_InitClass.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI0_InitClass);
	
}

void EXTI0_IRQHandler() {

	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == SET) {
		if (KEY_UP) KEY_UP = 0;
		else KEY_UP = 1;
		EXTI_ClearITPendingBit(EXTI_Line0);
	}

}	

void TIM2_IRQHandler(void) {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        time2 %= 1000;
        time2++;
        TIM_ClearITPendingBit(TIM2, TIM_FLAG_Update);
    }
}
