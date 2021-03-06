#include "main.h"
#include "lcd.h"
#include "bh1750.h"

static rt_thread_t sysled = RT_NULL;

void sys_led(void *param);

int main(void) {
    LCD_ShowString(0, 0, 15 * 16, 32 * 2, 24, "Hello RT_thread!");

}

/**
 * @brief 初始化
 * @return 无
 */
int sys_led_init(void){
    MX_I2C1_Init();

    //初始化系统提示线程 开始
    sysled = rt_thread_create("sysled",
                              sys_led,
                              RT_NULL,
                              128,
                              30,
                              5);

    if (sysled != RT_NULL) {
        rt_thread_startup(sysled);
    }
    //结束
}
INIT_APP_EXPORT(sys_led_init);

/**
 * @brief 提示系统运行
 * @param param 无
 */
void sys_led(void *param) {
    while (1) {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        rt_thread_delay(100);
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        rt_thread_delay(100);
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        rt_thread_delay(100);
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        rt_thread_delay(1500);
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
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
