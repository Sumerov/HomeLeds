#ifndef lcdFunctions
    #include <LiquidCrystal_I2C.h>
    #define lcdFunctions
#endif

void fillUpDisplay(char endSymbol[2]);
void debugLCD(bool refreshRows[4], bool oldOrNew);
void setupLCD();