#include "IRFunctions.h"

uint32_t getIrValue() {
    uint64_t irVal = 0; 
    for(int i=32+3; i<(results.rawlen-1); i++) {
        int Delta = results.rawbuf[i] - results.rawbuf[i+1];
        if (Delta < 0) Delta = -Delta;
        uint8_t b = (Delta < IR_TOLERANCE) ? 0 : 1;
        if ((i-3) < 63) {
            irVal = irVal | ((int64_t)b << (int64_t)(i-3));
        }
    }
    uint32_t x = irVal >> 32;
    irrecv.resume(); // get the next signal 
    return x;
}

extern uint8_t controlVal;
bool getControlValue(uint32_t irValue) {
  bool value = true;
  switch(irValue) {
    case 0: {controlVal = 127; value = false; break;}
    case 1276064752: {controlVal = 2; break;} case 1275868147: {controlVal = 3; break;} case 1341927427: {controlVal = 1; break;} case 1342124032: {controlVal = 0; break;}
    //Barvy
    case 1279210432: {controlVal = 10; break;} case 1279013827: {controlVal = 20; break;} case 1338781747: {controlVal = 30; break;} case 1338978352: {controlVal = 40; break;}
    case 1288647472: {controlVal = 11; break;} case 1288450867: {controlVal = 21; break;} case 1329344707: {controlVal = 31; break;} case 1329541312: {controlVal = 41; break;}
    case 1291793152: {controlVal = 12; break;} case 1291596547: {controlVal = 22; break;} case 1326199027: {controlVal = 32; break;} case 1326395632: {controlVal = 42; break;}
    case 2081358832: {controlVal = 13; break;} case 2081162227: {controlVal = 23; break;} case 2080572412: {controlVal = 33; break;} case 2080375807: {controlVal = 43; break;}
    case 2084504512: {controlVal = 14; break;} case 2084307907: {controlVal = 24; break;} case 2083718092: {controlVal = 34; break;} case 2083521487: {controlVal = 44; break;}
    //Sipky
    case 2093941552: {controlVal = 18; break;} case 2093744947: {controlVal = 28; break;} case 2093155132: {controlVal = 38; break;} case 2092958527: {controlVal = 4; break;}
    case 2097087232: {controlVal = 19; break;} case 2096890627: {controlVal = 29; break;} case 2096300812: {controlVal = 39; break;} case 2096104207: {controlVal = 5; break;}
    //DIY
    case 2131689712: {controlVal = 80; break;} case 2131493107: {controlVal = 81; break;} case 2130903292: {controlVal = 82; break;} case 2130706687: {controlVal = 6; break;}
    case 2134835392: {controlVal = 83; break;} case 2134638787: {controlVal = 84; break;} case 2134048972: {controlVal = 85; break;} case 2133852367: {controlVal = 7; break;}
    //MODY
    case 2144272432: {controlVal = 90; break;} case 2144075827: {controlVal = 91; break;} case 2143486012: {controlVal = 92; break;} case 2143289407: {controlVal = 93; break;}
    default: {controlVal = 127; value = false; break;}
  }
  return value;
}