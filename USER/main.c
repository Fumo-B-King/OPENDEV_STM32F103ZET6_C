#include "stm32.h"

uint16_t i;
uint16_t time2 = 0;
uint8_t KEY_UP = 0;
uint16_t Num = 0;

int main(void){
	
    Timer2_Init();
    Timer3_Init();
    LED_Init();
    LedSwitch_1(0);
    LedSwitch_2(0);
    OLED_Init();
    OLED_Clear();
    LED1_PWM_Init();
    Buzzer_Init();
    Key_Init();
    USART1_Init();
	
while(1) {

    for (i = 0; i < 100; i++) {
        TIM3_PWM(i);
        Delay_ms(10);
    }
    for (i = 100; i > 0; i--) {
        TIM3_PWM(i);
        Delay_ms(10);
    }
    OLED_ShowString(1, 1, "OLED Show");
    
    LedSwitch_2(KEY_UP);

    USART1_Send(0xFF);

}
}



