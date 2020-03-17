#line 1 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
#include <FastLED.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include <IRremote.h>
#include "lcdFunctions.h"
#include "IRFunctions.h"
#include "coreFunctions.h"
#define IR_TOLERANCE 17
const int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);
decode_results results;

#define SHIELDPWMMAX  4095
#define SHIELDPWMMAXPOW 16769025
#define SHIELDPWMMAXDUTY  50
#define RELAYPIN 3
#define AnalogR1 A0
#define AnalogR2 A1
#define AnalogP1 A3
#define AnalogP2 A2
#define AnalogOffset 3 //*10
#define resultOffset 1 //*10
#define NUM_LEDS_LEFT   60   //60  
#define NUM_LEDS_MID    80   //80
#define NUM_LEDS_MON    109  //109 
#define NUM_LEDS_RIGHT  70   //70 
#define getAS(x)  (sizeof(x) / sizeof((x)[0]))

uint8_t brightness = 30;
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

uint8_t ledsLenght[] = {NUM_LEDS_LEFT, NUM_LEDS_MID, NUM_LEDS_MON, NUM_LEDS_RIGHT};
CRGB ledsLeft[NUM_LEDS_LEFT];
CRGB ledsMid[NUM_LEDS_MID];
CRGB ledsMon[NUM_LEDS_MON];
CRGB ledsRight[NUM_LEDS_RIGHT];
CRGB *leds[] = {ledsLeft, ledsMid, ledsMon, ledsRight};
CLEDController *controllers[4];


uint8_t Analogs[] = {AnalogR1, AnalogR2, AnalogP1, AnalogP2};
uint8_t AnVal[] = {0, 0, 0, 0};
bool AnValChanged[] = {false, false, false, false};
bool AnToLedsOn[] = {false, false, false, false};
bool AnToLedsOnOld[] = {false, false, false, false};

// Leva leva, stred, prava stred, prava leva, prava prava
uint8_t ShieldPwms[] = {14, 13, 12, 4, 5, 6 , 8, 9, 10, 0, 1, 2, 3, 7, 11};
uint8_t ShieldPwmsVals[] = {0, 0, 0, SHIELDPWMMAX*SHIELDPWMMAXDUTY/10.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool AnToPWMOn[] = {false, false, false, false, false};
bool AnToPWMOnOld[] = {false, false, false, false, false};
uint8_t AnValSizes[] = {getAS(AnToLedsOn), getAS(AnToPWMOn), 0, 0};


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
static LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
uint8_t LCDcursor = 0;


#line 78 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void showStrip();
#line 90 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void setup();
#line 116 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void introSetup();
#line 157 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void loop();
#line 239 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void fadeToogleToColor(uint8_t red, uint8_t green, uint8_t blue);
#line 320 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void fadeTooglePwm(uint8_t red, uint8_t green, uint8_t blue);
#line 78 "r:\\DOWNLOAD\\škola\\ardunio\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
  
  irrecv.enableIRIn();
  irrecv.blink13(true);

  lcd.init();
  lcd.setBacklight(1);
  setupLCD(&lcd);
  
  Serial.begin(115200);
  controllers[0] = &FastLED.addLeds<WS2812B, 6, GRB>(ledsLeft, NUM_LEDS_LEFT).setCorrection( TypicalLEDStrip );
  controllers[1] = &FastLED.addLeds<WS2812B, 10, GRB>(ledsMid, NUM_LEDS_MID).setCorrection( TypicalLEDStrip );
  controllers[2] = &FastLED.addLeds<WS2812B, 11, GRB>(ledsMon, NUM_LEDS_MON).setCorrection( TypicalLEDStrip );
  controllers[3] = &FastLED.addLeds<WS2812B, 9, GRB>(ledsRight, NUM_LEDS_RIGHT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  brightness  );
  pwm.begin();
  for(uint8_t j = 0; j<16; j++) {
      pwm.setPWM(j, 0, 0);
  }
  delay(1000);
  introSetup();
}

int16_t value;
void introSetup() {
  double value;
  for(uint16_t i=0; i < SHIELDPWMMAX; i+=16) {
    value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
    for(uint16_t j = 0; j<15; j++) {
      pwm.setPWM(ShieldPwms[j], 0, value/2);
    }
    delay(2);
  }
  for(uint8_t i=0;i<4;i++) if(i!=1) AnToLedsOn[i] = true; 
  fadeToogleToColor(245, 245, 60);
  delay(1000);
  fadeToogleToColor(0, 120, 80);
  delay(500);
  fadeToogleToColor(200, 10, 0);
  delay(500);
  fadeToogleToColor(200, 10, 0);
  delay(500);
  fadeToogleToColor(200, 10, 200);
  delay(500); 
  fadeToogleToColor(245, 245, 60);
  for(int16_t i=SHIELDPWMMAX; i > 0; i-=16) {
    value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
    for(uint16_t j = 0; j<15; j++) {
      if(j == 3) continue;
      pwm.setPWM(ShieldPwms[j], 0, value/2);
    }
    delay(2);
  }  
} 

