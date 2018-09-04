/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */
# pragma once

// LED setting
#define LED_WIRED_PIN D5

// DHT setting
#define DHTPIN D3     // what digital pin we're connected to
// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// WiFi setting
const char * MY_WIFI_SSID = "WIFI_SSID";
const char * MY_WIFI_PASSWORD = "WIFI_PASSWORD";

// NTP server
const char * ntpServerName = "pool.ntp.org";
const int timeZone = 8;
#define LocalPort 8888      // local port to listen for UDP packets

#define USE_NTP_SYNC_IN_LOOP
#define SYNC_NTP_LOOP_FREQUENCY 10  // after how many loop
//#define USE_NTP_SYNC_TIMER    // still can't working
//#define SYNC_NTP_TIMER_FREQUENCY 30000  // after how many milliseconds
#define USE_SERIAL_TIME_SYNC

