#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <_Teensy.h>
#include <Arduino.h>



constexpr int MAX_ANALOG_KEYBOARD_SIZE{12};

constexpr int MAX_MACRO_SIZE{6};

constexpr int BUFFER_SIZE{3};

constexpr int KEY_DELAY{500};

constexpr int KEYBOARD_DELAY{20};

constexpr int ANALOG_PINS[12] = {  A0, A1, A2, A3, 
                                  A4, A5, A6, A7, 
                                  A8, A9, A10, A11 };

constexpr int MACROS[MAX_ANALOG_KEYBOARD_SIZE][MAX_MACRO_SIZE] = { {MODIFIERKEY_CTRL, KEY_C, 0, 0, 0, 0},
                                                                    {MODIFIERKEY_CTRL, KEY_V, 0, 0, 0, 0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0},
                                                                    {0} };




#endif