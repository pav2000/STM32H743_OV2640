/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "snow_tiger.h"
#include "../Src/OV2640/ov2640.h"
#include "../Src/OV2640/ov2640_regs.h"
//#include "../Src/OV2640/computer_vision.h"
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

CRC_HandleTypeDef hcrc;

DCMI_HandleTypeDef hdcmi;
DMA_HandleTypeDef hdma_dcmi;

I2C_HandleTypeDef hi2c3;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */
sensor_t sensor = {0};
Streem_State_t SPI_State;
Streem_State_t DCMI_State;
//defined in sensor.h

#if defined RGB565_128X128
__attribute__((section(".frame_buffer")))int8_t imag_b0[RGB565_128X128_BUF_SIZE] = {0};
__attribute__((section(".frame_buffer")))int8_t imag_b1[RGB565_128X128_BUF_SIZE] = {0};
__attribute__((section(".frame_buffer")))int8_t imag_b2[RGB565_128X128_BUF_SIZE] = {0};

#elif defined RGB565_160X160
__attribute__((section(".frame_buffer")))int8_t imag_b0[RGB565_160X160_BUF_SIZE] = {0};
__attribute__((section(".frame_buffer")))int8_t imag_b1[RGB565_160X160_BUF_SIZE] = {0};
__attribute__((section(".frame_buffer")))int8_t imag_b2[RGB565_160X160_BUF_SIZE] = {0};
#elif defined RGB565_QVGA
int8_t imag[RGB565_QVGA_BUF_SIZE] = {0};
#elif defined RGB565_VGA
int8_t imag[RGB565_VGA_BUF_SIZE] = {0};
#endif
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DCMI_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI2_Init(void);
static void MX_I2C3_Init(void);
static void MX_RTC_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM6_Init(void);
/* USER CODE BEGIN PFP */
static void sensor_setting(I2C_HandleTypeDef *camera_i2c);
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

	  /* Enable I-Cache---------------------------------------------------------*/
//	  SCB_EnableICache();

	  /* Enable D-Cache---------------------------------------------------------*/
//	  SCB_EnableDCache();
  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
// ???? ?????????????????? ?????????????? ???????????? ???????? ?????????????????????????? MX_DMA_Init(); ??????????   MX_DCMI_Init();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_DCMI_Init();

  MX_SPI2_Init();
  MX_I2C3_Init();
  MX_RTC_Init();
  MX_CRC_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */


   HAL_GPIO_WritePin(RST_CAM_GPIO_Port, RST_CAM_Pin, GPIO_PIN_SET);
   HAL_GPIO_WritePin(PWDN_CAM_GPIO_Port, PWDN_CAM_Pin, GPIO_PIN_RESET);
   sensor_setting(&hi2c3);


  ILI9341_Init();
 // HAL_GPIO_WritePin(LED_BOARD_GPIO_Port, LED_BOARD_Pin, GPIO_PIN_RESET);    // ???????????????????? ??????????????????  1
  HAL_GPIO_WritePin(PWDN_TFT_GPIO_Port, PWDN_TFT_Pin, GPIO_PIN_RESET);    // ???????????????? ?????????????????? ??????????????
  ILI9341_FillScreen(GREEN);
  ILI9341_SetRotation(SCREEN_HORIZONTAL_1);
  ILI9341_DrawText("Counting multiple segments at once", FONT2, 10, 200, BLACK, WHITE);

   HAL_TIM_Base_Start_IT(&htim6);
   HAL_TIM_Base_Start(&htim6);

  /* IMAGE EXAMPLE */
  /*
   		ILI9341_FillScreen(WHITE);
  		ILI9341_SetRotation(SCREEN_HORIZONTAL_2);
  		ILI9341_DrawText("RGB Picture", FONT3, 10, 10, RED, YELLOW);
  		ILI9341_DrawText("TIGER", FONT3, 10, 30, BLACK, WHITE);
  		HAL_Delay(2000);
  	//	int t1=HAL_GetTick();
  		ILI9341_DrawImage(snow_tiger, SCREEN_VERTICAL_2);
  	//	ILI9341_SetRotation(SCREEN_VERTICAL_1);
  	//	t1=HAL_GetTick()-t1;
  	//	char buf[32];
  	//	sprintf(buf,"time=%d",t1);
  	//	ILI9341_DrawText(buf, FONT3, 10, 10, BLACK, WHITE);
  		HAL_Delay(5000);
*/


