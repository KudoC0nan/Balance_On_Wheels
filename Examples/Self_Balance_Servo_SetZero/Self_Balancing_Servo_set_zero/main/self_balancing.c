#include<stdio.h>
#include "sra_board.h"
#include <math.h>
#include "main.c"

#include "tuning_websocket_server.h"

#define MAX_PITCH_CORRECTION (90.0f)
#define MAX_TOTAL_PITCH (850.0f)
#define MAX_PITCH_RATE (850.0f)

#define MODE NORMAL_MODE

#define MAX_PWM (100.0f)
#define MIN_PWM (90.0f)

// static const char* TAG = "Self_Balance";

float error_calculation(float current_pitch_error)
{
	// stores total pitch error
	static float total_pitch_error = 0.0f;
	// stores prev pitch error
	static float prev_pitch_error = 0.0f;
	// stores difference between current pitch and previous pitch error
	float pitch_difference_error = 0.0f;

	// time interval for derivative calculation
	float dt = 1.0f;

	// storing corrected pitch values
	float pitch_correction = 0.0f;
	float abs_pitch_correction = 0.0f;
	
	// For calculating Integral and Derivative terms
	float pitch_rate =0.0f;

	// PID Values Initialization
	float P_term = 0.0f,I_term=0.0f,D_term=0.0f;

	// Calculation of Error
	pitch_difference_error = current_pitch_error - prev_pitch_error;
	// calculating total pitch error (Integral)
	total_pitch_error = total_pitch_error + current_pitch_error;
	// calculating rate of change of error (Derivative)
	pitch_rate = pitch_difference_error/dt;

	// Calculation of PID Terms
	P_term = read_pid_const().kp * current_pitch_error;
	I_term = read_pid_const().ki * bound(total_pitch_error,-MAX_PITCH_CORRECTION,MAX_PITCH_CORRECTION);
	D_term = read_pid_const().kd * bound(pitch_rate,-MAX_PITCH_RATE,MAX_PITCH_RATE);

	// PITCH CORRECTION
	pitch_correction = P_term + I_term + D_term;

	// Graph Plotting 
	plot_graph(P_term,D_term,I_term,pitch_correction,current_pitch_error);

	// calculating absolute error
	abs_pitch_correction = fabs(pitch_correction);

	// storing current pitch error as previous pitch error
	prev_pitch_error = current_pitch_error;
	return abs_pitch_correction;
}

void motor_command(float abs_pitch_correction,float pitch_error,float *motor_cmd,float *motor_duty_cycle)
{
	/*
		float bound(float val, float min, float max)
		{
    		if (val > max)
        		val = max;
    		else if (val < min)
        		val = min;
    		return val;
		}
	*/

	// stores theoritical calculated values obtained by pid
	*motor_cmd = bound(abs_pitch_correction,0,MAX_PITCH_CORRECTION);
	
	//motor_duty_cycle used to give proper actual velocity corrections to motors and data is obtained from motor_cmd 
	*motor_duty_cycle = bound(*motor_cmd,MIN_PWM,MAX_PWM);	

	// bot is tilting upwards so motors are rotated in backward direction 
	if(pitch_error>1)
	{
		set_motor_speed(MOTOR_A_0,MOTOR_BACKWARD,*motor_duty_cycle);
		set_motor_speed(MOTOR_A_1,MOTOR_BACKWARD,*motor_duty_cycle);
	}
	// bot us tilting downwards so motors are rotated in forward direction
	else if(pitch_error<-1)
	{
		set_motor_speed(MOTOR_A_0,MOTOR_FORWARD,*motor_duty_cycle);
		set_motor_speed(MOTOR_A_1,MOTOR_FORWARD,*motor_duty_cycle);
	}
	// when bot is in equilibrium pos (neither titing upwards nor tilting downwards)
	else
	{
		set_motor_speed(MOTOR_A_0,MOTOR_STOP,0);
		set_motor_speed(MOTOR_A_1,MOTOR_STOP,0);
	}

	ESP_LOGI(TAG,"KP : %f , KI : %f , KD : %f",read_pid_const().kp,read_pid_const().ki,read_pid_const().kd);

}

void balance_task(void *arg)
{
	// euler_angle are complementary roll,pitch,yaw values from mpu6050
	// mpu_offset are initial accelerometer angles at rest pos
	float euler_angle[3], mpu_offset[3] = {0.0f,0.0f};
	
	// pitch error is current_pitch_error
	float pitch_angle , pitch_error;
	
	float motor_cmd =0.0f , motor_duty_cycle= 0.0f; 
	
	float pitch_cmd = 0.0f;

	float abs_pitch_correction = 0.0f;
	
	// initialisation of mpu6050
	if(enable_mpu6050() == ESP_OK)
	{
		// Enable motor driver a in mode - normal mode"
		enable_motor_driver(a,MODE);
		while(1)
		{
			// read_mpu6050 calculates roll,pitch,yaw angles 
			if(read_mpu6050(euler_angle,mpu_offset) == ESP_OK)
			{
				// euler_angle[0]-->Roll ,euler_angle[1]-->Pitch, euler_angle[2]-->Yaw 
				pitch_angle = euler_angle[1];
				
				// to read pid setpoint from tuning_http_server
				pitch_cmd = read_pid_const().setpoint;

				// calculating current pitch_error
				pitch_error = pitch_cmd - pitch_angle;
				abs_pitch_correction = error_calculation(pitch_error); 
				motor_command(abs_pitch_correction,pitch_error,&motor_cmd,&motor_duty_cycle);

			}
		}
	}
	// Remotes the task / delete the task
	vTaskDelete(NULL);
}


void app_main(void)
{
	start_websocket_server();
	xTaskCreate(&balance_task,"balance task",4096,NULL,2,NULL);
	servo_config_setting();

}