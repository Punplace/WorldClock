/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TimeLib.h>

const char * MY_WIFI_SSID = "Shen Family Mansion";
const char * MY_WIFI_PASSWORD = "guest@shen";
const char * ntpServerName = "pool.ntp.org";
const int timeZone = 8;

WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &NTP_address);

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

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(Udp.localPort());
    Serial.println("waiting for sync");
    setSyncProvider(getNtpTime);
    setSyncInterval(10);
}

void loop()
{
    Check_WiFi_Status();    //check if WIFI still connected

    static time_t prevDisplay = 0; // when the digital clock was displayed
    if (timeStatus() != timeNotSet)
    {
        if (now() != prevDisplay)   //update the display only if time has changed
        {
            prevDisplay = now();
            digitalClockDisplay();
        }
    }
}

void digitalClockDisplay()
{
    // digital clock display of the time
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print(" ");
    Serial.print(day());
    Serial.print(".");
    Serial.print(month());
    Serial.print(".");
    Serial.print(year());
    Serial.println();
}

void printDigits(int digits)
{
    // utility for digital clock display: prints preceding colon and leading 0
    Serial.print(":");
    if (digits < 10)
        Serial.print('0');
    Serial.print(digits);
}

/*-------- NTP code ----------*/

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
    IPAddress ntpServerIP; // NTP server's ip address

    while (Udp.parsePacket() > 0) ; // discard any previously received packets
    Serial.println("Transmit NTP Request");
    // get a random server from the pool
    WiFi.hostByName(ntpServerName, ntpServerIP);
    Serial.print(ntpServerName);
    Serial.print(": ");
    Serial.println(ntpServerIP);
    sendNTPpacket(ntpServerIP);
    uint32_t beginWait = millis();
    while (millis() - beginWait < 1500) 
    {
        int size = Udp.parsePacket();
        if (size >= NTP_PACKET_SIZE) 
        {
            Serial.println("Receive NTP Response");
            Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
            unsigned long secsSince1900;
            // convert four bytes starting at location 40 to a long integer
            secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
            secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
            secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
            secsSince1900 |= (unsigned long)packetBuffer[43];
            return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
        }
    }
    Serial.println("No NTP Response :-(");
    return 0; // return 0 if unable to get the time
}

// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &NTP_address)
{
    // set all bytes in the buffer to 0
    memset(packetBuffer, 0, NTP_PACKET_SIZE);
    // Initialize values needed to form NTP request
    // (see URL above for details on the packets)
    packetBuffer[0] = 0b11100011;   // LI, Version, Mode
    packetBuffer[1] = 0;     // Stratum, or type of clock
    packetBuffer[2] = 6;     // Polling Interval
    packetBuffer[3] = 0xEC;  // Peer Clock Precision
    // 8 bytes of zero for Root Delay & Root Dispersion
    packetBuffer[12] = 49;
    packetBuffer[13] = 0x4E;
    packetBuffer[14] = 49;
    packetBuffer[15] = 52;
    // all NTP fields have been given values, now
    // you can send a packet requesting a timestamp:
    Udp.beginPacket(NTP_address, 123); //NTP requests are to port 123
    Udp.write(packetBuffer, NTP_PACKET_SIZE);
    Udp.endPacket();
}
