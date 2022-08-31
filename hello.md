#Hello World!
---
ESP32 is a system on a chip that integrates the following features:

    Wi-Fi (2.4 GHz band)

    Bluetooth

    Dual high performance Xtensa® 32-bit LX6 CPU cores

    Ultra Low Power co-processor

    Multiple peripherals

Powered by 40 nm technology, ESP32 provides a robust, highly integrated platform, which helps meet the continuous demands for efficient power usage, compact design, security, high performance, and reliability.

The Espressif Internet Development Framework (ESP-IDF) uses FreeRTOS to make better use of the two high speed processors and manage the numerous built-in peripherals. It is done by creating tasks. Let's look at the hello world, that looks a little different from the ones that you might have seen. 
Espressif provides basic hardware and software resources to help application developers realize their ideas using the ESP32 series hardware. The software development framework by Espressif is intended for development of Internet-of-Things (IoT) applications with Wi-Fi, Bluetooth, power management and several other system features.

To start using ESP-IDF on ESP32, install the following software:

        Toolchain to compile code for ESP32

        Build tools - CMake and Ninja to build a full Application for ESP32

        ESP-IDF that essentially contains API (software libraries and source code) for ESP32 and scripts to operate the Toolchain

![ESP-32 Process](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/what-you-need.png)

This hello world prints the string on UART (eventually on the computer terminal). We will first look at the ESP-IDF structure.

     
    +--esp-idf
    	|
    	|
    	+ - - components
    	|
    	+ - - docs
    	|
    	+ - - examples
    	|
    	+ - - make
    	|
    	+ - - tools

The components directory holds all the 'C' code for the ESP32. It contains all the 'components' that make up the ESP32. It includes Drivers for numerous peripherals, the bootloader, BT(bluetooth), freeRTOS etc.

---
# Code
``` C
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

void app_main(void)
{
    printf("Hello world!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU cores, WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Free heap: %d\n", esp_get_free_heap_size());

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
```
---
## Header Files
1] `#include "freertos/FreeRTOS.h`
    Inclusion of this sets configuration required to run freeRTOS On Esp-32
    Esp-32 uses freeRTOS to make better use of two high speed processors and manage numerous build in pheripherals
    **FreeRTOS**
    FreeRTOS is a real-time operating system kernel for embedded devices.
    FreeRTOS provides methods for multiple threads or tasks, mutexes, semaphores and software timers. Thread priorities are supported.

2] `#include "freeRtos/task.h`
    This header provides multitasking functionality.

3] `#include "sdkconfig.h"`
    This header file helps in saving the project in sdkconfig root directory.
    Applications developers can use make menuconfig build target to edit components’ configuration. This configuration is saved inside sdkconfig file in the project root directory. Based on sdkconfig, application build targets will generate sdkconfig.h file in the build directory, and will make sdkconfig options available to component makefiles.

4] `#include "esp_system.h"`
    This inclusion configures the peripherals in the ESP system. Think of it as system initialization. It's like setting up all the components of your bike, before you could fire the engine!

5] `#include "esp_spi_flash.h"`
    The spi_flash component contains APIs related to reading, writing, erasing, memory mapping data in the external SPI flash. It also has higher-level APIs which work with partitions defined in the partition table.

6] `CONFIG_IDF_TARGET`  ESP - 32


## Functions
1] `void app_main(void)`
    Program execution begins with app_main(), just like our good old main()

2] `vTaskDelay()`
    
This function helps us delay a task by a specified amount of time.The actual time that the task remains blocked depends on the tick rate.The constant `portTICK_PERIOD_MS` can be used to calculate real time from the tick rate - with the resolution of one tick period.
    
**Syntax**
void vTaskDelay(const TickType_t xTicksToDelay)

**Parameters**
xTicksToDelay : The amount of time, in tick periods, that the calling task should block.

**Example**
vTaskDelay(1000 / portTICK_PERIOD_MS)
PortTICK_PERIOD_MS = 10ms
1000 / portTICK_PERIOD_MS = 100 ticks
100 * 10ms = 1 sec
Therefore a delay of 1 sec.
    
3] `nvs_flash_init()`
    ESP-32 modules run code from external flash.Unless youre using the ESP-32 chip, the module/board maker will take care of the flash initialization and access.
    Non-volatile storage (NVS) library is designed to store key-value pairs in flash.

4] `xTaskCreate()`

Create a new task and add it to the list of tasks that are ready to run.
Each task requires RAM that is used to hold the task state, and used by the task as its stack. If a task is created using xTaskCreate() then the required RAM is automatically allocated from the FreeRTOS heap. 

**Syntax**
`static BaseType_t xTaskCreate(TaskFunction_t pvTaskCode, const char *constpcName, const uint32_t usStackDepth, void *constpvParameters, UBaseType_t uxPriority, TaskHandle_t *constpvCreatedTask)`

