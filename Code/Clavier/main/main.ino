#include "AnalogKey.h"
#include "AnalogKeyboard.h"

#define KEYBOARD_DELAY 20

AnalogKey touche(A0, 1);

void setup() {

  pinMode( A0 , INPUT );
  pinMode(13, OUTPUT);
  Serial.begin(38400);


}

void loop() {
  // put your main code here, to run repeatedly:

  touche.KeyRead();

  if( touche.IsPressed( 100 ) ) {
    digitalWrite(13, HIGH);
  }else {
    digitalWrite(13, LOW);
  }

  Serial.println( touche.GetValue() );

  delay(KEYBOARD_DELAY);

}
