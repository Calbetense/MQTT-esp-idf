#pragma once

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include <esp_log.h>

#include <esp_wifi.h>
#include <esp_system.h>
#include <esp_event.h>
#include <esp_event_loop.h>
#include <nvs_flash.h>

#include <mqtt_client.h>

#include "secrets.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define SENSOR_DELAY    pdMS_TO_TICKS(1*1000)  // Time each sensor waits between samples 
#define CHANGE_DELAY    pdMS_TO_TICKS(5*1000)  // Time machine waits while changing between sensors

#define SLEEP           pdMS_TO_TICKS(2*60*1000) // 2 minutes

// General
#define D_G

#define D_WIFI
//WiFi Credentials in Secrets.h 

// MQTT
#define D_M

/* FreeRTOS event group to signal when we are connected & ready to make a request */
EventGroupHandle_t wifi_event_group;

/* The event group allows multiple bits for each event,
   but we only care about one event - are we connected
   to the AP with an IP? */
extern int CONNECTED_BIT;



/**** Declarations ****/
// WiFI
esp_err_t wifi_event_handler(void *ctx, system_event_t *event);
void initialise_wifi(void);

// MQTT
esp_mqtt_client_handle_t mqtt_init();
