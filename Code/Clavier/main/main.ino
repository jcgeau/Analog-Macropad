#include "Constants.h"
#include "AnalogKeyboard.h"
#include "Screen.h"
#include "RotaryEncoder.h"
#include "AnalogKey.h"

AnalogKeyboard clavier(11);

void setup() {

  Serial.begin(38400);
  Serial.println("init");

}

void loop() {

  clavier.Run();  

}