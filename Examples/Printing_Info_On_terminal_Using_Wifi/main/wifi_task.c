#include<stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"
#include "sra_board.h"
#include "tuning_websocket_server.h"

static const char* TAG = "Module"; 

void hello_print()
{
	while(1)
	{
		ESP_LOGI(TAG,"Modeling and Control of Two-Legged Wheeled Robot: \nIn this project, we will be building a two wheeled robot (with a hip and knee joint) which can balance at variable heights including a provision for jumping.\nMentees: Shreyas Patil, Arsh Ahmed Faisal Khan\nMentors: Marck, Ayush, Priyal");
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}

void app_main(void)
{
	start_websocket_server();
	start_wifi_logger();
	xTaskCreate(&hello_print, "hello print", 4096, NULL, 1, NULL);
}
