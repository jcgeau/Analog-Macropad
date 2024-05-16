#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

#include <Keyboard.h>
#include <string>
#include "AnalogKey.h"

const unsigned int KEYBOARD_SIZE = 12;

class AnalogKeyboard {

    public:

    AnalogKeyboard();
    ~AnalogKeyboard();
    

    private:
    
    AnalogKey keyp[KEYBOARD_SIZE]
    

};


#endif