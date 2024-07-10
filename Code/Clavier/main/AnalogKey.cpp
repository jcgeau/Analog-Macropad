#include "AnalogKey.h"

AnalogKey::AnalogKey() {}

AnalogKey::AnalogKey(int pin) : _pin(pin){

  pinMode(pin, INPUT);

}

AnalogKey::~AnalogKey(){



}

void AnalogKey::SetMacro(const int (&macro)[MAX_MACRO_SIZE]) {

  for(auto i = 0; i < MAX_MACRO_SIZE; i++){
    _macro[i] = macro[i];
    Serial.println(_macro[i]);
  }

}

unsigned int AnalogKey::BuffAvg(){

  auto avg = 0u;

  for( int i =0 ; i<BUFFER_SIZE ; i++){
    avg += _buffer[i];

  }

  return (avg / BUFFER_SIZE);

}

void AnalogKey::KeyRead(){

  if(_buffer_i >= BUFFER_SIZE){
    _buffer_i = 0;
  }

  _buffer[_buffer_i] = map(analogRead(_pin), _min, _max, 0, 255);

  _analogValue = BuffAvg();

  _buffer_i++;

}

void AnalogKey::KeyPress(){

  if(_pressed == 0) {
    for(auto i = 0; ((_macro[i] != 0) && ( i < MAX_MACRO_SIZE)); i++ ){
      Keyboard.press(_macro[i]);
    }
    _pressed = 1;
  }

}

void AnalogKey::KeyRelease(){


  for(auto i = 0; ((_macro[i] != 0) && ( i < MAX_MACRO_SIZE)); i++ ){
      Keyboard.release(_macro[i]);
    }
  _pressed = 0;

}


bool AnalogKey::IsPressed( unsigned int treshold){

  if(_analogValue < treshold){
    return true;
  }

  return false;

}

const int AnalogKey::GetMacro(){
  return {_macro[0]};

}

const int AnalogKey::GetValue(){
  return _analogValue;

}