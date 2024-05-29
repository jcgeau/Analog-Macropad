#ifndef ANALOG_KEY_H
#define ANALOG_KEY_H



#include <_Teensy.h>
#include "analog.c"


#define MACRO_SIZE  6
#define BUFFER_SIZE 5

#include <Arduino.h>

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
    AnalogKey(int port, int value);
    ~AnalogKey();

    void SetPort(int pin);
    void SetValue(int value);


    unsigned int BuffAvg();
    void KeyRead(); 
    void KeyWrite();
    void KeyPrint();
    void MacroWrite();
    bool IsPressed(int treshold);

    private:
    
    char _macro[MACRO_SIZE] = {0}; 
    unsigned int _analogValue;
    int _buffer[BUFFER_SIZE] = {0};
    int _buffer_i = 0;
    int _port;
    int _value;
    int _max;
    int _min;
    enum Joystick joystick = NO;
    

};


#endif