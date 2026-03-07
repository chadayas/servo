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
	auto tag = "[--ANGLE--]";	
	while(1){
		char ch = getchar();
		if (ch == 27){
			angle += 1.0;
			iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 0, angle);
		} else if(ch == 26){
			angle =- 1.0;
			iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 0, angle);
		}	
		vTaskDelay(5/ portTICK_PERIOD_MS);


			
	}

}