Example:
``` C
void app_main()
{
    nvs_flash_init();
    xTaskCreate(&hello_task,"hello_task",2040,NULL,5,NULL);

}
```

**Parameters**

pvTaskCode: Pointer to the task entry function. Tasks must be implemented to never return (i.e. continuous loop), or should be terminated using vTaskDelete function.

pcName: A descriptive name for the task. This is mainly used to facilitate debugging. Max length defined by configMAX_TASK_NAME_LEN - default is 16.

usStackDepth : The size of the task stack specified as the number of bytes. Note that this differs from vanilla FreeRTOS.

pvParameters: Pointer that will be used as the parameter for the task being created.

uxPriority : The priority at which the task should run. Systems that include MPU support can optionally create tasks in a privileged (system) mode by setting bit portPRIVILEGE_BIT of the priority parameter. For example, to create a privileged task at priority 2 the uxPriority parameter should be set to ( 2 | portPRIVILEGE_BIT ).

pvCreatedTask: Used to pass back a handle by which the created task can be referenced.

**Returns** 
pdPASS if the task was successfully created and added to a ready list, otherwise an error code defined in the file projdefs.h

**Explanation**
This function takes 5 arguments. Forget the NULL ones for now. The first parameter is address of the function which execute, when this task is scheduled to run!. The second parameter hello_task is the name given to the task and this could be any name. It used to obtain handle or while debugging the task. The next parameter 2048 is the memory allocated to the task in word (2 Bytes).The next paramater is task priority.

5]`fflush(stdout)`
fflush() is typically used for output stream only. Its purpose is to clear (or flush) the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream)

6] `esp_get_minimum_free_heap_size()` 
    Returns the minimum size of free heap memory that has ever been available (i.e., the smallest size of free heap memory in the applications lifetime).

7] `spi_flash_get_chip_size `
    Get flash chip size, as set in binary image header. Returns size of flash chip, in bytes .

8] `spi_flash_init()` 
    Initialize SPI flash access driver. This function must be called exactly once, before any other spi_flash_* functions are called. Currently this function is called from startup code. There is no need to call it from application code

9] `esp_restart()`
    It is used to software reset of the chip.When the function is called, execution of the program stops, both CPUs are reset, and the application is loaded by the bootloader and starts execution again.

##Structures
1] `esp_chip_info_t`
    The structure represents information about the chip. `esp_chip_info()` function fills `esp_chip_info_t` structure with information about the chip. This includes the chip revision, number of CPU cores, and a bit mask of features enabled in the chip.

    Public Members :
    
    1] esp_chip_model_t model
        Chip model, one of esp_chip_model_t

    2] uint32_t features
        Bit mask of CHIP_FEATURE_x feature flags

    3] uint16_t revision
        Chip revision number (in format MXX; where M - wafer major version, XX - wafer minor version)

    4] uint8_t cores
        Number of CPU cores

    5] esp_chip_info(&chip_info)
        Fill an esp_chip_info_t structure with information about the chip.
    
    6] esp_err_t esp_flash_get_size 
        Detect flash size based on flash ID. Returns ESP_OK on success or a flash error code if operation is failed.

## Important Concepts

### Flash Memory 
Flash memory is a non-volatile memory chip used for storage and for transfering data between a personal computer (PC) and digital devices. It has the ability to be electronically reprogrammed and erased. It is often found in USB flash drives, MP3 players, digital cameras and solid-state drives.

It is a type of nonvolatile memory that erases data in units called blocks and rewrites data at the byte level. 

### SPI (Serial Peripheral Interface)
Serial Peripheral Interface or SPI is a synchronous serial communication protocol, primarily used in embedded systems, that provides full – duplex communication at very high speeds.
Serial Peripheral Interface (SPI) is a master – slave type protocol that provides a simple and low cost interface between a microcontroller and its peripherals.When we say short distance communication, it often means communication with in a device or between the devices on the same board (PCB).

### Heap
Heap is a special Tree-based data structure in which the tree is a complete binary tree.
The advantages of heap memory are: Lifetime. Because the programmer now controls exactly when memory is allocated, it is possible to build a data structure in memory, and return that data structure to the caller. This was never possible with local memory, which was automatically deallocated when the function exited.


---
###References
https://exploreembedded.com/wiki/Hello_World_with_ESP32_Explained

https://www.freertos.org/a00127.html

https://demo-dijiudu.readthedocs.io/en/latest/api-reference/kconfig.html

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/

https://docs.espressif.com/projects/esp-idf/en/v3.3.3/api-reference/storage/spi_flash.html

https://www.freertos.org/a00125.html

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/misc_system_api.html#_CPPv415esp_chip_info_t

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/misc_system_api.html