# PWM (Pulse Width Modulation)
---
**Pulse-width modulation (PWM)**, or pulse-duration modulation (PDM), is a method of reducing the average power delivered by an electrical signal, by effectively chopping it up into discrete parts. 
Pulse Width Modulation, or PWM, is a technique for getting analog results with digital means. 
The average value of voltage (and current) fed to the load is controlled by turning the switch between supply and load on and off at a fast rate. The longer the switch is on compared to the off periods, the higher the total power supplied to the load.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8e/PWM%2C_3-level.svg/350px-PWM%2C_3-level.svg.png)

#Terms Related to PWM
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

## Duty Cycle
Duty cycle is the ratio of time a load or circuit is ON compared to the time the load or circuit is OFF. Duty cycle, sometimes called "duty factor," is expressed as a percentage of ON time. 
![](https://camo.githubusercontent.com/ff24881def52dcfe06c2fe38945f2f2a1f5586d855961978afc7b0cd8d95d31d/68747470733a2f2f7777772e6a61766174706f696e742e636f6d2f656d62656464656473797374656d2f696d616765732f70776d2d6176722d6d6963726f636f6e74726f6c6c6572322e706e67)

Example : A 60% duty cycle is a signal that is ON 60% of the time and OFF the other 40% of time.

![Duty Cycle Examples](https://camo.githubusercontent.com/d0855e0a936eef1086528a613492dc7bdc44deb191fbc2d47141eeb12fa9cb9a/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f622f62382f447574795f4379636c655f4578616d706c65732e706e67)

## Period
Period is a sum of both on and off times and period is calculated as shown in the equation below, where Toff represents the off-time and Ton represents the on-time of a signal.
![Formula for calculating Period](https://camo.githubusercontent.com/115ce559472d801b0d1c20721cc7fcc40310bea99975027fd97484e4335425db/68747470733a2f2f7777772e6a61766174706f696e742e636f6d2f656d62656464656473797374656d2f696d616765732f70776d2d6176722d6d6963726f636f6e74726f6c6c6572332e706e67)

#Applications of PWM
**PWM signals can be used for wide variety of applications**
1] PWM Techniques are used in Telecommunications for encoding purposes.

2] Pulse Width Modulation finds its use in controlling Brightness in Smart Lighting Systems 
![](https://camo.githubusercontent.com/a245ea0028ff10f4beb502a4e7a94e16fd0a213bfa6e487c2a9a9965f16cd84d/68747470733a2f2f6578706c6f7265656d6265646465642e636f6d2f77696b692f696d616765732f352f35342f305f4c5043313736385f50574d2e676966)
3] PWM-controlled device that clamps down hard on something.

4] Pin PWM header fan that helps to dissipate the heat from the motherboard.

5] Using the PWM technique and the switching mechanism we can control analog using the digital signal.

6] Pulse Width Modulation is also used to controls the speed of motors.
    (The speed of a DC motor can be controlled by varying its input voltage, i.e. by using PWM.The higher the duty cycle, the greater the average voltage being applied to the dc motor(High Speed) and the lower the duty cycle, the less the average voltage being applied to the dc motor(Low Speed)).

7] Pulse Width Modulation is used as a Volatge Regulator

![](https://camo.githubusercontent.com/b634e2d938e75c025364d39dd1b4f567b59594be6f4abdc9106a8078485d0b37/68747470733a2f2f7777772e6a61766174706f696e742e636f6d2f656d62656464656473797374656d2f696d616765732f70776d2d6176722d6d6963726f636f6e74726f6c6c6572342e706e67)

## Types of PWM
**1] Light Emitting Diode PWM (LEDPWM)**
LEDPWM has low and high speed mode and provides low (8-bit) resolution.

