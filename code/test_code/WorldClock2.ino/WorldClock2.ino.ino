/*---------------------------------------WS2812b------------------------------------------*/
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN D5
#define NUMBER 169
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(13, 13, PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

Adafruit_NeoPixel Guan = Adafruit_NeoPixel( NUMBER, PIN, NEO_GRB + NEO_KHZ800);

/*---------------------------------------red------------------------------------------*/
const uint16_t red[] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50,  51, 52, 53, 54, 55, 56, 57, 58, 59, 60,  61, 62, 63, 64, 65, 66, 67, 68, 69, 70,  71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
  81, 82, 83, 84, 85, 86, 87, 88, 89, 90,  91, 92, 93, 94, 95, 96, 97, 98, 99, 100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,  170,
  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,  197,  198,
  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,
  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,  253,  254,  255,
};
/*---------------------------------------green------------------------------------------*/
const uint16_t green[] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50,  51, 52, 53, 54, 55, 56, 57, 58, 59, 60,  61, 62, 63, 64, 65, 66, 67, 68, 69, 70,  71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
  81, 82, 83, 84, 85, 86, 87, 88, 89, 90,  91, 92, 93, 94, 95, 96, 97, 98, 99, 100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,  170,
  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,  197,  198,
  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,
  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,  253,  254,  255,
};
/*---------------------------------------blue------------------------------------------*/
const uint16_t blue[] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50,  51, 52, 53, 54, 55, 56, 57, 58, 59, 60,  61, 62, 63, 64, 65, 66, 67, 68, 69, 70,  71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
  81, 82, 83, 84, 85, 86, 87, 88, 89, 90,  91, 92, 93, 94, 95, 96, 97, 98, 99, 100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,  170,
  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,  197,  198,
  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,
  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,  253,  254,  255,
};
/*---------------------------------------Items------------------------------------------*/
// {start #,>>1 -1<<,#word}
#define x 35
#define y 3
const int Items[x][y] = {
  // ---------------------------------------------SayHello
  {12, -1, 4}, // Good 0
  {19, 1, 7}, // Morning 1
  {4, -1, 4}, // Noon 2
  {13, 1, 5}, // Night 3
  {7, -1, 2}, // Hi 4
  {38, -1, 5}, // Louis 5
  {32, -1, 4}, // Guan 6
  {39, 1, 4}, // Time 7
  {44, 1, 2}, // To 8
  {56, -1, 5}, // Sleep 9
  {47, 1, 5}, // Happy 10
  {64, -1, 8}, // Birthday 11
  // ---------------------------------------------ItIs
  {65, 1, 2}, // It 12
  {68, 1, 2}, // Is 13
  {96, 1, 2}, // To 14
  {116, -1, 4}, // Past 15
  {128, 1, 2}, // Pm 16
  {161, -1, 6}, // Oclock 17
  // ---------------------------------------------Hours
  {91, 1, 4}, // Five 18
  {75, 1, 3}, // Ten 19
  {90, -1, 7}, // Quarter 20
  {83, -1, 6}, // Twenty 21
  {71, 1, 4}, // Half 22
  // ---------------------------------------------Minutes
  {111, -1, 3}, // One 23
  {117, 1, 3}, // Two 24
  {108, -1, 5}, // Three 25
  {120, 1, 4}, // Four 26
  {124, 1, 4}, // Five 27
  {142, -1, 3}, // Six 28
  {139, -1, 5}, // Seven 29
  {134, -1, 5}, // Eight 30
  {143, 1, 4}, // Nine 31
  {147, 1, 3}, // Ten 32
  {150, 1, 6}, // Eleven 33
  {168, -1, 6}, // Twelve 34
};
/*---------------------------------------NTP------------------------------------------*/
//http://www.pool.ntp.org/zone/tw
//https://tttapa.github.io/ESP8266/Chap15%20-%20NTP.html
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#define Timezone +8
char ssid[] = "louisguan";  //  your network SSID (name)
char pass[] = "0989839679";       // your network password

