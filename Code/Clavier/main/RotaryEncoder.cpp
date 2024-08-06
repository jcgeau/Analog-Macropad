#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(int sw){

  _switchPin = sw;
  pinMode(sw, INPUT_PULLUP);

}


RotaryEncoder::~RotaryEncoder(){}

void RotaryEncoder::SetPins(int sw){

  _switchPin = sw;
  pinMode(sw, INPUT_PULLUP);

}

void RotaryEncoder::SetCommand(const int (&command)[DIRECTIONS]){

  for(auto i = 0; i < DIRECTIONS; i++){
    _command[i] = command[i];
  }

}

void RotaryEncoder::SetSwitch(int sw){

  _switch = sw;

}

void RotaryEncoder::EncoderRead(Encoder& enc){

  _newPosition = enc.read();

  if (_newPosition != _oldPosition) {
   _oldPosition = _newPosition;
  }

  

}

void RotaryEncoder::EncoderActivate(Encoder& enc){

  if(this->Clockwise(enc)){
    EncoderWrite(CLOCKWISE);

  }else if (this->CntrClockwise(enc)) {
    EncoderWrite(CNTR_CLOCKWISE);
  }

}

const void RotaryEncoder::EncoderWrite(int direction){

  switch(direction){

    case CLOCKWISE:
      Keyboard.press(_command[CLOCKWISE]);
      Keyboard.release(_command[CLOCKWISE]);
      Serial.println(_command[CLOCKWISE]);
      break;

    case CNTR_CLOCKWISE:
      Keyboard.press(_command[CNTR_CLOCKWISE]);
      Keyboard.release(_command[CNTR_CLOCKWISE]);
      Serial.println(_command[CNTR_CLOCKWISE]);
      break;

  }

}

bool RotaryEncoder::IsPressed(){

  if(digitalRead(_switchPin) == LOW){
    return true;
  }

  return false;

}

bool RotaryEncoder::Clockwise(Encoder& enc){

  if(_newPosition >= 4){
    this->ResetPos(enc);
    return true;
  }

  return false;

}

bool RotaryEncoder::CntrClockwise(Encoder& enc){

  if(_newPosition <= -4){
    this->ResetPos(enc);
    return true;
  }

  return false;

}

void RotaryEncoder::ResetPos(Encoder& enc){

  enc.write(0);
  _newPosition = 0;
  _oldPosition = 0;


}

void RotaryEncoder::Test(Encoder& enc){

  this->EncoderRead(enc);
  //Serial.println(_newPosition);


  if(this->Clockwise(enc)){
    Serial.println("+1");
  }

  if(this->CntrClockwise(enc)){
    Serial.println("-1");
  }

}