**2] Motor Controlled PWM (MCPWM)**
MCPWM has limited speed and provides high(16-bit) resolution.
Which means that mcpwm will count from 0 to (2^16)-1 in 1 sec i.e. 0 to 65535 in 1 sec.
It has two MCPWM peripherals. Each has 3 pairs of pwm output and can be used to control various types of motors.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAT4AAACfCAMAAABX0UX9AAACPVBMVEX///8AAADt7e3j4+PAwMDX19eIiIhycnLKysqCgoKoqKifn5+Pj4/w8PB7e3vg4OCvr6+6urpsbGzR0dH5///x+v////fa2tr6+vpkZGQpAACAten///X0/////88fAADr08CcXSfr///g/////+z//94AABEAACElAACEPgAAVY5eCQCETisAADXS+//ctZoAKUtJhcEAFD313s1CAABLkLg8PDzgwqiUXE/G+v9PT0/F6PMAAEEaAAAAABoxAAC84//AjWoAADw5AAB0IwC92fkfUJrr273/4LySyeaJxNYlJSVoXVxvfJDb7/uJnr7HnGyBp9Ozi36u0NqRYUWWfGdNWH+zmW43aKMwWHp8MgBcSlHH3fFkpb40UF9hUD80UXJ+MBMpF17PwqfowYpBMGpYL0tQZ2NRW3VnRFBsYUaoelvRq2XVvpIoJDBllsKNbUrru5Rhhb10XnC7lXqVu+BNTXqzfE+Ps6JlYn90VT04MUWvvcyczv6ycixhfqSnpZOSnrP0zptakayJX2B6ThdMFkQAAFDqr3o2Kg4TGzZmQBf/67yrgkO8o5qOg5d7hqYzN19cPiw3QUxwLii2ijtgJzUAL32bYQBDIwBQGgAdKlQuSUMlFgBiKgDPl1hVWC9mSQBBRy9RLhdofF6Gf0pvOgAmbZ2epG2Aai4ANlMjABuxysAzFyOinIEoUX+9wZ7HvoYAGHAoKABnbDdDQw8AL2stACeGeGkCcrRYIACXXDKXfH9BAB1fPTafymTgAAAMRElEQVR4nO2di18TRx7AZ/J+EiBPMEEMG1BBEFagJSAgYIjIEhREMCp3cCoFiiApRYMRqPWu4qu9nqL36Hk9cqWenr07qq3Xv+1mN/L4JLsuspMY2vl+PibBPGby3Z2Z37w2ABAIBAKBQCAQCAQCgUAgEAgEAoFAIBAIBAKBQCAQCAQCgUAg/MJwKDX4kG05G3YlPowY9Yghr8nU4UJv2GoujFUqLS5ydDj9iCBX4/ss45b1ybb8zkQ0enyfJUqa6FPhy4Xi56Yv/2h2djtT3QFAoBOAY8e7QgBQ3Uc2vCIV+oxyudwKZA5gQ//QPVtR22QWaYmlQl/1CZms52Rrrxv0PbN4TgWb0SO66fSGV6RC349nMs72u391HNC5LcD364GDQQAG4fvSEkuNPgvw/cZ5LrhwPsfbesE9NBQEgQ9Sre89PwDDoZFyMFp1GoyUV384BpwXK7aFPpP94hjY5R8fm/QPToBzPWPOS5PvQJ+zK+T7yDL18Un0R/X0JTd96fJ20HfFYAhbweBEYGaw8qrfdo6e9kXGU62v64z2bK+bOls6ZBqiTgXL7g63DHb8uB30neDu6KGaAt+Jc4ztnGv4zMxvU372HZFZUWPRfS3impqddpVNzM1/wpRsC31c+0Zd3wuc16Mu56fWwRvu1Ovzc3fjv+sE4591grIJ6mbEsh30GZWxeztq62gGALPFGeQerJFCfQu7Z8ACbED6wK1O53bQJw4JmwHRJxGiTxJEnySIPkkQfZIg+iRB9EmC6Nsyt4MC+hyOTbwbkz7qjmt76mudviugTwNrsuRib8ekr+yTGQF9Cqg3Y0kiDkz6yo4fK0X6ZPIEsiCEbTWZbz4H8eij7njuWpA+hzEeB5uLKoNyMyXhrcCkr0R9uRMYVYaMBHJQxtEJ+HryVSD/ePTlf6G6xwBFRkZ2POoaNhdtuljym6pPNgcefQsRQE27eAuvGaqzVrNLf16zzPC8BpO+YS8YDfEXXlSF6FarkMAXZ8ckzhCtgUdfdQtqPBjRpuPWDhAY43s/Fn3OO1ZAz/LrM64vgPDcY2y/92JIjyWVgYttVwOYi7p4nkll4NLa6wJX/ZgSS6m+vvfBwl4rzzOp1McewC93YEoslfqcaXH2LaTf2ec5mqFm+PUZZeuVX6AzmXUfGM3O6LDw63OsL7vynAtSf0ivui8vYpkbEwqbc3Sr9Tb1eU2/m+/9ePSN+EGXVyBsbjMoVx+PfvF5J47kWDDpu5J5uQXpMyUstrNnxiKuNy+6w6Pv+fy1E1bhsBmqNGkaNuddMA1ELEaVXhWPQc3G+2qRjGPSd1re3YLCZi1/8C7a99kCmPSdcC08EwybNaLrPbEV3sAOwbA5y4QjjTjw6KMMKpVA07GpA45Hn0+lnRVoOmRJWrEbr89kZ9Zu5XY76ugY7Xb2Xqa0ApvJbgVOpVxmN1nYp+OOJ7bxPocdpcMmzK6qMHF3JjYXVsAmjDKA3mF3cJmM3W7knQ5Y9cH7qG2vh+XAObkTwsIOSyNb6xZ1lMEQoJvgDJiDY43wBgOcJTAuBMamL38nRG3jKIQtwHcZpb7cAorZXCx7+/Z5wV/YdB/UBovhSXTG1cG4EPid6ttTCL1gHCJ9AdhrNl+Encib3H69SLH7JBitQ1+rETYgo35ALyZPXxNE0fWDwsIGaulg2D7w8BDTvByUD9TvHSlqsXXBWsZZ3GttLtxfinKZXvoeLXaC4T/+qZz686NS1FFQWMuQKnTEj/fdc3/54VdR5zc33I21f0UuP3ycNH31Z2sZT+75woZRWIn+poOgGQWM1NL9gbrTnr99Df0LcMxZfKUtRJWcTy99/X+PGpe0i+V59XtjozqTcF4zcHOf92qFd0+k5758KQoaa/9RUfqg/5uk6cv9uM4/fqMHNoygKoOjeTms6a6L0j+8zP/2yYGxceh3Frd/Vdn6z6fppe/Z6I1/QQ3S17Syqg+xPwRGC5807RgvetKEyu+hJ01PmkK7kqfvCDpS0cBGfWwuehmq67vnFcye3qeHCmzF84Hvnj8aSDN9ntyv7nseloOlogbUiJwKlb3+BvTDrw968+B5VJ837ivoelwrT6I+/8i3/+4cgQ2+3Cj6e7Sdae6PNbCBov88c420Pd5rsRVHFuB/Ty6kmT7XA1jpWSxH7cSy/tpl6OfqPgR1E64wtmJ4qIDVF4BRxwZ9tmPH8eprrS/0In3Oi7A98+nO5TV9cxBOgOo6OA+QPucSWwtu0Md2rt+pvuYV1whsWdj9EoCBRQgrwqilfV1+prjmEB5GjwpLF2Andf3wmj5fu9BMm1KdKZ6LeH3wNLX0HWqvWgDVjQrtBQYUP4rpow6go9m6G+XJdiAKbtUycxv0+b4vFdCnNIjO9m0JTON9k95JL78+M/r6OWJTlZjG+44NdAro06Aur17J84RE8OizlWR88KaZNqiOdVBscr6xZmydtmn5tBUotHpDAmouF1rsXTc8+ubGgHPaajQYZQlkwfXeOnWxqIX3/ZiGS2ezXniBwsCzu1UPYdXa2cduD8MEppm2oOBMm3zDKFH+k6PJ1PcJA1on+Auv3bA+1db4+DCO1DgE9MntLrbPvlbUppZLwevtc0a7ib8EbqLlpSTpc8SPDsSnj2oHo3jLK19Itj7nUhFqw8rg2qB2vsLlO8Vl3ncTwgjviDt2ffSrMLqdbF+VRtdXgvxw7HG1OiSQhnjgknR9tpJ9nL4dtM59W4dKZn6m8puiWfZ77Krw9kD+rOPW59vJdnj7KjbM69iuv2TvnFPsoAY/aaQvNA7P59Q/CoJd+7IWD55pQN2Qm4cBfaAy7vVOs8ZsER8udXiOtvAOnwroy51Ht3v2l+658LSuPwjoH06XQBhFVQd9J393oj6nRsOkm74JEIBH0DlXcJU7CzyLe9HXiMa9Pu+eZjgkEDbnrE8TVddU1XTwLS8R0ddXOD+Qe9iCDlv1YtTEfUDrzkR9I/OaSwy/PrPWtHbczD0rmjdXoptHVJ8fVHP6Sq9WNABBfRHLoMBEJRc260SusSF29u1nbCW1BUgf/fBl7Dk+fc/94D0BfRp2fVpshZ/ttl6nT/I874+FDah7Dv0J+qibK4Bumo97ed4V7VE/Cpu1QkvDMt7sT0BfPVf37S/oWy4Am9F3QYuaGYXWwHN5DS5szkhV2DwI+zOf5q4wG/UVhdjzfwqGLxbGNwB5EeD5CIXNjoSo2aiAbWrRC7wItLwPV1Akt/uZa7P6Xs+0yU3xyHWwbX2FGkYE9NnYiQ5UW7P6ypC+PUWloxDOALbnAGFC1J73vZbttPEVXpliE4ecX58tAD+rgYUh0Ly/lNPXVEkvHpplm45XL+CyNv4gjpxR1QQFwmZ9Wg8ZcOBfWZ+v0hpQLT856wa32930izCo1sb0aVWqDP4gaDsuDecgGxMkQfRJguiTBNEnCaJPEkTflmHHAN+5PpvZsj31UUMdAvrkWZtYooZJ3+inXgF9suREzbj0VYdfuQWHDNRZYh0PPPpsr3wdglsCa5Ix0YZL33B4eAYYVRpFAnqus56dirXNrdMadm2zwZxwUVUzl4s2fZouzvVMK33s2ma7OR6lDmU7RyHnMu7szm7n29aBSV9PWNndABQqnquxatkV1no7lwufOltooP+twaMvsAOA9/hn2pTZ60U3EJVNJW9fh22IAa0RocKrWy27nv+F6e+TO1y6NURbXqMlqdtiYoi2vOhobsstgQj6pwa+/05x3DceTa8NqTHE9dE/8dc6qdVX1i8wUf32YNqYkKkLW8X1UfznXor1BSK4zj1822KYgMBosylzPWK91avThzc/0/a2jOZk3LXy65Ovb83x5M7q9OnVdOSdcI8L6ENhc/bqVCWN4kBz8vS9aUsgrFK9vpQGhTKRlWb6rhhesDNtPBGXigubc1KyJbCd2xJoUGTFozBwuVCl6QK1vIiFm2nj31FZlSG2lRGTvpBj0o/C5qzMBNiDmKPf+i86CIHr7Mt4IbTKQHyaEl/hdfQIXUmjKjMZOwJ/VuN9Pj3bMG3HASuOd60vBtEnCaJPEkSfJIg+SRB9kiD6JEH0SYLokwTRJwmiTxJEnyS2rT7HL0+frEaNjewtZ9xYpcdGdip/4hPwXGp5q5i2PpiL8fdlU/oDswQCgUAgEAgEAoFAIBAIBAKBQCAQCAQCgUAgEAgEAoHwS+X/to9Wp5+eOGEAAAAASUVORK5CYII=)

