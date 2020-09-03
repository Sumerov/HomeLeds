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

uint32_t IRdecodeType() { 
  uint32_t value = 0;
  switch (results.decode_type) {
    case NEC: {
      value = results.value;
      break;     
    }  
    case PANASONIC: {
      value = results.value;
      break;
    } 
  }
  
  irrecv.resume();
  return value;
}

bool getControlValue(uint32_t irValue) {
  bool value = true;
  Serial.println("//IR//");
  Serial.print("IRVal: ");
  Serial.print(irValue);
  controlVal = 127;

  //NEC
  switch(irValue) {
    case 0: {controlVal = 127; /*value = false;*/ break;}
    case 16726725: {controlVal = 2; break;} case 16759365: {controlVal = 3; break;} case 16745085: {controlVal = 1; break;} case 16712445: {controlVal = 0; break;}
    //Barvy
    case 16718565: {controlVal = 10; break;} case 16751205: {controlVal = 20; break;} case 16753245: {controlVal = 30; break;} case 16720605: {controlVal = 40; break;}
    case 16722645: {controlVal = 11; break;} case 16755285: {controlVal = 21; break;} case 16749165: {controlVal = 31; break;} case 16716525: {controlVal = 41; break;}
    case 16714485: {controlVal = 12; break;} case 16747125: {controlVal = 22; break;} case 16757325: {controlVal = 32; break;} case 16724685: {controlVal = 42; break;}
    case 16726215: {controlVal = 13; break;} case 16758855: {controlVal = 23; break;} case 16742535: {controlVal = 33; break;} case 16775175: {controlVal = 43; break;}
    case 16718055: {controlVal = 14; break;} case 16750695: {controlVal = 24; break;} case 16734375: {controlVal = 34; break;} case 16767015: {controlVal = 44; break;}
    //Sipky
    case 16722135: {controlVal = 18; break;} case 16754775: {controlVal = 28; break;} case 16738455: {controlVal = 38; break;} case 16771095: {controlVal = 4; break;}
    case 16713975: {controlVal = 19; break;} case 16746615: {controlVal = 29; break;} case 16730295: {controlVal = 39; break;} case 16762935: {controlVal = 5; break;}
    //DIY
    case 16724175: {controlVal = 80; break;} case 16756815: {controlVal = 81; break;} case 16740495: {controlVal = 82; break;} case 16773135: {controlVal = 6; break;}
    case 16716015: {controlVal = 83; break;} case 16748655: {controlVal = 84; break;} case 16732335: {controlVal = 85; break;} case 16764975: {controlVal = 7; break;}
    //MODY
    case 16720095: {controlVal = 90; break;} case 16752735: {controlVal = 91; break;} case 16736415: {controlVal = 92; break;} case 16769055: {controlVal = 93; break;}
    default: {controlVal = 127; /*value = false;*/ break;}
  }
  if(controlVal == 127) {
    //PANASONIC
    switch(irValue) {
      case 0: {controlVal = 127; value = false; break;}
      //mixer
      case 89161941: {controlVal = 2; break;} case 89129045: {controlVal = 3; break;} case 89153589: {controlVal = 1; break;} case 89149445: {controlVal = 0; break;}
      //search x skip
      case 89145365: {controlVal = 10; break;} case 89178261: {controlVal = 20; break;} case 89166535: {controlVal = 30; break;} case 89149959: {controlVal = 40; break;}
      //Numbers
      case 89131101: {controlVal = 11; break;} case 89163997: {controlVal = 21; break;} case 89147421: {controlVal = 31; break;} case 89180317: {controlVal = 41; break;}
      case 89139325: {controlVal = 12; break;} case 89172221: {controlVal = 22; break;} case 89155645: {controlVal = 32; break;} case 89188541: {controlVal = 42; break;}
      case 89135181: {controlVal = 13; break;} case 89170420: {controlVal = 23; break;} case 89137524: {controlVal = 33; break;} case 89168077: {controlVal = 43; break;}
      //Menu
      case 89149700: {controlVal = 14; break;} case 89129300: {controlVal = 24; break;} case 89162196: {controlVal = 34; break;} case 89172735: {controlVal = 44; break;}
      //Options
      case 89133639: {controlVal = 18; break;} case 89186999: {controlVal = 28; break;} case 89174759: {controlVal = 38; break;} case 89182596: {controlVal = 4; break;}
      case 89162961: {controlVal = 19; break;} case 89130065: {controlVal = 29; break;} case 89183616: {controlVal = 39; break;} case 89142624: {controlVal = 5; break;}
      //Peak search
      case 89190820: {controlVal = 80; break;} 
      default: {if(controlVal == 127 ){ controlVal = 127;value = false;} break;}
    }
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


