#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "nvs_flash.h"

#include "wifi_handler.h"


int aws_iot_demo_main( int argc, char ** argv );

void init_device() { // Función para inicializar diferentes aspectos del dispositivo

	// Initialize storage
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Connect to wireless AP
	connect_wifi();

    // Connect AWS IOT CORE
    aws_iot_demo_main(0,NULL);

    // Otras inicializaciones (Configurar pines GPIO, Inicializar periféricos...)
}

void app_main(void) {

	init_device();

    // Tareas

	// Schedule
	
	
}
