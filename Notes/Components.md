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
