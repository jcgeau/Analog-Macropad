
#include "Constants.h"
#include "AnalogKey.h"
#include "AnalogKeyboard.h"

AnalogKeyboard clavier(2);

//AnalogKey key(A0);

void setup() {
  
  //key.SetMacro(MACROS[0]);
  pinMode(13, OUTPUT);
  Serial.begin(38400);

}

void loop() {

  clavier.KeyboardRead();
  clavier.KeyboardPress();
  //key.KeyRead();
  //Serial.println(analogRead(A0));
  //Serial.println(key.GetValue());
  //Serial.println(key.GetMacro());

  /*
  if(key.IsPressed(100)){
      key.KeyPress();
      digitalWrite(13, HIGH);
    }else {
      key.KeyRelease();
      digitalWrite(13, LOW); 
    }
  */
  
  delay(KEYBOARD_DELAY);

}