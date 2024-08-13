/**
 * @file AnalogKeyboard.h
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief Class that represent the whole keyboard
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

#include <_Teensy.h>
#include <Arduino.h>
#include <Encoder.h>

#include "Constants.h"
#include "AnalogKey.h"
#include "RotaryEncoder.h"
#include "Screen.h"

/**
 * @brief State of the keyboard. used for menu navigation on the GUI screen
 * 
 */
enum State{
  NORMAL,
  OPTIONS,
  CHOOSE_MODE,
  CHOOSE_THRESHOLD,
  CHOOSE_DEADZONE
};

/**
 * @brief The Mode of the keyboard represents which macro profile is curently being used
 * 
 */
enum Mode {
    MODE1,
    MODE2,
    MODE3,
};


class AnalogKeyboard {

    public:

    AnalogKeyboard(int dimensions);
    ~AnalogKeyboard();

    /// Getters 
    const unsigned int GetThreshold();
    const unsigned int GetDeadzone();
    const enum State GetState();
    const enum Mode GetMode();


    /// Setters  
    void ChangeMode(enum Mode m);
    void ChangeState(enum State s);
    void SetJoystick(int up, int down, int left, int right);

    /// modifying attributes by increments 
    void IncrementSetting(bool dir, const char* setting);
    void IncrementVariable(unsigned int& variable, int increment, int min, int max);


    /// Only method required in main.cpp
    void Run();


    /// Methods for navigatin the GUI menu
    void Menu();

    void OptionsMenu();
    void ChooseModeMenu();
    void ThresholdMenu();
    void DeadzoneMenu();

    void MenuExit();
    void MenuMode();
    void MenuState();


    /// Methods used to detect inputs and write outputs
    void MoveJoystick();
    void KeyboardRead();
    void KeyboardPress();


    private:
    
    enum State _state = NORMAL;
    enum Mode _mode = MODE1;

    /// Real dimension of the _key array
    int _dim;
    AnalogKey _key[MAX_ANALOG_KEYBOARD_SIZE];

    /// Dictates the activation height of every key
    unsigned int _threshold{152};

    /// Dictates the minimum press distance before a joystick input is sent to the pc
    unsigned int _deadzone{200};


    RotaryEncoder _encoder[MAX_ENCODER_SIZE] = {RotaryEncoder(0), RotaryEncoder(3)};
    Screen _screen;

};


#endif