unsigned int localPort = 2390;      // local port to listen for UDP packets
/* Don't hardwire the IP address or we won't get the benefits of the pool.
    Lookup the IP address for the host name instead */
//IPAddress timeServer(129, 6, 15, 28); // time.nist.gov NTP server
IPAddress timeServerIP; // time.nist.gov NTP server address
const char* ntpServerName = "1.tw.pool.ntp.org";
const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets
// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;
/*---------------------------------------DHT11------------------------------------------*/
#include <dht.h> // include DHT11 library  
#define dht_dpin D3 // DHT11 signal input form Pin4 
dht DHT; // initail DHT11 sensor
/*---------------------------------------DS3231------------------------------------------*/
#include <Wire.h> // IIC Comunication
#define DS3231_I2C_ADDRESS 0x68

byte decToBcd(byte val) {
  return ( (val / 10 * 16) + (val % 10) );
}

byte bcdToDec(byte val) {
  return ( (val / 16 * 10) + (val % 16) );
}

int LastH;
int LastM;
/*---------------------------------------Setup------------------------------------------*/
void setup() {
  Wire.begin(); // Join I2C bus
  Serial.begin(115200);
  Guan.begin();

  Guan.show(); // Initialize all pixels to 'off'
  clearall();

  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());

  NTPClientRTC();
  Serial.println("RTC Calibration in Setup Sucessfully");
  Serial.println("****************************************");
}
/*---------------------------------------Loop------------------------------------------*/
void loop() {
  //  rainbow(1);
  NTPClientRTC();
  displayTime();
  Humidity_temperature();
  //  test1();
  //  test2();
  clearall();
  ShowTime1();
}
/*---------------------------------------NTP W/ RTC calibration------------------------------------------*/
void NTPClientRTC() {
  //get a random server from the pool
  WiFi.hostByName(ntpServerName, timeServerIP);

  sendNTPpacket(timeServerIP); // send an NTP packet to a time server
  // wait to see if a reply is available
  delay(1000);

  int cb = udp.parsePacket();
  if (!cb) {
    Serial.println("no packet yet");
  }
  else {
    //    Serial.print("packet received, length=");//-------------------------------------------------------------
    //    Serial.println(cb);//-------------------------------------------------------------
    // We've received a packet, read the data from it
    udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

    //the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    //    Serial.print("Seconds since Jan 1 1900 = " );//-------------------------------------------------------------
    //    Serial.println(secsSince1900);//-------------------------------------------------------------

    // now convert NTP time into everyday time:
    //    Serial.print("Unix time = ");//-------------------------------------------------------------
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years:
    unsigned long epoch = secsSince1900 - seventyYears + Timezone * 60 * 60;
    // print Unix time:
    //    Serial.println(epoch);//-------------------------------------------------------------

    // print the year, month and day and dayofweek:
    Serial.print("The UTC date is ");       // UTC is the time at Greenwich Meridian (GMT)
    Serial.print(year(epoch)) ;
    Serial.print('/');
    if (month(epoch) < 10 ) {
      // In the first 10 seconds of each minute, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.print(month(epoch)) ;
    Serial.print('/');
    if (day(epoch) < 10 ) {
      // In the first 10 seconds of each minute, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.print(day(epoch));
    Serial.print(" ");
    switch (weekday(epoch)) {
      case 1:
        Serial.print("Sun.");
        break;
      case 2:
        Serial.print("Mon.");
        break;
      case 3:
        Serial.print("Tue.");
        break;
      case 4:
        Serial.print("Wed.");
        break;
      case 5:
        Serial.print("Thu.");
        break;
      case 6:
        Serial.print("Fri.");
        break;
      case 7:
        Serial.print("Sat.");
        break;
    }
    Serial.println("");
    // print the hour, minute and second:
    Serial.print("The UTC time is ");       // UTC is the time at Greenwich Meridian (GMT)
    if (((epoch  % 86400L) / 3600) < 10 ) {
      // In the first 10 minutes of each hour, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day)
    Serial.print(':');
    if ( ((epoch % 3600) / 60) < 10 ) {
      // In the first 10 minutes of each hour, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
    Serial.print(':');
    if ( (epoch % 60) < 10 ) {
      // In the first 10 seconds of each minute, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.println(epoch % 60); // print the second
    setDS3231time(epoch % 60, (epoch  % 3600) / 60, ((epoch  % 86400L) / 3600) , weekday(epoch), day(epoch), month(epoch), year(epoch) - 2000);
  }
  delay(100);  // wait ten seconds before asking for the time again
}
/*---------------------------------------DS3231 Display Time------------------------------------------*/
void displayTime() {
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  // send it to the serial monitor

  Serial.print("The DS3231 RTC is ");
  Serial.print("20");
  Serial.print(year, DEC);
  Serial.print("/");
  if (month < 10)  {
    Serial.print("0");
  }
  Serial.print(month, DEC);
  Serial.print("/");
  if (dayOfMonth < 10)  {
    Serial.print("0");
  }
  Serial.print(dayOfMonth, DEC);
  Serial.print(" ");
  switch (dayOfWeek) {
    case 1:
      Serial.print("Sun.");
      break;
    case 2:
      Serial.print("Mon.");
      break;
    case 3:
      Serial.print("Tue.");
      break;
    case 4:
      Serial.print("Wed.");
      break;
    case 5:
      Serial.print("Thu.");
      break;
    case 6:
      Serial.print("Fri.");
      break;
    case 7:
      Serial.print("Sat.");
      break;
  }
  Serial.print(" ");
  if (hour < 10)  {
    Serial.print("0");
  }
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute < 10)  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second < 10)  {
    Serial.print("0");
  }
  Serial.println(second, DEC);
  delay(300);
}
/*---------------------------------------DS3231 Led ShowTime1------------------------------------------*/
void ShowTime1() {
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  // send it to the serial monitor
#define delaydelay 250

  if (hour > 1 && hour <= 11) {
    ShowByShow(0, delaydelay); // GOOD
    ShowByShow(1, delaydelay); // morning
  }
  else if (hour > 11 && hour <= 17) {
    ShowByShow(0, delaydelay); // GOOD
    ShowByShow(2, delaydelay); // noon
  }
  else if (hour > 17 && hour <= 23) {
    ShowByShow(0, delaydelay); // GOOD
    ShowByShow(3, delaydelay); // night
  }
  else {
    ShowByShow(7, delaydelay); // time
    ShowByShow(8, delaydelay); // to
    ShowByShow(9, delaydelay); // sleep
  }

  ShowByShow(5, delaydelay); // Louis
  ShowByShow(6, delaydelay); // Guan
  ShowByShow(12, delaydelay); // it
  ShowByShow(13, delaydelay); // is


  switch (minute - minute % 5) {
    case 5:
      ShowByShow(18, delaydelay);
      break;
    case 10:
      ShowByShow( 19, delaydelay);
      break;
    case 15:
      ShowByShow( 20, delaydelay);
      break;
    case 20:
      ShowByShow( 21, delaydelay);
      break;
    case 25:
      ShowByShow( 21, delaydelay);
      ShowByShow( 18, delaydelay);
      break;
    case 30:
      ShowByShow( 22, delaydelay);
      break;
    case 35:
      ShowByShow( 22, delaydelay);
      ShowByShow( 18, delaydelay);
      break;
    case 40:
      ShowByShow( 22, delaydelay);
      ShowByShow( 19, delaydelay);
      break;
    case 45:
      ShowByShow( 20, delaydelay);
      ShowByShow( 22, delaydelay);
      break;
    case 50:
      ShowByShow( 22, delaydelay);
      ShowByShow( 21, delaydelay);
      break;
    case 55:
      ShowByShow( 22, delaydelay);
      ShowByShow( 20, delaydelay);
      ShowByShow( 18, delaydelay);
      break;
    case 0:
      ShowByShow( 17, delaydelay);
      break;
  }

  ShowByShow( 15, delaydelay); // past

  switch (hour) {

    case 1:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 2:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 3:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 4:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 5:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 6:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 7:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 8:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 9:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 10:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 11:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 12:
      ShowByShow( hour - 22, delaydelay);
      break;
    case 13:
      ShowByShow( 23, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 14:
      ShowByShow( 24, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 15:
      ShowByShow( 25, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 16:
      ShowByShow( 26, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 17:
      ShowByShow( 27, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 18:
      ShowByShow( 28, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 19:
      ShowByShow( 29, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 20:
      ShowByShow( 30, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 21:
      ShowByShow( 31, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 22:
      ShowByShow( 32, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 23:
      ShowByShow( 33, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
    case 0:
      ShowByShow( 34, delaydelay);
      ShowByShow( 16, delaydelay);
      break;
  }
  delay(5000);


}
/*------------------------------DHT11 display temperature amd humidity----------------------------*/
void Humidity_temperature() {
  DHT.read11(dht_dpin);

  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print("C,");

  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("%");

  delay(50);//每2500ms更新一次

}
/*---------------------------------------Set DS3231------------------------------------------*/
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year) {
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
/*---------------------------------------Read DS3231------------------------------------------*/
void readDS3231time(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year) {
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
/*---------------send an NTP request to the time server at the given address----------------*/
void sendNTPpacket(IPAddress& address) {
  //  Serial.println("sending NTP packet...");//-------------------------------------------------------------
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  udp.beginPacket(address, 123); //NTP requests are to port 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}

void test1() {
  for (int j = 0 ; j < x; j++) {
    for (int i = 0 ; i < Items[j][2]; i++) {
      Guan.setPixelColor(Items[j][0] + Items[j][1]*i, red[random(0, 255)], green[random(0, 255)], blue[random(0, 255)]);
      Guan.show();
      delay(500);
    }
    delay(1500);
    clearall();
  }
}

void test2() {
  for (int j = 0 ; j < x; j++) {
    for (int i = 0 ; i < Items[j][2]; i++) {
      Guan.setPixelColor(Items[j][0] + Items[j][1]*i, red[random(0, 255)], green[random(0, 255)], blue[random(0, 255)]);
    }
    Guan.show();
    delay(1500);
    clearall();
  }
}

void ShowByShow(int which, int bybytime) {
  for (int i = 0 ; i < Items[which][2]; i++) {
    Guan.setPixelColor(Items[which][0] + Items[which][1]*i, red[random(0, 255)], green[random(0, 255)], blue[random(0, 255)]);
    Guan.show();
    delay(bybytime);
  }
}

void ShowAllShow(int which) {
  for (int i = 0 ; i < Items[which][2]; i++) {
    Guan.setPixelColor(Items[which][0] + Items[which][1]*i, red[random(0, 255)], green[random(0, 255)], blue[random(0, 255)]);
  }
  Guan.show();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < Guan.numPixels(); i++) {
    Guan.setPixelColor(i, c);
    Guan.show();
    delay(wait);
  }
}

void clearall() {
  for (int i = 0; i < Guan.numPixels(); i++) {
    Guan.setPixelColor(i, Guan.Color(0, 0, 0));
  }
  Guan.show();
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < Guan.numPixels(); i++) {
      Guan.setPixelColor(i, Wheel((i + j) & 255));
    }
    Guan.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < Guan.numPixels(); i++) {
      Guan.setPixelColor(i, Wheel(((i * 256 / Guan.numPixels()) + j) & 255));
    }
    Guan.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return Guan.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return Guan.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return Guan.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
