#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H



#include <_Teensy.h>
#include <Arduino.h>

#include "Constants.h"
#include "AnalogKey.h"




enum Mode {
    MODE1,
    MODE2,
    MODE3,
    MODE_SIZE

};

class AnalogKeyboard {

    public:

    AnalogKeyboard();
    AnalogKeyboard(int dimensions);
    ~AnalogKeyboard();
    
    void ChangeMode();
    void KeyboardRead();
    void KeyboardPress();

    private:
    
    AnalogKey _key[MAX_ANALOG_KEYBOARD_SIZE];
    int _dim;
    enum Mode _mode = MODE1;
    unsigned int _treshold{100};
};


#endif