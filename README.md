![](https://i.imgur.com/V6Vat3e.jpg)

# About The Project
Modeling and Control of Two-Legged Wheeled Robot:
In this project, we will be building a two wheeled robot (with a hip and knee joint) which can balance at variable heights including a provision for jumping.
---
# Design
---
## File Structure of Design
---

---
## Description of Design
---

---
## Equations used to derive Parameters of Bot
---

---

## Specifications of Bot
---

---

## Problems faced during Design
---

---

## Software used for Design
---

---

# Components
---

**SRA BOARD**
SRA-Dev-Board is a PCB (Printed Circuit Board) designed by our SRA team.
![SRA Development Board](https://github.com/SRA-VJTI/sra-board-hardware-design/raw/master/documentation/assets/3d_sideview.png)

The SRA-dev-Board includes :
* Microcontroller (ESP32)
* Motor Drivers (TB6612FNG)
* Push buttons (which can be used for various applications)
* MPU and Line Sensor Array Breakouts
* Onboard Power Management System
* OLED and Servo Motor Breakouts

[SRA Board CAD Design](https://github.com/SRA-VJTI/sra-board-hardware-design)

---

**ESP-32 Microcontroller**
![](https://i.imgur.com/qfL7c7m.jpg)

ESP32 is a series of low-cost, low-power system on a chip microcontrollers with integrated Wi-Fi and dual-mode Bluetooth.
![](https://www.electronicshub.org/wp-content/uploads/2017/11/Basics-of-Microcontrollers-Image-2.jpg)

[More on ESP-32](https://github.com/KudoC0nan/Balance_On_Wheels/blob/dev_arsh/Notes/hello.md)

---

**Motor Driver (TB6613FNG)**
![](https://i.imgur.com/mpkMVv8.jpg)

We are using TB6612FNG Motor Driver. In simplest terms, Motor Drivers are current amplifiers.
Their function  is to take a low-current control signal, and turn it into a  proportionally higher-current signal that can drive a motor.
A Motor driver can control 2 motors. In normal mode motor driver controls 2 motors at a time giving a maximum current capacity of 1.2A to each motor.
Whereas in parallel mode the motor driver controls a single motor giving a max current capacity of 2.4A to single motor
Parallel mode is used for motors which require high current (Motors with Heavy Current Consumption)

[More on Motor Drivers](https://github.com/KudoC0nan/Balance_On_Wheels/blob/dev_arsh/Notes/pwm.md)

---

**LM2596 Buck Converter (Voltage Regualator)**

![](https://i.imgur.com/SWkWW9l.jpg)

Voltage regulator automatically maintains a constant voltage even though the input voltage changes. It compares the output voltage with a precise reference voltage and adjusts the pass device to maintain a constant output voltage.

This is better over other regulators as : 
* It has better efficiency of about 92%.
* Less power wastage -> Less Heat release  
* Provides high output current upto 3A.

LM2596 INPUT VOLTAGE : 12V (Range is less than 40V)
LM2596 OUTPUT VOLTAGE : 5V In SRA BOARD , 6V for N20 Motors.

---

**N20 Motors**


![](https://i.imgur.com/hztx7pB.jpeg)


The N20 Micro Gear 6V 600 RPM DC Motor (High Torque) is lightweight, high torque, and low RPM motor. It is equipped with gearbox assembly so as to increase the torque of the motor. It has a very small size so as fit in complex spaces of small-scale application. One can connect this Micro Gear Motor to wheels to drive them from one place to other while carrying high loads.

[More on N20- Motors](https://github.com/KudoC0nan/Balance_On_Wheels/blob/dev_shreyas/N20_Motor.md)

---

**MG90 Servos**

![](https://camo.githubusercontent.com/5105adc2c31f624ca2f1473e5ff03c042f80fcf41a3cd54e776da363c74edbc3/68747470733a2f2f636f6d706f6e656e74733130312e636f6d2f73697465732f64656661756c742f66696c65732f636f6d706f6e656e74732f4d473930532d4d6963726f2d536572766f2d4d6f746f722e6a7067)

A Servo Motor is a rotary actuator or linear actuator that allows for precise control of angular or linear position, velocity and acceleration. It consists of a suitable motor coupled to a sensor for position feedback. Servos are not a specific class of motor, although the term Servo Motor is often used to refer to a motor suitable for use in a closed-loop control system.

MG90S is a micro servo motor with metal gear. This small and lightweight servo comes with high output power, thus ideal for RC Airplane, Quadcopter or Robotic Arms.

[More on Servo Motor](https://github.com/KudoC0nan/Balance_On_Wheels/blob/dev_shreyas/Servo_Motor.md)

---
# PWM (Pulse Width Modulation)
---

**Pulse-width modulation (PWM)**, or pulse-duration modulation (PDM), is a method of reducing the average power delivered by an electrical signal, by effectively chopping it up into discrete parts.

Pulse Width Modulation, or PWM, is a technique for getting analog results with digital means. 

The average value of voltage (and current) fed to the load is controlled by turning the switch between supply and load on and off at a fast rate. The longer the switch is on compared to the off periods, the higher the total power supplied to the load.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8e/PWM%2C_3-level.svg/350px-PWM%2C_3-level.svg.png)

### Terms Related to PWM
![](https://camo.githubusercontent.com/91f59b02dab698ad875f82b3bf853775560ed1f5cd059211f928f57debd09acb/68747470733a2f2f7777772e6a61766174706f696e742e636f6d2f656d62656464656473797374656d2f696d616765732f70776d2d6176722d6d6963726f636f6e74726f6c6c6572312e706e67)

There are various terms related with the Pulse Width Modulation:-

**Off-Time**
 Duration of time period when the signal is low.
**ON-Time** 
Duration of time period when the signal is high.
**Duty cycle** 
It is the percentage of the time period when the signal remains ON during the period of the pulse width modulation signal.
**Period** 
It is the sum of off-time and on-time of pulse width modulation signal.

[More on PWM](https://github.com/KudoC0nan/Balance_On_Wheels/blob/dev_arsh/Notes/pwm.md)

---

# PID Control
---
The "PID" in "PID Control" stands for **"Proportional, Integral, Derivative"**. These three terms describe the basic elements of a PID controller. Each of these elements performs a different task and has a different effect on the functioning of a system and it is one kind of device used to control different process variables like pressure, flow, temperature, and speed in industrial applications. 

**Basic Working Of PID Controller**
![](https://i.imgur.com/MviKXyH.png)

In a typical PID controller these elements are driven by a combination of the system command and the feedback signal from the thing that is being controlled (usually referred to as the "Plant"). Their outputs are added together to form the system output.

A “Plant” is simply used for the thing that we wish to control.

The plant feedback is subtracted from the command signal to generate an error. 

This error signal drives the Proportional and Integral elements.

The Derivative element is driven only from Plant Feedback.

The resulting signals are added together and used to drive the plant.

**P Term (Proportional Term)**

The PROPORTIONAL value is directly proportional to the position of the object with respect to the reference.

U α e   

∴ U = Kₚ.e

Where,
Kₚ = Proportional gain
e = error
U = Correction Term

In our Bot the Error is the Pitch Error, i.e, difference between current pitch angle to the initial angle of reference (Set point). 

Larger values of Kp typically mean faster response since the larger the error, the larger the  Proportional term correction signal. However, an excessively large proportional gain will lead to  instability and oscillation.

**D Term (Derivate Term or Damping term)**

The DERIVATIVE is the rate of change of the proportional value.

U₂ ∝ rate of change of error

∴ U₂ = Kd.(de/dt)

Where,
Kd = Derivative gain
de/dt = Change in Error = (Current error - Previous error)/Time

A derivative term does not consider the magnitude of the error. A pure 'D' controller takes the rate of change of error, and tries to bring this rate to zero.

It aims at flattening the Error Trajectory into a horizontal line, Damping the Force applied , and so reduces Overshoot (Reduces Oscillations occured by P Term).

**I Term (Integral Term or Steady State Error)**

The INTEGRAL value records the history of your Bot's motion. It is a sum of all the values of the Proportional term that were recorded.

U3 α Cumulative Error

∴ U3 = Ki * Cumulative Error

∴ U3 = Ki * ∫e(t)dt

Where, 
Ki = integral gain
∫e(t)dt = Cumulative error (in time interval 0 ➡ t )

Integral term increases action in relation not only to the Error but also the time for which it has persisted.

So, if the Applied Force is not enough to bring the error to zero, this force will be increased as time passes. 

A pure 'I' controller could bring the error to Zero, but it would be both slow reacting at the start (because the action would be small at the beginning, depending on time to get significant) and brutal at the end (the action increases as long as the error is positive, even if the error has started to approach zero).

Applying too much integral when the error is small and decreasing will lead to overshoot.

Total Error can be given

U = U1 + U2 +U3

∴ U = Kp * e + Kd * (de/dt) + Ki * ∫e(t)dt

[More on PID](https://www.wescottdesign.com/articles/pid/pidWithoutAPhd.pdf)

---

# File Structure of Code
---

```
- myProject/
             - CMakeLists.txt
             - sdkconfig
             - components/ - component1/ - CMakeLists.txt
                                         - Kconfig
                                         - src1.c
                           - component2/ - CMakeLists.txt
                                         - Kconfig
                                         - src1.c
                                         - include/ - component2.h
             - main/       - CMakeLists.txt
                           - src1.c
                           - src2.c

             - build/
```

---

# Self Balancing Code Explanation
---

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

---

# Jumping Code Explanation
---

---

# Problems faced after Design (On Hardware Bot)
---


---

# Future Implementation of Project
---
Ideas for expansion of our project 

1) Segway Bot , in which we can add camera ,speech recognition and self driving facility in a confined space. We can also add arms to it . So this Bot can interact with people (by recognizing their face and voice) ,can change height and  with arms can lift up objects.(Assistant Type)   
We can also use DFS ans BFS algorithm.

https://techcrunch.com/2016/01/07/segway-has-created-a-robot-that-connects-to-your-two-wheeled-scooter/

2) For obstacle avoiding , ultrasonic sensors (hc sr04) or  Lidar sensors or IR sensors along with our present bot can be used
Lidar sensor has ability to measure 3d structures accurately .It uses laser beam.
Cost is high 
Ultrasonic sensors uses sound waves for detection. It's cost effective. Less sensor accuracy and limited detection range 

Sensor fusion will enables us to improve obstacle detection and localization of objects in dark and foggy areas 
Also more accurate estimation of environment (wind speed etc) 

Also for obstacle detection we can use computer vision also.

https://www.science.gov/topicpages/o/obstacle+detection+algorithm
(2nd and 3rd paper algorithm is useful for us) 

3) Multi Terrain RoBot which can change the length of individual legs based upon terrain and balance itself accordingly

---

## Contributors
[Shreyas Patil](https://github.com/KudoC0nan)
[Arsh Khan](https://github.com/Arsh-Khan)

## Acknowledgement and Bibliography
---
Special Thanks to our Mentors [Marck Koothoor](https://github.com/marck3131) [Ayush Kaura](https://github.com/Ayush-Kaura) [Priyal](https://github.com/Pixels123priyal)
[SRA VJTI](https://github.com/SRA-VJTI)
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/
https://www.youtube.com/playlist?list=PLrOFa8sDv6jcp8E3ayUFZ4iNI8uuPjXHe
https://dspace.mit.edu/handle/1721.1/119961
https://www.wescottdesign.com/articles/pid/pidWithoutAPhd.pdf

