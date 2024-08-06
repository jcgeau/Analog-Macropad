#include "Constants.h"
#include "AnalogKeyboard.h"
#include "Screen.h"
#include "RotaryEncoder.h"
#include "AnalogKey.h"


//AnalogKeyboard clavier(2);
//AnalogKey key(A0);

//Screen ecran;

//AnalogKeyboard clavier(3);
//Encoder a(2,1);
RotaryEncoder enc;
int test{0};

void setup() {
  
  //key.SetMacro(MACROS[0]);
  //pinMode(13, OUTPUT);
  Serial.begin(38400);
  //ecran.Idle("Macropad V01", CYAN); 
  //ecran.OptionsTest();

}

void loop() {

  //enc.EncoderRead(a);

  //ecran.ModifyTest();
  
  //clavier.Run();

  /*
  if(key.IsPressed(100)){
      key.KeyPress();
      digitalWrite(13, HIGH);
    }else {
      key.KeyRelease();
      digitalWrite(13, LOW); 
    }
  */
  

}