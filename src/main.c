#include <main.h>

#ifdef D_G
static const char* TAG = "General";
#endif

void app_main() {

    #ifdef D_G
    ESP_LOGI(TAG, "Starting app");
    #endif

    wifi_init();
    vTaskDelay(1500 / portTICK_PERIOD_MS);    
    esp_mqtt_client_handle_t client = mqtt_init();
    vTaskDelay(1500 / portTICK_PERIOD_MS);   

    esp_mqtt_client_publish(client, "Home/", "Hello, my dear", 0, 2, 0);

    while(1){
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }

}