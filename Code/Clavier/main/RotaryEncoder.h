#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H


#include <_Teensy.h>
#include <Arduino.h>
#include <Encoder.h>

#include "Constants.h"


enum Direction{

  CLOCKWISE,
  CNTR_CLOCKWISE,
  DIRECTIONS

};

class RotaryEncoder {

    public:

    RotaryEncoder();
    ~RotaryEncoder();

    void SetPins(int sw, int clk, int dt);
    void SetCommand(const int (&command)[DIRECTIONS]);
    void SetSwitch(int sw);

    void EncoderRead();
    const void EncoderWrte(int direction);
    void EncoderActivate();

    private:

    int _switchPin;
    int _switch;

    Encoder _encoder = Encoder(0,0);
    long _newPosition{0};
    long _oldPosition{0};
    int _command[DIRECTIONS];

};


#endif