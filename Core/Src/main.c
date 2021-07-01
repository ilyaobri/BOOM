/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim16;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM16_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void SemSegSet(uint8_t set){
	if(set == 0){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_RESET);
	} else if(set == 1){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_RESET);
	} else if(set == 2){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 3){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 4){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 5){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 6){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 7){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_RESET);
	} else if(set == 8){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 9){
		  HAL_GPIO_WritePin(SemSeg_A_GPIO_Port, SemSeg_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_B_GPIO_Port, SemSeg_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_C_GPIO_Port, SemSeg_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_D_GPIO_Port, SemSeg_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_E_GPIO_Port, SemSeg_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_F_GPIO_Port, SemSeg_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SemSeg_G_GPIO_Port, SemSeg_G_Pin, GPIO_PIN_SET);
	} else if(set == 10){
		  HAL_GPIO_TogglePin(SemSeg_H_GPIO_Port, SemSeg_H_Pin);
	}
}

void LedSet(uint8_t set){
	if(set == 10){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET);
	} else if(set == 9){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 8){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 7){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 6){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 5){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 4){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 3){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 2){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 1){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
	} else if(set == 0){
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET);
	}
}

uint8_t count = 0;
uint8_t wincount = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if(count>8){
		count = 0;
	}
	count++;

	if(wincount == 5){
		GameWin();
	} else {
		LedSet(count);
	}

}

void GameWin(){
	LedSet(10);
	if(count == 6){
		wincount = 0;
		HAL_GPIO_WritePin(Piezo_GPIO_Port, Piezo_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SemSeg_H_GPIO_Port, SemSeg_H_Pin, GPIO_PIN_RESET);
		return;
	}
	HAL_GPIO_TogglePin(Piezo_GPIO_Port, Piezo_Pin);
	HAL_GPIO_TogglePin(SemSeg_H_GPIO_Port, SemSeg_H_Pin);
}

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
  MX_ADC1_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim16);
  HAL_GPIO_WritePin(SemSeg_KA_GPIO_Port, SemSeg_KA_Pin, GPIO_PIN_SET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  if(HAL_GPIO_ReadPin(button_GPIO_Port, button_Pin) == GPIO_PIN_SET){
		  if(count > 6){
			  wincount++;
			  count = 0;
		  } else {
			  wincount=0;
			  count = 0;
			  HAL_GPIO_WritePin(Piezo_GPIO_Port, Piezo_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SemSeg_H_GPIO_Port, SemSeg_H_Pin, GPIO_PIN_SET);
		  }
		  while(HAL_GPIO_ReadPin(button_GPIO_Port, button_Pin) == GPIO_PIN_SET){}
		  HAL_GPIO_WritePin(Piezo_GPIO_Port, Piezo_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SemSeg_H_GPIO_Port, SemSeg_H_Pin, GPIO_PIN_RESET);

	  }


	  SemSegSet(wincount);






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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 8000;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 1000;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin
                          |LED_5_Pin|LED_6_Pin|LED_7_Pin|SemSeg_F_Pin
                          |SemSeg_E_Pin|SemSeg_D_Pin|SemSeg_C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_8_Pin|LED_9_Pin|SemSeg_H_Pin|SemSeg_G_Pin
                          |SemSeg_B_Pin|SemSeg_A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_10_Pin|SemSeg_KA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin LED_4_Pin
                           LED_5_Pin LED_6_Pin LED_7_Pin SemSeg_F_Pin
                           SemSeg_E_Pin SemSeg_D_Pin SemSeg_C_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin
                          |LED_5_Pin|LED_6_Pin|LED_7_Pin|SemSeg_F_Pin
                          |SemSeg_E_Pin|SemSeg_D_Pin|SemSeg_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_8_Pin LED_9_Pin SemSeg_H_Pin SemSeg_G_Pin
                           SemSeg_B_Pin SemSeg_A_Pin */
  GPIO_InitStruct.Pin = LED_8_Pin|LED_9_Pin|SemSeg_H_Pin|SemSeg_G_Pin
                          |SemSeg_B_Pin|SemSeg_A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_10_Pin SemSeg_KA_Pin */
  GPIO_InitStruct.Pin = LED_10_Pin|SemSeg_KA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : button_Pin */
  GPIO_InitStruct.Pin = button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(button_GPIO_Port, &GPIO_InitStruct);

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
