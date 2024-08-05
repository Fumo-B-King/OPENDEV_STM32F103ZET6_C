#include "stm32.h"

void Timer2_Init(void) {

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_InternalClockConfig(TIM2);

    TIM_TimeBaseInitTypeDef TIM2_InitClass;
    TIM2_InitClass.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM2_InitClass.TIM_CounterMode = TIM_CounterMode_Up;
    TIM2_InitClass.TIM_Period = 1000;
    TIM2_InitClass.TIM_Prescaler = 71;
    TIM_TimeBaseInit(TIM2, &TIM2_InitClass);
    
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(TIM2, ENABLE);

    NVIC_TIM2();
	
}


void Timer3_Init(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_InternalClockConfig(TIM3);

    TIM_TimeBaseInitTypeDef TIM3_InitClass;
    TIM3_InitClass.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM3_InitClass.TIM_CounterMode = TIM_CounterMode_Up;
    TIM3_InitClass.TIM_Period = 100;
    TIM3_InitClass.TIM_Prescaler = 719;
    TIM3_InitClass.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM3_InitClass);

    TIM_CounterModeConfig(TIM3, TIM_CounterMode_Up);

    TIM_OCInitTypeDef TIM3_OCInitClass;
    TIM_OCStructInit(&TIM3_OCInitClass);
    TIM3_OCInitClass.TIM_OCMode = TIM_OCMode_PWM1;
    TIM3_OCInitClass.TIM_OutputState = TIM_OCPolarity_High;
    TIM3_OCInitClass.TIM_Pulse = 0;
	TIM3_OCInitClass.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OC2Init(TIM3, &TIM3_OCInitClass);
	
	TIM_Cmd(TIM3, ENABLE);

}

void TIM3_PWM(uint16_t Compare) {

	TIM_SetCompare2(TIM3, Compare);

}
