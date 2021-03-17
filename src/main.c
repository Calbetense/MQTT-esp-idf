#include <main.h>

#ifdef D_G
static const char* TAG = "General";
#endif

void app_main() {

    #ifdef D_G
    ESP_LOGI(TAG, "Starting app");
    #endif

    char dato[sizeof(float)*2];

    initialise_wifi(); 
    vTaskDelay(5000 / portTICK_PERIOD_MS);    
    esp_mqtt_client_handle_t client = mqtt_init();


        /* initialize random seed: */
        srand (time(NULL));

    while(1){
        // Temperatura
        for (uint8_t i = 0; i < 10; i++)
        {
        ESP_LOGI(TAG, "\nSimulación de toma de muestra\n");
        vTaskDelay(SENSOR_DELAY);
        }
        
        /* generate random number between 18 and 34 */
        sprintf(dato, "%d", rand() % 16 + 18);
        ESP_LOGI(TAG, "Envío de dato, temp %s\n", dato);
        esp_mqtt_client_publish(client, "/iabs/petrolina/projetocamarao/bebedouro/bercario/agua/temperatura", dato, 0, 2, 0);
        vTaskDelay(CHANGE_DELAY);

        // O2
        for (uint8_t i = 0; i < 10; i++)
        {
        ESP_LOGI(TAG, "Simulación de toma de muestra\n");
        vTaskDelay(SENSOR_DELAY);
        }
        
        /* generate random number between 2 and 10 */
        sprintf(dato, "%d", rand() % 10 + 2);
        ESP_LOGI(TAG, "Envío de dato, DO %s\n", dato);
        esp_mqtt_client_publish(client, "/iabs/petrolina/projetocamarao/bebedouro/bercario/agua/oxigeniodissolvido", dato, 0, 2, 0);
        vTaskDelay(CHANGE_DELAY);

        // ORP
        for (uint8_t i = 0; i < 10; i++)
        {
        ESP_LOGI(TAG, "Simulación de toma de muestra\n");
        vTaskDelay(SENSOR_DELAY);
        }
        
        /* generate random number between 18 and 34 */
        sprintf(dato, "%d", rand() % 1200 - 600);
        ESP_LOGI(TAG, "Envío de dato, ORP %s\n", dato);
        esp_mqtt_client_publish(client, "/iabs/petrolina/projetocamarao/bebedouro/bercario/agua/orp", dato, 0, 2, 0);
        vTaskDelay(CHANGE_DELAY);

        vTaskDelay(SLEEP);
    }

}