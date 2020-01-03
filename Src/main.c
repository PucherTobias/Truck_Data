/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "MY_FLASH.h" 

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

/* USER CODE BEGIN PV */

uint32_t test_writearray[] = {1,2,3,4,5,6,7,8,9};


uint32_t read_velocity[169];
int32_t read_angle[169];
uint32_t read_thrust[169];
uint32_t read_steering[169];

int lol = 0;

uint32_t w_velocity[] = {240,
99,
171,
1,
7,
46,
230,
214,
214,
220,
207,
205,
148,
91,
85,
74,
83,
50,
50,
52,
56,
101,
144,
195,
158,
95,
115,
95,
128,
56,
37,
60,
35,
99,
148,
185,
201,
121,
74,
68,
80,
25,
35,
44,
119,
138,
152,
64,
60,
158,
230,
199,
99,
66,
66,
93,
60,
19,
33,
27,
31,
66,
76,
199,
179,
144,
83,
93,
66,
89,
119,
42,
27,
46,
78,
80,
50,
64,
101,
107,
126,
113,
201,
152,
128,
136,
80,
42,
60,
78,
52,
44,
42,
80,
123,
93,
68,
33,
31,
25,
27,
44,
27,
33,
39,
33,
27,
37,
58,
60,
58,
72,
44,
33,
27,
27,
25,
21,
19,
23,
31,
42,
42,
48,
50,
54,
70,
68,
66,
91,
160,
152,
123,
58,
70,
87,
85,
62,
99,
152,
199,
82,
70,
78,
126,
99,
156,
148,
95,
85,
76,
132,
111,
68,
169,
201,
128,
66,
27,
5,
17,
7,
17,
21,
17,
25,
15,
21,
13,
};
int32_t w_angle[] = {6,
6,
6,
6,
6,
6,
6,
6,
5,
6,
6,
6,
5,
5,
5,
5,
4,
0,
3,
1,
0,
-2,
-4,
-4,
-5,
-9,
-5,
-5,
-5,
-6,
-6,
-5,
-5,
-5,
-5,
-5,
-5,
-5,
-9,
-5,
-5,
-5,
-4,
-3,
-2,
-1,
0,
0,
0,
0,
-3,
0,
1,
1,
2,
4,
4,
4,
5,
4,
4,
5,
5,
7,
3,
6,
5,
6,
6,
8,
10,
11,
10,
12,
11,
12,
13,
12,
14,
10,
14,
15,
15,
12,
16,
18,
18,
18,
18,
19,
20,
21,
22,
22,
23,
23,
23,
23,
23,
23,
19,
22,
21,
22,
22,
21,
21,
21,
22,
21,
21,
20,
15,
18,
17,
17,
16,
15,
15,
14,
14,
13,
13,
12,
12,
10,
10,
9,
8,
5,
8,
8,
8,
5,
8,
7,
7,
7,
7,
6,
7,
3,
7,
7,
7,
4,
7,
8,
7,
8,
8,
9,
9,
9,
9,
10,
10,
11,
10,
12,
10,
11,
10,
6,
10,
10,
5,
10,
10
};
    
