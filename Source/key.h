#ifndef __KEY_H
#define __KEY_H

void KEY_Config(void);
void KEY_IntrConfig(void);

#define KEY0_STATE  GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) //KEY1 状态，高电位按键断开，低电位按键闭合
#define KEY1_STATE  GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) //KEY2 状态

#endif

