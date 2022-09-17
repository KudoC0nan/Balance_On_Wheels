#include "sra_board.h"

#define TAG "MCPWM_SERVO_CONTROL"

servo_config servo_a = {
	.servo_pin = SERVO_A,
	.min_pulse_width = CONFIG_SERVO_A_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_A_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_A_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_0,
	.gen = MCPWM_OPR_A,
};

servo_config servo_b = {
	.servo_pin = SERVO_B,
	.min_pulse_width = CONFIG_SERVO_B_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_B_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_B_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_0,
	.gen = MCPWM_OPR_B,
};

servo_config servo_c = {
	.servo_pin = SERVO_C,
	.min_pulse_width = CONFIG_SERVO_C_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_C_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_C_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_A,
};

servo_config servo_d = {
	.servo_pin = SERVO_D,
	.min_pulse_width = CONFIG_SERVO_D_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_D_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_D_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_B,
};

static void mcpwm_servo_control(void *arg)
{
	enable_servo();

	while (1)
	{
		for (int i = 130,j=0; i>=0 && j<=130; i--,j++)
		{
			set_angle_servo(&servo_a, i);
			set_angle_servo(&servo_b, j);
			set_angle_servo(&servo_c, j);
			set_angle_servo(&servo_d, i);
			vTaskDelay(3);
		}
		for (int i = 0,j=130; i<=180 && j>=0; i++,j--)
		{
			set_angle_servo(&servo_a, i);
			set_angle_servo(&servo_b, j);
			set_angle_servo(&servo_c, j);
			set_angle_servo(&servo_d, i);
			vTaskDelay(3);
		}

	}
}

void app_main()
{
	xTaskCreatePinnedToCore(mcpwm_servo_control, "mcpwm_example_servo_control", 4096, NULL, 5, NULL, 1);
}