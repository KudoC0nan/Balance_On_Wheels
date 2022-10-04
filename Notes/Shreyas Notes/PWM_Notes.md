## PWM
</p>It is used for getting analog results with digital means. An analog signal is simply a wave of any shape and can take a range of values.<br>
These have a continuously varying value and a huge resolution.<br>
Also as it takes many values the power consumption is very high and circuits might become hot.<br>
Unlike analog signals, digital signals are not continuous, but signals are discrete in value and time. These signals are represented by binary<br> numbers and consist of different voltage</p>
![What-are-Analog-and-Digital-Signals](https://instrumentationtools.com/wp-content/uploads/2021/04/What-are-Analog-and-Digital-Signals.png?ezimgfmt=ng:webp/ngcb1)

---

### Duty Cycle
<p>Duty cycle is the ratio of time a load or circuit is ON compared to the time the load or circuit is OFF. Duty cycle, sometimes called "duty factor," is expressed as a percentage of ON time. A 60% duty cycle is a signal that is ON 60% of the time and OFF the other 40%.</p>

---
### Commands for PWM
**mcpwm_gpio_init()** -- To initialize the mcpwm gpio with operators<br>
**Mcpwm_config_t** -- Struct to config the mcpwm<br>
**mcpwm_init()** -- initialize the mcwm unit parameters config, timer
Set motor speed<br>
**mcpwm_set_duty()** -- sets duty of each operator
**mcpwm_set_duty_type()** -- Call this function every time after mcpwm_set_signal_high or mcpwm_set_signal_low to resume with previously set duty cycle


---

  
