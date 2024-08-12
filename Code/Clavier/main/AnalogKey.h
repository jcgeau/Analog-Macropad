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

    /// Reading the input
    void KeyRead(); 

    /// Processing data 
    unsigned int BuffAvg();
    bool IsPressed(unsigned int treshold);

    /// Sending command to pc
    void MoveJoystick();
    void KeyPress();
    void KeyRelease();

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
    
    unsigned int _deadzone{200};

    enum JoystickPos _direction{NO};
    bool _pressed{0};


};


#endif