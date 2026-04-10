#include "main.h"
#include <stdio.h>
#include <string.h>

#define ADC_BUFFER_SIZE 10
#define THRESHOLD 3000

uint16_t adc_buffer[ADC_BUFFER_SIZE];
uint16_t adc_average = 0;
char uart_msg[50];

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;
TIM_HandleTypeDef htim2;

/* Calculate average */
uint16_t calculate_average(uint16_t *buffer)
{
  uint32_t sum = 0;

  for (int i = 0; i < ADC_BUFFER_SIZE; i++)
  {
    sum += buffer[i];
  }

  return sum / ADC_BUFFER_SIZE;
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();

  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buffer, ADC_BUFFER_SIZE);

  while (1)
  {
    adc_average = calculate_average(adc_buffer);

    if (adc_average > THRESHOLD)
    {
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 800);

      sprintf(uart_msg, "WARNING: Threshold Exceeded\r\n");
      HAL_UART_Transmit(&huart2, (uint8_t*)uart_msg, strlen(uart_msg), 100);
    }
    else
    {
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 200);
    }

    sprintf(uart_msg, "Average ADC Value: %d\r\n", adc_average);
    HAL_UART_Transmit(&huart2, (uint8_t*)uart_msg, strlen(uart_msg), 100);

    HAL_Delay(1000);
  }
}
