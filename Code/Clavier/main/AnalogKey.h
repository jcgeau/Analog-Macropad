/**
 * @file AnalogKey.h
 * @author Jean-Christophe Gauthier (jean-christophe.gauthier@polymtl.ca)
 * @brief Represents the behaviour of a single analog key with its own magnetic sensor
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ANALOG_KEY_H
#define ANALOG_KEY_H

#include <_Teensy.h>
#include <Arduino.h>
#include <string>

#include "Constants.h"


/**
 * @brief Represents a direction for the joystick command, NO by default
 * 
 */
enum JoystickPos {

    NO,
    X_RIGHT,
    X_LEFT,
    Y_UPPER,
    Y_LOWER

};

class AnalogKey {

    public:

    AnalogKey(){};
    AnalogKey(int pin);
    ~AnalogKey();

    /// Getters 
    const int GetValue();

    /// Setters 
    void SetJoystick(enum JoystickPos direction);
    void SetMacro(const int (&macro)[MAX_MACRO_SIZE]);
    void SetMessage(std::string s);
    void SetButton(int button);

    /// Reading the input
    void KeyRead(); 

    /// Processing data 
    unsigned int BuffAvg();
    bool IsPressed(unsigned int treshold);

    /// Sending command to pc
    void MoveJoystick(unsigned int deadzone);
    void KeyPress();
    void KeyRelease();

    void KeyPressMacro(int i);
    void KeyReleaseMacro(int i);

    /// Testing
    void Test();

    private:

    /// Pin on the microcontroller
    int _pin;

    /// Macro to be sent to the computer (will eventually be its own type)
    int _macro[MAX_MACRO_SIZE]{0}; 

    /// average value of the ADC reading
    unsigned int _analogValue;
    int _buffer[BUFFER_SIZE] = {255};
    int _buffer_i{0};

    /// Boundries of the Sensor output, used to normalise the ADC value to a [0 ,255] range 
    int _max{310};
    int _min{150};

    enum JoystickPos _direction{NO};
    int _button;

    bool _funkypressed{0};
    bool _pressed{0};
    std::string _message;

    


};


#endif