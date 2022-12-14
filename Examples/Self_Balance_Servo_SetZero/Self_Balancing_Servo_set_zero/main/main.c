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
		set_angle_servo(&servo_a,0);
		set_angle_servo(&servo_b, 105);
		set_angle_servo(&servo_c, 105);
		set_angle_servo(&servo_d, 0);
		// set_angle_servo(&servo_a,70);
		// set_angle_servo(&servo_b,0);
		// set_angle_servo(&servo_c,0);
		// set_angle_servo(&servo_d,70);
		// for (int i = 0,j=70,k=140; i<=70 && j>=0 && k>=60; i++,j--,k--)
		// {
		// 	set_angle_servo(&servo_a, k);
		// 	set_angle_servo(&servo_b, i);
		// 	set_angle_servo(&servo_c, j);
		// 	set_angle_servo(&servo_d, i);
		// 	vTaskDelay(3);
		// }
		// vTaskDelay(5);
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