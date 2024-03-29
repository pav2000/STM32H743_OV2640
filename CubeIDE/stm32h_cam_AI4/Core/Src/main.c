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
#include "app_x-cube-ai.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "network.h"
#include "network_data.h"
#include "../Src/OV2640/ov2640.h"
#include "../Src/OV2640/ov2640_regs.h"
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

/* USER CODE BEGIN PV */
sensor_t sensor = {0}; // Структура камеры
// Определение фрейм буфера для камеры
// Организация буфера внутри дисплея. От верхнего левого угла по длинной стороне (т.е сначала запоняется верхняя длинная сторона)
#if defined RGB565_128X128
__attribute__((section(".frame_buffer")))int8_t imag[RGB565_128X128_BUF_SIZE] = {0};
#elif defined RGB565_160X160
__attribute__((section(".frame_buffer")))int8_t imag[RGB565_160X160_BUF_SIZE] = {0};
#elif defined RGB565_QVGA
__attribute__((section(".frame_buffer")))int8_t imag[RGB565_QVGA_BUF_SIZE] = {0};
#elif defined RGB565_VGA
__attribute__((section(".frame_buffer")))int8_t imag[RGB565_VGA_BUF_SIZE] = {0};
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
/* USER CODE BEGIN PFP */
static void sensor_setting(I2C_HandleTypeDef *camera_i2c);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static void init_AI(void);
static uint8_t run_AI(uint16_t *frameBuffer, bool avr);
static float input[28][28];// монохромная картинка 28х28
static float output[10];
static const char lable[10][11] = { "Number 0",
									"Number 1",
									"Number 2",
									"Number 3",
									"Number 4",
									"Number 5",
									"Number 6",
									"Number 7",
									"Number 8",
									"Number 9"};
// Инициализация нейросети
/* Global handle to reference the instantiated C-model */
static ai_handle network = AI_HANDLE_NULL;

/* Global c-array to handle the activations buffer */
AI_ALIGNED(32)
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
/* Array of pointer to manage the model's input/output tensors */
static ai_buffer *ai_input;
static ai_buffer *ai_output;

