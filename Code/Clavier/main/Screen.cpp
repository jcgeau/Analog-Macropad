#include <stdint.h>
#include "Screen.h"


Screen::Screen(){

  _tft.initR(INITR_BLACKTAB);
  _tft.setRotation(3);
  _tft.fillScreen(BLACK);
  

}

Screen::~Screen(){

}

enum Options Screen::GetOptions(){

  return _option;

}

/// @brief Displays the idle menu
/// @param title Specifies the title on the idle screen
/// @param color Sets the color of the title
void Screen::Idle(const char* title, uint16_t color ){

  _tft.setTextWrap(false);
  _tft.fillScreen(BLACK);
  _tft.setTextSize(2);

  _tft.fillCircle(80, 64, 30, YELLOW);
  _tft.fillRoundRect(50, 74, 60, 30, 0, BLACK);
  _tft.fillRoundRect(50, 68, 70, 3, 0, BLACK);
  _tft.fillRoundRect(50, 63, 70, 2, 0, BLACK);
  _tft.fillRoundRect(50, 58, 70, 1, 0, BLACK);

  _tft.drawLine(0, 74, 160, 74,MAGENTA);
  _tft.drawLine(0, 80, 160, 80,MAGENTA);
  _tft.drawLine(0, 94, 160, 94,MAGENTA);
  _tft.drawLine(0, 110, 160, 110,MAGENTA);

  _tft.drawLine(80, 74, 80, 128,MAGENTA);
  _tft.drawLine(90, 74, 100, 128,MAGENTA);
  _tft.drawLine(100, 74, 120, 128,MAGENTA);
  _tft.drawLine(110, 74, 140, 128,MAGENTA);
  _tft.drawLine(120, 74, 160, 128,MAGENTA);
  _tft.drawLine(130, 74, 180, 128,MAGENTA);
  _tft.drawLine(140, 74, 200, 128,MAGENTA);
  _tft.drawLine(150, 74, 220, 128,MAGENTA);

  _tft.drawLine(70, 74, 60, 128,MAGENTA);
  _tft.drawLine(60, 74, 40, 128,MAGENTA);
  _tft.drawLine(50, 74, 20, 128,MAGENTA);
  _tft.drawLine(40, 74, 0, 128,MAGENTA);
  _tft.drawLine(30, 74, -20, 128,MAGENTA);
  _tft.drawLine(20, 74, -40, 128,MAGENTA);
  _tft.drawLine(10, 74, -60, 128,MAGENTA);

  _tft.setCursor(0,0);
  _tft.setTextColor(BLACK);
  _tft.print(title);

  _tft.setCursor( 80 - (_tft.getCursorX()/2), 10);
  _tft.setTextColor(color);
  _tft.println(title);

}

/// @brief Display a general options select menu
/// @param title title of the options select menu
/// @param option1 
/// @param option2 
/// @param option3 
/// @param color Sets the color of the title
void Screen::Options(const char *title, const char *option1, const char *option2, const char *option3, uint16_t color ){

  _tft.setTextWrap(false);
  _tft.fillScreen(BLACK);
  _tft.setTextSize(2);

  _tft.setCursor(0,0);
  _tft.setTextColor(BLACK);
  _tft.print(title);

  _tft.setCursor( 80 - (_tft.getCursorX()/2), 10);
  _tft.setTextColor(color);
  _tft.println(title);

  
  _tft.setTextColor(WHITE);

  _tft.setCursor(10 , _tft.getCursorY()+10);
  _tft.println(option1);

  _tft.setCursor(10 , _tft.getCursorY()+10);
  _tft.println(option2);

  _tft.setCursor(10 , _tft.getCursorY()+10);
  _tft.println(option3);
  
  this->OptionsRectangle();
  
}

/// @brief draws a rectangle around the option selection to give user feedback on the GUI of the options menu
void Screen::OptionsRectangle(){

  switch(_option){

    case OPTION1:
    _tft.drawRect(5, 31, 150, 26, WHITE);
    break;

    case OPTION2:
    _tft.drawRect(5, 57, 150, 26, WHITE);
    break;

    case OPTION3:
    _tft.drawRect(5, 83,  150, 26, WHITE);
    break;

  }

}

/// @brief Moves the selection up in the options menu
void Screen::OptionUp(){

  if(_option != OPTION1){
    _option = _option - 1;
  }

}

/// @brief Moves the selection down in the options menu
void Screen::OptionDown(){

  if(_option != OPTION3){
    _option = _option + 1;
  }

}

/// @brief Test for the Options menu
void Screen::OptionsTest(){

  this->Options("Options", "Mode", "Threshold", "Deadzone", CYAN);

  for(auto i{0}; i < 2; i++){

    this->OptionDown();
    this->Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    delay(1000);

  }

  for(auto i{0}; i < 2; i++){

    this->OptionUp();
    this->Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    delay(1000);

  }

}

/// @brief Displays a general modify menu (a menu where you change the value of a variable and a gauge is increased or decreased depending on the value of the variable)
/// @param title Title of modify menu 
/// @param color Color of the title
/// @param val value that is mapped on the gauge
void Screen::Modify(const char *title, uint16_t color, uint8_t val){

  _tft.setTextWrap(false);
  _tft.fillScreen(BLACK);
  _tft.setTextSize(2);

  _tft.setCursor(10, 10);
  _tft.setTextColor(color);
  _tft.println(title);

  _tft.drawRect( 125, 10,  20, 108, WHITE);

  this->ModifyRectangle(val);

}

/// @brief Draws a rectangle representing the gauge proportionnal to the value
/// @param val value
void Screen::ModifyRectangle(uint8_t val){

  _tft.setTextColor(WHITE);
  _tft.setCursor(10, 26);
  _tft.print(val);

  int val_map = map(val, 0, 255, 104, 12);
  _tft.fillRoundRect( 127, val_map, 16, 116 - val_map, 2, CYAN);


}

/// @brief Testing for the modify menu
void Screen::ModifyTest(){
  
  uint8_t val = 0;

  this->Modify("Deadzone",  CYAN, val);

  while(val < 255){
  val += 1;
  this->Modify("Deadzone",  CYAN, val);
  delay(10);

  }

  while(val > 0){
  val -= 1;
  this->Modify("Deadzone",  CYAN, val);
  delay(10);

  }


}