#include <stdio.h>
#include "driver/ledc.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "iot_servo.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



extern "C" void app_main(void)
{
	servo_config_t s_cfg{};
	s_cfg.max_angle = 270;
	s_cfg.min_width_us = 500;
	s_cfg.max_width_us = 2500;
	s_cfg.freq = 50;	
	s_cfg.timer_number = LEDC_TIMER_0;
	s_cfg.channel_number = 1;
	s_cfg.channels.servo_pin[0] = GPIO_NUM_14;
	s_cfg.channels.ch[0] = LEDC_CHANNEL_0;
	
	iot_servo_init(LEDC_LOW_SPEED_MODE, &s_cfg); 
	
	float angle = 0.0;
	while(1){
		char ch = getchar();
		if (ch == 27){
			getchar();
			int arrow = getchar();
			if (arrow == 68){
				auto tag = "[INCREASE ANGLE]";		
				angle += 1.0;
				if (angle >270.0f) angle = 270.f;
				iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 0, angle);
				ESP_LOGI(tag, " %.1f", angle);	
			} else if (arrow == 67){
				auto tag = "[DECREASE ANGLE]";	
				angle = angle - 1.0;
				if (angle < 0.0f) angle = 0.0;	
				iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 0, angle);
				ESP_LOGI(tag, " %.1f", angle);	
			}
		}
		vTaskDelay(10 / portTICK_PERIOD_MS);
	}

}
