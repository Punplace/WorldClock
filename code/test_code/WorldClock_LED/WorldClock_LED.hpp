/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <Adafruit_NeoPixel.h>
#include <vector>

class WorldClock_LED : public Adafruit_NeoPixel
{
public:
    WorldClock_LED(void);
    WorldClock_LED(uint16_t n, uint8_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800);
    ~WorldClock_LED();

    void show_digits(uint8_t number);       // from 0 to 99
    void show_greeting(int hour);           // from 0 to 23
    void show_minute(int minute);           // from 0 to 59
    void show_hour(int hour, int minute);
    void show_temperature(int temperature);
    void show_humidity(int humidity);
private:
    int select_color();
    struct text_struct
    {
        uint8_t start, length;
        int8_t delta;
        text_struct(uint8_t start, int8_t delta, uint8_t length):
            start(start), delta(delta), length(length)
        {
        }
    };
    struct graph_struct
    {
        std::vector<uint8_t> grids;
        graph_struct(std::vector<uint8_t> grids):
            grids(grids)
        {
        }
        graph_struct(void);
    };
    static const text_struct normal_texts[12], hour_texts[14], minute_texts[9];
    static const graph_struct digit_in_ones[10], digit_in_tens[10];
    void show_text(const text_struct& text_s, bool progressively = true);
    void set_graph(const graph_struct& graph);
    void show_text_and_graph(const text_struct& text_s, int number);
};

