/*
 * fsm.c
 *
 *  Created on: Nov 15, 2023
 *      Author: PC
 */

#include "uart.h"
#include "global.h"
#include <stdio.h>

uint32_t ADC_value = 0;
uint32_t ADC_value2 = 0;
uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t uart_buffer[MAX_BUFFER_SIZE];
int command_flag = 0;
uint8_t command_data[MAX_BUFFER_SIZE];
int cp_state = WAIT;
int cm_state = SENDING;
char str[100];


UART_HandleTypeDef huart2;

void clear_buffer() {
	memset(uart_buffer,0,sizeof(uart_buffer));
	index_buffer=0;
}

//void command_parser_fsm() {
//	switch(cp_state){
//	case WAIT:
//		if(temp == '!'){
//			clear_buffer();
//			cp_state = RECEIVE;
//		}
//		break;
//	case RECEIVE:
//		if(temp == '!'){
//			clear_buffer();
//		}
//		else if(temp == '#'){
//			command_flag = 1;
//			memcpy(command_data, uart_buffer, sizeof(command_data));
//			clear_buffer();
//		}
//		else if(index_buffer == 0){
//			cp_state = WAIT;
//		}
//		break;
//	default:
//		break;
//	}
//}

int isRSTreceived(){
	if(command_data[0] == 'R' && command_data[1] == 'S' && command_data[2] == 'T' && command_data[3] == '#')
		return 1;
	return 0;
}

int isOKreceived(){
	if(command_data[0] == 'O' && command_data[1] == 'K' && command_data[2] == '#')
		return 1;
	return 0;
}

void uart_transmit(){
	switch(status){
	case TUNING_AMBER:
		ADC_value = buffer[0] * 10 + buffer[1];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!TUNING AMBER: %d# \r\n", ADC_value), 1000);
		break;
	case TUNING_GREEN:
		ADC_value = buffer[0] * 10 + buffer[1];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!TUNING GREEN: %d# \r\n", ADC_value), 1000);
		break;
	case TUNING_RED:
		ADC_value = buffer[0] * 10 + buffer[1];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!TUNING RED: %d# \r\n", ADC_value), 1000);
		break;
	case MANUAL_AMBER_RED:
		ADC_value = led_buffer[0] * 10 + led_buffer[2];
		ADC_value2 = led_buffer[1] * 10 + led_buffer[3];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!MANUAL AMBER: %d\t RED %d# \r\n", ADC_value, ADC_value2), 1000);
		break;
	case MANUAL_GREEN_RED:
		ADC_value = led_buffer[0] * 10 + led_buffer[2];
		ADC_value2 = led_buffer[1] * 10 + led_buffer[3];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!MANUAL GREEN: %d\t RED %d# \r\n", ADC_value, ADC_value2), 1000);
		break;
	case MANUAL_RED_AMBER:
		ADC_value = led_buffer[0] * 10 + led_buffer[2];
		ADC_value2 = led_buffer[1] * 10 + led_buffer[3];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!MANUAL RED: %d\t AMBER %d# \r\n", ADC_value, ADC_value2), 1000);
		break;
	case MANUAL_RED_GREEN:
		ADC_value = led_buffer[0] * 10 + led_buffer[2];
		ADC_value2 = led_buffer[1] * 10 + led_buffer[3];
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!MANUAL RED: %d\t GREEN %d# \r\n", ADC_value, ADC_value2), 1000);
		break;
	default:
		break;
	}
}

void uart_communication_fsm() {
	switch(cm_state){
//	case RST_WAITING:
//		if(isRSTreceived()){
//			ADC_value = led_buffer[0] * 10 + led_buffer[1];
//			cm_state = SENDING;
//
//		}
//		break;
	case SENDING:
		if(timerFlag[9] == 1){
			if(isOKreceived()){
					clear_buffer();
					command_flag = 0;
					cp_state = WAIT;
					cm_state = RST_WAITING;
			}
			else{
					clear_buffer();
					memset(command_data, 0, sizeof(command_data));
					uart_transmit();
			}
			setTimer(9, 100);
		}

		break;
	default:
		break;
	}
}


