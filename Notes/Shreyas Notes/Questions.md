## Normal Mode and Parallel Mode
---
- ### Normal Mode
  The Driver controls two motors giving each an output of 1.2Amps.
- ### Parallel Mode
  The Driver controls a single motor giving it an output of 2.4Amps. This mode is used when a motor which requires a high current input is being used.
## Duty Cycle
---
It is the ratio of time a load/circuit is ON compared to the time the load/circuit is OFF.
Eg. 6-% Duty Cycle means the circuit is ON 60% of the time and OFF 40% of the time.
## Minimum Duty Cycle for the motors to rotate
---
The min. duty cycle for the motors to start rotating is 50%. This is beacuse the provided output for a required amount of time is necessary for the motor to overcome
the frctional forces. Thus once the duty cycle is increased beyond the threshold, the torque produced for a longer time now is able to overcome the static friction.
## enable_motor_driver()
---
It is a function used to enable the motor driver in a specific mode.
Eg. enable_motor_driver(a, NORMAL_MODE); Enables motor driver A in Normal Mode.
## Which motor driver is used?
---
The motor driver used(in the SRA board) is TB6612FNG.
## vTaskDelay()
---
vTaskDelay() specifies a time at which the task wishes to unblock relative to the time at which vTaskDelay() is called. 
Eg. specifying a block period of 100 ticks will cause the task to unblock 100 ticks after vTaskDelay() is called. Thats is 100ms.
vTaskDelay(100 / portTICK_PERIOD_MS)
## xTaskCreate()
---
Create a new task and add it to the list of tasks that are ready to run.
If a task is created using xTaskCreateStatic() then the RAM is provided by the application writer, so it can be statically allocated at compile time.
Eg. xTaskCreate(&pwm_task, "pwm_task", 4096, NULL, 1, NULL);
where **&pwm_task** is the pointer to the task
      **pwm_task** is the name of the task
      **4096** is STACK_BYTES(i.e. RAM)
      The rest are the priorities given to the task i.e. here the priority is 0,1,0 which means priority is 1. 
      The priority can range from Highest- 0 to Lowest- 10.
