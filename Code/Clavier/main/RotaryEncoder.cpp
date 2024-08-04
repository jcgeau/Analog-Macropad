#include "core_pins.h"
#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(){}


RotaryEncoder::~RotaryEncoder(){}

void RotaryEncoder::SetPins(int sw, int clk, int dt){

  _switchPin = sw;
  pinMode(sw, INPUT_PULLUP);

  _encoder = Encoder(dt, clk);

}

void RotaryEncoder::SetCommand(const int (&command)[DIRECTIONS]){

  for(auto i = 0; i < DIRECTIONS; i++){
    _command[i] = command[i];
  }

}

void RotaryEncoder::SetSwitch(int sw){

  _switch = sw;

}

void RotaryEncoder::EncoderRead(){

    _newPosition = _encoder.read();

    if (_newPosition != _oldPosition) {
     _oldPosition = _newPosition;
      Serial.println(_newPosition);
    }

}

void RotaryEncoder::EncoderActivate(){

  if(this->Clockwise()){
    EncoderWrite(CLOCKWISE);

  }else if (this->CntrClockwise()) {
    EncoderWrite(CNTR_CLOCKWISE);

  }

}

const void RotaryEncoder::EncoderWrite(int direction){

  switch(direction){

    case CLOCKWISE:
      Keyboard.press(_command[CLOCKWISE]);
      Keyboard.release(_command[CLOCKWISE]);
      break;

    case CNTR_CLOCKWISE:
      Keyboard.press(_command[CNTR_CLOCKWISE]);
      Keyboard.release(_command[CNTR_CLOCKWISE]);
      break;

  }

}

bool RotaryEncoder::IsPressed(){

  if(digitalRead(_switchPin) == LOW){
    return true;
  }

  return false;

}

bool RotaryEncoder::Clockwise(){

  if(_newPosition >= 4){
    this->ResetPos();
    return true;
  }

  return false;

}

bool RotaryEncoder::CntrClockwise(){

  if(_newPosition <= -4){
    this->ResetPos();
    return true;
  }

  return false;

}

void RotaryEncoder::ResetPos(){

  _newPosition = 0;
  _oldPosition = 0;


}
