#include "AnalogKey.h"

AnalogKey::AnalogKey(){



}

AnalogKey::~AnalogKey(){



}

void AnalogKey::SetPort(int pin){

  _port = pin;

}

void AnalogKey::KeyRead(){

  _analogValue = map(analogRead(_port), _min, _max, 0, 255);

}

void AnalogKey::KeyWrite(){

  //Keyboard.write(_value);

}

void AnalogKey::keyPrint(){

  Serial.print(_value);

}