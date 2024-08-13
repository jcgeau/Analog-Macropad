/**
 * @file main.ino
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief main program to be flashed on the microcontroller
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Constants.h"
#include "AnalogKeyboard.h"
#include "Screen.h"
#include "RotaryEncoder.h"
#include "AnalogKey.h"

AnalogKeyboard clavier(11);

void setup() {

  Serial.begin(38400);
  clavier.Run();

}

void loop() {

  clavier.Run();  

}