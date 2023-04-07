/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define HARDWARE "1.00"  // Версия железа
#define SOFTWARE "1.16"  // Версия программы
#define hFONT2   14      // высота шрифта в точках FONT2

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#include "../Src/ILI9341/ILI9341_GFX.h"
#include "../Src/ILI9341/ILI9341_STM32_Driver.h"
//#include "snow_tiger.h"
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY1_BOARD_Pin GPIO_PIN_3
#define KEY1_BOARD_GPIO_Port GPIOE
#define PWDN_CAM_Pin GPIO_PIN_13
#define PWDN_CAM_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_0
#define KEY2_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_1
#define KEY1_GPIO_Port GPIOC
#define PWDN_TFT_Pin GPIO_PIN_0
#define PWDN_TFT_GPIO_Port GPIOA
#define LED_BOARD_Pin GPIO_PIN_1
#define LED_BOARD_GPIO_Port GPIOA
#define RST_CAM_Pin GPIO_PIN_2
#define RST_CAM_GPIO_Port GPIOA
#define KEY2_BOARD_Pin GPIO_PIN_5
#define KEY2_BOARD_GPIO_Port GPIOC
#define DC_TFT_Pin GPIO_PIN_0
#define DC_TFT_GPIO_Port GPIOB
#define CS_TFT_Pin GPIO_PIN_12
#define CS_TFT_GPIO_Port GPIOB
#define RST_TFT_Pin GPIO_PIN_0
#define RST_TFT_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
