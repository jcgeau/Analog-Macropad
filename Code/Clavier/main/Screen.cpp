#include "Screen.h"


Screen::Screen(){

  _tft.initR(INITR_BLACKTAB);
  _tft.setRotation(3);
  _tft.fillScreen(BLACK);
  

}

Screen::~Screen(){

}

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
  
}

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

void Screen::OptionUp(){

  if(_option != OPTION1){
    _option = _option - 1;
  }

}

void Screen::OptionDown(){

  if(_option != OPTION3){
    _option = _option + 1;
  }

}

void Screen::OptionsTest(){

  this->Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
  this->OptionsRectangle();

  for(auto i{0}; i < 2; i++){

    this->OptionDown();
    this->Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    this->OptionsRectangle();
    delay(1000);

  }

  for(auto i{0}; i < 2; i++){

    this->OptionUp();
    this->Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    this->OptionsRectangle();
    delay(1000);

  }

}

void Screen::Modify(const char *title, uint16_t color){

  _tft.setTextWrap(false);
  _tft.fillScreen(BLACK);
  _tft.setTextSize(2);

  _tft.setCursor(10, 10);
  _tft.setTextColor(color);
  _tft.println(title);

  _tft.drawRect( 125, 10,  20, 108, WHITE);
}

void Screen::ModifyRectangle(uint8_t val){

  _tft.setTextColor(WHITE);
  _tft.setCursor(10, 26);
  _tft.print(val);

  int val_map = map(val, 0, 255, 104, 12);
  _tft.fillRoundRect( 127, val_map, 16, 116 - val_map, 2, CYAN);


}

void Screen::ModifyTest(){
  
  uint8_t val = 0;

  this->Modify("Deadzone",  CYAN);
  this->ModifyRectangle(val);

  while(val < 255){
  val += 1;
  this->Modify("Deadzone",  CYAN);
  this->ModifyRectangle(val);
  delay(10);

  }

  while(val > 0){
  val -= 1;
  this->Modify("Deadzone",  CYAN);
  this->ModifyRectangle(val);
  delay(10);

  }


}
