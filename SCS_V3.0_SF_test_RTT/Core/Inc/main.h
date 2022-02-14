/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <stdio.h>
#include "rtthread.h"
#include "scs_thread.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_6
#define LED_GPIO_Port GPIOE
#define DAC_CS1_Pin GPIO_PIN_2
#define DAC_CS1_GPIO_Port GPIOA
#define DAC_CS2_Pin GPIO_PIN_3
#define DAC_CS2_GPIO_Port GPIOA
#define DAC_LDAC_Pin GPIO_PIN_4
#define DAC_LDAC_GPIO_Port GPIOA
#define DAC_SCK_Pin GPIO_PIN_5
#define DAC_SCK_GPIO_Port GPIOA
#define DAC_SDIN_Pin GPIO_PIN_6
#define DAC_SDIN_GPIO_Port GPIOA
#define SW_CV_OUTPUT_Pin GPIO_PIN_7
#define SW_CV_OUTPUT_GPIO_Port GPIOA
#define TRIGGER_IN_Pin GPIO_PIN_0
#define TRIGGER_IN_GPIO_Port GPIOB
#define TRIGGER_OUT_Pin GPIO_PIN_1
#define TRIGGER_OUT_GPIO_Port GPIOB
#define SW_CV_MODE_Pin GPIO_PIN_12
#define SW_CV_MODE_GPIO_Port GPIOB
#define SW_CV_PLOAR_Pin GPIO_PIN_15
#define SW_CV_PLOAR_GPIO_Port GPIOA
#define BEEP_Pin GPIO_PIN_5
#define BEEP_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */


#define	LED_ON()	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET)
#define	LED_OFF()	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET)


#define	DAC_CS1_L()		HAL_GPIO_WritePin(DAC_CS1_GPIO_Port,DAC_CS1_Pin,GPIO_PIN_RESET)
#define	DAC_CS1_H()		HAL_GPIO_WritePin(DAC_CS1_GPIO_Port,DAC_CS1_Pin,GPIO_PIN_SET)

#define	DAC_CS2_L()		HAL_GPIO_WritePin(DAC_CS2_GPIO_Port,DAC_CS2_Pin,GPIO_PIN_RESET)
#define	DAC_CS2_H()		HAL_GPIO_WritePin(DAC_CS2_GPIO_Port,DAC_CS2_Pin,GPIO_PIN_SET)

#define	DAC_LDAC_L()	HAL_GPIO_WritePin(DAC_LDAC_GPIO_Port,DAC_LDAC_Pin,GPIO_PIN_RESET)
#define	DAC_LDAC_H()	HAL_GPIO_WritePin(DAC_LDAC_GPIO_Port,DAC_LDAC_Pin,GPIO_PIN_SET)

#define	DAC_SCK_L()		HAL_GPIO_WritePin(DAC_SCK_GPIO_Port,DAC_SCK_Pin,GPIO_PIN_RESET)
#define	DAC_SCK_H()		HAL_GPIO_WritePin(DAC_SCK_GPIO_Port,DAC_SCK_Pin,GPIO_PIN_SET)

#define	DAC_SDIN_L()	HAL_GPIO_WritePin(DAC_SDIN_GPIO_Port,DAC_SDIN_Pin,GPIO_PIN_RESET)
#define	DAC_SDIN_H()	HAL_GPIO_WritePin(DAC_SDIN_GPIO_Port,DAC_SDIN_Pin,GPIO_PIN_SET)


#define	SW_CV_MODE_L()	HAL_GPIO_WritePin(SW_CV_MODE_GPIO_Port,SW_CV_MODE_Pin,GPIO_PIN_RESET)
#define	SW_CV_MODE_H()	HAL_GPIO_WritePin(SW_CV_MODE_GPIO_Port,SW_CV_MODE_Pin,GPIO_PIN_SET)

#define	SW_CV_OUTPUT_L()	HAL_GPIO_WritePin(SW_CV_OUTPUT_GPIO_Port,SW_CV_OUTPUT_Pin,GPIO_PIN_RESET)
#define	SW_CV_OUTPUT_H()	HAL_GPIO_WritePin(SW_CV_OUTPUT_GPIO_Port,SW_CV_OUTPUT_Pin,GPIO_PIN_SET)

#define	SW_CV_PLOAR_L()	HAL_GPIO_WritePin(SW_CV_PLOAR_GPIO_Port,SW_CV_PLOAR_Pin,GPIO_PIN_RESET)
#define	SW_CV_PLOAR_H()	HAL_GPIO_WritePin(SW_CV_PLOAR_GPIO_Port,SW_CV_PLOAR_Pin,GPIO_PIN_SET)

#define 	debug_log

#ifdef debug_log

			#define		log_info(...)	printf(__VA_ARGS__)

#else
			#define		log_info(...)
#endif





extern volatile unsigned int SysTick_Count;

extern UART_HandleTypeDef huart1;


void AD5542_Write(float val);
void SystemClock_Config(void);
void MX_USART1_UART_Init(void);




/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
