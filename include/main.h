#pragma once

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include <esp_wifi.h>
#include <esp_system.h>
#include <esp_event.h>
#include <esp_event_loop.h>
#include <nvs_flash.h>

#include <mqtt_client.h>

#include "secrets.h"

// General
#define D_G

#define D_WIFI
//WiFi Credentials in Secrets.h 

// MQTT
#define D_M



/**** Declarations ****/
void wifi_init();

esp_mqtt_client_handle_t mqtt_init();