#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

#include <Keyboard.h>
#include <string>
#include "AnalogKey.h"

const unsigned int KEYBOARD_SIZE = 12;

enum modes {
    MODE1,
    MODE2,
    MODE3,
    MODE_SIZE

};

class AnalogKeyboard {

    public:

    AnalogKeyboard();
    ~AnalogKeyboard();
    void changeMode();

    private:
    
    AnalogKey _key[KEYBOARD_SIZE];
    unsigned uint8_t _mode[MODE_SIZE];

};


#endif