/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <ESP8266WiFi.h>
#include "CUSTOM_SETTING.hpp"
#include "WorldClock_LED.hpp"
//#include <Adafruit_NeoPixel.h>
//#include "library/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp"

static bool WiFi_is_Connected;
inline void Check_WiFi_Status()
{
    for(int count = 0;count < 5, WiFi.status() != WL_CONNECTED;count++)
    {
        WiFi_is_Connected = false;
        Serial.print("connecting to ");
        Serial.print(MY_WIFI_SSID);
        Serial.println(" ...");
        delay(1000);
        if(WiFi.status() == WL_CONNECTED)
        {
            WiFi_is_Connected = true;
            Serial.print("WiFi connected, IP address : ");
            Serial.println(WiFi.localIP());
        }
        else
        {
            Serial.print("WiFi status: ");
            Serial.println(WiFi.status());
        }
    }
}

WorldClock_LED * LED_strip;

void setup()
{
    Serial.begin(115200);
    Serial.flush();

    // set WiFi
    //ETS_GPIO_INTR_DISABLE();
    WiFi.mode(WIFI_STA);
    WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASSWORD);
    Check_WiFi_Status();
    //ETS_GPIO_INTR_ENABLE();

    LED_strip = new WorldClock_LED(169, LED_WIRED_PIN, NEO_GRB + NEO_KHZ800);
    LED_strip->begin();
    LED_strip->show();
}

void loop()
{
////////////////////// check if WIFI still connected //////////////////////
    Check_WiFi_Status();

    int hour = random(0, 23);
    int minute = random(0, 59);
    int temperature = random(0, 99);
    int humidity = random(0, 99);
    LED_strip->clear();
    LED_strip->show_greeting(hour);
    LED_strip->show_minute(minute);
    LED_strip->show_hour(hour, minute);
    delay(2500);
    LED_strip->clear();
    LED_strip->show_temperature(temperature);
    delay(2500);
    LED_strip->clear();
    LED_strip->show_humidity(humidity);
    delay(2500);
}

