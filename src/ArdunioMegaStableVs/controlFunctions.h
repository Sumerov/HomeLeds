#ifndef controlFunctions
    #define controlFunctions
    #include <IRremote.h>   
    #define IR_TOLERANCE 17

    uint32_t IRdecodeType() ;
    bool getControlValue(uint32_t irValue);
    bool getControlAction(uint8_t *rgb);
    void segmentsSet(uint8_t segment, bool type );

    extern bool AnToLedsOn[];
    extern bool AnToPWMOn[];
    extern bool AnToLedsOnOld[];
    extern bool AnToPWMOnOld[];
#endif

