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



AnalogKeyboard clavier(11);

void setup() {

  Serial.begin(38400);
  clavier.SetJoystick(0, 1, 9, 3);
  Joystick.Z(512);
  Joystick.Zrotate(512);
  Mouse.screenSize(1920, 1080);

}

void loop() {

  clavier.Run();  

}