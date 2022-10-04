# PID Controller Explanation
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
