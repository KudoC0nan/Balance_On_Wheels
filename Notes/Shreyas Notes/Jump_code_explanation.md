# Jump Code Explanation

First, we configure the servos using the struct servo_config.

It contains their configuration, i.e. 

`servo_pin`  It contains the gpio pin number to which servo is connected.

`min_pulse_width`  It contains the minimum pulse width of servo motor

`max_pulse_width`  It contains the maximum pulse width of servo motor

`max_degree`  It contains the maximum degree servo motor can rotate

`mcpwm_num`  It contains MCPWM unit to use

`timer_num`  It contains MCPWM timer to use

`gen`  It contains MCPWM operator to use

Enabling the servos

`enable_servo()`It enables the Servo port on the sra board and sets up PWM for the three pins in servo port.

Then, `set_angle_servo(servo_config *config, unsigned int degree_of_rotation)` is used to set the angle of the servos 
attached to the servo port of SRA Board

`config` it is the pointer to the servo_config struct

`degree_of_rotation` angle to which the servo must be set, depends on value of MAX_DEGREE macro

The Logic

![img](https://media.discordapp.net/attachments/1006252475629711551/1023268706685571225/IMG_20220924_215353578.jpg?width=960&height=453)

Here, basically we are increasing the height of the robot in iterations rather than in a single movement. This is because, such movement woth appropriate de

delays produce a thrust which pushes the bot upwards. Such thrust is not produced is a single down-up movement.