void init_AI()
{
	  ai_error err;
	  char buf[200];
	  /* Create a local array with the addresses of the activations buffers */
	  const ai_handle act_addr[] = { activations };
	  /* Create an instance of the model */
	  err = ai_network_create_and_init(&network, act_addr, NULL);
	  if (err.type != AI_ERROR_NONE) {
		sprintf(buf,"Err create:%d",(int)err.code);
		ILI9341_DrawText(buf, FONT2, 220,1*hFONT2+1, BLACK, LIGHTGREY);
		} else ILI9341_DrawText("Create OK", FONT2, 220, 1*hFONT2+1, BLACK, LIGHTGREY);
	  /* Reteive pointers to the model's input/output tensors */
	   ai_input = ai_network_inputs_get(network, NULL);
	   ai_output = ai_network_outputs_get(network, NULL);

}
// Запуск нейросети
static uint8_t run_AI(uint16_t *frameBuffer, bool avr)
{
	char buf[200];
	float B,G,R;
// Подготовка данных для нейросети из изображения полученного от камеры.
// В буфере лежит картинка 160(строки) на 160(столбцы) по 2 байта на точку ПО СТРОЧНО!
// Нейросеть всасывает картинку 28х28 (верхний левый угол) с прореживанием или усреднением (флаг avr)!!
// Картинка переводится в градации серого!
	for(int i = 0; i < 28; i ++)  // Строки
	{
		for(int j = 0; j < 28; j ++) // Столбцы
		{
			if(avr){// усредняем матрицу точек 5х5
			B=0;G=0;R=0;
			for(int n = 0; n < 5; n ++) // Усреднение точек
			{
				for(int m = 0; m < 5; m ++)
				{
				uint16_t RGB_sample = frameBuffer[(i*160*5+n)+(j*5+m)]; // усреднение точек - матрица усреднения 5х5 по всей картинке 160х160
				B =B+(float)(RGB_sample & 0x1f) / 32.0;
				G =G+(float)((RGB_sample >> 6) & 0x1f) / 32.0;
				R =R+(float)(RGB_sample >> 11) / 32.0;
			//	B = B+ (float)(RGB_sample & 0x1f) / 128.0;
			//	G = G+ (float)((RGB_sample >> 5) & 0x3f) / 128.0;
			//	R = R+ (float)(RGB_sample >> 11) / 128.0;
				}
			}
			input[i][j]=(R + G + B)/(3.0*25.0);
		//	float pre_sum = (R + G + B)/(25.0);
		//	float sum = pre_sum < 0.3 ? (1-pre_sum) : 0.0;
		//	input[i][j] = (sum - 0.1307) / 0.3081;


			}
			else { // Без усреднения точек (просто берется каждая пятая точка)
				uint16_t RGB_sample = frameBuffer[(i*160*5)+(j*5)];     // берется каждая пятая точка из картинки 160х160
				B = (float)(RGB_sample & 0x1f) / 32.0;
				G = (float)((RGB_sample >> 6) & 0x1f) / 32.0;
				R = (float)(RGB_sample >> 11) / 32.0;
				input[i][j]=(R + G + B)/3.0;
			//	B = (float)(RGB_sample & 0x1f) / 128.0;
			//	G = (float)((RGB_sample >> 5) & 0x3f) / 128.0;
			//	R = (float)(RGB_sample >> 11) / 128.0;
			//	float pre_sum = (R + G + B);
     		//	float sum = pre_sum < 0.3 ? (1-pre_sum) : 0.0;
			//	input[i][j] = (sum - 0.1307) / 0.3081;
			}
		}
	}

	ai_error err;
	ai_i32 batch;
	  /* Update IO handlers with the data payload */
	  ai_input[0].data = AI_HANDLE_PTR(input);
	  ai_output[0].data = AI_HANDLE_PTR(output);

	  SCB_EnableDCache();
	  batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
      SCB_DisableDCache();
	  if (batch != 1) {
	    err = ai_network_get_error(network);
	    sprintf(buf,"Err type:0x%x code:0x%x",(int)err.type,(int)err.code);
	   	ILI9341_DrawText(buf, FONT2, 220, 2*hFONT2+1, BLACK, LIGHTGREY);
	    } else ILI9341_DrawText("Run OK", FONT2, 220, 2*hFONT2+1, BLACK, LIGHTGREY);

	   // Поиск победителя
	    uint8_t res = 0;
	  	float max = output[0];
	  	for(int g = 1; g < 10; g++)
	  	{
	  		if(max < output[g])
	  		{
	  			res = g;
	  			max = output[g];
	  		}
	  	}
	  	return res;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  char buf[64];
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
 // Не правильно сначала должно быть инициализация MX_DMA_Init(); потом   MX_DCMI_Init();
  MX_DMA_Init();
  MX_DCMI_Init();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DCMI_Init();
  MX_DMA_Init();
  MX_SPI2_Init();
  MX_I2C3_Init();
  MX_RTC_Init();
  MX_CRC_Init();
//  MX_X_CUBE_AI_Init();
  /* USER CODE BEGIN 2 */
  //  MX_X_CUBE_AI_Init(); НЕОБХОДИМО ЗАКОМЕНТИРОВАТЬ, нейросеть создается функцией  init_AI(); ниже по коду
   HAL_GPIO_WritePin(RST_CAM_GPIO_Port, RST_CAM_Pin, GPIO_PIN_SET);
   HAL_GPIO_WritePin(PWDN_CAM_GPIO_Port, PWDN_CAM_Pin, GPIO_PIN_RESET);
   sensor_setting(&hi2c3);

  ILI9341_Init();
//  HAL_GPIO_WritePin(LED_BOARD_GPIO_Port, LED_BOARD_Pin, GPIO_PIN_RESET); // Установить светодиод  1
  // Стартовый экран
  HAL_GPIO_WritePin(PWDN_TFT_GPIO_Port, PWDN_TFT_Pin, GPIO_PIN_RESET);     // Включить подсветку дисплея
  ILI9341_FillScreen(LIGHTGREY);
  ILI9341_SetRotation(SCREEN_HORIZONTAL_1);
  ILI9341_DrawRectangle(0,240-2*hFONT2,320-1, 2*hFONT2, WHITE); // Область в две строки для вывода инфы
  ILI9341_DrawHLine(0, 240-2*hFONT2, 320, RED);
  sprintf(buf,"Software: %s Hardware: %s",SOFTWARE, HARDWARE);
  ILI9341_DrawText(buf, FONT2, 130, 240-1*hFONT2+1, RED, WHITE);
  ILI9341_DrawText("Start", FONT2, 220,0*hFONT2+1, BLACK, LIGHTGREY);
  ILI9341_DrawText("Thinning 5x5 points  ", FONT2, 2, 240-2*hFONT2+1, BLACK, WHITE);

  uint32_t old_time, fps;
  bool pause=false;     // есть ли пауза
  bool key2WasUp=true;  // была ли кнопка отпущена?
  bool key2IsUp;        // текущее состояние кнопки
  bool avr=false;       // есть ли усреднение
  bool key1WasUp=true;  // была ли кнопка отпущена?
  bool key1IsUp;        // текущее состояние кнопки

  init_AI(); // Создание нейросети
  for(int j = 0; j < 10; j ++) // Названия классов на дисплей
	   {
	    ILI9341_DrawText(lable[j], FONT2,220, 70+j*hFONT2, BLACK, LIGHTGREY);
	    }
  ILI9341_DrawText("NMIST", FONT4, 220, 50, RED, LIGHTGREY);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  // Кнопка Select ставит процесс на паузу (тригерная кнопка)
	  key2IsUp=HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
	  if (key2WasUp && !key2IsUp) {
		  key2IsUp=HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
	      if (!key2IsUp) { pause=!pause; }
	  }
	  key2WasUp=key2IsUp;

	  // Кнопка Enter вывод рамки где работает нейросеть (тригерная кнопка)
	  key1IsUp=HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
	  if (key1WasUp && !key1IsUp) {
		  key1IsUp=HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
	      if (!key1IsUp) {
	    	  avr=! avr;
	    	  if (avr) ILI9341_DrawText("Averaging 5x5 points", FONT2, 2, 240-2*hFONT2+1, BLACK, WHITE);
	    	  else     ILI9341_DrawText("Thinning 5x5 points  ", FONT2, 2, 240-2*hFONT2+1, BLACK, WHITE);
	      }
	  }
	  key1WasUp=key1IsUp;

      if (!pause){ // если нет паузы
	         old_time=HAL_GetTick();
		     sensor.snapshot(hdcmi, (int32_t *)imag);
		     ILI9341_render160x160((uint16_t *)imag,30,35,160,160);
		     uint8_t number = run_AI((uint16_t*)imag, avr); // Запуск нейросети
		     fps=HAL_GetTick()-old_time;
		     sprintf(buf,"FPS=%d ",(int)(1000/fps));
		     ILI9341_DrawText(buf, FONT2, 2, 240-1*hFONT2+1, BLACK, WHITE);
		     ILI9341_DrawText(lable[number], FONT4, 80, 10, BLUE, LIGHTGREY);
		     for(int j = 0; j < 10; j ++)
		     {
		    	 sprintf(buf,"%.2f",output[j]);
		    	 ILI9341_DrawText(buf, FONT2,290, 70+j*hFONT2, BLACK, LIGHTGREY);
		     }

      }
     //  MX_X_CUBE_AI_Process(); НЕОБХОДИМО ЗАКОМЕНТИРОВАТЬ, нейросеть запускается кодом выше
    /* USER CODE END WHILE */

//  MX_X_CUBE_AI_Process();
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
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
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

	  sensor.contrast_level = 1;   // 2
	  sensor.brightness_level = 2; // 2
	  sensor.saturation_level = 2; // 2

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

