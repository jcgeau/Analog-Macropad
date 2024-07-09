
#include "Constants.h"
#include "AnalogKey.h"
#include "AnalogKeyboard.h"

AnalogKeyboard clavier(2);


void setup() {

  pinMode(13, OUTPUT);
  Serial.begin(38400);

}

void loop() {

  clavier.KeyboardRead();
  clavier.KeyboardPress();
  delay(KEYBOARD_DELAY);

}