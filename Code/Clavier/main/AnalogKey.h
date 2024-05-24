#ifndef ANALOG_KEY_H
#define ANALOG_KEY_H


#define MACRO_SIZE  10
#define BUFFER_SIZE  5

class AnalogKey {

    public:

    AnalogKey();
    ~AnalogKey();

    void SetPort(int pin);
    void SetValue(int value);

    
    void KeyRead(); // aller voir la fonction map() de arduino
    void KeyWrite();
    void keyPrint();
    void macroWrite();

    private:
    
    char _macro[MACRO_SIZE] = {0}; 
    int _analogValue;
    int _buffer[BUFFER_SIZE] = {0};
    int _port;
    int _value;
    int _max;
    int _min;
    

};


#endif