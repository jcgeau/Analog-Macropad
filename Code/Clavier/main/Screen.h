#ifndef SCREEN_H
#define SCREEN_H



#include <_Teensy.h>
#include <Arduino.h>
#include <SPI.h>
#include <ST7735_t3.h>

#include "Constants.h"


class Screen {

    public:
    Screen();
    ~Screen();



    private:

    ST7735_t3 _tft = ST7735_t3(CS, DC, MOSI, SCK, RST);

    
    

};


#endif