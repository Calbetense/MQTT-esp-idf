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

// General
#define D_G


// WIFI
#define SSID    "TESLA"
#define PASSWD  "tebcampillo123"

#define D_WIFI


// MQTT
#define D_M



/**** Declarations ****/
void wifi_init();

esp_mqtt_client_handle_t mqtt_init();