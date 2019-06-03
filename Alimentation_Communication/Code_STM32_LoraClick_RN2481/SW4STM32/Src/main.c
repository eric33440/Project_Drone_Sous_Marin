/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 ** This notice applies to any and all portions of this file
 * that are not between comment pairs USER CODE BEGIN and
 * USER CODE END. Other portions of this file, whether
 * inserted by the user or by software development tools
 * are owned by their respective copyright owners.
 *
 * COPYRIGHT(c) 2019 STMicroelectronics
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stm32f4xx_hal.h>
#include "uart.h"
#include "init_uart.h"
#include <string.h>
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


/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/


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
	MX_USART2_UART_Init();
	MX_USART3_UART_Init();

	/* USER CODE BEGIN 2 */

	/* USER CODE END 2 */
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */

	char * symbole={
			"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"sssssssssooossssssssssssssssssssssosssossssssssssssssssssssssssssooosssssssssssssssssssssssossssssss\r\n",
			"sssssssooosssssssssssssssssssssssosoosssoss/...:osssssssssssssssooossssssssssssssso+syyssoso+ossosss\r\n",
			"sssssooossssssssssssssssssssssssossoooooss:`````:sssssssssooosoososssssssssssssss/::/ohdhyysoooossss\r\n",
			"ssssoossssssssssssssssssssssssssssssoosss+``````+ssssssso:```./sssssssssssssssss/::::::/+oo++ossssss\r\n",
			"ssssossssssssssssssssssssssssssssssssssso.`````:sssssso:``````.sssssssssssssssss:::::----:::/sssssss\r\n",
			"ssssssssssssssssssssssssssss+-.../ssssss:`````.ossss+-```````-+sssssssssssssss+--::---::::::+sssssss\r\n",
			"ssssssssssssssssssssssssssss.`````ossss+``````+sss+-```````-+sssssssssssssssss/  .:::::::::/ssssssss\r\n",
			"ssssssssssssssssssssssssssss.`````+ssso.`````:ss+-```````-+sssssssssssssssssss/   ``.---.` /ssssssss\r\n",
			"ssssssssssssssssssssssssssss-`````/sss-`````.o+-```````-+sssssssssssssssssssss/  ` ```     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss-`````/ss/``````/-```````-+sssssssssssssssssssssss/  - -/:     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss:`````:so``````````````./ossssssssssssssssssssssss/  . -:.     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss:`````-s-```````````````..-:+ossssssssssssssssssss/  - -:.     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss/`````-/`````````````````````.-/osssssssssssssssss/  . -:.     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss/```````````````````..``````````.:osssssssssssssss/  - ./.     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss+`````````````.:/+ooooo+/:-````````/osssssssssssss/  . -/.     /sssossss\r\n",
			"sssssoooossosssssssssssssssso``````````./ossssssssssssso/.``````-ossssssssssss/  . .:`     /sooossss\r\n",
			"ssssoso++ooosssssssssssssssso`````````:ossssssssssssssssss/``````.ooosssssssss/  . .-`     /ooosssss\r\n",
			"ssssssssooosssssssssssssssss+````````+sssssssssssssssssssss+.`````-sssssssssss/  - -:.     /osssssss\r\n",
			"ssssssssosssssssssssssssssss/```````/sssssssssssssssssssssss+``````ossssssssss/  - .:.     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss-```````ssss+oooo+ooooooooo+oosss.`````/ssssssssss/  - -:.     /ssssssss\r\n",
			"ssssssssssssssssssssssssssss```````-sss+-..//-.-//-o./+.o.ssso/-```/ssssssssss/  - -/.     /ssssssss\r\n",
			"sssssssssssssssssssssssssss+```````.sss+-o-//:.-+/:o./o-s:sssssso:+sssssssssss/  . -:.     /ssssssss\r\n",
			"sssssssssssssssssssssssssss:````````+sssosoooooosooooosososs+/:.``/sssssssssss/  - .--     /ssssssss\r\n",
			"sssssssssssssssssssssssssss-`````````osssssssssssssssssssss+``````+sssssssssss/  . -:.     /ssssssss\r\n",
			"sssssssssssssssssssssssssss```````````/sssssssssssssssssss:``````:ssssssssssss/    .:.     /ssssssss\r\n",
			"ssssssssssssssssssssssssss+````````````./sssssssssssssso/.``````:sssssssssssss/    -/.     /ssssssss\r\n",
			"ssssssssssssssssssssssssss:```````````````-/+ossssso+/-```````.+ssssssssssssss+            +ssssssss\r\n",
			"ssssssssssssssssssssssssss.`````````````````````.```````````.:ossssssssssssssss/`        `/sssssssss\r\n",
			"sssssssssssssssssssssssss+````````````````````````````````-/ossssssosssssssssssss+/::::/+sssssssssss\r\n",
			"sssssssssooosssssssssssss:`````````````````````````````.:+sssssssooossssssssssssssssssssssssssssssss\r\n",
			"sssssssooosssssssssssssso````````````````````````````./osssssssoooossssssssssssssssssssssoso+ossosss\r\n",
			"ssssssoossssssssssssssss:``````````````````````````-+sssssssssoosssssssssssssssssssssssssosooooossss\r\n",
			"ssssosssssssssssssssssso````````````````````````./osssssssssoosssssssssssssssssssssssssssssssossssss\r\n",
			"sssssssssssssssssssssss-``````````````````````-+osssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssssssssssos:`````````````````````-+ssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssssssssso.. ```````````````````-+ssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssssssssh:.     ``````````````.+ssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssssssydhdho/.      `````````:osssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"sssssssssssssssydhdmhddhs+-`     `````/sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssssydhddhdmdhddhho-`     `/ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"sssssssssssssydhddhdmhhmdhddhdho/.   `-/osssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssssydhddhdmhdmdhmdhddhdmhs+.`  :sssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"sssssssssssydhmdhdmhdmdhmdhdmhdmdhmdhho/ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssssssssydhmdhdmhdmdhmdhdmhdmhhmdhddyhdyyssssssssssssssssssssosssssssssssssssssssssssssssssooossss\r\n",
			"sssssoooohhyddhdmhdmdhmdhmdhdmhdmdhho+oyhdmdsssssssssssssssssosooosoosssssssssssssssssssssssooosssss\r\n",
			"ssssoso+shyddhdmhdmhdmdhmdhdmhdmdhdyoossdmdssssssssssssssssssos++ooossssssssssssssssssssssoossssssss\r\n",
			"sssssoshyyddhmmhdmhdmdhmdhdmhdmdyyssddhdmdsssssssssssssssssssosso+osssssssssssssssssssssosssssssssss\r\n",
			"sssssshhhmdhmdhdmhdmdhmdhdmhdmdhyoooyhdmdsssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n",
			"ssssshhdmdhmdhdmhdmdhmdhmmhdmhdmdyyhydmhssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss\r\n"};
	HAL_UART_Transmit(&huart2,(uint8_t*)"\033c",5,10);
	//for(int i =0 ; i<sizeof(symbole);i++)
	HAL_UART_Transmit(&huart2,(uint8_t*)symbole,sizeof(symbole),1000);
	//HAL_UART_Transmit(&huart2,(uint8_t*)symbole,sizeof(symbole),10);
	//HAL_UART_Transmit(&huart3,(uint8_t*)"mac reset\r\n",11,10);
	init_lora(1);
	//HAL_UART_Receive_IT(&huart3,bufferdata1,sizeof(bufferdata1));
	//envoie_bis(10,2,"aa");
	global_envoie();

	//global_reception();
	while (1)
	{
		/* USER CODE BEGIN 3 */

	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */



/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if(huart==&huart3)
	{
		HAL_UART_Transmit(&huart2,bufferdata1,sizeof(bufferdata1),tx_timout);
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
