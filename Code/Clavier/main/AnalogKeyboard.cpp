/**
 * @file AnalogKeyboard.cpp
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief Implementation of the AnalogKeyboard class
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "AnalogKeyboard.h"

Encoder ENCODERS[MAX_ENCODER_SIZE]{Encoder(2,1), Encoder(5,4)};

AnalogKeyboard::AnalogKeyboard(int dimensions = 0): _dim(dimensions){

  for(auto i{0}; i < dimensions; i++){
    _key[i] = AnalogKey(ANALOG_PINS[i]);
    _key[i].SetMacro(MACROS[i]);
  }

  for(auto i{0}; i < MAX_ENCODER_SIZE; i++ ){
    _encoder[i].SetPins(ENCODER_PINS[i]);
    _encoder[i].SetCommand(ENCODER_COMMAND[i]);
  }

  _screen.Idle("Macropad V01", CYAN);

}

AnalogKeyboard::~AnalogKeyboard(){

}


void AnalogKeyboard::Run(){
  
 // Read de tous les touches et encodeurs 
  this->KeyboardRead();
  this->KeyboardPress();

 // Menus
  this->Menu();

}

const unsigned int AnalogKeyboard::GetThreshold(){

  return _threshold;

}

const unsigned int AnalogKeyboard::GetDeadzone(){

  return _deadzone;

}

const enum State AnalogKeyboard::GetState(){

  return _state;

}

const enum Mode AnalogKeyboard::GetMode(){

  return _mode;

}



void AnalogKeyboard::ChangeState(enum State s){

  _state = s;

}

void AnalogKeyboard::ChangeMode(enum Mode m){

  _mode = m;

}

/// @brief Set a Key to be a joystick direction
/// @param all Index of the key in the _key array
void AnalogKeyboard::SetJoystick(int up, int down, int left, int right){

  _key[up].SetJoystick(Y_UPPER);
  _key[down].SetJoystick(Y_LOWER);
  _key[left].SetJoystick(X_LEFT);
  _key[right].SetJoystick(X_RIGHT);

}

/// @brief Increments or decrements an attribute, meant to be used with a rotary encoder hence the param direction 
/// @param direction Dictates whether to increment or decrement the setting  
/// @param setting A string to specify which attribute to modify
void AnalogKeyboard::IncrementSetting(bool direction, const char* setting){

  if(setting == "Threshold"){
    switch(direction){
      case 1:
      this->IncrementVariable(_threshold, INCREMENT, 0, 255);
      break;

      case 0:
      this->IncrementVariable(_threshold, -1*INCREMENT, 0, 255);
      break;

    }

  }


  if(setting == "Deadzone"){
    switch(direction){
      case 1:
      this->IncrementVariable(_deadzone, INCREMENT, 0, 255);
      break;

      case 0:
      this->IncrementVariable(_deadzone, -1*INCREMENT, 0, 255);
      break;

    }
  }

}

/// @brief Increments or decrement a variable in a specified range
/// @param increment  By how much we want to increment or decrement the value
/// @param min The minimum value the variable must not be lower than 
/// @param max The maximum value the variable must not be higher than
void AnalogKeyboard::IncrementVariable(unsigned int& variable, int increment, int min, int max){

  if( ( ( variable + increment ) >= min ) && ( ( variable + increment ) <= max ) ){
    variable += increment;
  }

}

/// @brief Handles every menu interaction with the GUI
void AnalogKeyboard::Menu(){

  if(_encoder[0].IsPressed()){

  this->OptionsMenu();

  this->ChooseModeMenu();

  this->ThresholdMenu();

  this->DeadzoneMenu();
    
  }

}

/// @brief Handles the interactions for the main options menu
void AnalogKeyboard::OptionsMenu(){

  this->ChangeState(OPTIONS);

  _screen.Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
  delay(MENU_DELAY);

  while(this->GetState() == OPTIONS){

    _encoder[0].EncoderRead(ENCODERS[0]);

    if(_encoder[0].Clockwise(ENCODERS[0])){
      _screen.OptionUp();
      _screen.Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    }

    if(_encoder[0].CntrClockwise(ENCODERS[0])){
      _screen.OptionDown();
      _screen.Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    }

    this->MenuState();
    this->MenuExit();

  }

}

/// @brief Handles the interactions for the choose mode menu
void AnalogKeyboard::ChooseModeMenu(){

  if(this->GetState() == CHOOSE_MODE){

    _screen.Options("Choose Mode", "Mode1", "Mode1", "Mode1", RED);
    delay(MENU_DELAY);

    while(this->GetState() == CHOOSE_MODE){

    _encoder[0].EncoderRead(ENCODERS[0]);

    if(_encoder[0].Clockwise(ENCODERS[0])){
      _screen.OptionUp();
      _screen.Options("Choose Mode", "Mode1", "Mode1", "Mode1", RED);
    }

    if(_encoder[0].CntrClockwise(ENCODERS[0])){
      _screen.OptionDown();
      _screen.Options("Choose Mode", "Mode1", "Mode1", "Mode1", RED);
    }

    this->MenuMode();

    }

  }

}

/// @brief Handles the interactions with the choosing the threshold menu
void AnalogKeyboard::ThresholdMenu(){

  if(this->GetState() == CHOOSE_THRESHOLD){
    _screen.Modify("Threshold", BLUE, this->GetThreshold());

    while(this->GetState() == CHOOSE_THRESHOLD){

      _encoder[0].EncoderRead(ENCODERS[0]);

      if(_encoder[0].Clockwise(ENCODERS[0])){
        this->IncrementSetting(true, "Threshold");
        _screen.Modify("Threshold", BLUE, this->GetThreshold());
      }

      if(_encoder[0].CntrClockwise(ENCODERS[0])){
        this->IncrementSetting(false, "Threshold");          
        _screen.Modify("Threshold", BLUE, this->GetThreshold());
      }
      
      this->MenuExit();

    }

  }

}

/// @brief Handles the interactions with the choosing the deadzone menu
void AnalogKeyboard::DeadzoneMenu(){

  if(this->GetState() == CHOOSE_DEADZONE){
    _screen.Modify("Deadzone", BLUE, this->GetDeadzone());

    while(this->GetState() == CHOOSE_DEADZONE){

      _encoder[0].EncoderRead(ENCODERS[0]);

      if(_encoder[0].Clockwise(ENCODERS[0])){
        this->IncrementSetting(true, "Deadzone");
        _screen.Modify("Deadzone", BLUE, this->GetDeadzone());
      }

      if(_encoder[0].CntrClockwise(ENCODERS[0])){
        this->IncrementSetting(false, "Deadzone");          
        _screen.Modify("Deadzone", BLUE, this->GetDeadzone());
      }

      this->MenuExit();

    }

  }

}

/// @brief Links a selection made on the GUI and changes the mode of the keyboard following that selection
void AnalogKeyboard::MenuMode(){

  if(_encoder[0].IsPressed()){
    switch(_screen.GetOptions()){

      case OPTION1:
      this->ChangeMode(MODE1);
      break;

      case OPTION2:
      this->ChangeMode(MODE2);
      break;

      case OPTION3:
      this->ChangeMode(MODE3);
      break;

    }
      
    this->ChangeState(NORMAL);
    _screen.Idle("Macropad V01", CYAN);
    delay(MENU_DELAY);

  }

}

/// @brief Links a selection made on the GUI and changes the state of the keyboard following that selection
void AnalogKeyboard::MenuState(){

  if(_encoder[0].IsPressed()){
    switch(_screen.GetOptions()){

      case OPTION1:
      this->ChangeState(CHOOSE_MODE);
      break;

      case OPTION2:
      this->ChangeState(CHOOSE_THRESHOLD);
      break;

      case OPTION3:
      this->ChangeState(CHOOSE_DEADZONE);
      break;

    }

  }

}

/// @brief Exits the menu to be back to normal fonctionning state
void AnalogKeyboard::MenuExit(){

  if(_encoder[1].IsPressed()){
    this->ChangeState(NORMAL);
    _screen.Idle("Macropad V01", CYAN);
  }

}

/// @brief Reads every AnalogKey and RotaryEncoder on the keyboard
void AnalogKeyboard::KeyboardRead(){

  for(auto i{0}; i < _dim; i++){
    _key[i].KeyRead();
  }
  
  for(auto i{0}; i < MAX_ENCODER_SIZE; i++){
    _encoder[i].EncoderRead(ENCODERS[i]);
  }

}

/// @brief Activate every AnalogKey and RotaryEncoder if any whas activated
void AnalogKeyboard::KeyboardPress(){
  
  for(auto i{0} ; i < _dim; i++){

    if(_key[i].IsPressed(_threshold)){
      _key[i].KeyPress();
    }else {
      _key[i].KeyRelease();
    }

  }

  for(auto i{0}; i < MAX_ENCODER_SIZE; i++){
    _encoder[i].EncoderActivate(ENCODERS[i]);
  }

}

/// @brief Moves the stick if a key is activated
void AnalogKeyboard::MoveJoystick(){

  for(auto i{0} ; i < _dim; i++){
    _key[i].MoveJoystick();
  }
 
}
