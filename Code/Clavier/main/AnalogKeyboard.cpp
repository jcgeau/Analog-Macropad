#include "AnalogKeyboard.h"

AnalogKeyboard::AnalogKeyboard(){


}

AnalogKeyboard::~AnalogKeyboard(){


}

void AnalogKeyboard::ChangeMode(){



}

void AnalogKeyboard::KeyboardRead(){

  for(int i = 0; i < KEYBOARS_SIZE; i++){

    _key[i].KeyRead()

  }



}

void AnalogKeyboard::KeyboardPrint(){


  for(int i = 0; i < KEYBOARS_SIZE; i++){

    if(_key[i].IsPressed())

    _key[i].KeyPrint()

  }



}

void AnalogKeyboard::KeyboardWrite(){






}