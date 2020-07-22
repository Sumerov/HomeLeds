#ifndef lcdFunctions
    #include <LiquidCrystal_I2C.h>
    #define lcdFunctions

    void fillUpDisplay(char endSymbol[2]);
    void debugLCD(bool refreshRows[4], bool oldOrNew);
    void setupLCD();

    extern uint8_t AnVal[];
    extern uint8_t brightness;
    extern uint8_t currentBrightness;
    extern bool AnToLedsOn[];
    extern bool AnToPWMOn[];
    extern bool AnToLedsOnOld[];
    extern bool AnToPWMOnOld[];
    extern uint8_t controlVal;
    extern bool debugLCDswitch;
    extern bool backlightLCDswitch;
    extern uint16_t MaxTValue;
#endif

