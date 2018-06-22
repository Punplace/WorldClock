//http://kiki888.pixnet.net/blog/post/30727861-%E8%8B%B1%E6%96%87%E6%99%82%E9%96%93%E8%A1%A8%E7%A4%BA%E6%B3%95%28%E5%B9%BE%E9%BB%9E%E5%B9%BE%E5%88%86%E8%8B%B1%E6%96%87%29

#include <Adafruit_NeoPixel.h>

#define PIN D5
#define NUMBER 169
// Parameter 1 = number of pixels in Guan
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED Guan)
Adafruit_NeoPixel Guan = Adafruit_NeoPixel(NUMBER, PIN, NEO_RGB + NEO_KHZ800);

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

// {start #,>>1 -1<<,#word}
const int Good[] = {12, -1, 4};
const int Hi[] = {7, -1, 2};
const int Noon[] = {4, -1, 4};
const int Night[] = {13, 1, 5};
const int Morning[] = {19, 1, 7};
const int Louis[] = {38, -1, 5};
const int guan[] = {32, -1, 4};
const int two[] = {28, -1, 3};
const int Time[] = {39, 1, 4};
const int to[] = {44, 1, 2};
const int Happy[] = {47, 1, 5};
const int Birthday[] = {64, -1, 8};
const int Sleep[] = {56, -1, 5};
const int It[] = {65, 1, 2};
const int Is[] = {68, 1, 2};
const int Half[] = {71, 1, 4};
const int ten[] = {75, 1, 3};
const int Quarter[] = {90, -1, 7};
const int Twenty[] = {83, -1, 6};
const int five[] = {124, 1, 4};
const int To[] = {96, 1, 2};
const int Minute[] = {98, 1, 6};
const int Past[] = {116, -1, 4};
const int One[] = {111, -1, 3};
const int Three[] = {108, -1, 5};
const int Two[] = {117, 1, 3};
const int Four[] = {120, 1, 4};
const int Five[] = {124, 1, 4};
const int Pm[] = {128, 1, 2};
const int Six[] = {142, -1, 3};
const int Seven[] = {139, -1, 5};
const int Eight[] = {134, -1, 5};
const int Nine[] = {143, 1, 4};
const int Ten[] = {147, 1, 3};
const int Eleven[] = {150, 1, 6};
const int Twelve[] = {168, -1, 6};
const int Oclock[] = {161, -1, 6};

// {start #,>>1 -1<<,#word}
#define x 37
#define y 3
const int Items[x][y] = {
  {12, -1, 4}, // Good
  {7, -1, 2}, // Hi
  {4, -1, 4}, // Noon
  {13, 1, 5}, // Night
  {19, 1, 7}, // Morning
  {38, -1, 5}, // Louis
  {32, -1, 4}, // Guan
  {28, -1, 3}, // Two
  {39, 1, 4}, // Time
  {44, 1, 2}, // To
  {47, 1, 5}, // Happy
  {64, -1, 8}, // Birthday
  {56, -1, 5}, // Sleep
  {65, 1, 2}, // It
  {68, 1, 2}, // Is
  {71, 1, 4}, // Half
  {75, 1, 3}, // Ten
  {90, -1, 7}, // Quarter
  {83, -1, 6}, // Twenty
  {91, 1, 4}, // Five
  {96, 1, 2}, // To
  {98, 1, 6}, // Minute
  {116, -1, 4}, // Past
  {111, -1, 3}, // One
  {108, -1, 5}, // Three
  {117, 1, 3}, // Two
  {120, 1, 4}, // Four
  {124, 1, 4}, // Five
  {128, 1, 2}, // Pm
  {142, -1, 3}, // Six
  {139, -1, 5}, // Seven
  {134, -1, 5}, // Eight
  {143, 1, 4}, // Nine
  {147, 1, 3}, // Ten
  {150, 1, 6}, // Eleven
  {168, -1, 6}, // Twelve
  {161, -1, 6}, // Oclock
};

void setup() {
  Guan.begin();
  Guan.show(); // Initialize all pixels to 'off'
  clearall();
}

void loop() {
  //  rainbow(1);
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

