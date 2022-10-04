# Self Balancing Code Explanation

Firstly we initialize Euler_angle and mpu_offset to zero. Euler angles are complementary roll,pitch,yaw values.

We get the readings of angle from both Gyroscope and Accelerometer.Both sensors can give readings directly. 

Gyroscope has a problem of Gyroscopic Drift which accumulates over time, so it gives reliable readings for short period of time.
Whereas Accelerometer is jittery and sensitive, but the readings are based on g-vector which has an absolute value, the readings can be relied for long term.

To use the benefits of each Sensors we do Sensor fusion.

Idea behind Complementary filter is to take slow moving signals from gyroscope and fast moving signals from a accelerometer and combine them.
Accelerometer data is reliable for long term so we apply a "Low pass" filter to it whereas Gyroscope data is reliable in short term so we use "High pass" filter

![](https://gunjanpatel.files.wordpress.com/2016/07/7bca7-mw04.jpg?w=583&h=207)


Next we read the Pitch value of angle from MPU 6050.

`pitch_angle = euler_angle[1]`

We also read Setpoint from Https server.

`pitch_cmd = read_pid_const().setpoint`

Then we calculate the Pitch Error by subtracting pitch angle from setpoint of bot.

`pitch_error = pitch_cmd - pitch_angle`

Then we pass the current generated error to `error_calculation functuon(pitch_error)`which returns absolute pitch correction term for motor command

Calculation of Error :

Firstly in `error_calculation()` function we find Difference in Pitch Error which is difference of current pitch error and previous pitch error.

`pitch_difference_error = current_pitch_error - prev_pitch_error`

Then we calculate total pitch error which is useful for Steady state error(Integral Term)

`total_pitch_error =total_pitch_error + current_pitch_error`

Then we calculate the rate of change of error for Derivative 'D' term to reduce the oscillations caused by P term.

`pitch_rate = pitch_difference_error/dt`


For Calculation of PID terms

For P term we read the value of kp from https server and multiply that value with current pitch error.

`P_term = read_pid_const().kp * current_pitch_error`

For D term we read the value of kd from https server and multiply it by bounded value of Pitch Rate between MIN and MAX Pitch Rate predefined.

`D_term = read_pid_const().kd * bound(pitch_rate,-MAX_PITCH_RATE,MAX_PITCH_RATE)`

For I term we again read the value ki from https server and multiply it by bounded value of total pitch error between MIN and MAX Pitch correction.

`I_term = read_pid_const().ki * bound(total_pitch_error,-MAX_PITCH_CORRECTION,MAX_PITCH_CORRECTION)`

Now that we have calculated PID error terms we then calculate the pitch correction term which is sum of all the errors.

`pitch_correction = P_term + I_term + D_term`

Then we plot the graph of PID term, pitch correction and current pitch error terms onto the server.

`plot_graph(P_term,D_term,I_term,pitch_correction,current_pitch_error)`

Then we store the current pitch error as previous pitch error for further calculations when this error calculation function runs again.

`prev_pitch_error = current_pitch_error`

Then we calculate the absolute pitch correction term and then returing this term back to main loop

`abs_pitch_correction = fabs(pitch_correction)`

The received absolute pitch error is passed onto the motor command function which will decide the motion of bot to counter the error.

`motor_command(abs_pitch_correction,pitch_error,&motor_cmd,&motor_duty_cycle)`

The function takes in 4 parameters.
absoloute pitch correction term recieved from error_calculation function, current pitch error, motor command(calculates theoritical calculated error values obtained by PID) and motor duty cycle (which gives proper actual velocity corrections to motors obtained from motor command).

In `motor_command()` function : 

Firstly we calculate motor command which is the bounded value of absolute pitch correction between 0 and Max pitch correction.

`*motor_cmd = bound(abs_pitch_correction,0,MAX_PITCH_CORRECTION);`

Then we calculate motor duty cycle which is bounded value of motor command between MIN and MAX PWM which are predefined in code.

`*motor_duty_cycle = bound(*motor_cmd,MIN_PWM,MAX_PWM)`

The Main Part of Self Balancing Code :

Now If the `pitch_error` is -ve it implies that the front of the bot is below the the desired position (i.e. pitch_angle < pitch_cmd),in simple words Bot is tilting downwars so both the motors are given command to rotate in forward direction to balance itself.

``` C
if(pitch_error<-1)
	{
		set_motor_speed(MOTOR_A_0,MOTOR_FORWARD,*motor_duty_cycle);
		set_motor_speed(MOTOR_A_1,MOTOR_FORWARD,*motor_duty_cycle);
	}
```    

If the `pitch_error` is +ve it implies that the front of the bot is above the the desired position (i.e. pitch_angle > pitch_cmd),in simple words Bot is tilting Upwards so both the motors are given command to rotate in backward direction to balance itself.

``` C
if(pitch_error>1)
	{
		set_motor_speed(MOTOR_A_0,MOTOR_BACKWARD,*motor_duty_cycle);
		set_motor_speed(MOTOR_A_1,MOTOR_BACKWARD,*motor_duty_cycle);
	}
```

If the `pitch_error` is equal to zero , it implies that the front of the bot is exactly in equilibrium position which is neither tilting upwards and downwards (i.e. pitch_angle = pitch_cmd),in simple words Bot is equilibrium it has achieved Self Balancing , now both the motors are given command to Stop by giving them Zero Duty Cycle.

``` C
if(pitch_error==0)
	{
		set_motor_speed(MOTOR_A_0,MOTOR_STOP,0);
		set_motor_speed(MOTOR_A_1,MOTOR_STOP,0);
	}
```
`set_motor_speed()` function takes in 3 Inputs.Firstly Motor Id,Secondly Motor Rotation Direction and Lastly Duty Cycle.

And all the above functions continues to execute again in a loop for achieving the desirable result,i.e, Self Balancing.

[Link to Self Balancing Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/dev_arsh/Examples/Self_Balance_Code)