---
#CODE

```C
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//Components
#include "sra_board.h"

// Select the mode needed by uncommenting its definition
#define MODE NORMAL_MODE
// #define MODE PARALLEL_MODE

void pwm_task(void *arg)
{

	if (MODE == NORMAL_MODE)
	{
		enable_motor_driver(a, NORMAL_MODE); // Enable motor driver A in Normal Mode

		// Make the Motors go forward & backward alternatively, at different PWM from 60 to 100
		while (1)
		{
			for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++)
			{
				// setting motor speed of MOTOR A0 in forward direction with duty cycle
				set_motor_speed(MOTOR_A_0, MOTOR_FORWARD, duty_cycle);

				// setting motor speed of MOTOR A1 in forward direction with duty cycle
				set_motor_speed(MOTOR_A_1, MOTOR_FORWARD, duty_cycle);

				// adding delay of 100ms
				vTaskDelay(100 / portTICK_PERIOD_MS);
			}

			// stopping the MOTOR A0
			set_motor_speed(MOTOR_A_0, MOTOR_STOP, 0);

			// stopping the MOTOR A1
			set_motor_speed(MOTOR_A_1, MOTOR_STOP, 0);

			// adding delay of 100ms
			vTaskDelay(100 / portTICK_PERIOD_MS);

			for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++)
			{
				// setting motor speed of MOTOR A0 in backward direction with duty cycle
				set_motor_speed(MOTOR_A_0, MOTOR_BACKWARD, duty_cycle);

				// setting motor speed of MOTOR A1 in backward direction with duty cycle
				set_motor_speed(MOTOR_A_1, MOTOR_BACKWARD, duty_cycle);

				// adding delay of 100ms
				vTaskDelay(100 / portTICK_PERIOD_MS);
			}

			// stopping the MOTOR A0
			set_motor_speed(MOTOR_A_0, MOTOR_STOP, 0);

			// stopping the MOTOR A1
			set_motor_speed(MOTOR_A_1, MOTOR_STOP, 0);

			// adding delay of 100ms
			vTaskDelay(100 / portTICK_PERIOD_MS);
		}
	}

	else if (MODE == PARALLEL_MODE)
	{
		enable_motor_driver(a, PARALLEL_MODE); // Enable motor driver A in Parallel Mode

		// Make the Motors go forward & backward alternatively, at different PWM from 60 to 100
		while (1)
		{
			for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++)
			{
				// setting motor speed of motor A in forward direction with duty cycle
				set_motor_speed(MOTOR_A_0, MOTOR_FORWARD, duty_cycle);

				// adding delay of 100ms
				vTaskDelay(100 / portTICK_PERIOD_MS);
			}

			// stopping the motor A
			set_motor_speed(MOTOR_A_0, MOTOR_STOP, 0);

			// adding delay of 100ms
			vTaskDelay(100 / portTICK_PERIOD_MS);

			for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++)
			{
				// setting motor speed of motor A in backward direction with duty cycle
				set_motor_speed(MOTOR_A_0, MOTOR_BACKWARD, duty_cycle);

				// adding delay of 100ms
				vTaskDelay(100 / 10);
			}

			// stopping the motor A
			set_motor_speed(MOTOR_A_0, MOTOR_STOP, 0);

			// adding delay of 100ms
			vTaskDelay(100 / portTICK_PERIOD_MS);
		}
	}
}
void app_main()
{
	// Basic Function for task creation
	xTaskCreate(&pwm_task, "pwm_task", 4096, NULL, 1, NULL);
}
```
## Expalanation

