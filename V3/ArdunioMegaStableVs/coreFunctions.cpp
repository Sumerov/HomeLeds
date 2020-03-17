#include "coreFunctions.h"
#include "lcdFunctions.h"

uint8_t Analogs[] = {AnalogR1, AnalogR2, AnalogP1, AnalogP2};
uint8_t AnVal[] = {0, 0, 0, 0};
uint8_t counters[] = {3, 3, 3, 3};
bool AnValChanged[] = {false, false, false, false};
bool AnToLedsOn[] = {false, false, false, false};
bool AnToLedsOnOld[] = {false, false, false, false};
bool AnToPWMOn[] = {false, false, false, false, false};
bool AnToPWMOnOld[] = {false, false, false, false, false};


// Leva leva, stred, prava stred, prava leva, prava prava
uint8_t ShieldPwms[] = {14, 13, 12, 4, 5, 6 , 8, 9, 10, 0, 1, 2, 3, 7, 11};
uint8_t ShieldPwmsVals[] = {0, 0, 0, SHIELDPWMMAX*SHIELDPWMMAXDUTY/10.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

uint8_t newRGB[] = {240,240,60};
uint8_t currentRGB[] = {240,240,60};
uint16_t currentRGBpwm[] = {3765,3765,940};

uint8_t ledsLenght[] = {NUM_LEDS_LEFT, NUM_LEDS_MID, NUM_LEDS_MON, NUM_LEDS_RIGHT};
CRGB ledsLeft[NUM_LEDS_LEFT];
CRGB ledsMid[NUM_LEDS_MID];
CRGB ledsMon[NUM_LEDS_MON];
CRGB ledsRight[NUM_LEDS_RIGHT];
CRGB *leds[] = {ledsLeft, ledsMid, ledsMon, ledsRight};
CLEDController *controllers[4];

//Tlacitka řada 2 pro PLED {ALLON, ALLON, SINGLE, KOMBINACE....}
uint8_t R1Left[] =   {254, 60, 95, 104, 112,  151,        203,  127,  178};   //9
uint8_t R1Mid[] =    {254, 60, 80, 92,  87,   151,  101,  203,        178};   //9
uint8_t R1Mon[] =    {254, 60, 67, 92,  112,  72,   101,  203,  127      };   //9
uint8_t R1Right[] =  {254, 60, 64, 104, 87,   72,   101,        127,  178};   //9
uint8_t *R1control[] = {R1Left, R1Mid, R1Mon, R1Right};
uint8_t R1controlSizes[] = {getAS(R1Left), getAS(R1Mid), getAS(R1Mon), getAS(R1Right)};

//Tlacitka řada 1 pro PLED {ALLON, ALLON, SINGLE, KOMBINACE....}
uint8_t PWMLeft[] =   {254, 60, 95, 104, 112,  151,        203,  127,  178};  //9 
uint8_t PWMMid[] =    {254, 60, 80, 92,  87,   151,  101,  203,        178};  //9 
uint8_t PWMRLeft[] =  {254, 60, 64, 104, 87,   72,   101,        127,  178};  //9
uint8_t PWMRBack[] =  {254, 60, 67, 92,  112,  72,   101,  203,  127      };  //9
uint8_t PWMRRight[] = {254, 60, 64, 104, 87,   72,   101,        127,  178};  //9
uint8_t *R2control[] = {PWMLeft, PWMMid, PWMRLeft, PWMRBack, PWMRRight};
uint8_t R2controlSizes[] = {getAS(PWMLeft), getAS(PWMMid), getAS(PWMRLeft), getAS(PWMRBack), getAS(PWMRRight)};
uint8_t AnValSizes[] = {getAS(AnToLedsOn), getAS(AnToPWMOn), 0, 0};
bool AnChanged = false;

extern uint8_t brightness;
extern uint8_t currentBrightness;
extern bool controlBools[];
extern uint8_t controlVal;
extern bool controlOn;

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void introSetup() {
  double value = 0;
  for(uint16_t i=0; i < SHIELDPWMMAX; i+=16) {
    value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
    for(uint16_t j = 0; j<15; j++) {
      pwm.setPWM(ShieldPwms[j], 0, value/2);
    }
    delay(2);
  }
  for(uint8_t i=0;i<4;i++) if(i!=1) AnToLedsOn[i] = true; 
  brightness = 200;
  FastLED.setBrightness( brightness );
  fadeToogleToColor(245, 245, 245, false);
  delay(1000);
  fadeToogleToColor(245, 0, 0, false);
  delay(500);
  fadeToogleToColor(0, 245, 0, false);
  delay(500);
  fadeToogleToColor(0, 0, 245, false);
  delay(500);
  fadeToogleToColor(245, 245, 60, false);
  delay(500); 
  for(int16_t i=SHIELDPWMMAX; i > 0; i-=16) {
    value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
    for(uint16_t j = 0; j<15; j++) {
      if(j == 3) continue;
      pwm.setPWM(ShieldPwms[j], 0, value/2);
    }
    delay(2);
  }  
  for(uint8_t i=0;i<4;i++) if(i!=1) AnToLedsOn[i] = false;
  fadeToogleToColor(240, 240, 60, false);
  for(uint8_t i=0;i<4;i++) if(i!=1) AnToLedsOn[i] = false;
  for(uint8_t i=0;i<4;i++) if(i!=1) AnToLedsOnOld[i] = false;
} 

void getAnalogValues(bool controlOn) {
  AnChanged = false;
  uint8_t startFrom = 0;
  uint8_t val = 0;
  if(controlOn) { startFrom = 3; }
  
  for(uint8_t i=startFrom; i<4; i++) {
    delay(20);
    val = (uint8_t) ((double) analogRead(Analogs[i])/1023.0 * 255.0); 
    if(i<2) {
      if(val >= 5 && ((val <= AnVal[i]-AnalogOffset) || (val >= AnVal[i]+AnalogOffset))) {
        if(counters[i] > 0) {
          counters[i] --;  
        } else {
          AnVal[i] = val;
          AnValChanged[i] = true;  
          counters[i] = 3;
          AnChanged = true;
        }
      } 
    } if(i>1) {
      if(val >= 0 && ((val <= AnVal[i]-AnalogOffset) || (val >= AnVal[i]+AnalogOffset))) {
        if(counters[i] > 0 && !controlOn) {
          counters[i] --;  
        } else {
          AnVal[i] = val;
          AnValChanged[i] = true;  
          counters[i] = 3;
          AnChanged = true;
        }  
      }  
    } 
  }
  // DEBUGGING
  if(AnChanged) {
    Serial.println("//////////////");
    Serial.print("AnVals: [");
    for(uint8_t i = 0; i<4 ; i++) {
      Serial.print(AnVal[i]);
      if(i<3) Serial.print(", "); 
      else Serial.println("]"); 
    }
    Serial.print("AnValChanged: [");
    for(uint8_t i = 0; i<4 ; i++) {
      Serial.print(AnValChanged[i]);
      if(i<3) Serial.print(", "); 
      else Serial.println("]"); 
    }
  }  
}

bool getBooleansFromAn(uint8_t **control, uint8_t pos, uint8_t pos2, uint8_t *sizes) {
    uint8_t *p = control[pos];
    for(uint8_t i=0; i<sizes[pos]; i++) {
      if(AnVal[pos2] >= p[i]-resultOffset && AnVal[pos2] <= p[i]+resultOffset) {
        if(pos2==0) AnToLedsOn[pos] = true;
        if(pos2==1) {
          AnToPWMOn[pos] = true;  
          AnToLedsOn[1] = false;
        }
        break;
      }
    }
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
    Serial.print("PWMvals: "); 
    for(uint8_t i = 0; i<4 ; i++) {
      Serial.print(AnToPWMOn[i]);
      if(i<3) Serial.print(", "); 
    } Serial.print(" ("); 
    for(uint8_t i = 0; i<4; i++) {
      Serial.print(AnToPWMOn[i]);
      if(i<3) Serial.print(", "); 
    } Serial.println(")"); 
    Serial.println("//////////////----//");
    return false;
}

void fadeToogleToColor(uint8_t red, uint8_t green, uint8_t blue, bool reset) {
  bool LCDRefreshRows[] = {0,0,1,1};
  debugLCD(LCDRefreshRows, true);
  uint8_t RGBfadeIn[] = {0, 0, 0};
  uint8_t RGBfadeOut[] = {0, 0, 0};
  uint8_t calcRGB[] = {currentRGB[0], currentRGB[1], currentRGB[2]};
  uint8_t setRGB[] = {red, green, blue};
  bool fadeInCalc = false;
  bool fadeOutCalc = false;
  bool ChangeCalc = false;
  double calcVal = 0;
  uint16_t i;
  uint8_t j;
  uint8_t k;
  bool directionSwitch[] = {false, false, false};
  
  for(k=0; k<3; k++) {
    directionSwitch[k] = (calcRGB[k] <= setRGB[k]) ? true:false;  
  }
  
  for(i=FadeMINVALUE; i<FadeMAXVALUE; i+=5) {
      ChangeCalc = false;
      fadeInCalc = false;
      fadeOutCalc = false;
      for(j=0; j<4; j++) {
        if(AnToLedsOn[j] == true && AnToLedsOnOld[j] == false) {
          //FADE IN
          if(!fadeInCalc) {
            calcVal = (double)(pow(i,2)/(double)FadeMAXVALUE2);
            if(calcVal < 0.05) continue;
            RGBfadeIn[0] = (uint8_t) (calcVal*(double)red);
            RGBfadeIn[1] = (uint8_t) (calcVal*(double)green);
            RGBfadeIn[2] = (uint8_t) (calcVal*(double)blue);
            fadeInCalc = true;
          }  
          fill_solid(leds[j], ledsLenght[j], CRGB(RGBfadeIn[0], RGBfadeIn[1], RGBfadeIn[2]));      
        } else if(AnToLedsOn[j] == true) { 
          //Change new
          if(!ChangeCalc) {
            for(k=0; k<3; k++) { 
              if( directionSwitch[k] ) {
                if(calcRGB[k] <= setRGB[k]) {
                  calcVal = (double)(pow(i,2)/(double)FadeMAXVALUE2);
                  calcRGB[k] = currentRGB[k] + calcVal*(setRGB[k]-currentRGB[k]);
                }
              } else {
                 if(calcRGB[k] >= setRGB[k]) {
                  calcVal = (double)(pow((FadeMAXVALUE)-i+FadeMINVALUE,2)/(double)FadeMAXVALUE2);
                  calcRGB[k] = (uint8_t) (setRGB[k] + calcVal*(double)(currentRGB[k]-setRGB[k]));
                }
              }
            } 
            ChangeCalc = true;
          }
          fill_solid(leds[j], ledsLenght[j], CRGB(calcRGB[0], calcRGB[1], calcRGB[2])); 
        } else if(AnToLedsOnOld[j] == true) { 
          //FADE OUT
          if(!fadeOutCalc) {
            calcVal = (double)(pow((FadeMAXVALUE)-i+FadeMINVALUE,2)/(double)FadeMAXVALUE2);
            if(calcVal > 1) calcVal = 1;
            if(calcVal < 0.05) calcVal = 0;
            RGBfadeOut[0] = (uint8_t) (calcVal*(double)currentRGB[0]);
            RGBfadeOut[1] = (uint8_t) (calcVal*(double)currentRGB[1]);
            RGBfadeOut[2] = (uint8_t) (calcVal*(double)currentRGB[2]);
            fadeOutCalc = true;
          }
          fill_solid(leds[j], ledsLenght[j], CRGB(RGBfadeOut[0], RGBfadeOut[1], RGBfadeOut[2]));
        } 
      }
      showStrip();
      delay(5);
   }
   for(i=0; i<4; i++) {
    AnToLedsOnOld[i] = AnToLedsOn[i];   
    if(reset) AnToLedsOn[i] = false;
   }
   currentRGB[0] = red;
   currentRGB[1] = green;
   currentRGB[2] = blue;  
}

void writePwmsValue(uint16_t *rgb, uint8_t index) {
  uint16_t RGBfinal[] = {0,0,0};
  for(uint8_t p=0;p<3;p++) {
    RGBfinal[p] = (uint16_t) ((double)rgb[p]*currentBrightness / 255.0);
    pwm.setPWM(ShieldPwms[3*index + p], 0, RGBfinal[p]);
  }
}

void fadeTooglePwm(uint8_t red, uint8_t green, uint8_t blue, bool reset) {
  bool LCDRefreshRows[] = {0,0,1,1};
  debugLCD(LCDRefreshRows, true);
  uint16_t RGBfadeIn[] = {0, 0, 0};
  uint16_t RGBfadeOut[] = {0, 0, 0};
  uint16_t calcRGB[] = {currentRGBpwm[0], currentRGBpwm[1], currentRGBpwm[2]};
  uint16_t setRGB[] = {(double)red*SHIELDPWMMAX/255.0, (double)green*SHIELDPWMMAX/255.0, (double)blue*SHIELDPWMMAX/255.0};
  uint16_t RGBfinal[] = {0, 0, 0};
  bool fadeInCalc = false;
  bool fadeOutCalc = false;
  bool ChangeCalc = false;
  double calcVal = 0;
  uint16_t i;
  uint8_t j;
  uint8_t k;
  bool directionSwitch[] = {false, false, false};
  
  for(k=0; k<3; k++) {
    directionSwitch[k] = (calcRGB[k] <= setRGB[k]) ? true:false;  
  }
  
  for(i=FadeMINVALUEPWM; i<FadeMAXVALUEPWM; i+=5) {
      ChangeCalc = false;
      fadeInCalc = false;
      fadeOutCalc = false;
      for(j=0; j<5; j++) {
        if(AnToPWMOn[j] == true && AnToPWMOnOld[j] == false) {
          //FADE IN
          if(!fadeInCalc) {
            calcVal = (double)(pow(i,2)/(double)FadeMAXVALUEPWM2);
            if(calcVal < 0.05) continue;
            RGBfadeIn[0] = (uint16_t) (calcVal*(double)setRGB[0]);
            RGBfadeIn[1] = (uint16_t) (calcVal*(double)setRGB[1]);
            RGBfadeIn[2] = (uint16_t) (calcVal*(double)setRGB[2]);
            fadeInCalc = true;
          }  
          // Vykresleni Fade In 
          writePwmsValue(RGBfadeIn, j);
        } else if(AnToPWMOn[j] == true) { 
          //Change new
          if(!ChangeCalc) {
            for(k=0; k<3; k++) { 
              if( directionSwitch[k] ) {
                if(calcRGB[k] <= setRGB[k]) {
                  calcVal = (double)(pow(i,2)/(double)FadeMAXVALUEPWM2);
                  calcRGB[k] = currentRGBpwm[k] + calcVal*(setRGB[k]-currentRGBpwm[k]);
                }
              } else {
                 if(calcRGB[k] >= setRGB[k]) {
                  calcVal = (double)(pow((FadeMAXVALUEPWM)-i+FadeMINVALUEPWM,2)/(double)FadeMAXVALUEPWM2);
                  calcRGB[k] = (uint16_t) (setRGB[k] + calcVal*(double)(currentRGBpwm[k]-setRGB[k]));
                }
              }
            } 
            ChangeCalc = true;
          }
          writePwmsValue(calcRGB, j); // Vykresleni Change Color 
        } else if(AnToPWMOnOld[j] == true) { 
          //FADE OUT
          if(!fadeOutCalc) {
            calcVal = (double)(pow((FadeMAXVALUEPWM)-i+FadeMINVALUEPWM,2)/(double)FadeMAXVALUEPWM2);
            if(calcVal > 1) calcVal = 1;
            if(calcVal < 0.05) calcVal = 0;
            RGBfadeOut[0] = (uint16_t) (calcVal*(double)currentRGBpwm[0]);
            RGBfadeOut[1] = (uint16_t) (calcVal*(double)currentRGBpwm[1]);
            RGBfadeOut[2] = (uint16_t) (calcVal*(double)currentRGBpwm[2]);
            fadeOutCalc = true;
          }
          writePwmsValue(RGBfadeOut, j); // Vykresleni Fade Out
        } else {
          for(uint8_t p=0;p<3;p++) RGBfinal[p] = 0;
        }
      }
      delay(5);
   }
   for(i=0; i<4; i++) {
    AnToPWMOnOld[i] = AnToPWMOn[i];   
    if(reset) AnToPWMOn[i] = false;
   }
   currentRGBpwm[0] = setRGB[0];
   currentRGBpwm[1] = setRGB[1];
   currentRGBpwm[2] = setRGB[2];  
}

void brightnessSet() {
  bool LCDRefreshRows[] = {1,0,0,0};
  while(brightness != currentBrightness) {
    currentBrightness += (brightness < currentBrightness)? -1 : 1 ;
    FastLED.setBrightness( currentBrightness );
    showStrip();
    debugLCD(LCDRefreshRows, true); //tady je delay
  }
}

void controlCheckOut() {
  bool showdebug = false;
  for(uint8_t i=0; i<4; i++) {
      if(controlBools[i]) {
        showdebug = true;
        switch(i) {
          case 0: {  // TURNOFF
            for(uint8_t i=0; i<4; i++) { 
              AnToLedsOn[i] = false;
              AnToPWMOn[i] = false;
            }
            AnToPWMOn[4] = false;
            fadeToogleToColor(newRGB[0], newRGB[1], newRGB[2], true);
            break;
          }
          case 1: { // rgbChanged
            for(uint8_t i=0; i<4; i++) { AnToLedsOn[i] = AnToLedsOnOld[i]; }
            fadeToogleToColor(newRGB[0], newRGB[1], newRGB[2], true);
            controlOn = false;
            break;
          }
          case 2: { // brightnessChanged
            brightnessSet();
            break;
          }
          case 3: { // segmentChanged
            fadeToogleToColor(newRGB[0], newRGB[1], newRGB[2], true);
          }
          case 4: { // segmentChanged
            // PWMs
          }
          default: {break;}
        }
        controlBools[i] = false;
      }  
    }/*
  if(showdebug) {
    Serial.println("//");
    Serial.print("Control:");
    Serial.println( controlVal );
    Serial.println("//--//");
  }*/
}

void analogCheckOut() {
  int32_t value = 0;
  for(uint8_t i=0; i<4; i++) {
    if(AnValChanged[i]) {
      for(uint8_t j=0; j<AnValSizes[i]; j++) { 
        if(i==0) getBooleansFromAn( R1control, j, i, R1controlSizes); 
        if(i==1) getBooleansFromAn( R2control, j, i, R2controlSizes);  
      }
      bool LCDRefreshRows[] = {0,0,1,1};
      debugLCD(LCDRefreshRows, true);
      switch(i) {
        case 0: {
          value = (double) pow(AnVal[2], 3) / pow(242, 3) * 255.0; 
          if(value > 255) value = 255;
          brightness = value;
          FastLED.setBrightness(  brightness  );
          fadeToogleToColor(newRGB[0], newRGB[1], newRGB[2], true);
          break;
        }
        case 1: {           
          for(uint8_t j = 0; j<16; j++) {
            pwm.setPWM(j, 0, 0);
          }
          for(uint8_t j=0; j<5; j++) {
            if(AnToPWMOn[j]) {
              for(uint8_t k=0; k<3; k++) {
                ShieldPwmsVals[j*3+k] = (double)2000/10.0;
                pwm.setPWM(ShieldPwms[j*3+k], 0, 2000);
              }
            } else {
              for(uint8_t k=0; k<3; k++) {
                ShieldPwmsVals[j*3+k] = 0;
                pwm.setPWM(ShieldPwms[j*3+k], 0, 0);
              }
            }
          }
          if(AnVal[i] <= 59) {
            for(uint16_t i=0; i < SHIELDPWMMAX; i+=16) {
              value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
              pwm.setPWM(ShieldPwms[3], 0, value);
              delay(2);
            }  
            ShieldPwmsVals[3] = (double)SHIELDPWMMAX*SHIELDPWMMAXDUTY/10.0;  
          }
          break;
        }
        case 2: { 
          value = (double) pow(AnVal[2], 3) / pow(242, 3) * 255.0; 
          if(value > 255) value = 255;
          brightness = value;
          brightnessSet();
          break;
        }
        case 3: {break;}
        default: {break;}
      }
      //if(i==0) for(uint8_t o = 0; o<4; o++) AnToLedsOn[o] = false;
      if(i==1) {
        for(uint8_t o = 0; o<5; o++) {
          AnToPWMOnOld[o] = AnToPWMOn[o];
          AnToPWMOn[o] = false; 
        }  
      } 
    } 
    AnValChanged[i] = false; 
  }
}