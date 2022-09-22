//Components
#include "sra_board.h"


// C Headers
#include <stdio.h>
#include <math.h>

#include "tuning_websocket_server.h"
#include "main.c"

//The main task to balance the robot
void print_task(void *arg)
{
	float euler_angle[3],mpu_offset[3] = {0.0,0.0,0.0};
	float roll_angle,pitch_angle,yaw_angle;
	// Ensure successful initialisation of MPU-6050
	if (enable_mpu6050() == ESP_OK)
	{
		while (1)
		{
			if (read_mpu6050(euler_angle, mpu_offset) == ESP_OK)
			{
				roll_angle = euler_angle[0];
				pitch_angle = euler_angle[1];
				yaw_angle = euler_angle[2];

				printf("Roll : %f \t Pitch : %f \t	Yaw : %f\n",roll_angle,pitch_angle,yaw_angle);
				// servo_control();
			}
		}
	}
}

void app_main()
{
	start_websocket_server();
	// servo_config_setting();
	xTaskCreate(&print_task, "print task", 4096, NULL, 2, NULL);
	servo_config_setting();
}	

