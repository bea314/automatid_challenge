#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "wifi_handler.h"

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

    // Otras inicializaciones (Configurar pines GPIO, Inicializar periféricos...)
}

void app_main(void) {

	init_device();

    // Tareas

	// Schedule
	
	
}
