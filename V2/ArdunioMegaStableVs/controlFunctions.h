#ifndef controlFunctions
    #define controlFunctions
    #include <IRremote.h>   
    #define IR_TOLERANCE 17

    uint32_t getIrValue();
    bool getControlValue(uint32_t irValue);
    bool getControlAction(uint8_t *rgb);
#endif