
#include "Constants.h"
#include "AnalogKey.h"
#include "AnalogKeyboard.h"
#include "Screen.h"
#include "RotaryEncoder.h"


//AnalogKeyboard clavier(2);
AnalogKey key(A0);

Screen ecran;


void setup() {
  
  //key.SetMacro(MACROS[0]);
  //pinMode(13, OUTPUT);
  Serial.begin(38400);
  
  
}

void loop() {

  //ecran.OptionsTest();  
  key.Test();
  delay(50);
  //clavier.KeyboardRead();
  //clavier.KeyboardPress();

  /*
  if(key.IsPressed(100)){
      key.KeyPress();
      digitalWrite(13, HIGH);
    }else {
      key.KeyRelease();
      digitalWrite(13, LOW); 
    }
  */
  
  //delay(KEYBOARD_DELAY);

}