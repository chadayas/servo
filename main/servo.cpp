#include <stdio.h>

void app_main(void)
{
	servo_config_t s_cfg{};
	s_cfg.max_angle = 270;
	s_cfg.min_width_us = 500;
	s_cfg.max_width_us = 2500;
	s_cfg.timer_number = LEDC_TIMER_0;



}
