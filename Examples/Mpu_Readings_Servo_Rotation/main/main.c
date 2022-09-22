#include "sra_board.h"

#define TAG "MCPWM_SERVO_CONTROL"



servo_config servo_a = {
	.servo_pin = SERVO_A,
	.min_pulse_width = 500,
	.max_pulse_width = 3000,
	.max_degree = 180,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_0,
	.gen = MCPWM_OPR_A,
};

servo_config servo_b = {
	.servo_pin = SERVO_B,
	.min_pulse_width = 500,
	.max_pulse_width = 3000,
	.max_degree = 180,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_0,
	.gen = MCPWM_OPR_B,
};

servo_config servo_c = {
	.servo_pin = SERVO_C,
	.min_pulse_width = 500,
	.max_pulse_width = 3000,
	.max_degree = 180,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_A,
};

servo_config servo_d = {
	.servo_pin = SERVO_D,
	.min_pulse_width = 500,
	.max_pulse_width = 3000,
	.max_degree = 180,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_B,
};

void servo_control(void *arg)
{
	enable_servo();
	while (1)
	{
		for (int i = 15; i < 45; i++)
		{
			set_angle_servo(&servo_a, i);
			set_angle_servo(&servo_b, i);
			set_angle_servo(&servo_c, i);
			set_angle_servo(&servo_d, i);
			vTaskDelay(5);
			printf("%i",i);
		}

		for (int i = 45; i > 15; i--)
		{
			set_angle_servo(&servo_a, i);
			set_angle_servo(&servo_b, i);
			set_angle_servo(&servo_c, i);
			set_angle_servo(&servo_d, i);
			vTaskDelay(5);
		}
	}
}

void servo_config_setting()
{
	xTaskCreate(&servo_control,"servo control",4096,NULL,1,NULL);
}

// void app_main()
// {

// 	xTaskCreatePinnedToCore(servo_control, "servo_control", 4096, NULL, 1, NULL, 1);
// }