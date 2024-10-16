/*
 * UsartController.c
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#include "UsartRouter.h"
#include "UsartController.h"

uint8_t length = 0;
uint8_t parsedData = 0;
uint8_t buffer[32] = {};
uint32_t timer = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	uint8_t byte = rxcall;
	if((HAL_GetTick()-timer) > 2){
		length = 0;
		parsedData = 0;
	}
	if(byte == HEADER || parsedData > 0){
		buffer[parsedData] = byte;
		if(parsedData == 3)
			length = byte;
		if(parsedData >= length+4){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			ParsingData(buffer, parsedData+1);
			length = 0;
			parsedData = 0;
		}else
			parsedData++;
	}
	timer = HAL_GetTick();
	HAL_UART_Receive_IT(huart,&rxcall,1);
}

