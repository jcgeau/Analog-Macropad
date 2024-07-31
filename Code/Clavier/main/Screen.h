#ifndef SCREEN_H
#define SCREEN_H



#include <_Teensy.h>
#include <Arduino.h>
#include <SPI.h>
#include <ST7735_t3.h>

#include "Constants.h"

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


enum Options {

  OPTION1,
  OPTION2,
  OPTION3

};

class Screen {

    public:
    Screen();
    ~Screen();

    void Options(const char *title, const char *option1, const char *option2, const char *option3, uint16_t color );
    void OptionsRectangle();
    void OptionUp();
    void OptionDown();

    void OptionsTest();

    void Modify(const char *title, uint16_t color);
    void ModifyRectangle(uint8_t val);
    
    void ModifyTest();

    private:

    enum Options _option{OPTION1};
    ST7735_t3 _tft = ST7735_t3(SCREEN_CS, SCREEN_DC, MOSI, SCK, SCREEN_RST);

    
    

};


#endif