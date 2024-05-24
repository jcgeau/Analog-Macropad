#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

#include "AnalogKey.h"

#define KEYBOARD_SIZE 12

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
    unsigned int _mode[MODE_SIZE];

};


#endif