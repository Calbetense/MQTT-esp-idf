#include <main.h>

#ifdef D_WIFI
static const char *TAG = "ESP32";
#endif

void wifi_init(){
    
    #ifdef D_WIFI
    ESP_LOGI(TAG, "Wifi init");
    #endif

    ESP_ERROR_CHECK(nvs_flash_init());

    tcpip_adapter_init();

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = SSID,
            .password = PASSWD,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));

    ESP_ERROR_CHECK(esp_wifi_start());
    ESP_ERROR_CHECK(esp_wifi_connect());
    

    #ifdef D_WIFI
    ESP_LOGI(TAG, "Wifi Connected");
    #endif
}



