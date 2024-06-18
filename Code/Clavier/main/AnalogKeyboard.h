#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

#include <_Teensy.h>
#include <Arduino.h>

#include "AnalogKey.h"


#define ANALOG_KEYBOARD_SIZE 12
#define KEY_DELAY 500

enum Mode {
    MODE1,
    MODE2,
    MODE3,
    MODE_SIZE

};

class AnalogKeyboard {

    public:

    AnalogKeyboard();
    ~AnalogKeyboard();
    
    void ChangeMode();
    void KeyboardRead();
    void KeyboardPrint();
    void KeyboardWrite();

    private:
    
    AnalogKey _key[ANALOG_KEYBOARD_SIZE];
    AnalogKey _controller[4];
    enum Mode _mode = MODE1;
    unsigned int _treshold;
};


#endif