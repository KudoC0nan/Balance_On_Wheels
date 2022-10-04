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

static void servo_control(void *arg)
{
	enable_servo();

	while (1)
	{
		set_angle_servo(&servo_a, 105);
		set_angle_servo(&servo_b, 0);
		set_angle_servo(&servo_c, 0);
		set_angle_servo(&servo_d, 105);
		vTaskDelay(3);
		set_angle_servo(&servo_a, 0);
		set_angle_servo(&servo_b, 105);
		set_angle_servo(&servo_c, 105);
		set_angle_servo(&servo_d, 0);
		vTaskDelay(2);
		set_angle_servo(&servo_a, 20);
		set_angle_servo(&servo_b, 85);
		set_angle_servo(&servo_c, 85);
		set_angle_servo(&servo_d, 20);
		vTaskDelay(2);
		set_angle_servo(&servo_a, 0);
		set_angle_servo(&servo_b, 105);
		set_angle_servo(&servo_c, 105);
		set_angle_servo(&servo_d, 0);
		vTaskDelay(2);
		set_angle_servo(&servo_a, 50);
		set_angle_servo(&servo_b, 55);
		set_angle_servo(&servo_c, 55);
		set_angle_servo(&servo_d, 50);
		vTaskDelay(2);
		set_angle_servo(&servo_a, 0);
		set_angle_servo(&servo_b, 105);
		set_angle_servo(&servo_c, 105);
		set_angle_servo(&servo_d, 0);
		vTaskDelay(2);
		set_angle_servo(&servo_a, 105);
		set_angle_servo(&servo_b, 0);
		set_angle_servo(&servo_c, 0);
		set_angle_servo(&servo_d, 105);

	}
}

void app_main()
{
	xTaskCreatePinnedToCore(&servo_control, "servo_control", 4096, NULL, 5, NULL, 1);
}
