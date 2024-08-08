/**
 * @file RotaryEncoder.h
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief Represents and dictates the behaviour of a single rotary encoder
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <_Teensy.h>
#include <Arduino.h>
#include <Encoder.h>

#include "Constants.h"

/// @brief Used to specify the direction when using the _command array
enum Direction{

  CLOCKWISE,
  CNTR_CLOCKWISE,
  DIRECTIONS

};

class RotaryEncoder {

    public:

    RotaryEncoder(int sw);
    ~RotaryEncoder();

    /// Setters
    void SetCommand(const int (&command)[DIRECTIONS]);
    void SetSwitch(int sw);
    void ResetPos(Encoder& enc);


    /// Reading inputs 
    void EncoderRead(Encoder& enc);
    

    /// Writing to ouputs 
    const void EncoderWrite(enum Direction direction);
    void EncoderActivate(Encoder& enc);


    ///  Detection of a press or a rotation
    bool IsPressed();
    bool Clockwise(Encoder& enc);
    bool CntrClockwise(Encoder& enc);


    /// Testing 
    void Test(Encoder& enc);


    private:

    /// Attributes for the switch
    int _switchPin;
    int _switch;

    /// Attributes used for the Encoder.h library implementation
    long _newPosition{0};
    long _oldPosition{0};

    /// Macro for the encoder in each direction
    int _command[DIRECTIONS];

};

#endif