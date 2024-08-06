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

    RotaryEncoder(int sw);
    ~RotaryEncoder();


    void SetPins(int sw);
    void SetCommand(const int (&command)[DIRECTIONS]);
    void SetSwitch(int sw);

    void EncoderRead(Encoder& enc);
    const void EncoderWrite(int direction);
    void EncoderActivate(Encoder& enc);
    void ResetPos(Encoder& enc);
    
    
    bool IsPressed();
    bool Clockwise(Encoder& enc);
    bool CntrClockwise(Encoder& enc);

    void Test(Encoder& enc);

    private:

    int _switchPin;
    int _switch;

    long _state{0};
    long _newPosition{0};
    long _oldPosition{0};
    int _command[DIRECTIONS];

};

#endif