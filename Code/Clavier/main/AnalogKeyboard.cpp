#include "AnalogKeyboard.h"


AnalogKeyboard::AnalogKeyboard(){

}

AnalogKeyboard::AnalogKeyboard(int dimensions): _dim(dimensions){

  for(auto i{0}; i < dimensions; i++){
    _key[i] = AnalogKey(ANALOG_PINS[i]);
    _key[i].SetMacro(MACROS[i]);
  }

  

}

AnalogKeyboard::~AnalogKeyboard(){


}

void AnalogKeyboard::ChangeMode(){



}

void AnalogKeyboard::KeyboardRead(){

  for(auto i{0}; i < _dim; i++){

    _key[i].KeyRead();

  }
  


}


void AnalogKeyboard::KeyboardPress(){
  
  for(auto i{0} ; i < _dim; i++){

    if(_key[i].IsPressed(_treshold)){
      _key[i].KeyPress();
    }else {
      _key[i].KeyRelease();
    }
  }

  }