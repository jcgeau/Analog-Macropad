#ifndef ANALOG_KEY_H
#define ANALOG_KEY_H

#include <Keyboard.h>
#include <string>

const unsigned int BUFFER_SIZE = 5;

class AnalogKey {

    public:

    AnalogKey();
    ~AnalogKey();

    void SetPort(int pin);
    void SetValue(int value);

    
    void KeyRead(); // aller voir la fonction map() de arduino
    void KeyWrite();

    private:
    
    int _buffer[BUFFER_SIZE] = {0};
    int _port;
    int _value;
    

};


#endif