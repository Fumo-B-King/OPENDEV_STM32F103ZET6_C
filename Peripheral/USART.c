#include "stm32.h"

void USART1_Init(void) {

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIOA_InitClass;
    GPIOA_InitClass.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIOA_InitClass.GPIO_Pin = GPIO_Pin_9;
    GPIOA_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIOA_InitClass);

    GPIOA_InitClass.GPIO_Mode = GPIO_Mode_IPU;
	GPIOA_InitClass.GPIO_Pin = GPIO_Pin_10;
	GPIOA_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIOA_InitClass);

    USART_InitTypeDef USART1_InitClass;
    USART1_InitClass.USART_BaudRate = 9600;
    USART1_InitClass.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART1_InitClass.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART1_InitClass.USART_Parity = USART_Parity_No;
    USART1_InitClass.USART_StopBits = USART_StopBits_1;
    USART1_InitClass.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART1_InitClass);

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    NVIC_USART1();

    USART_Cmd(USART1, ENABLE);

}

void USART1_Send(uint8_t Byte) {

	USART_SendData(USART1, Byte);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

}


