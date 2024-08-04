#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H



#include <_Teensy.h>
#include <Arduino.h>
#include <Encoder.h>

#include "Constants.h"
#include "AnalogKey.h"
#include "RotaryEncoder.h"
#include "Screen.h"



enum State{
  NORMAL,
  OPTIONS,
  CHOOSE_MODE,
  CHOOSE_THRESHOLD,
  CHOOSE_DEADZONE

};

enum Mode {
    MODE1,
    MODE2,
    MODE3,
    MODE_SIZE
};

class AnalogKeyboard {

    public:

    AnalogKeyboard(int dimensions);
    ~AnalogKeyboard();


    void Run();
    void Menu();
    
    
    void IncrementSetting(bool dir, const char* setting);
    void IncrementVariable(int variable, int increment, int min, int max);

    const unsigned int GetThreshold();
    const unsigned int GetDeadzone();

    void SetJoystick(int up, int down, int left, int right);

    void ChangeState(enum State s);
    const enum State GetState();

    void ChangeMode(enum Mode m);
    const enum Mode GetMode();

    void MoveJoystick();
    void KeyboardRead();
    void KeyboardPress();

    private:
    
    AnalogKey _key[MAX_ANALOG_KEYBOARD_SIZE];
    int _dim;

    enum State _state = NORMAL;
    enum Mode _mode = MODE1;
    unsigned int _threshold{100};
    unsigned int _deadzone{20};
    RotaryEncoder _encoder[MAX_ENCODER_SIZE];
    Screen _screen;

};


#endif