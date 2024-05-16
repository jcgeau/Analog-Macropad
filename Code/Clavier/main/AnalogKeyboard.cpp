#include "AnalogKeyboard.h"

AnalogKeyboard::AnalogKeyboard(){

    Keyboard.begin();

}

AnalogKeyboard::~AnalogKeyboard(){

    Keyboard.end();

}