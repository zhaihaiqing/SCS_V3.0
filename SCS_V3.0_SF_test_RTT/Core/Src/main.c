/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
/* USER CODE END 0 */


volatile unsigned int SysTick_Count = 0;




/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	
	float x=0;
	
  /* USER CODE END 1 */                                                                                                                                                                                                                                                                                           

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
	

  /* USER CODE BEGIN SysInit */
	
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();
  //MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
	//HAL_Delay(1000);//延时1S，等待所有电源稳定
	rt_thread_mdelay(1000);
	rt_kprintf("Hardware Init OK!\r\n");
	
	
	SW_CV_PLOAR_L();//S1：设置极性，L=正极性，H=负极性
	SW_CV_MODE_L(); //S2：设置模式，L=电压模式，H=电流模式
	SW_CV_OUTPUT_L();//S3：L=不输出,H=输出
	
	

		
	
	//AD5542_Write(0.5);
	
	scs_thread_init();
	
  while (1)
  {
		
			
		
		
			rt_thread_mdelay(30000);
			rt_kprintf("..\r\n");
		
			//SW_CV_MODE_H();
//		SW_CV_MODE_L();
//		HAL_Delay(2000);
//		SW_CV_MODE_H();
//		HAL_Delay(2000);
		
//			AD5542_Write(x);
//			HAL_Delay(8);
//			x+=0.1;
//			if(x>=4)x=0;
		
		

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DAC_CS1_Pin|DAC_CS2_Pin|DAC_LDAC_Pin|DAC_SCK_Pin
                          |DAC_SDIN_Pin|SW_CV_OUTPUT_Pin|SW_CV_PLOAR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, TRIGGER_OUT_Pin|SW_CV_MODE_Pin|BEEP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : DAC_CS1_Pin DAC_CS2_Pin DAC_LDAC_Pin DAC_SCK_Pin
                           DAC_SDIN_Pin SW_CV_OUTPUT_Pin SW_CV_PLOAR_Pin */
  GPIO_InitStruct.Pin = DAC_CS1_Pin|DAC_CS2_Pin|DAC_LDAC_Pin|DAC_SCK_Pin
                          |DAC_SDIN_Pin|SW_CV_OUTPUT_Pin|SW_CV_PLOAR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : TRIGGER_IN_Pin */
  GPIO_InitStruct.Pin = TRIGGER_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TRIGGER_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TRIGGER_OUT_Pin SW_CV_MODE_Pin BEEP_Pin */
  GPIO_InitStruct.Pin = TRIGGER_OUT_Pin|SW_CV_MODE_Pin|BEEP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */




void USART_PutChar(char  ch)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF); 
}


PUTCHAR_PROTOTYPE
{
	USART_PutChar((char) ch);
	return ch;
}



void AD5542_Write( float val)
{
	unsigned short reg_val;
	
	unsigned char i=0;
	//算要写入的值
	
	reg_val=(val*65536.0/4.096);
	
	DAC_LDAC_H();
	
	DAC_CS1_L();
	DAC_CS2_L();
	
	
	for(i=0;i<16;i++)
	{
		if(((reg_val<<i)&0x8000)==0x8000) 
		{
			DAC_SDIN_H();
		}
		else
		{
			DAC_SDIN_L();
		}
		__nop();__nop();
		DAC_SCK_L();
		__nop();__nop();
		DAC_SCK_H();
		__nop();__nop();
	}
	
	__nop();__nop();
	DAC_LDAC_L();
	
	DAC_CS1_H();
	DAC_CS2_H();
}







//	SW_CV_PLOAR_L();//S1：设置极性，L=正极性，H=负极性
//	SW_CV_MODE_L(); //S2：设置模式，L=电压模式，H=电流模式
//	SW_CV_OUTPUT_L();//S3：L=不输出,H=输出


static void set_ploar( int argc, char **argv)
{
	//rt_kprintf("argc=%d\r\n",argc);
	if(argc <2)
	{
		rt_kprintf("Missing parameters\r\n");
	}
	else if(argc <2)
	{
		rt_kprintf("Too many parameters\r\n");
	}
	else
	{
		rt_kprintf("argv=%d %s\r\n",argv[1],argv[1]);
		if('0'==(int)argv[1])
		{
			rt_kprintf("set Ploar to +");
		}
		if('1'==(int)argv[1])
		{
			rt_kprintf("set Ploar to -");
		}
	}
	
}
MSH_CMD_EXPORT(set_ploar,set_ploar(0=P,1=N));


static void set_mode( int argc, char **argv)
{
	if(argc <2)
	{
		rt_kprintf("Missing parameters\r\n");
	}
	else if(argc <2)
	{
		rt_kprintf("Too many parameters\r\n");
	}
	else
	{
		
	}
}
MSH_CMD_EXPORT(set_mode,set_mode(0=V,1=C));


static void set_out( int argc, char **argv)
{
	if(argc <2)
	{
		rt_kprintf("Missing parameters\r\n");
	}
	else if(argc <2)
	{
		rt_kprintf("Too many parameters\r\n");
	}
	else
	{
		
	}
}
MSH_CMD_EXPORT(set_out,set_out(0=Not Output,1=Output));








static void set_dac1( int argc, char **argv)
{
	unsigned short reg_val;
	
	unsigned char i=0;
	unsigned int val=0;
	//算要写入的值
	
	
	if(argc <2)
	{
		rt_kprintf("Missing parameters\r\n");
	}
	else if(argc <2)
	{
		rt_kprintf("Too many parameters\r\n");
	}
	else
	{
		
	}
	
	
	
	
	reg_val=(val*65536.0/4.096);
	
	DAC_LDAC_H();
	
	DAC_CS1_L();
	__nop();__nop();
	
	for(i=0;i<16;i++)
	{
		if(((reg_val<<i)&0x8000)==0x8000) 
		{
			DAC_SDIN_H();
		}
		else
		{
			DAC_SDIN_L();
		}
		__nop();__nop();
		DAC_SCK_L();
		__nop();__nop();
		DAC_SCK_H();
		__nop();__nop();
	}
	
	__nop();__nop();
	DAC_LDAC_L();
	
	DAC_CS1_H();
}


MSH_CMD_EXPORT(set_dac1,Set_DAC1(Voltage) Val (mV));







static void set_dac2( int argc, char **argv)
{
	unsigned short reg_val;
	
	unsigned char i=0;
	unsigned int val=0;
	//算要写入的值
	
	
	if(argc <2)
	{
		rt_kprintf("Missing parameters\r\n");
	}
	else if(argc <2)
	{
		rt_kprintf("Too many parameters\r\n");
	}
	else
	{
		
	}
	
	reg_val=(val*65536.0/4.096);
	
	DAC_LDAC_H();
	
	DAC_CS2_L();
	__nop();__nop();
	
	for(i=0;i<16;i++)
	{
		if(((reg_val<<i)&0x8000)==0x8000) 
		{
			DAC_SDIN_H();
		}
		else
		{
			DAC_SDIN_L();
		}
		__nop();__nop();
		DAC_SCK_L();
		__nop();__nop();
		DAC_SCK_H();
		__nop();__nop();
	}
	
	__nop();__nop();
	DAC_LDAC_L();
	
	DAC_CS2_H();
}
MSH_CMD_EXPORT(set_dac2,Set_DAC2(Current) Val (mA));

//INIT_BOARD_EXPORT(set_dac2);





















































/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
