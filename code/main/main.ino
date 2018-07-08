/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <ESP8266WiFi.h>
#include "CUSTOM_SETTING.hpp"

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
}

void loop()
{
////////////////////// check if WIFI still connected //////////////////////
    Check_WiFi_Status();
}

