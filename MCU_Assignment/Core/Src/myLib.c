/*
 * myLib.c
 *
 *  Created on: Nov 18, 2023
 *      Author: HOME
 */


#include "myLib.h"
#include "global.h"
int index7SEGLed = 0;
int led_buffer[4] = {0, 0, 0, 0};

int currentLed13 = 0;
int currentLed24 = 0;

int realAmberTime = 2; //real time in second
int realGreenTime = 3;
int realRedTime = 5;


//void update7SEGLed(int index) {
//	enState(index);
//	display7SEG(led_buffer[index]);
//}
//
void updateLedBuffer() {
	led_buffer[0] = currentLed13 / 10;
	led_buffer[2] = currentLed13 % 10;

	led_buffer[1] = currentLed24 / 10;
	led_buffer[3] = currentLed24 % 10;
}

//  void enState(uint8_t enIndex) {
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_(0), SET);
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_(1), SET);
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_(2), SET);
//  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_(3), SET);
//  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_(enIndex), RESET);
//  }
//
//  void clear7SEG() {
//  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, SET);
//  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, SET);
//  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, SET);
//  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, SET);
//  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, SET);
//  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, SET);
//  }
//
//  void display7SEG(uint8_t num) {
//  	  switch(num) {
//  	  	  case 0:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, SET);
//  	  		break;
//  		  case 1:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, SET);
//  	  		break;
//  		  case 2:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  case 3:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  case 4:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  case 5:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  case 6:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  case 7:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, SET);
//  	  		break;
//  		  case 8:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  case 9:
//  	  		HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, SET);
//  	  		HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  	  		HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  		break;
//  		  default:
//  			HAL_GPIO_WritePin(SegA_GPIO_Port, SegA_Pin, SET);
//  		    HAL_GPIO_WritePin(SegB_GPIO_Port, SegB_Pin, RESET);
//  		    HAL_GPIO_WritePin(SegC_GPIO_Port, SegC_Pin, RESET);
//  		  	HAL_GPIO_WritePin(SegD_GPIO_Port, SegD_Pin, SET);
//  		  	HAL_GPIO_WritePin(SegE_GPIO_Port, SegE_Pin, RESET);
//  		  	HAL_GPIO_WritePin(SegF_GPIO_Port, SegF_Pin, RESET);
//  		  	HAL_GPIO_WritePin(SegG_GPIO_Port, SegG_Pin, RESET);
//  	  }
//    }
//
  void clearTrafficLight() {
//  	HAL_GPIO_WritePin(GPIOA, Green1_Pin, SET);
//  	HAL_GPIO_WritePin(GPIOA, Red1_Pin, SET);
//  	HAL_GPIO_WritePin(GPIOA, Yellow1_Pin, SET);
//  	HAL_GPIO_WritePin(GPIOA, Green2_Pin, SET);
//  	HAL_GPIO_WritePin(GPIOA, Red2_Pin, SET);
//  	HAL_GPIO_WritePin(GPIOA, Yellow2_Pin, SET);

  	led_buffer[0] = 0;
  	led_buffer[1] = 0;
  	led_buffer[2] = 0;
  	led_buffer[3] = 0;

  	currentLed13 = 0;
  	currentLed24 = 0;
//  	clear7SEG();
  }

  void onAmber1() {
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
  }

  void onRed1() {
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
  }

  void onGreen1() {
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
  }

  void onAmber2() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
  }

  void onRed2() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
  }

  void onGreen2() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
  }

  void onAmberPedes() {
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
  }
  void onGreenPedes() {
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
  }
  void onRedPedes() {
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
  }
  void clearPedesLed() {
    HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
  }


  void clearled() {
    HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
    HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);

    HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
  }

  int time_buzzer;
  TIM_HandleTypeDef htim3;
  int duty=0;

  void buzzer_on() {
  		  if (buzzer_flag==1) {
  //			  if (currentLed24>2) {
  //				  currentLed24=2;
  //				  setTimer(3, 200);
  //				  time_buzzer=200;
  ////				  onRedPedes();
  //			  } else {
  //				  setTimer(3, (currentLed24+1)*100);
  //				  time_buzzer=(currentLed24+1)*100;
  ////				  onAmberPedes();
  //			  }
  			  if (b==1) {
  				  time_buzzer=realGreenTime*100;
  				  b=0;
  			  } else {
  				  time_buzzer=currentLed13*100;
  			  }
  			  buzzer_flag=0;
  			  duty=0;
  			  timerFlag[6]=1;
  		  }
  		  if (duty>=100) {
  			  duty=0;
  		  }
  		  __HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,duty);
  		  if (timerFlag[6]==1) {
  			  duty+=1;
  			  setTimer(6, time_buzzer/100);
  		  }
    }

  void buzzer_off() {
	  __HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
    }