/*

    int8_t t=0;
   while(1){
    ILI9341_SetRotation(SCREEN_VERTICAL_2);
    ILI9341_SetAddress(0,0,ILI9341_SCREEN_HEIGHT,ILI9341_SCREEN_WIDTH);
  	HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);	//data
  	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);	//select
  	int t1=HAL_GetTick();
  	uint8_t test = 0;
 // 	HAL_SPI_Transmit(HSPI_INSTANCE, &test, 1, 1000);

  	if (t==0){
  	if(HAL_SPI_Transmit_DMA(HSPI_INSTANCE,snow_tiger,65000)!= HAL_OK){ ILI9341_DrawText("ERROR", FONT3, 10, 20, BLACK, WHITE);}
  	t=1;
  	}
  	else {
  	 	if(HAL_SPI_Transmit_DMA(HSPI_INSTANCE,snow_tiger+65000,65000)!= HAL_OK){ ILI9341_DrawText("ERROR", FONT3, 10, 20, BLACK, WHITE);}
  	  	t=0;
  	}
  	while(HAL_SPI_GetState(HSPI_INSTANCE) != HAL_SPI_STATE_READY);

//	HAL_SPI_Transmit(HSPI_INSTANCE, &snow_tiger+65000, 65000, 1000);
//  	if(HAL_SPI_Transmit_DMA(HSPI_INSTANCE,snow_tiger+65000+1,65000)!= HAL_OK){ ILI9341_DrawText("ERROR", FONT3, 10, 20, BLACK, WHITE);}
  	t1=HAL_GetTick()-t1;
  	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);	//deselect//
	char buf[32];
	sprintf(buf,"time=%d",t1);
	ILI9341_DrawText(buf, FONT3, 10, 150, BLACK, WHITE);
   }
*/

  DCMI_State = REDY;
  SPI_State = REDY;
  uint8_t order = 0;

  int8_t *hdmi_buff_pointer;
  int8_t *spi_buff_pointer;
  int8_t *ai_buff_pointer;
   while (1)
    {
	 /*
	   if(DCMI_State == REDY && SPI_State == REDY)
	 	  {
	 		  switch(order){
	 		  case 0:
	 			  hdmi_buff_pointer = imag_b0;
	 			  spi_buff_pointer = imag_b1;
	 			  ai_buff_pointer = imag_b2;
	 			  break;
	 		  case 1:
	 			  hdmi_buff_pointer = imag_b1;
	 			  spi_buff_pointer = imag_b2;
	 			  ai_buff_pointer = imag_b0;
	 			  break;
	 		  default:
	 			  hdmi_buff_pointer = imag_b2;
	 			  spi_buff_pointer = imag_b0;
	 			  ai_buff_pointer = imag_b1;
	 			  order = -1;
	 		  }

	 		 memchr(hdmi_buff_pointer,0x00,128*128*2);
	 		  sensor.snapshot(hdcmi, (int32_t *)hdmi_buff_pointer);
	 		  DCMI_State = BUSY;

	 		 ILI9341_render((uint16_t *)spi_buff_pointer);
	 		  SPI_State = BUSY;
	 	  }
	 	*/
	 //   memset(imag_b0,0x00,128*128*2);
	 //   sensor.snapshot(hdcmi, (int32_t *)imag_b0);
	 //   ILI9341_render((uint16_t *)imag_b0);

	     sensor.snapshot(hdcmi, (int32_t *)imag_b0);
	     ILI9341_render((uint16_t *)imag_b0);

    }



/*
  sensor.snapshot(hdcmi, (int32_t *)hdmi_buff_pointer);
  HAL_Delay(100);
  ILI9341_SetRotation(SCREEN_VERTICAL_2);
 // ILI9341_SetAddress(1,1,128,128);
//	HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);	//data
//	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);	//select
	int t1=HAL_GetTick();

//	    uint8_t test = 0;
//		HAL_SPI_Transmit(HSPI_INSTANCE, &test, 1, 1000);
//		if(HAL_SPI_Transmit_DMA(HSPI_INSTANCE,hdmi_buff_pointer,128*128*2)!= HAL_OK){ ILI9341_DrawText("ERROR", FONT3, 10, 20, BLACK, WHITE);}
//		HAL_SPI_Transmit(HSPI_INSTANCE, hdmi_buff_pointer,128*128*2, 10);
//		while(HAL_SPI_GetState(HSPI_INSTANCE) != HAL_SPI_STATE_READY);
	    ILI9341_render(hdmi_buff_pointer);
	t1=HAL_GetTick()-t1;
	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);	//deselect//
	HAL_Delay(100);
	char buf[32];
	sprintf(buf,"time=%d",t1);
	ILI9341_DrawText(buf, FONT3, 10, 150, BLACK, WHITE);

    }
*/
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Macro to configure the PLL clock source
  */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 20;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DCMI Initialization Function
  * @param None
  * @retval None
  */