In `components/sra-board-component/src/motor_driver.c` you can see that the frequency is set to be 20KHz.
In the example duty cycle goes from 60 to 100 and then 0 and then from 60 to 100 in opposite direction for both  the modes.
For one pulse it takes 1/20 KHz secs i.e. 5x10^-5 sec (50 µs) 60% duty cycle means it will be on for 3x10^-5 sec  (30 µs ) and off for 100/(80 x 10^-6 ) i.e 1.25 µs + 20 µs .In the next iteration the value of duty cycle increases and in the last it becomes 100 % which means that signal is high for 5  µs and then a delay again for 1.25 µs. Same in opposite direction.

---

## Header Files

1] `#include<math.h>`
The math.h header defines various mathematical functions and one macro. 
2] `#include <time.h>`
The time.h header defines four variable types, two macro and various functions for manipulating date and time.
3] `#include <string.h>`
The string.h header defines one variable type, one macro, and various functions for manipulating arrays of characters.
4] `#include <stdlib.h>`
The stdlib.h header defines four variable types, several macros, and various functions for performing general functions.
5] `include "sra_board.h"`
Includes components of Sra Board
6] `#define MODE NORMAL_MODE`
Defining a macro, mode as normal_mode

## Functions

1] `enable_motor_driver(a,NORMAL_MODE) or enable_motor_driver(a,NORMAL_MODE)`

