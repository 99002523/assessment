/*
 * header1.c
 *
 *  Created on: 05-Oct-2020
 *      Author: Training
 */

#include "main.h"

ADC_HandleTypeDef hadc1;

uint32_t pot()
{
	volatile int a;
	HAL_ADC_Start(&hadc1);
	if(HAL_ADC_PollForConversion(&hadc1, 5)==HAL_OK)
	{
	  	 a=HAL_ADC_GetValue(&hadc1);
	 }
	 HAL_Delay(50);
	return a;
}




int pir()
{
	 if(HAL_GPIO_ReadPin(pir_sensor_GPIO_Port, pir_sensor_Pin))
	 {
	  //HAL_GPIO_WritePin();
	 //while (HAL_GPIO_ReadPin(PIRVALUE_01_GPIO_Port, PIRVALUE_01_Pin));
	  HAL_Delay(1000);
	  //HAL_GPIO_WritePin(LED_OUTPUT_GPIO_Port, LED_OUTPUT_Pin, 0);
	  return 1;
	  while(HAL_GPIO_ReadPin(pir_sensor_GPIO_Port,pir_sensor_Pin));
	 }
	 return 0;
}
