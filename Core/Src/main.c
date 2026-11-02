/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include <stdint.h>
#include <stdio.h>
#include "freeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "semphr.h"
#include "timers.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define COUNTER 0
#define SHARED 1
#define EVENT_BIT (1UL << 0 )
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

void vCalcSwitch1Task();
void vIncreaseVarTask();
void vDecreaseVarTask();
void vUARTTask();
typedef struct{
	 int data;
	 int value;

}UARTDataStruct;

QueueHandle_t UARTData;
TaskHandle_t CalcSwitch1;
TaskHandle_t IncreaseVar;
TaskHandle_t DecreaseVar;
TaskHandle_t UART;
SemaphoreHandle_t xSemaphore;
EventGroupHandle_t xEventHandle;

int counter =0;
int shared =0;


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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
xTaskCreate(vCalcSwitch1Task, "CalcSwitch1", 50, NULL, 1, NULL); 	// FreeRTOS xTaskCreate API in task creation section

xTaskCreate(vIncreaseVarTask, "IncreaseVar", 50, NULL, 1, NULL);	// FreeRTOS xTaskCreate API in task creation section

xTaskCreate(vDecreaseVarTask, "DecreaseVar", 50, NULL, 1, NULL);	// FreeRTOS xTaskCreate API in task creation section

xTaskCreate(vUARTTask,"UARTTASK",100,NULL,1,NULL);

UARTData = xQueueCreate(10,sizeof(UARTDataStruct)); 	// FreeRTOS xQueueCreate API in queues  section

xSemaphore = xSemaphoreCreateMutex(); 					// FreeRTOS xSemaphoreCreateMutex API in Semaphores & Mutexes section

xEventHandle = xEventGroupCreate(); 					// FreeRTOS xEventGroupCreate API in Event groups or Flags section

  vTaskStartScheduler();         						//FRee RTOS  vTaskStartScheduler API from Kernal control section
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
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
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
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_PIN){  //HAL page 228 Description of STM32F1 HAL and low-layer drivers - User manual
	BaseType_t xResult,xHigherPriorityTaskWoken = pdFALSE;
		if(GPIO_PIN == GPIO_PIN_0){
			counter++;
			if(counter >= 9) counter = 0;
			xResult= xEventGroupSetBitsFromISR(xEventHandle,EVENT_BIT,&xHigherPriorityTaskWoken); // FreeRTOS xEventGroupSetBitsFromISR API in Event groups or Flags section
			portYIELD_FROM_ISR(xHigherPriorityTaskWoken); 										 // was in the sample code of xEventGroupSetBitsFromISR it triggers the context switching

		}
	}
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) // this hook function prevents an overflow error, i didn't study it yet i searched and copied it
{
    void xTask;
    void pcTaskName;


    taskDISABLE_INTERRUPTS();
    while(1){}
}

void vCalcSwitch1Task(void *pvParameters){

	UARTDataStruct msg;

	EventBits_t xbit;
	while(1){
		xbit = xEventGroupWaitBits(xEventHandle,EVENT_BIT,pdTRUE,pdTRUE,2); 	// FreeRTOS xEventGroupWaitBits  API in Event groups or Flags section
		if(xSemaphoreTake(xSemaphore,0) == pdTRUE){								// FreeRTOS xSemaphoreTake API in Semaphores & Mutexes section
			uint32_t xCounter = counter * 10;
			msg.data = COUNTER;
			msg.value = xCounter;
			xQueueSend(UARTData,&msg,0);										// FreeRTOS xQueueSend API in Queues section
			xSemaphoreGive( xSemaphore );									    // FreeRTOS xSemaphoreGive API in Semaphores & Mutexes section

		};


	}

};
void vIncreaseVarTask(void *pvParameters){

	UARTDataStruct msg;
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1){
		vTaskDelayUntil(&xLastWakeTime,10);					//FreeRTOS vTaskDelayUntil() API in Task control section
			if(xSemaphoreTake(xSemaphore,0) == pdTRUE){     // FreeRTOS xSemaphoreTake API in Semaphores & Mutexes section


			shared++;
			if (shared > 200) shared = 100;
			msg.data = SHARED;
			msg.value = shared;
			xQueueSend(UARTData,&msg,0);					// FreeRTOS xQueueSend API in Queues section
			xSemaphoreGive( xSemaphore );  					// FreeRTOS xSemaphoreGive API in Semaphores & Mutexes section
			};
	}
};
void vDecreaseVarTask(void *pvParameters){
	UARTDataStruct msg;
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1){
		vTaskDelayUntil(&xLastWakeTime,12);				  //FreeRTOS vTaskDelayUntil() API in Task control section
		if(xSemaphoreTake(xSemaphore,0) == pdTRUE){		  // FreeRTOS xSemaphoreTake API in Semaphores & Mutexes section
		shared--;
		if (shared < 100) shared = 200;
		msg.data = SHARED;
		msg.value = shared;

		xQueueSend(UARTData,&msg,0);					 // FreeRTOS xQueueSend API in Queues section
	    xSemaphoreGive( xSemaphore );   				 // FreeRTOS xSemaphoreGive API in Semaphores & Mutexes section
		};
	};

	};

void vUARTTask(void *pvParameters){

	TickType_t xLastWakeTime = xTaskGetTickCount();
	UARTDataStruct ReceivedData;
	char buffer[20];
	while(1){
		vTaskDelayUntil(&xLastWakeTime,5);								//FreeRTOS vTaskDelayUntil() API in Task control section
		 xQueueReceive(UARTData,&ReceivedData,0);						// FreeRTOS xQueueReceive API in Queues section
		 int data =0;
		 if(ReceivedData.data == COUNTER){
			 data = snprintf(buffer,sizeof(buffer),"Counter: %d",ReceivedData.value);
		 }else if(ReceivedData.data == SHARED){
		data = snprintf(buffer,sizeof(buffer),"Shared: %d",ReceivedData.value);
		 };
		 HAL_UART_Transmit(&huart1,(uint8_t*)buffer,data,HAL_MAX_DELAY);  // HAL page 556 Description of STM32F1 HAL and low-layer drivers - User manual

	}

}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
  };
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
