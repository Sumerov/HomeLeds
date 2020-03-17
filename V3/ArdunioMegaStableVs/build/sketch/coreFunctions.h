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
    #define FadeMAXVALUE 500
    #define FadeMAXVALUE2 250000
    #define FadeMINVALUE 30
    #define NUM_LEDS_LEFT   60   //60  
    #define NUM_LEDS_MID    80   //80
    #define NUM_LEDS_MON    109  //109 
    #define NUM_LEDS_RIGHT  70   //70 
    #define getAS(x)  (sizeof(x) / sizeof((x)[0]))
#endif

void introSetup();
void getAnalogValues(bool controlOn);
bool getBooleansFromAn(uint8_t **control, uint8_t pos, uint8_t pos2, uint8_t *sizes);
void fadeToogleToColor(uint8_t red, uint8_t green, uint8_t blue, bool reset);
void fadeTooglePwm(uint8_t red, uint8_t green, uint8_t blue);
void brightnessSet();
void controlCheckOut();
void analogCheckOut();