uint8_t i;
uint8_t j;
uint8_t k;
uint8_t val = 0;
uint8_t counters[] = {3, 3, 3, 3};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t IRvalue = 0;
uint8_t controlVal = 0;
bool controlOn = false;
void loop() {
  if (irrecv.decode(&results)) {
     IRvalue = getIrValue();
     controlOn = getControlValue(IRvalue);
  }
  
  getAnalogValues(controlOn);
  if(AnValChanged[3] && AnVal[3] > 250) controlOn = false;  
  
  for(uint8_t i=0; i<4; i++) {
    if(AnValChanged[i]) {
      for(uint8_t j=0; j<AnValSizes[i]; j++) { 
        if(i==0) getBooleansFromAn( R1control, j, i, R1controlSizes); 
        if(i==1) getBooleansFromAn( R2control, j, i, R2controlSizes);  
      }
      switch(i) {
        case 0: {
          brightness = (double) pow(AnVal[2], 3) / pow(242, 3) * 255.0; 
          if(brightness > 255) brightness = 255;
          FastLED.setBrightness(  brightness  );
          //adeToogleToColor(255, 255, 60);
          uint8_t r = random(255);
          uint8_t g = random(255);
          uint8_t b = random(255);
          Serial.print("Brightness: "); Serial.println(brightness);
          Serial.print("Colors: "); Serial.print(r); Serial.print(", "); Serial.print(g); Serial.print(", "); Serial.print(b);

          fadeToogleToColor(r, g, b);
          
          break;
        }
        case 1: { 
          //fadeTooglePwm(255,255,60);
          
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
          brightness = (double) pow(AnVal[2], 3) / pow(242, 2) * 100.0; 
          if(brightness > 100) brightness = 100;
          FastLED.setBrightness(  brightness  );
          break;
        }
        case 3: {break;}
        default: {break;}
      }
      if(i==0) for(uint8_t o = 0; o<4; o++) AnToLedsOn[o] = false;
      if(i==1) for(uint8_t o = 0; o<5; o++) AnToPWMOn[o] = false;
      AnValChanged[i] = false;     
    }
  }
  delay(20);
}

#define FadeMAXVALUE 500
#define FadeMAXVALUE2 250000
#define FadeMINVALUE 30
uint8_t currentRGB[] = {255,255,60};

void fadeToogleToColor(uint8_t red, uint8_t green, uint8_t blue) {
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
  
  //FadeMAXVALUE2 = (uint32_t)FadeMAXVALUE * FadeMAXVALUE;
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
                if(calcRGB[k] <= setRGB[k]+1) {
                  calcVal = (double)(pow(i,2)/(double)FadeMAXVALUE2);
                  calcRGB[k] = currentRGB[k] + calcVal*(setRGB[k]-currentRGB[k]);
                }
              } else {
                 if(calcRGB[k] >= setRGB[k]-1) {
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
   }
   currentRGB[0] = red;
   currentRGB[1] = green;
   currentRGB[2] = blue;  
}



void fadeTooglePwm(uint8_t red, uint8_t green, uint8_t blue) {
  value = 0;
  for(int16_t i=FadeMINVALUE; i<FadeMAXVALUE; i+=5) {
      for(uint8_t j=0; j<5; j++) {
        if(AnToPWMOn[j] == AnToPWMOnOld[j]) {
          continue;
        } else if(AnToPWMOn[j] == true) { 
          //FADE IN
          value = (double)(pow(i,2)/(double)FadeMAXVALUE2)*SHIELDPWMMAX/SHIELDPWMMAXDUTY;
          if(value<15) continue;
          pwm.setPWM(ShieldPwms[j*3+0], 0, value*red/255);
          pwm.setPWM(ShieldPwms[j*3+1], 0, value*green/255);
          pwm.setPWM(ShieldPwms[j*3+2], 0, value*blue/255);
          if(j==2) Serial.println(value);
        } else { 
          //FADE OUT
          value = (double)(pow((FadeMAXVALUE)-i+FadeMINVALUE,2)/(double)FadeMAXVALUE2)*SHIELDPWMMAX/SHIELDPWMMAXDUTY;
          if(value > SHIELDPWMMAX) value = SHIELDPWMMAX;
          //if(FadeMAXVALUE-i>FadeMINVALUE+5 && value<20) { continue; }
          if(FadeMAXVALUE-i<FadeMINVALUE+5) value = 0;
          pwm.setPWM(ShieldPwms[j*3+0], 0, value*red/255);
          pwm.setPWM(ShieldPwms[j*3+1], 0, value*green/255);
          pwm.setPWM(ShieldPwms[j*3+2], 0, value*blue/255);
          if(j==2) Serial.println(value);
        }
      }
      showStrip();
      delay(5);
   }
   for(uint8_t i=0; i<5; i++) {
    AnToPWMOnOld[i] = AnToPWMOn[i];   
   }
}