uint32_t w_thrust[] = {0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
11,
13,
12,
13,
17,
21,
22,
23,
22,
20,
22,
21,
21,
20,
19,
18,
19,
16,
8,
9,
9,
18,
17,
17,
17,
17,
16,
16,
11,
13,
29,
30,
27,
20,
21,
21,
21,
20,
19,
18,
18,
18,
18,
18,
18,
19,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
18,
21,
21,
21,
21,
21,
20,
21,
21,
21,
20,
20,
20,
18,
19,
19,
19,
19,
19,
20,
19,
19,
19,
19,
18,
19,
20,
21,
21,
21,
21,
21,
21,
21,
21,
21,
21,
21,
22,
22,
22,
22,
22,
22,
22,
22,
22,
21,
21,
21,
21,
22,
22,
22,
21,
21,
21,
21,
20,
20,
20,
20,
20,
20,
20,
20,
20,
20,
19,
20,
20,
20,
20,
19,
19,
20,
19,
19,
19,
20,
19,
19,
19,
20,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
};
uint32_t w_steering[] = {90,
90,
90,
80,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
89,
89,
89,
89,
89,
89,
89,
90,
89,
89,
89,
89,
89,
89,
89,
108,
90,
89,
120,
135,
134,
134,
135,
134,
89,
89,
89,
89,
89,
89,
117,
89,
135,
134,
134,
90,
89,
90,
89,
89,
89,
89,
90,
89,
89,
89,
90,
119,
134,
134,
134,
135,
135,
135,
135,
134,
134,
135,
135,
102,
89,
89,
89,
90,
46,
90,
90,
89,
89,
90,
89,
89,
84,
46,
89,
45,
45,
45,
45,
45,
45,
45,
45,
89,
89,
90,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
45,
87,
89,
89,
89,
90,
89,
87,
89,
89,
90,
89,
89,
89,
89,
89,
90,
90,
89,
89,
89,
89,
90,
89,
89,
89,
89,
89,
89,
90,
89,
89,
90,
89,
89,
89,
90,
89,
89,
90,
90,
89,
89,
89
};


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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


  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

	////////////////flash mit den adressen von Oben nach unten Durcharbeiten.. anders geht es nicht
	//WRITE
	
	lol= 1;
	//Velocity
	MY_FLASH_SetSectorAddrs(8, 0x08100000);
//	MY_FLASH_WriteN(0, w_velocity, 169, DATA_TYPE_32);
	MY_FLASH_ReadN(0, read_velocity, 169, DATA_TYPE_32);
//	HAL_Delay(10);
	lol=2;
	//Angle
	MY_FLASH_SetSectorAddrs(9, 0x08140000);
//	MY_FLASH_WriteN(0, w_angle, 169, DATA_TYPE_32);
	MY_FLASH_ReadN(0, read_angle, 169, DATA_TYPE_32);

lol=3;
//	//Thrust
	MY_FLASH_SetSectorAddrs(10, 0x08180000);
//	MY_FLASH_WriteN(0, w_thrust, 169, DATA_TYPE_32);
	MY_FLASH_ReadN(0, read_thrust, 169, DATA_TYPE_32);
	
	lol=4;
//	//Steering
	MY_FLASH_SetSectorAddrs(11, 0x081C0000);
//	MY_FLASH_WriteN(0, w_steering, 169, DATA_TYPE_32);
	MY_FLASH_ReadN(0, read_steering, 169, DATA_TYPE_32);

	lol = 5;
	
	
	//READ



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		lol = 6;
	
//		
//	MY_FLASH_SetSectorAddrs(11, 0x081E0000);
//	MY_FLASH_ReadN(0, read_thrust, 169, DATA_TYPE_32);
//	
//		
//	MY_FLASH_SetSectorAddrs(11, 0x081F0000);
//	MY_FLASH_ReadN(0, read_steering, 169, DATA_TYPE_32);
//
	
  }		// while Ende

	
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

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV6;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pins : RMII_MDC_Pin RMII_RXD0_Pin RMII_RXD1_Pin */
  GPIO_InitStruct.Pin = RMII_MDC_Pin|RMII_RXD0_Pin|RMII_RXD1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RMII_REF_CLK_Pin RMII_MDIO_Pin RMII_CRS_DV_Pin */
  GPIO_InitStruct.Pin = RMII_REF_CLK_Pin|RMII_MDIO_Pin|RMII_CRS_DV_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : RMII_TXD1_Pin */
  GPIO_InitStruct.Pin = RMII_TXD1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(RMII_TXD1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : STLK_RX_Pin STLK_TX_Pin */
  GPIO_InitStruct.Pin = STLK_RX_Pin|STLK_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : USB_SOF_Pin USB_ID_Pin USB_DM_Pin USB_DP_Pin */
  GPIO_InitStruct.Pin = USB_SOF_Pin|USB_ID_Pin|USB_DM_Pin|USB_DP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_VBUS_Pin */
  GPIO_InitStruct.Pin = USB_VBUS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_VBUS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RMII_TX_EN_Pin RMII_TXD0_Pin */
  GPIO_InitStruct.Pin = RMII_TX_EN_Pin|RMII_TXD0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
