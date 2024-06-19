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
    ~AnalogKeyboard();
    
    void ChangeMode();
    void KeyboardRead();
    void KeyboardPrint();
    void KeyboardWrite();

    private:
    int a = BUFFER_SIZE;
    //AnalogKey* _key = KEYS;
    //AnalogKey _controller[4];
    enum Mode _mode = MODE1;
    unsigned int _treshold;
};


#endif