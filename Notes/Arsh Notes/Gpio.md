# GPIO (General Purpose Input Output)
---
An Uncommited digital signal pin on an IC or electronic circuit board used as input or output or both controlled by software .
GPIOs has no predefined purpose and are unused by default.
It is used to connect microcontrollers to other electronic devices [Sensors , Diodes , SOC ,etc]
By default Input from connected device via GPIOs.
There are 25 GPIO pins in ESP-32 which can be assigned to various purposes.
There are 34 Physical GPIOs.

**Image of ESP-32**
![ESP-32](https://www.mouser.in/images/espressifsystems/lrg/ESP32-DevKitC-32D_t.jpg)

##Header Files Required For GPIOs
`include "driver/gpio.h"`
This header file configures Gpio pins. This header files carry functions involving Gpio pins like setting direction of flow of instructions [setting up of Output and Input value]
GPIO pin behavior is usually configured statically, but can also be configured or reconfigured at runtime.

`#define BLINK_GPIO_CONFIG_BLINK_GPIO`
It is used to setup string macros for command config_blink_gpio
Can also use project configuration menu 
>idf.py menuconfig 

to choose the Gpio to blink or you can edit the following line and set a number here
Macros is a fragment of code that is given the name.

## GPIO Functions 
1] `gpio_pad_select_gpio()`
    This Function is used to manually control the pins of ESP-32 and use them as source for input or output. This command helps in putting the pins into Gpio mode.

2] `gpio_set_direction(BLINK_GPIO,GPIO_MODE_OUTPUT)`
    This function helps in setting up the mode of a pin as either input only or ouput only or both
    
**Syntax**
    `gpio_set_direction(gpio_num_t gpio_num, gpio_mode_tmode)`

**Parameters**
    1] gpio_num : Configure GPIO pin Number and it should be GPIO number
                  Eg: For GPIO16, gpio_num should be GPIO_NUM_16(16);
    2] mode : GPIO Direction(Input or Output or Both)

**Return Value**
    1] ESP_OK : Success if process is Successful
    2] ESP_ERR_INVALID_ARG : GPIO error if the process fails

3] `gpio_set_level(Blink_GPIO, 0)`
    This functions helps set the output of a pin.
    0 - Corresponds to low output
    1 - Corresponds to high output

**Syntax**
    `gpio_set_level(gpio_num_t gpio_num, uint32_t level)`

**Parameters**
    1] gpio_num : Configure GPIO pin Number and it should be GPIO number
                  Eg: For GPIO16, gpio_num should be GPIO_NUM_16(16);
    2] level : 
    0 - Low output
    1 - High output 

**Return Value**
    1] ESP_OK : Success if process is Successful
    2] ESP_ERR_INVALID_ARG : GPIO error if the process fails


[More Functions GPIO Functions visit](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html,"https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html")


### References :
[More on GPIO.h](https://software-dl.ti.com/simplelink/esd/simplelink_cc13x0_sdk/2.20.00.38/exports/docs/tidrivers/doxygen/html/_g_p_i_o_8h.html,"https://software-dl.ti.com/simplelink/esd/simplelink_cc13x0_sdk/2.20.00.38/exports/docs/tidrivers/doxygen/html/_g_p_i_o_8h.html")