WorldClock_LED::WorldClock_LED(void):
    Adafruit_NeoPixel()
{
}
WorldClock_LED::WorldClock_LED(uint16_t n, uint8_t p, neoPixelType t):
    Adafruit_NeoPixel(n, p, t)
{
}
WorldClock_LED::~WorldClock_LED()
{
}
void WorldClock_LED::show_digits(uint8_t number)
{
    set_graph(digit_in_tens[int(number / 10)]);
    set_graph(digit_in_ones[int(number % 10)]);
    show();
}
void WorldClock_LED::set_graph(const graph_struct& graph)
{
    for(uint8_t grid:graph.grids)
    {
        setPixelColor(grid, select_color());
    }
}
int WorldClock_LED::select_color()
{
    return Color(random(0, 255), random(0, 255), random(0, 255));
}
void WorldClock_LED::show_text(const text_struct& text_s, bool progressively)
{
    for(int i = 0;i < text_s.length;i++)
    {
        setPixelColor(text_s.start + text_s.delta * i, select_color());
        if(progressively)
        {
            show();
            delay(250);
        }
    }
}
void WorldClock_LED::show_greeting(int hour)
{
    if(hour >= 1 && hour <= 11)
    {
        show_text(normal_texts[0]); //GOOD
        show_text(normal_texts[1]); //MORNING
    }
    else if(hour > 11 && hour <= 17)
    {
        show_text(normal_texts[0]); //GOOD
        show_text(normal_texts[2]); //NOON
    }
    else if(hour > 17 && hour <= 23)
    {
        show_text(normal_texts[0]); //GOOD
        show_text(normal_texts[3]); //NIGHT
    }
    else
    {
        show_text(normal_texts[7]); //TIME
        show_text(normal_texts[8]); //TO
        show_text(normal_texts[9]); //SLEEP
    }
}
void WorldClock_LED::show_minute(int minute)
{
    bool over_half_hour = false;
    minute = minute - minute % 5;
    if(minute > 30)
    {
        over_half_hour = true;
        minute = 60 - minute;
    }
    show_text(minute_texts[0]); //IT
    show_text(minute_texts[1]); //IS
    if(!minute)
        return;
    switch(minute)
    {
        case 5:
            show_text(minute_texts[4]); //FIVE
        break;
        case 10:
            show_text(minute_texts[5]); //TEN
        break;
        case 15:
            show_text(minute_texts[6]); //QUARTER
        break;
        case 20:
            show_text(minute_texts[7]); //TWENTY
        break;
        case 25:
            show_text(minute_texts[7]); //TWENTY
            show_text(minute_texts[4]); //FIVE
        break;
        case 30:
            show_text(minute_texts[8]); //HALF
        break;
    }
    if(over_half_hour)
        show_text(minute_texts[2]); //TO
    else
        show_text(minute_texts[3]); //PAST
}
void WorldClock_LED::show_hour(int hour, int minute)
{
    bool is_afternoon = false;
    if(hour >= 12)
        is_afternoon = true;
    hour = hour % 12;
    if(!hour)
        hour = 12;
    show_text(hour_texts[hour]);

    minute = minute - minute % 5;
    if(!minute)
        show_text(hour_texts[0]);   //OCLOCK

    if(is_afternoon)
        show_text(hour_texts[13]);  //PM
}
void WorldClock_LED::show_temperature(int temperature)
{
    show_text_and_graph(normal_texts[10], temperature);
}
void WorldClock_LED::show_humidity(int humidity)
{
    show_text_and_graph(normal_texts[11], humidity);
}
void WorldClock_LED::show_text_and_graph(const text_struct& text_s, int number)
{
    show_text(text_s, false);
    show();
    delay(1000);
    show_digits(number);
}
const WorldClock_LED::text_struct WorldClock_LED::normal_texts[12]
{
    {12, -1, 4},    // 00 GOOD
    {19, 1, 7},     // 01 MORNING
    {4, -1, 4},     // 02 NOON
    {13, 1, 5},     // 03 NIGHT
    {7, -1, 2},     // 04 HI
    {38, -1, 5},    // 05
    {32, -1, 4},    // 06
    {39, 1, 4},     // 07 TIME
    {44, 1, 2},     // 08 TO
    {56, -1, 5},    // 09 SLEEP
    {168, -1, 13},  // 10 TEMPERATURE
    {12, -1, 13},   // 11 HUMIDITY
};
const WorldClock_LED::text_struct WorldClock_LED::minute_texts[9]
{
    {65, 1, 2},     // 00 IT
    {68, 1, 2},     // 01 IS
    {96, 1, 2},     // 02 TO
    {116, -1, 4},   // 03 PAST
    {91, 1, 4},     // 04 FIVE
    {75, 1, 3},     // 05 TEN
    {90, -1, 7},    // 06 QUARTER
    {83, -1, 6},    // 07 TWENTY
    {71, 1, 4},     // 08 HALF
};
const WorldClock_LED::text_struct WorldClock_LED::hour_texts[14]
{
    {161, -1, 6},   // 00 Oclock
    {111, -1, 3},   // 01 One
    {117, 1, 3},    // 02 Two
    {108, -1, 5},   // 03 Three
    {120, 1, 4},    // 04 Four
    {124, 1, 4},    // 05 Five
    {142, -1, 3},   // 06 Six
    {139, -1, 5},   // 07 Seven
    {134, -1, 5},   // 08 Eight
    {143, 1, 4},    // 09 Nine
    {147, 1, 3},    // 10 Ten
    {150, 1, 6},    // 11 Eleven
    {168, -1, 6},   // 12 Twelve
    {128, 1, 2},    // 13 Pm
};
const WorldClock_LED::graph_struct WorldClock_LED::digit_in_tens[10]
{
    {{14, 15, 16, 17, 38, 39, 64, 65, 33, 44, 59, 70, 91, 116, 117, 142, 96, 111, 122, 137, 144, 145, 146, 147, }},
    {{33, 44, 59, 70, 96, 111, 122, 137, }},
    {{14, 15, 16, 17, 33, 44, 59, 70, 89, 88, 87, 86, 91, 116, 117, 142, 144, 145, 146, 147, }},
    {{14, 15, 16, 17, 33, 44, 59, 70, 89, 88, 87, 86, 96, 111, 122, 137, 144, 145, 146, 147, }},
    {{38, 39, 64, 65, 33, 44, 59, 70, 89, 88, 87, 86, 96, 111, 122, 137, }},
    {{14, 15, 16, 17, 38, 39, 64, 65, 89, 88, 87, 86, 96, 111, 122, 137, 144, 145, 146, 147, }},
    {{14, 15, 16, 17, 38, 39, 64, 65, 89, 88, 87, 86, 91, 116, 117, 142, 96, 111, 122, 137, 144, 145, 146, 147, }},
    {{14, 15, 16, 17, 38, 39, 64, 65, 33, 44, 59, 70, 96, 111, 122, 137, }},
    {{14, 15, 16, 17, 38, 39, 64, 65, 33, 44, 59, 70, 89, 88, 87, 86, 91, 116, 117, 142, 96, 111, 122, 137, 144, 145, 146, 147, }},
    {{14, 15, 16, 17, 38, 39, 64, 65, 33, 44, 59, 70, 89, 88, 87, 86, 96, 111, 122, 137, 144, 145, 146, 147, }},
};
const WorldClock_LED::graph_struct WorldClock_LED::digit_in_ones[10]
{
    {{21, 22, 23, 24, 31, 46, 57, 72, 26, 51, 52, 77, 98, 109, 124, 135, 103, 104, 129, 130, 151, 152, 153, 154, }},
    {{26, 51, 52, 77, 103, 104, 129, 130, }},
    {{21, 22, 23, 24, 26, 51, 52, 77, 82, 81, 80, 79, 98, 109, 124, 135, 151, 152, 153, 154, }},
    {{21, 22, 23, 24, 26, 51, 52, 77, 82, 81, 80, 79, 103, 104, 129, 130, 151, 152, 153, 154, }},
    {{31, 46, 57, 72, 26, 51, 52, 77, 82, 81, 80, 79, 103, 104, 129, 130, }},
    {{21, 22, 23, 24, 31, 46, 57, 72, 82, 81, 80, 79, 103, 104, 129, 130, 151, 152, 153, 154, }},
    {{21, 22, 23, 24, 31, 46, 57, 72, 82, 81, 80, 79, 98, 109, 124, 135, 103, 104, 129, 130, 151, 152, 153, 154, }},
    {{21, 22, 23, 24, 31, 46, 57, 72, 26, 51, 52, 77, 103, 104, 129, 130, }},
    {{21, 22, 23, 24, 31, 46, 57, 72, 26, 51, 52, 77, 82, 81, 80, 79, 98, 109, 124, 135, 103, 104, 129, 130, 151, 152, 153, 154, }},
    {{21, 22, 23, 24, 31, 46, 57, 72, 26, 51, 52, 77, 82, 81, 80, 79, 103, 104, 129, 130, 151, 152, 153, 154, }},
};

