#include <_Teensy.h>
#include <Arduino.h>

void macro1(){
  
  Keyboard.press(MODIFIERKEY_CTRL);
  Keyboard.press(KEY_C);
  Keyboard.releaseAll();
  delay(300);

  Mouse.moveTo(500, 1050);
  Mouse.click();
  delay(1000);
  
  Keyboard.press(MODIFIERKEY_CTRL);
  Keyboard.press(KEY_N);
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.press(MODIFIERKEY_CTRL);
  Keyboard.press(KEY_V);
  Keyboard.releaseAll();
  
}

void macro2(){

  Keyboard.print("jegaub");
  delay(100);
  
  Mouse.moveTo(770, 405);
  Mouse.click();


}

void macro3(){}

void macro4(){}

void macro5(){}

void macro6(){}

void macro7(){}

void macro8(){}

void macro9(){}

void macro10(){}

void macro11(){}

void macro12(){}

void doMacro(int index){

  switch(index){

  case 0: 
    macro1();
    break;  

  case 1: 
    macro2();
    break;

  case 2: 
    macro3();
    break;

  case 3: 
    macro4();
    break;

  case 4: 
    macro5();
    break;

  case 5: 
    macro6();
    break;

  case 6: 
    macro7();
    break;

  case 7: 
    macro8();
    break;

  case 8: 
    macro9();
    break;

  case 9: 
    macro10();
    break;

  case 10: 
    macro11();
    break;

  case 11: 
    macro12();
    break;

  }
}
