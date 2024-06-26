
#include "Constants.h"
#include "AnalogKey.h"
#include "AnalogKeyboard.h"

AnalogKey KEYS[] = {        AnalogKey(A0), 
                            AnalogKey(A1), 
                            AnalogKey(A2), 
                            AnalogKey(A3), 
                            AnalogKey(A4), 
                            AnalogKey(A5), 
                            AnalogKey(A6), 
                            AnalogKey(A7), 
                            AnalogKey(A8), 
                            AnalogKey(A9), 
                            AnalogKey(A10), 
                            AnalogKey(A11) };


//AnalogKey touche(A0);

void setup() {

  pinMode(13, OUTPUT);
  Serial.begin(38400);


}

void loop() {
  // put your main code here, to run repeatedly:

  KEYS[0].KeyRead();

  if( KEYS[0].IsPressed( 100 ) ) {
    digitalWrite(13, HIGH);
  }else {
    digitalWrite(13, LOW);
  }

  Serial.println( KEYS[0].GetValue() );

  delay(KEYBOARD_DELAY);

}
