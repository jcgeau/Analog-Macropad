#ifndef ANALOG_KEY_H
#define ANALOG_KEY_H

#include <Keyboard.h>
#include <string>

const unsigned int BUFFER_SIZE = 5;

class AnalogKey {

    public:

    AnalogKey();
    ~AnalogKey();


    private:
    
    int _buffer[BUFFER_SIZE];
    string _port;
    string _value;
    

};


#endif