`esp_err_t enable_motor_driver_a(int mode)`	

Enables Motor driver A in Parallel or Normal Mode.

**Parameters**
mode : if mode = 1 is passed, motor driver is operated in parallel mode, if mode = 2 is passed, motor driver is operated in normal mode

**Returns** 
esp_err_t returns ESP_OK if motor driver initialised properly, else it returns ESP_ERR_INVALID_ARG

`esp_err_t enable_motor_driver_b(int mode)`	

Enables Motor driver B in Parallel or Normal Mode.

**Parameters**
mode : if mode = 1 is passed, motor driver is operated in parallel mode, if mode = 2 is passed, motor driver is operated in normal mode

**Returns** 
esp_err_t returns ESP_OK if motor driver initialised properly, else it returns ESP_ERR_INVALID_ARG

2] `set_motor_speed()`

Set the speed of motors.

**Syntax**
`esp_err_t set_motor_speed (int motor_id,int direction,float duty_cycle)`
 
**Parameters**
motor_id : set it as MOTOR_A_0, MOTOR_A_1, MOTOR_B_0, MOTOR_B_1 to select the appropriate motor to set its speed and direction

direction : set is as MOTOR_FORWARD for forward motion, MOTOR_BACKWARD for backward motion, MOTOR_STOP to stop the motor

