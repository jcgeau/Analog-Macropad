#ifndef ANALOG_KEY_H
#define ANALOG_KEY_H



#include <_Teensy.h>
#include <Arduino.h>

#include "Constants.h"



enum Joystick {

    NO,
    X_UPPER,
    X_LOWER,
    Y_UPPER,
    Y_LOWER

};

class AnalogKey {

    public:

    AnalogKey();
    AnalogKey(int port);
    ~AnalogKey();

    const int GetValue();
    const int GetMacro();

    void SetPort(int pin);
    void SetValue(int value);


    unsigned int BuffAvg();

    void KeyRead(); 
    
    void KeyPress();
    void KeyRelease();
    void SetMacro(const int (&macro)[MAX_MACRO_SIZE]);
    bool IsPressed(unsigned int treshold);

    private:
    
    int _macro[MAX_MACRO_SIZE]{0}; 
    unsigned int _analogValue;
    int _buffer[BUFFER_SIZE] = {0};
    int _buffer_i{0};
    int _pin;
    int _max{580};
    int _min{400};
    enum Joystick joystick{NO};
    bool _pressed{0};

};


#endif