static void MX_DCMI_Init(void)
{

  /* USER CODE BEGIN DCMI_Init 0 */

  /* USER CODE END DCMI_Init 0 */

  /* USER CODE BEGIN DCMI_Init 1 */

  /* USER CODE END DCMI_Init 1 */
  hdcmi.Instance = DCMI;
  hdcmi.Init.SynchroMode = DCMI_SYNCHRO_HARDWARE;
  hdcmi.Init.PCKPolarity = DCMI_PCKPOLARITY_RISING;
  hdcmi.Init.VSPolarity = DCMI_VSPOLARITY_LOW;
  hdcmi.Init.HSPolarity = DCMI_HSPOLARITY_LOW;
  hdcmi.Init.CaptureRate = DCMI_CR_ALL_FRAME;
  hdcmi.Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;
  hdcmi.Init.JPEGMode = DCMI_JPEG_DISABLE;
  hdcmi.Init.ByteSelectMode = DCMI_BSM_ALL;
  hdcmi.Init.ByteSelectStart = DCMI_OEBS_ODD;
  hdcmi.Init.LineSelectMode = DCMI_LSM_ALL;
  hdcmi.Init.LineSelectStart = DCMI_OELS_ODD;
  if (HAL_DCMI_Init(&hdcmi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DCMI_Init 2 */

  /* USER CODE END DCMI_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.Timing = 0x70843A4F;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES_TXONLY;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 0x0;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  hspi2.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
  hspi2.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
  hspi2.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi2.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi2.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
  hspi2.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
  hspi2.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
  hspi2.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
  hspi2.Init.IOSwap = SPI_IO_SWAP_DISABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 48000;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 5000;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream7_IRQn);
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PWDN_CAM_GPIO_Port, PWDN_CAM_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PWDN_TFT_GPIO_Port, PWDN_TFT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_BOARD_Pin|RST_CAM_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DC_TFT_Pin|CS_TFT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RST_TFT_GPIO_Port, RST_TFT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : KEY1_BOARD_Pin */
  GPIO_InitStruct.Pin = KEY1_BOARD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(KEY1_BOARD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PWDN_CAM_Pin */
  GPIO_InitStruct.Pin = PWDN_CAM_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PWDN_CAM_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : KEY2_Pin KEY1_Pin KEY2_BOARD_Pin */
  GPIO_InitStruct.Pin = KEY2_Pin|KEY1_Pin|KEY2_BOARD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PWDN_TFT_Pin */
  GPIO_InitStruct.Pin = PWDN_TFT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PWDN_TFT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_BOARD_Pin RST_CAM_Pin */
  GPIO_InitStruct.Pin = LED_BOARD_Pin|RST_CAM_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DC_TFT_Pin CS_TFT_Pin */
  GPIO_InitStruct.Pin = DC_TFT_Pin|CS_TFT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PD13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : RST_TFT_Pin */
  GPIO_InitStruct.Pin = RST_TFT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RST_TFT_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
static void sensor_setting(I2C_HandleTypeDef *camera_i2c)
{
	  sensor.bus.i2c = camera_i2c;
	  ov2640_init(&sensor);

	  sensor.write_reg(&sensor, BANK_SEL, 0x01);
	  if(sensor.read_reg(&sensor, REG_PID) != sensor.pid)
	  {
		  Error_Handler();
	  }
	  if(sensor.read_reg(&sensor, REG_VER) != sensor.rev)
	  {
		  Error_Handler();
	  }

	  sensor.pixformat = PIXFORMAT_RGB565;
	#if defined RGB565_128X128
	  sensor.framesize = FRAMESIZE_128X128;
	#elif defined RGB565_160X160
	  sensor.framesize = FRAMESIZE_160X160;
	#elif defined RGB565_QVGA
	sensor.framesize = FRAMESIZE_QVGA;
	#elif defined RGB565_VGA
	sensor.framesize = FRAMESIZE_VGA;
	#endif

	  sensor.contrast_level = 2;
	  sensor.brightness_level = 2;
	  sensor.saturation_level = 2;

	  if(sensor.reset(&sensor) == -1)
	  {
		  Error_Handler();
	  }
	  if(sensor.set(&sensor) == -1)
	  {
		  Error_Handler();
	  }
}
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

