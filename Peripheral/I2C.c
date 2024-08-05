#include "stm32.h"

void I2C2_Init() {

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIOB_InitClass;
	GPIOB_InitClass.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIOB_InitClass.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIOB_InitClass.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOB_InitClass);

    I2C_InitTypeDef I2C2_InitClass;
    I2C2_InitClass.I2C_Ack = I2C_Ack_Enable;
    I2C2_InitClass.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C2_InitClass.I2C_ClockSpeed = 50000;
    I2C2_InitClass.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C2_InitClass.I2C_Mode = I2C_Mode_I2C;
    I2C2_InitClass.I2C_OwnAddress1 = 0x78;
    I2C_Init(I2C2, &I2C2_InitClass);


    I2C_Cmd(I2C2, ENABLE);

}

void I2C2_SendData(uint16_t Data) {

    I2C_GenerateSTART(I2C2, ENABLE);
    

    I2C_GenerateSTOP(I2C2, ENABLE);

}
