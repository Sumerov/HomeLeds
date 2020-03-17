#ifndef coreFunctions
    #define coreFunctions
    #define AnalogOffset 3 //*10
    #define resultOffset 1 //*10
    #include <Wire.h>
    #include "Arduino.h"
    
    extern uint8_t AnVal[];
    extern bool AnToLedsOn[];
    extern bool AnToPWMOn[];
    extern uint8_t Analogs[];
    extern uint8_t counters[];
    extern bool AnValChanged[];
    
    bool getBooleansFromAn(uint8_t **control, uint8_t pos, uint8_t pos2, uint8_t *sizes);
    void getAnalogValues(bool controlOn);

#endif
