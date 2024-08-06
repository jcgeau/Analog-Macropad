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
};


class AnalogKeyboard {

    public:

    AnalogKeyboard(int dimensions);
    ~AnalogKeyboard();


    void Run();
    void Menu();
    

    void OptionsMenu();
    void ChooseModeMenu();
    void ThresholdMenu();
    void DeadzoneMenu();

    void MenuExit();
    void MenuMode();
    void MenuState();
    
    void IncrementSetting(bool dir, const char* setting);
    void IncrementVariable(unsigned int& variable, int increment, int min, int max);

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
    
    enum State _state = NORMAL;
    enum Mode _mode = MODE1;

    AnalogKey _key[MAX_ANALOG_KEYBOARD_SIZE];
    int _dim;

    unsigned int _threshold{100};
    unsigned int _deadzone{20};

    RotaryEncoder _encoder[MAX_ENCODER_SIZE] = {RotaryEncoder(0), RotaryEncoder(3)};
    Screen _screen;

};


#endif