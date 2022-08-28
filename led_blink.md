# LED BLINK
---
In the simplest terms, a **Light-emitting diode (LED)** is a semiconductor device that emits light when an electric current is passed through it. 
It is a light sensor which emits light that is reflected from surface which further helps in sensing the environment. 


![LED](https://www.electrical4u.com/wp-content/uploads/What-is-a-LED.png "LED")
![LED ON PCB](https://lh6.googleusercontent.com/yx89w48teGWcD2TGhw34hbs-j4heDzFSqXiIf1M0FlALTBRjLJMm3kqtfSy-MOcnhfZqNBNsvbWtYIbQzEYRuG6BZTW-vugA5tJUpADq8JD61KAXQn9Kfcd3rEd_flhYqWr8o-g4aF9KPNIM2xXa3gMts-a06eHx_nw2sHAKvrCES00jl2UDVhMWB6Opw5o)

 0  0   0   0   0  0   0   1 -->The position of bits   corresponds to the position of LEDS in the series and the value at the corresponding position shows the state of the LED.The bit from right represents 1st LED and the bit from left represent last led (8th LED)
0 -> LED is OFF
1 -> LED is ON

Example :If I want only 5th and 6th LED to stay ON, I’ll write 00110000

---
## Code
``` c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"

void app_main()
{
    ESP_ERROR_CHECK(enable_bar_graph());
    // enable_bar_graph() turns on the gpio pins, if it succeeds it returns ESP_OK else it returns ESP_FAIL
    // If the argument of ESP_ERROR_CHECK() is not equal ESP_OK, then an error message is printed on the console, and abort() is called. 
    

    while(1)
    {
        //blinks all the 8 leds 5 times
        for (int i = 0; i < 5; i++)
        {
            ESP_ERROR_CHECK(set_bar_graph(0xFF));
            //0xFF = 1111 1111(all leds are on)
            // setting values of all 8 leds to 1
            vTaskDelay(1000 / portTICK_RATE_MS);
            //delay of 1s
            ESP_ERROR_CHECK(set_bar_graph(0x00));
            //0x00 = 0000 0000(all leds are off)
            // setting values of all 8 leds to 0
            vTaskDelay(1000 / portTICK_RATE_MS);
            //delay of 1s
        }

        uint8_t var = 0x01;
        //0x01 = 0000 0001(only 8th led is on)
        // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.

        while(1)
        {   
            // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.
            if (var == 0x00)
            //if variable var is  0x00(i.e, all leds are off)
            //it checks whether the value of var has changed from 0x01 to 0x00.
            {
                var = 0x01;
           //setting var to  0x01(8th led is on)
            }            
            ESP_ERROR_CHECK(set_bar_graph(var));
            // var contains the data for the LEDs and it's been passed as an argument to set_bar_graph() function.
            var = var << 1;
            // It left shifts the values of var eg. from 0x01(means only the 8th led is on) it changes to 
            // 0x02 (means only the 7th LED is on). Similarly, the LED's are turned on one by one from the 8th to the 1st.
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            //delay of 1s
        }
    }
}
```
---
### Header Files : 
1] `#include "freertos/FreeRTOS.h`
    Inclusion of this sets configuration required to run freeRTOS On Esp-32
    Esp-32 uses freeRTOS to make better use of two high speed processors and manage numerous build in pheripherals
    **FreeRTOS**
    FreeRTOS is a real-time operating system kernel for embedded devices.
    FreeRTOS provides methods for multiple threads or tasks, mutexes, semaphores and software timers. Thread priorities are supported.

2] `#include "freeRtos/task.h`
    This header provides multitasking functionality.

### Functions 
1] `void app_main(void)`
    Program execution begins with app_main(), just like our good old main()

2] `ESP_ERROR_CHECK()`
    ESP_ERROR_CHECK macro serves similar purpose as assert, except that it checks esp_err_t value rather than a bool condition. If the argument of ESP_ERROR_CHECK is not equal ESP_OK, then an error message is printed on the console, and abort() function is called.

3] `enable_bar_graph()`
    It Enables the bar graph LED's GPIO pins.
    It looks for other GPIO tasks and initialize the Free GPIO's
    **Syntax**
    `esp_err_t enable_bar_graph()`	
    **Returns**
    esp_err_t returns ESP_OK if enabled correctly, and ESP_FAIL if it failed to initialise

4] `set_bar_graph()`
    Set the value of bar graph LED.
    **Syntax**
    `esp_err_t set_bar_graph(uint8_t data)`
    **Parameters**
    Data 8bit binary in hexadecimal form, i.e, the pattern that is needed to be shown on the bar graph LED
    **Returns**
    esp_err_t returns ESP_OK

5] `vTaskDelay()`
 This function helps us delay a task by a specified amount of time.The actual time that the task remains blocked depends on the tick rate.The constant `portTICK_PERIOD_MS` can be used to calculate real time from the tick rate - with the resolution of one tick period.

Example :
vTaskDelay(1000 / portTICK_PERIOD_MS)

portTICK_PERIOD_MS = 10ms
1000 / portTICK_PERIOD_MS = 100 ticks
100 * 10ms = 1 sec
Therefore a delay of 1 sec.

---
## Code (LED Blink in Fibonacci Series)
```C
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"

void app_main()
{
    ESP_ERROR_CHECK(enable_bar_graph());
    
    uint8_t var = 0xFF;
    uint8_t a =0;
    uint8_t b =1;
    uint8_t sum;
    while(1)
    {   
        var = 0xFF;
        ESP_ERROR_CHECK(set_bar_graph(var << (8-b)));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        for(int i=3;i<=7;i++)
        {
            var = 0xFF;
            sum = a+b;   
            ESP_ERROR_CHECK(set_bar_graph(var << (8-sum)));
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            a=b;
            b=sum;
        }
        a=0;
        b=1;
    }
}                
	



```
---





###References :
[More on Exception Handeling](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/error-handling.html)
[More on Unsigned integers](https://www.badprog.com/c-type-what-are-uint8-t-uint16-t-uint32-t-and-uint64-t)
[More on SRA Board Components](https://sravjti.in/sra-board-component/bar__graph_8h.html#ab10cdc6b54d4e647335eebb25dabd2f7)