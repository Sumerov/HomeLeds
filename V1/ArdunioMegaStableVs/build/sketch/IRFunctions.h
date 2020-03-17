#ifndef IRFunctions
    #define IRFunctions
    #include <IRremote.h>
    #include <Wire.h>
    #include "Arduino.h"
    #define IR_TOLERANCE 17

    extern IRrecv irrecv;
    extern decode_results results;

    uint32_t getIrValue();
    bool getControlValue(uint32_t irValue);

#endif

