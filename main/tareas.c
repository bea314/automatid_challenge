/* 1º Ejemplo básico con tareas.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"

void tarea1(void *pvParameter)
{
    while(1) {
      printf("Ejecutando tarea 1\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}

void tarea2(void *pvParameter)
{
    while(1) {
       printf("Ejecutando tarea 2\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}

void tarea3(void *pvParameter)
{
    while(1) {
      printf("Ejecutando tarea 3\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}

void tarea4(void *pvParameter)
{
    while(1) {
       printf("Ejecutando tarea 4\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}



void app_main()
{
    nvs_flash_init();
    xTaskCreate(&tarea1, "tarea1", 1024, NULL, 1, NULL);
    xTaskCreate(&tarea2, "tarea2", 1024, NULL, 2, NULL);
    xTaskCreate(&tarea3, "tarea3", 1024, NULL, 3, NULL);
    xTaskCreate(&tarea4, "tarea4", 1024, NULL, 4, NULL);


    vTaskStartScheduler();
}