## Servo Motor

A servomotor (or servo motor) is a rotary actuator or linear actuator that allows for precise control of angular or linear position, velocity and 
acceleration. It consists of a suitable motor coupled to a sensor for position feedback. It also requires a relatively sophisticated controller, 
often a dedicated module designed specifically for use with servomotors.
Servomotors are not a specific class of motor, although the term servomotor is often used to refer to a motor suitable for use in a closed-loop 
control system. 

![Alt text](https://upload.wikimedia.org/wikipedia/commons/6/63/3417_09_Servogetriebe.jpg "industrial servo")

## Mechanism

A servomotor is a closed-loop servomechanism that uses position feedback to control its motion and final position. The input to its control is a 
signal (either analogue or digital) representing the position commanded for the output shaft.

The motor is paired with some type of position encoder to provide position and speed feedback. In the simplest case, only the position is measured. 
The measured position of the output is compared to the command position, the external input to the controller. If the output position differs from 
that required, an error signal is generated which then causes the motor to rotate in either direction, as needed to bring the output shaft to the 
appropriate position. As the positions approach, the error signal reduces to zero and the motor stops. 

## Encoder

Simple servomotors may use resistive potentiometers as their position encoder. These are only used at the very simplest and cheapest level, and are
in close competition with stepper motors. They suffer from wear and electrical noise in the potentiometer track. Although it would be possible to 
electrically differentiate their position signal to obtain a speed signal, PID controllers that can make use of such a speed signal generally warrant 
a more precise encoder. 

Modern servomotors use rotary encoders, either absolute or incremental. Absolute encoders can determine their position at 
power-on, but are more complicated and expensive. Incremental encoders are simpler, cheaper and work at faster speeds. Incremental systems, like stepper 
motors, often combine their inherent ability to measure intervals of rotation with a simple zero-position sensor to set their position at start-up.

## MG-90s Servo

MG90S is a micro servo motor with metal gear. This small and lightweight servo comes with high output power, thus ideal for  RC Airplane, Quadcopter or 
Robotic Arms.

![Alt text](https://components101.com/sites/default/files/components/MG90S-Micro-Servo-Motor.jpg "mg90s servo")

* Operating Voltage: 4.8V to 6V (Typically 5V)
* Stall Torque: 1.8 kg/cm (4.8V)
* Max Stall Torque: 2.2 kg/cm (6V)
* Operating speed is 0.1s/60° (4.8V)
* Gear Type: Metal
* Rotation : 0°-180°
* Weight of motor : 13.4gm

This 2.2kg/cm torque means that the motor can pull a weight of 2.2kg when it is suspended at a distance of 1cm.
To make this motor rotate, we have to power the motor with +5V using the Red and Brown wire and send PWM signals to the Orange colour wire.

![Alt text](https://components101.com/sites/default/files/inline-images/MG90S-Servo-PWM.png "mg90s servo")

From the picture we can understand that the PWM signal produced should have a frequency of 50Hz that is the PWM period should be 20ms. Out of which the 
On-Time can vary from 1ms to 2ms. So when the on-time is 1ms the motor will be in 0° and when 1.5ms the motor will be 90°, similarly when it is 2ms it 
will be 180°. So, by varying the on-time from 1ms to 2ms the motor can be controlled from 0° to 180°

