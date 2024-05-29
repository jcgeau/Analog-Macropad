#include "AnalogKeyboard.h"

AnalogKeyboard::AnalogKeyboard(){

  for(int i = 0; i< ANALOG_KEYBOARD_SIZE; i++){
    _key[i] = AnalogKey( (A0 + i) , ('a' + i) );
  }

}

AnalogKeyboard::~AnalogKeyboard(){


}

void AnalogKeyboard::ChangeMode(){



}

void AnalogKeyboard::KeyboardRead(){

  for(int i = 0; i < ANALOG_KEYBOARD_SIZE; i++){

    _key[i].KeyRead();

  }



}

void AnalogKeyboard::KeyboardPrint(){


  for(int i = 0; i < ANALOG_KEYBOARD_SIZE; i++){

    if(_key[i].IsPressed(_treshold)){

      _key[i].KeyPrint();
      delay(KEY_DELAY);

    }
  }

}

void AnalogKeyboard::KeyboardWrite(){

  for(int i = 0; i < ANALOG_KEYBOARD_SIZE; i++){

    if(_key[i].IsPressed(_treshold)){

      _key[i].KeyWrite();
      delay(KEY_DELAY);

    }
  }

  }