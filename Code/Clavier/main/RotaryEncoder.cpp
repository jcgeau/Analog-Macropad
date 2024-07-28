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

  if(_newPosition >= 4){
    EncoderWrte(CLOCKWISE);
    _newPosition = 0;
    _oldPosition = 0;

  }else if (_newPosition <= -4) {
    EncoderWrte(CNTR_CLOCKWISE);
    _newPosition = 0;
    _oldPosition = 0;
  }

}

const void RotaryEncoder::EncoderWrte(int direction){

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
