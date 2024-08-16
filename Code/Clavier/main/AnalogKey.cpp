/**
 * @file AnalogKey.cpp
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief Implementation of the AnalogKey class
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "AnalogKey.h"
#include "Macros.h"

AnalogKey::AnalogKey(int pin) : _pin(pin){

  pinMode(pin, INPUT);

}

AnalogKey::~AnalogKey(){

}

const int AnalogKey::GetValue(){
  return _analogValue;

}

void AnalogKey::SetJoystick(enum JoystickPos direction){

  _direction = direction;

}

void AnalogKey::SetMacro(const int (&macro)[MAX_MACRO_SIZE]) {

  for(auto i = 0; i < MAX_MACRO_SIZE; i++){
    _macro[i] = macro[i];
    Serial.println(_macro[i]);
  }

}

void AnalogKey::SetMessage(std::string s){

  _message = s;

}

void AnalogKey::SetButton(int button){

  _button = button;

}

/// @brief Puts Value of ADC reading in a [0, 255] range into the buffer. The Analog value is the average of the buffer 
void AnalogKey::KeyRead(){

  if(_buffer_i >= BUFFER_SIZE){
    _buffer_i = 0;
  }

  _buffer[_buffer_i] = map(analogRead(_pin), _min, _max, 0, 255);

  _analogValue = BuffAvg();

  _buffer_i++;

}

/// @brief Finds the average value of the _buffer array
/// @return The average value of the buffer
unsigned int AnalogKey::BuffAvg(){

  auto avg = 0u;

  for( int i =0 ; i<BUFFER_SIZE ; i++){
    avg += _buffer[i];

  }

  return (avg / BUFFER_SIZE);

}

/// @brief Finds if a key is pressed i.e. if the position is bellow a specified threshold
/// @param treshold Height under which a key is activated
/// @return If the key is pressed(true) or not(false)
bool AnalogKey::IsPressed( unsigned int treshold){

  if(_analogValue < treshold){
    return true;
  }

  return false;

}

/**
 * @brief Moves a joystick in the direction specified by the attribute _joystick
 * 
 * for more information onthe properties of joystick see: https://www.pjrc.com/teensy/td_joystick.html
 * 
 */
void AnalogKey::MoveJoystick(unsigned int deadzone){



  if(_analogValue < deadzone){

  switch (_direction){
    
    case NO:

      if((_analogValue < 160)){
        Joystick.button(_button, 1);
      }else{
        Joystick.button(_button, 0);
      }

      break;

    case Y_UPPER:
      Joystick.Y(map(_analogValue, 0, deadzone, 0, 512));
      break;

    case Y_LOWER:
      Joystick.Y(map(_analogValue, deadzone, 0, 512, 1023));
      break;

    case X_RIGHT:
      Joystick.X(map(_analogValue, deadzone, 0, 512, 1023));
      break;

    case X_LEFT:
      Joystick.X(map(_analogValue, 0, deadzone, 0, 512));
      break;

  }
  }

}

/// @brief Presses the keys found in the _macro array, _pressed is used to not press the value if the key is already held down
void AnalogKey::KeyPress(){

  if(_pressed == 0) {
    for(auto i = 0; ((_macro[i] != 0) && ( i < MAX_MACRO_SIZE)); i++ ){
      Keyboard.press(_macro[i]);
    }
    _pressed = 1;
  }

}

/// @brief Releases the keys found in the _macro array
void AnalogKey::KeyRelease(){


  for(auto i = 0; ((_macro[i] != 0) && ( i < MAX_MACRO_SIZE)); i++ ){
      Keyboard.release(_macro[i]);
    }
  _pressed = 0;

}

void AnalogKey::KeyPressMacro(int i){

  if(_pressed == 0) {
    doMacro(i);
    _pressed = 1;
  }

}

/// @brief Releases the keys found in the _macro array
void AnalogKey::KeyReleaseMacro(int i){

  _pressed = 0;

}

/// @brief function to test the behaviour of the key, serial.println() lets us visualise the AnalogValue on a serial plotter 
void AnalogKey::Test(){

  //Serial.println(analogRead(_pin));
  //this->KeyRead();
  //Serial.println(key.GetValue());


}