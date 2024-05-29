#include "AnalogKey.h"
#include "AnalogKeyboard.h"

#define KEYBOARD_DELAY 20

AnalogKeyboard clavier;


void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i < ANALOG_KEYBOARD_SIZE; i++){

    pinMode( (A0 + i) , INPUT );
  
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  clavier.KeyboardRead();
  clavier.KeyboardPrint();

  delay(KEYBOARD_DELAY);
}
