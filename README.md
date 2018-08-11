WorldClock
==========

## required
### hardware
* DS3231(clock)
* DHT11(temperature and humidity)
* NodeMCUv2 (1.0)
* WS2812 5050(LED)
    [工作原理](https://makeryan.wordpress.com/2017/11/20/%E4%B8%80%E5%80%8B%E6%9C%8B%E5%8F%8B%E7%9A%84%E9%A1%98%E6%9C%9B-ws2812-5050-5v-led/)
* wood plate 2mm
* wood plate 3mm
* acrylic plate

### tools
* laser cutter

### library
* [Adafruit NeoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation)
* [DHT-sensor-library](https://learn.adafruit.com/dht/using-a-dhtxx-sensor)

#### installation
1. Downaload ZIP file from GitHub
    * [adafruit/Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel/archive/master.zip)
    * [adafruit/Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor/archive/master.zip)
    * [adafruit/DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library/archive/master.zip)
    * [PaulStoffregen/Time](https://github.com/PaulStoffregen/Time/archive/master.zip)
    * [JChristensen/DS3232RTC](https://github.com/JChristensen/DS3232RTC/archive/master.zip)
2. Goto `Sketch > Include Library > Add .ZIP Library` and choose the file you just download.
