/**
 * @file RotaryEncoder.h
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief Implements the RotaryEncoder class
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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

void RotaryEncoder::ResetPos(Encoder& enc){

  enc.write(0);
  _newPosition = 0;
  _oldPosition = 0;

}

/// @brief Detects if and in what direction the encoder is rotated and updates the position
/// @param enc Encoder from the Encoder.h library
void RotaryEncoder::EncoderRead(Encoder& enc){

  _newPosition = enc.read();

  if (_newPosition != _oldPosition) {
   _oldPosition = _newPosition;
  }

}

/// @brief Presses and releases a key from the _comand array, the direction of the rotation
/// @param direction 
const void RotaryEncoder::EncoderWrite(enum Direction direction){

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

/// @brief Writes the command if encoder hits a pulse in a certain direction
/// @param enc Encoder from the Encoder.h library
void RotaryEncoder::EncoderActivate(Encoder& enc){

  if(this->Clockwise(enc)){
    EncoderWrite(CLOCKWISE);

  }else if (this->CntrClockwise(enc)) {
    EncoderWrite(CNTR_CLOCKWISE);
  }

}

/// @brief Detects if the switch on the encoder is engaged
/// @return If the encoder is engaged
bool RotaryEncoder::IsPressed(){

  if(digitalRead(_switchPin) == LOW){
    return true;
  }

  return false;

}

/**
 * @brief Detect if the position of the encoder is on another notch in the clockwise direction
 * 
 * Note* the encoder updates 4 times before settling into the mechanical notch hence why we have >= 4 & <= -4
 * 
 * @param enc Encoder from the Encoder.h library 
 * @return true 
 * @return false 
 */
bool RotaryEncoder::Clockwise(Encoder& enc){

  if(_newPosition >= 4){
    this->ResetPos(enc);
    return true;
  }

  return false;

}

/**
 * @brief Detect if the position of the encoder is on another notch in the counter clockwise direction
 * 
 * Note* the encoder updates 4 times before settling into the mechanical notch hence why we have >= 4 & <= -4
 * 
 * @param enc Encoder from the Encoder.h library 
 * @return true 
 * @return false 
 */
bool RotaryEncoder::CntrClockwise(Encoder& enc){

  if(_newPosition <= -4){
    this->ResetPos(enc);
    return true;
  }

  return false;

}

/// @brief Function for testing
/// @param enc Encoder from the Encoder.h library 
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
