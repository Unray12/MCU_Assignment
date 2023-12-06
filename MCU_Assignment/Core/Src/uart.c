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
int cm_state = RST_WAITING;
char str[100];


UART_HandleTypeDef huart2;

void clear_buffer() {
	memset(uart_buffer,0,sizeof(uart_buffer));
	index_buffer=0;
}

void command_parser_fsm() {
	switch(cp_state){
	case WAIT:
		if(temp == '!'){
			clear_buffer();
			cp_state = RECEIVE;
		}
		break;
	case RECEIVE:
		if(temp == '!'){
			clear_buffer();
		}
		else if(temp == '#'){
			command_flag = 1;
			memcpy(command_data, uart_buffer, sizeof(command_data));
			clear_buffer();
		}
		else if(index_buffer == 0){
			cp_state = WAIT;
		}
		break;
	default:
		break;
	}
}

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

void uart_communication_fsm() {
	switch(cm_state){
	case RST_WAITING:
		if(isRSTreceived()){
			ADC_value = led_buffer[0] * 10 + led_buffer[1];
			cm_state = SENDING;

		}
		break;
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
					ADC_value = led_buffer[0] * 10 + led_buffer[2];
					ADC_value2 = led_buffer[1] * 10 + led_buffer[3];
					if(status == AUTO_AMBER_RED || status == AUTO_GREEN_RED || status == AUTO_RED_AMBER || status == AUTO_RED_GREEN)
						HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!AUTOMATIC: %d, %d# \r\n", ADC_value, ADC_value2), 1000);
					else if(status == MANUAL_AMBER_RED || status == MANUAL_GREEN_RED || status == MANUAL_RED_AMBER || status == MANUAL_RED_GREEN)
						HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!MANUAL: %d, %d# \r\n", ADC_value, ADC_value2), 1000);
					else if(status == TUNING_AMBER || status == TUNING_GREEN || status == TUNING_RED)
						HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!TUNING: %d# \r\n", ADC_value), 1000);
			}
			setTimer(9, 100);
		}

		break;
	default:
		break;
	}
}


