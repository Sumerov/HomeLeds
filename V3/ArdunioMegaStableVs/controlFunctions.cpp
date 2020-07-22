#include "controlFunctions.h"

const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
uint8_t controlVal = 0;
uint8_t brightness = 30;
uint8_t currentBrightness = 30;
bool controlOn = false;
bool debugLCDswitch = false;
bool backlightLCDswitch = false;
bool runLCD = false;
// {turnOff, rgbChanged, brightnessChanged, segmentChangeLeds, segmentChangePwms}
bool controlBools[] = {false, false, false, false, false};

    

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


bool getControlValue(uint32_t irValue) {
  bool value = true;
  Serial.println("//IR//");
  Serial.print("IRVal: ");
  Serial.print(irValue);
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
  Serial.print(" => controlVal : ");
  Serial.println(controlVal);
  Serial.println("////==////");
  return value;
}

void segmentsSet(uint8_t segment, bool type ) {
  if(type) {
    for(uint8_t i=0; i<4; i++) {
      AnToLedsOn[i] = AnToLedsOnOld[i];
    }  
    AnToLedsOn[segment] = !AnToLedsOnOld[segment];
     // DEBUGGING
    Serial.print("PLEDvals: ");
    for(uint8_t i = 0; i<4; i++) {
      Serial.print(AnToLedsOn[i]);
      if(i<3) Serial.print(", "); 
    } Serial.print(" ("); 
    for(uint8_t i = 0; i<4; i++) {
      Serial.print(AnToLedsOnOld[i]);
      if(i<3) Serial.print(", "); 
    } Serial.println(")"); 
    controlBools[3] = true;
  } else {
    for(uint8_t i=0; i<5; i++) {
      AnToPWMOn[i] = AnToPWMOnOld[i];
    }  
    if(segment == 2) {
      AnToPWMOn[segment] = !AnToPWMOnOld[segment];
      AnToPWMOn[segment+1] = !AnToPWMOnOld[segment+1];
      AnToPWMOn[segment+2] = !AnToPWMOnOld[segment+2];
    }
    AnToPWMOn[segment] = !AnToPWMOnOld[segment];
    // DEBUGGING
    Serial.print("PWMvals: "); 
    for(uint8_t i = 0; i<4 ; i++) {
      Serial.print(AnToPWMOn[i]);
      if(i<3) Serial.print(", "); 
    } Serial.print(" ("); 
    for(uint8_t i = 0; i<4; i++) {
      Serial.print(AnToPWMOn[i]);
      if(i<3) Serial.print(", "); 
    } Serial.println(")"); 
  } 
  controlBools[4] = true;
  Serial.println("//////////////----//");
}

bool getControlAction(uint8_t *rgb) {
  bool value = true;
  uint8_t increment = 10;
  //rgb[0] = 0; rgb[1] = 0; rgb[2] = 0;
  uint8_t v[] = {0, 100, 160, 200, 255};
  switch(controlVal) {
    case 127: {value = false; break;}
    case 2: { if(brightness<250) brightness += increment; controlBools[2] = true; break;} 
    case 3: { if(brightness>5) brightness-= increment; controlBools[2] = true; break;} 
    case 1: { value = false; break;} 
    case 0: { controlBools[0] = true; break;}
    //Barvy
    case 10: { rgb[0] = v[4]; rgb[1] = v[0]; rgb[2] = v[0]; break;} 
    case 20: { rgb[0] = v[0]; rgb[1] = v[4]; rgb[2] = v[0]; break;} 
    case 30: { rgb[0] = v[0]; rgb[1] = v[0]; rgb[2] = v[4]; break;} 
    case 40: { rgb[0] = v[4]; rgb[1] = v[4]; rgb[2] = v[4]; break;}
    case 11: { rgb[0] = v[4]; rgb[1] = v[1]; rgb[2] = v[0]; break;} 
    case 21: { rgb[0] = v[0]; rgb[1] = v[4]; rgb[2] = v[1]; break;} 
    case 31: { rgb[0] = v[1]; rgb[1] = v[0]; rgb[2] = v[4]; break;} 
    case 41: { rgb[0] = v[4]; rgb[1] = v[2]; rgb[2] = v[2]; break;}
    case 12: { rgb[0] = v[4]; rgb[1] = v[2]; rgb[2] = v[0]; break;} 
    case 22: { rgb[0] = v[0]; rgb[1] = v[4]; rgb[2] = v[2]; break;} 
    case 32: { rgb[0] = v[2]; rgb[1] = v[0]; rgb[2] = v[4]; break;} 
    case 42: { rgb[0] = v[4]; rgb[1] = v[2]; rgb[2] = v[2]; break;}
    case 13: { rgb[0] = v[4]; rgb[1] = v[2]; rgb[2] = v[0]; break;} 
    case 23: { rgb[0] = v[0]; rgb[1] = v[4]; rgb[2] = v[2]; break;} 
    case 33: { rgb[0] = v[2]; rgb[1] = v[0]; rgb[2] = v[4]; break;} 
    case 43: { rgb[0] = v[2]; rgb[1] = v[2]; rgb[2] = v[4]; break;}
    case 14: { rgb[0] = v[4]; rgb[1] = v[4]; rgb[2] = v[0]; break;} 
    case 24: { rgb[0] = v[0]; rgb[1] = v[4]; rgb[2] = v[4]; break;} 
    case 34: { rgb[0] = v[4]; rgb[1] = v[0]; rgb[2] = v[4]; break;} 
    case 44: { rgb[0] = v[2]; rgb[1] = v[2]; rgb[2] = v[4]; break;}
    //Sipky
    case 18: { rgb[0] = (rgb[0] < 255-2*increment)? rgb[0] + 2*increment : 255; break;} 
    case 28: { rgb[1] = (rgb[1] < 255-2*increment)? rgb[1] + 2*increment : 255; break;} 
    case 38: { rgb[2] = (rgb[2] < 255-2*increment)? rgb[2] + 2*increment : 255; break;} 
    case 4: { debugLCDswitch = !debugLCDswitch; value = false; runLCD=true; break;}
    case 19: { rgb[0] = (rgb[0] > 0+2*increment)?rgb[0] - 2*increment : 0; break;} 
    case 29: { rgb[1] = (rgb[1] > 0+2*increment)?rgb[1] - 2*increment : 0; break;} 
    case 39: { rgb[2] = (rgb[2] > 0+2*increment)?rgb[2] - 2*increment : 0; break;} 
    case 5: { backlightLCDswitch = !backlightLCDswitch; value = false; runLCD=true; break;}
    //DIY
    case 80: { segmentsSet(0, true); break;} 
    case 81: { segmentsSet(1, true); break;} 
    case 82: { segmentsSet(2, true); break;} 
    case 6: {  segmentsSet(3, true); break;}
    case 83: { segmentsSet(0, false); break;} 
    case 84: { segmentsSet(1, false); break;} 
    case 85: { segmentsSet(2, false); break;} 
    case 7: { break;}
    //MODY
    case 90: { break;} 
    case 91: { break;} 
    case 92: { break;} 
    case 93: { break;}
    default: {value = false; break;}
  }
  if(10 <= controlVal && controlVal < 50) {
    value = true;
    controlBools[1] = true;
  }
   // DEBUGGING
    Serial.print("controlBools: ");
    for(uint8_t i = 0; i<4; i++) {
      Serial.print(controlBools[i]);
      if(i<3) Serial.print(", "); 
    }Serial.print(" ("); Serial.print(value);Serial.println(")");
  return value;
}


