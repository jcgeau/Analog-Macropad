#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <_Teensy.h>
#include <Arduino.h>
#include <Encoder.h>
#include <ST7735_t3.h>


// Constants needed for the rotary encoders
constexpr int MAX_ENCODER_SIZE{2};

constexpr int ENCODER_PINS[MAX_ENCODER_SIZE][3] { { 0, 1, 2 },
                                                  { 3, 4, 5 }};

constexpr int ENCODER_COMMAND[MAX_ENCODER_SIZE][3]{ { KEY_MEDIA_VOLUME_INC , KEY_MEDIA_VOLUME_DEC , KEY_MEDIA_MUTE },
                                                    { KEY_MEDIA_FAST_FORWARD , KEY_MEDIA_REWIND , KEY_MEDIA_PAUSE }};


// Constants need for the Screen
constexpr int SCREEN_RST{8};

constexpr int SCREEN_DC{9};

constexpr int SCREEN_CS{10};

constexpr int SCREEN_SCK{13};

constexpr int SCREEN_MOSI{11};


// Constants needed for the analog keys
constexpr int MAX_ANALOG_KEYBOARD_SIZE{12};

constexpr int MAX_MACRO_SIZE{6};

constexpr int BUFFER_SIZE{3};

constexpr int KEY_DELAY{500};

constexpr int KEYBOARD_DELAY{20};

constexpr int ANALOG_PINS[12] = {  A0, A1, A2, A3, 
                                  A4, A5, A6, A7, 
                                  A8, A15, A16, A17 };

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