#include "AnalogKeyboard.h"


AnalogKeyboard::AnalogKeyboard(){

}

AnalogKeyboard::AnalogKeyboard(int dimensions): _dim(dimensions){

  for(auto i{0}; i < dimensions; i++){
    _key[i] = AnalogKey(ANALOG_PINS[i]);
    _key[i].SetMacro(MACROS[i]);
  }

  for(auto i{0}; i < MAX_ENCODER_SIZE; i++ ){
    _encoder[i] = Encoder(ENCODER_PINS[i][0], ENCODER_PINS[i][1], ENCODER_PINS[i][2]);
  }

}

AnalogKeyboard::~AnalogKeyboard(){

}

void AnalogKeyboard::SetJoystick(int up, int down, int left, int right){

  _key[up].SetJoystick(Y_UPPER);
  _key[down].SetJoystick(Y_LOWER);
  _key[left].SetJoystick(X_LEFT);
  _key[right].SetJoystick(X_RIGHT);

}

void AnalogKeyboard::ChangeMode(){


}

void AnalogKeyboard::KeyboardRead(){

  for(auto i{0}; i < _dim; i++){
    _key[i].KeyRead();
  }
  
  for(auto i{0}; i < MAX_ENCODER_SIZE; i++){
    _encoder.EncoderRead();
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

  for(auto i{0}; i < MAX_ENCODER_SIZE; i++){
    _encoder.EncoderActivate();
  }

}

void AnalogKeyboard::MoveJoystick(){

  for(auto i{0} ; i < _dim; i++){
    _key[i].MoveJoystick();
  }
 
}
