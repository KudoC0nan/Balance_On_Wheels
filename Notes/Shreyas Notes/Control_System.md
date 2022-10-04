##Control Loops

The drawing in Figure shows a block diagram of a
control loop. Some command is given to a controller, and the controller determines a
drive signal to be applied to the plant. In response to being driven, the plant responds
with some behavior. In a closed-loop control system such as a PID loop, the plant behavior
is measured, and this measurement is fed back to the controller, which uses it along with
the command to determine the plant drive.

<img src=Balance_On_Wheels/Develop/assets/pid.png/>

## PID Control

The "PID" in "PID Control" stands for "Proportional, Integral, Derivative". These three terms
describe the basic elements of a PID controller. Each of these elements performs a different
task and has a different effect on the functioning of a system.
In a typical PID controller these elements are driven by a combination of the system com-
mand and the feedback signal from the thing that is being controlled (usually referred to
as the "Plant"). Their outputs are added together to form the system output.

<img src=/>

## Example Plants

Motor & Gear
The first example plant is a motor driving a gear train, with the output position of the
gear train being monitored by a potentiometer or some other position reading device. You
might see this kind of mechanism driving a carriage on a printer, or a throttle mechanism
in a cruise control system or almost any other moderately precise position controller.
The motor is driven by a voltage which
is commanded by software and applied to its terminals. The motor output is geared down
to drive the actual mechanism. The position of this final drive is measured by the poten-
tiometer (“pot” in the figure) which outputs a voltage proportional to the motor position.
In the absence of external influences, a DC motor driven by a voltage will go at a constant
speed, proportional to the applied voltage. Usually the motor armature has some resistance
that limits its ability to accelerate, so the motor will have some delay between the input
voltage changing and the speed changing. The gear train takes the movement of the
motor and multiplies it by a constant. Finally, the potentiometer measures the position of
the output shaft.
The response of the motor position to the input voltage can be described by the equa-
tion $$frac/
