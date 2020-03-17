#ifndef lcdFunctions
    #define lcdFunctions
    #include <avr\pgmspace.h>
    #include <LiquidCrystal_I2C.h>
    #include <Wire.h>
    #include "Arduino.h"

    
    extern uint8_t brightness;

    void debugLCD(uint8_t vals[4], LiquidCrystal_I2C *lcd);
    void setupLCD(LiquidCrystal_I2C *lcd);

#endif