duty_cycle : set the duty cycle of the motor driver PWM

**Returns** 
esp_err_t returns ESP_OK if speed correctly, ESP_FAIL if any error occurs

3] `xTaskCreate()`
Create a new task and add it to the list of tasks that are ready to run.
Each task requires RAM that is used to hold the task state, and used by the task as its stack. If a task is created using xTaskCreate() then the required RAM is automatically allocated from the FreeRTOS heap. 

Example:
``` C
void app_main()
{
    nvs_flash_init();
    xTaskCreate(&hello_task,"hello_task",2040,NULL,5,NULL);

}
```
This function takes 5 arguments. Forget the NULL ones for now. The first parameter is address of the function which execute, when this task is scheduled to run!. The second parameter hello_task is the name given to the task and this could be any name. It used to obtain handle or while debugging the task. The next parameter 2048 is the memory allocated to the task in word (2 Bytes).The next paramater is task priority.

4] `vTaskDelay()`

This function helps us delay a task by a specified amount of time.The actual time that the task remains blocked depends on the tick rate.The constant `portTICK_PERIOD_MS` can be used to calculate real time from the tick rate - with the resolution of one tick period.
    
    Example :
    vTaskDelay(1000 / portTICK_PERIOD_MS)
    PortTICK_PERIOD_MS = 10ms
    1000 / portTICK_PERIOD_MS = 100 ticks
    100 * 10ms = 1 sec
    Therefore a delay of 1 sec.

#Normal Mode VS Parallel Mode
![](https://lh4.googleusercontent.com/Yv3qCGZtVGild_xhu-7YbwICoVbGVKMOUazREo9x8XTOBwO_2oFRM9ARHYODa1-IhzgiKYwG3ItA8IpvJg2ET8-cjon1qcczAtB2M7_KmEGrt2Wf3GVTITzqDjj9uw1mSumK55sDbt5xPoa6Yb-D-YcNs0NjKHxGlpvU_Yg3CMS-c-GSuXbLBKgibT-FFi00bYRLwQ)
 
![](https://lh3.googleusercontent.com/QM-oOXo9PcOdHIypK5IDG5iTDdUvYOg7PwdzQ_FNflTk0hloO4LpCJCyuWwUQUPyb8COjeZVmqLjWO42QLwTbpwd-YXriouBtlZ7cAPJc6xWHPhsgkg0YLwm98pPtnOL4TCjcq1QWV6QrVTNU_JA70xK7O9zEFDhOFk8vydocFzZlju0fS1niI6ObzADGy1_3T7VoQ)


A Motor driver can control 2 motors. In normal mode motor driver controls 2 motors at a time giving a maximum current capacity of 1.2A to each motor.
Whereas in parallel mode the motor driver controls a single motor giving a max current capacity of 2.4A to single motor
Parallel mode is used for motors which require high current (Motors with Heavy Current Consumption)

## Motor Driver 

In our SRA Board we are using **TB6612FNG Motor Driver**.
![](https://lh4.googleusercontent.com/c4yAOR6bwPdzkB7Vy_ZfZecTnRTRjpjSXafJke_YRI2AxcxWPJC5mCWQ-lXbNGtt3lFq8ZOLJbpG92QkjNNW73PEd0t7KCF5wmH0kb4j836he4sVg0OHyJoonkHLrbGXm_kxfBEorD1ngSxLxb5vxnfT1ZxlCiCLkIqVAWNVGQggyGwhfX5DEsr0LqvR-G9g4UatKg)

In simplest terms, Motor Drivers are current amplifiers.
Their function  is to take a low-current control signal, and turn it into a  proportionally higher-current signal that can drive a motor.

The TB6612FNG H-Bridge is a small and inexpensive dual-channel H-Bridge controller. In this type of motor driver all of the input pins are on one side and all of the output and power pins are on the other side.  

## Minimum Duty Cycle Required

Minimum Duty Cycle required for rotation of single or both motor is around 50-55% Duty Cycle.
Minimum Duty Cycle is required to overcome the Frictional Forces (Static).
Once the Duty Cycle passes the Threshold Value, it is able to Static Frictional Forces and due to inertia the motor rotates for long period of time.
 