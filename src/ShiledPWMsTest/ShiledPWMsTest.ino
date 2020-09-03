#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define RELAYPIN 3
#define SHIELDPWMMAX  4095
#define SHIELDPWMMAXPOW 16769025
#define SHIELDPWMMAXDUTY  99
 int delay222= 500;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define LED_PIN     6
#define LED_PIN2    10
#define NUM_LEDS    20
#define BRIGHTNESS  30
int i = 0;
uint8_t Pwms1[] = {6,9,10,11};
uint8_t Pwms4[] = {2, 1, 0, 4, 5, 6, 8, 9, 10, 12, 13, 14, 7, 11, 3};
uint8_t ShieldPwms[] = {12, 13, 14, 4, 5, 6 , 8, 9, 10, 0, 1, 2, 3, 7, 11};


int incomingByte = 0; // for incoming serial data
void setup() {
  Serial.begin(9600);
  //Serial.println("16 channel PWM test!");
  
  pwm.begin();
  pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
  for(int j = 0; j<16; j++) {
      pwm.setPWM(j, 0, 0);
  }

  //pinMode(RELAYPIN, OUTPUT);  
  //digitalWrite(RELAYPIN, LOW);
  delay(1000);
  double value = 0;
}

#define FadeMAXVALUEPWM 500
#define FadeMAXVALUEPWM2 250000
#define FadeMINVALUEPWM 30
bool AnToPWMOn[] = {false, false, false, false, false};
bool AnToPWMOnOld[] = {false, false, false, false, false};
uint8_t newRGB[] = {240,240,60};
uint8_t currentRGB[] = {240,240,60};
uint16_t currentRGBpwm[] = {3765,3765,940};

uint8_t currentBrightness = 130;

void loop() {

//Serial.println("START");
/*
//////////////////////////////////////////
AnToPWMOn[1] = true;   //fadein
fadeTooglePwm(245, 100, 245, false);
delay(1000);
AnToPWMOn[1] = true; //fadeout
fadeTooglePwm(100, 150, 245, false);
delay(1000);
AnToPWMOn[1] = false; //changecolor
fadeTooglePwm(245, 245, 245, false);
delay(1000);
for(uint8_t i=0;i<5;i++) AnToPWMOn[i] = false; 
fadeTooglePwm(80, 100, 120, false);
delay(1000);
delay(1000);
////////////////////////////////////////////
*/
////////////////////////////////////////////
//introtest
for(uint8_t i=0;i<5;i++) AnToPWMOn[i] = true; 
delay(1000);
fadeTooglePwm(245, 245, 245, false);
delay(1000);
fadeTooglePwm(245, 0, 0, false);
delay(500);
fadeTooglePwm(0, 245, 0, false);
delay(500);
fadeTooglePwm(0, 0, 245, false);
delay(500);
fadeTooglePwm(245, 245, 60, false);
delay(500); 
for(uint8_t i=0;i<5;i++) AnToPWMOn[i] = false;
fadeTooglePwm(245, 245, 60, false);
////////////////////////////////////////////

/*
for(uint8_t i=0;i<5;i++) AnToPWMOn[i] = false; 
fadeTooglePwm(245, 245, 60, false);*/
delay(1000);
delay(1000);
//Serial.println("done");


/*
  introSetup();
  delay(4000);
*/
  
 /*
  for(i=0; i<15; i++) {
      for(int j = 0; j<15; j++) {
        pwm.setPWM(ShieldPwms[j], 0, 0);
      }
      delay(500);
    
      pwm.setPWM(ShieldPwms[i], 0, 2000);
      delay(4000);
   }*/
/*
   //RBBBB
   //BRRRR
   delay(4000);
   
   for(int j = 0; j<15; j++) {
        pwm.setPWM(ShieldPwms[j], 0, 0);
   }
      
   for(int j=0;j<3;j++) {
    for(int j = 0; j<15; j++) {
        pwm.setPWM(ShieldPwms[j], 0, 0);
     }
     delay(500);
      for(int i = 0; i<5; i++) {
        pwm.setPWM(ShieldPwms[j+3*i], 0, 2000);  
        delay(1000);
      }
      delay(1000);
   }
   
  for(int j = 0; j<15; j++) {
      pwm.setPWM(ShieldPwms[j], 0, 2000);
  }
  */
}


void writePwmsValue(uint16_t *rgb, uint8_t index) {
  uint16_t RGBfinal[] = {0,0,0};
  for(uint8_t p=0;p<3;p++) {
    RGBfinal[p] = (uint16_t) ((double)rgb[p]*currentBrightness / 255.0);
    pwm.setPWM(ShieldPwms[3*index + p], 0, RGBfinal[p]);
  }

  if(index==1) {
          Serial.print(RGBfinal[0]);
          Serial.print(", ");
          Serial.print(RGBfinal[1]);
          Serial.print(", ");
          Serial.println(RGBfinal[2]);
  }
}

void fadeTooglePwm(uint8_t red, uint8_t green, uint8_t blue, bool reset) {
  //bool LCDRefreshRows[] = {0,0,1,1};
  //debugLCD(LCDRefreshRows, true);
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
                  //if(k==1 && j == 0) Serial.println(calcVal+3);
                }
              } else {
                 if(calcRGB[k] >= setRGB[k]) {
                  calcVal = (double)(pow((FadeMAXVALUEPWM)-i+FadeMINVALUEPWM,2)/(double)FadeMAXVALUEPWM2);
                  calcRGB[k] = (uint16_t) (setRGB[k] + calcVal*(double)(currentRGBpwm[k]-setRGB[k]));
                  //if(k==1 && j == 0) Serial.println(calcVal);
                }
              }
              if(j==0 && k == 1) {
                //Serial.println(directionSwitch[k]); // 0,1,0,1
                /*Serial.print(", ");
                Serial.print(calcRGB[k]); // 
                Serial.print(", ");*/
                //Serial.println(setRGB[k]); // 0,4000,0,4000
                //Serial.println(calcRGB[k]);  // 4000, nahoru, 4000, nahoru
                //Serial.println(calcVal);
              }
            
            } 
            ChangeCalc = true;
          }
          // Vykresleni Change Color 
          writePwmsValue(calcRGB, j);
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
          // Vykresleni Fade Out
          writePwmsValue(RGBfadeOut, j);
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

void introSetup() {
  uint16_t value;
  for(uint16_t i=0; i < SHIELDPWMMAX; i+=16) {
    value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
    for(uint16_t j = 0; j<15; j++) {
      pwm.setPWM(ShieldPwms[j], 0, value);
    }
    delay(2);
    Serial.println(value);
  }
  delay(500);
  for(int16_t i=SHIELDPWMMAX; i > 0; i-=16) {
    value = (double)pow(i, 3)/(double)SHIELDPWMMAXPOW * (double)SHIELDPWMMAXDUTY / 100.0;
    for(uint16_t j = 0; j<15; j++) {
      if(j == 3) continue;
      pwm.setPWM(ShieldPwms[j], 0, value);
    }
    delay(2);
    Serial.println(value);
  }
} 
