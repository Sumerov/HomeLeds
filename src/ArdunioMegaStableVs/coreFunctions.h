#ifndef coreFunctions
    #define coreFunctions
    #include <FastLED.h>
    #include <Adafruit_PWMServoDriver.h>
    #define SHIELDPWMMAX  4095
    #define SHIELDPWMMAXPOW 16769025
    #define SHIELDPWMMAXDUTY  50
    #define AnalogR1 A0
    #define AnalogR2 A1
    #define AnalogP1 A3
    #define AnalogP2 A2
    #define AnalogOffset 3 //*10
    #define resultOffset 1 //*10
    #define FadeMINVALUE 30
    #define FadeMAXVALUEPWM 500
    #define FadeMAXVALUEPWM2 250000
    #define FadeMINVALUEPWM 30
    #define NUM_LEDS_LEFT   60   //60  
    #define NUM_LEDS_MID    80   //80
    #define NUM_LEDS_MON    109  //109 
    #define NUM_LEDS_RIGHT  70   //70 
    #define getAS(x)  (sizeof(x) / sizeof((x)[0]))

    void introSetup();
    void getAnalogValues(bool controlOn);
    bool getBooleansFromAn(uint8_t **control, uint8_t pos, uint8_t pos2, uint8_t *sizes);
    void fadeToogleToColor(uint8_t red, uint8_t green, uint8_t blue, int16_t maxValue, bool reset);
    void writePwmsValue(uint16_t *rgb, uint8_t index);
    void fadeTooglePwm(uint8_t red, uint8_t green, uint8_t blue);
    void brightnessSet();
    void controlCheckOut();
    void analogCheckOut();
    
    extern uint8_t brightness;
    extern uint8_t currentBrightness;
    extern bool controlBools[];
    extern uint8_t controlVal;
    extern bool controlOn;
#endif

