#include "AnalogKey.h"

AnalogKey::AnalogKey() {};

AnalogKey::AnalogKey(int port, int value) : _port(port), _value(value){



}

AnalogKey::~AnalogKey(){



}

void AnalogKey::SetPort(int pin){

  _port = pin;

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

  _buffer[_buffer_i] = map(analogRead(_port), _min, _max, 0, 255);

  _analogValue = BuffAvg();

  _buffer_i++;

}

void AnalogKey::KeyWrite(){

  //Keyboard.write(_value);

}

void AnalogKey::KeyPrint(){

  Serial.println(_value);

}

bool AnalogKey::IsPressed( int treshold){

  if(_analogValue < treshold){
    return true;
  }

  return false;

}

const int AnalogKey::GetValue(){
  return _analogValue;

}