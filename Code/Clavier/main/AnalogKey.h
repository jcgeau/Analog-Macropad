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
    void SetPort(int pin);
    void SetValue(int value);


    unsigned int BuffAvg();
    void KeyRead(); 
    void KeyWrite();
    void KeyPrint();
    void MacroWrite();
    bool IsPressed(unsigned int treshold);

    private:
    
    char _macro[MACRO_SIZE] = {0}; 
    unsigned int _analogValue;
    int _buffer[BUFFER_SIZE] = {0};
    int _buffer_i{0};
    int _pin;
    int _value{0};
    int _max{470};
    int _min{250};
    enum Joystick joystick = NO;
    

};


#endif