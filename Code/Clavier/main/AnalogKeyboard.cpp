#include "AnalogKeyboard.h"

AnalogKeyboard::AnalogKeyboard(int dimensions = 0): _dim(dimensions){

  for(auto i{0}; i < dimensions; i++){
    _key[i] = AnalogKey(ANALOG_PINS[i]);
    _key[i].SetMacro(MACROS[i]);
  }

  for(auto i{0}; i < MAX_ENCODER_SIZE; i++ ){
    _encoder[i].SetPins(ENCODER_PINS[i]);
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

void AnalogKeyboard::Menu(){

  if(_encoder[0].IsPressed()){

  this->OptionsMenu();

  this->ChooseModeMenu();

  this->ThresholdMenu();

  this->DeadzoneMenu();
    
  }

}

void AnalogKeyboard::OptionsMenu(){

  this->ChangeState(OPTIONS);

  _screen.Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
  delay(1000);

  while(this->GetState() == OPTIONS){

    _encoder[0].EncoderRead(ENCODERS[0]);

    if(_encoder[0].Clockwise()){
      _screen.OptionUp();
      _screen.Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    }

    if(_encoder[0].CntrClockwise()){
      _screen.OptionDown();
      _screen.Options("Options", "Mode", "Threshold", "Deadzone", CYAN);
    }

    this->MenuState();
    this->MenuExit();

  }

}

void AnalogKeyboard::ChooseModeMenu(){

  if(this->GetState() == CHOOSE_MODE){

    _screen.Options("Choose Mode", "Mode1", "Mode1", "Mode1", RED);

    while(this->GetState() == CHOOSE_MODE){

    _encoder[0].EncoderRead(ENCODERS[0]);

    if(_encoder[0].Clockwise()){
      _screen.OptionUp();
      _screen.Options("Choose Mode", "Mode1", "Mode1", "Mode1", RED);
    }

    if(_encoder[0].CntrClockwise()){
      _screen.OptionDown();
      _screen.Options("Choose Mode", "Mode1", "Mode1", "Mode1", RED);
    }

    this->MenuMode();

    }

  }

}

void AnalogKeyboard::ThresholdMenu(){

  if(this->GetState() == CHOOSE_THRESHOLD){
    _screen.Modify("Threshold", BLUE, this->GetThreshold());

    while(this->GetState() == CHOOSE_THRESHOLD){

      _encoder[0].EncoderRead(ENCODERS[0]);

      if(_encoder[0].Clockwise()){
        this->IncrementSetting(true, "Threshold");
        _screen.Modify("Threshold", BLUE, this->GetThreshold());
      }

      if(_encoder[0].CntrClockwise()){
        this->IncrementSetting(false, "Threshold");          
        _screen.Modify("Threshold", BLUE, this->GetThreshold());
      }
      
      this->MenuExit();
      
    }

  }

}

void AnalogKeyboard::DeadzoneMenu(){

  if(this->GetState() == CHOOSE_DEADZONE){
    _screen.Modify("Deadzone", BLUE, this->GetDeadzone());

    while(this->GetState() == CHOOSE_DEADZONE){

      _encoder[0].EncoderRead(ENCODERS[0]);

      if(_encoder[0].Clockwise()){
        this->IncrementSetting(true, "Deadzone");
        _screen.Modify("Deadzone", BLUE, this->GetDeadzone());
      }

      if(_encoder[0].CntrClockwise()){
        this->IncrementSetting(false, "Deadzone");          
        _screen.Modify("Deadzone", BLUE, this->GetDeadzone());
      }

      this->MenuExit();

    }

  }

}

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
      
    _screen.Idle("Macropad V01", CYAN);

  }

}

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

    _screen.Idle("Macropad V01", CYAN);

  }

}

void AnalogKeyboard::MenuExit(){

  if(_encoder[1].IsPressed()){
    this->ChangeState(NORMAL);
    _screen.Idle("Macropad V01", CYAN);
  }

}

void AnalogKeyboard::IncrementSetting(bool dir, const char* setting){

  if(setting == "Threshold"){
    switch(dir){
      case true:
      this->IncrementVariable(_threshold, INCREMENT, 0, 255);
      break;

      case false:
      this->IncrementVariable(_threshold, -1*INCREMENT, 0, 255);
      break;

    }

  }


  if(setting == "Deadzone"){
    switch(dir){
      case true:
      this->IncrementVariable(_deadzone, INCREMENT, 0, 255);
      break;

      case false:
      this->IncrementVariable(_deadzone, -1*INCREMENT, 0, 255);
      break;

    }
  }

}

void AnalogKeyboard::IncrementVariable(int variable, int increment, int min, int max){

  if( ( ( variable + increment ) >= min ) && ( ( variable + increment ) <= max ) ){
    variable += increment;
  }

}

const unsigned int AnalogKeyboard::GetThreshold(){

  return _threshold;

}

const unsigned int AnalogKeyboard::GetDeadzone(){

  return _deadzone;

}

void AnalogKeyboard::SetJoystick(int up, int down, int left, int right){

  _key[up].SetJoystick(Y_UPPER);
  _key[down].SetJoystick(Y_LOWER);
  _key[left].SetJoystick(X_LEFT);
  _key[right].SetJoystick(X_RIGHT);

}

void AnalogKeyboard::ChangeState(enum State s){

  _state = s;

}

const enum State AnalogKeyboard::GetState(){

  return _state;

}

void AnalogKeyboard::ChangeMode(enum Mode m){

  _mode = m;

}

const enum Mode AnalogKeyboard::GetMode(){

  return _mode;

}

void AnalogKeyboard::KeyboardRead(){

  for(auto i{0}; i < _dim; i++){
    _key[i].KeyRead();
  }
  
  for(auto i{0}; i < MAX_ENCODER_SIZE; i++){
    _encoder[i].EncoderRead(ENCODERS[i]);
  }

}

void AnalogKeyboard::KeyboardPress(){
  
  for(auto i{0} ; i < _dim; i++){

    if(_key[i].IsPressed(_threshold)){
      _key[i].KeyPress();
    }else {
      _key[i].KeyRelease();
    }

  }

  for(auto i{0}; i < MAX_ENCODER_SIZE; i++){
    _encoder[i].EncoderActivate();
  }

}

void AnalogKeyboard::MoveJoystick(){

  for(auto i{0} ; i < _dim; i++){
    _key[i].MoveJoystick();
  }
 
}
