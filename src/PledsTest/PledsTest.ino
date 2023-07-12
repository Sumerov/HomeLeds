#include <FastLED.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

#define RELAYPIN 3
#define NUM_LEDS_LEFT   144   //30(144)  
#define NUM_LEDS_MID    149   // 92 (150)
#define NUM_LEDS_MON    14  //109 
#define NUM_LEDS_RIGHT  30   //70 
 

uint8_t ledsLenght[] = {NUM_LEDS_LEFT, NUM_LEDS_MID, NUM_LEDS_MON, NUM_LEDS_RIGHT};
bool AnToLedsOn[] = {false, false, false, false};
bool AnToLedsOnOld[] = {false, false, false, false};
CRGB ledsLeft[NUM_LEDS_LEFT];
CRGB ledsMid[NUM_LEDS_MID];
CRGB ledsMon[NUM_LEDS_MON];
CRGB ledsRight[NUM_LEDS_RIGHT];
CRGB *leds[] = {ledsLeft, ledsMid, ledsMon, ledsRight};
CLEDController *controllers[4];


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
int brightness = 70;

void setup() {
  controllers[0] = &FastLED.addLeds<WS2812B, 6, GRB>(ledsLeft, NUM_LEDS_LEFT).setCorrection( TypicalLEDStrip );
  controllers[1] = &FastLED.addLeds<WS2812B, 11, GRB>(ledsMid, NUM_LEDS_MID).setCorrection( TypicalLEDStrip );
  controllers[2] = &FastLED.addLeds<WS2812B, 10, GRB>(ledsMon, NUM_LEDS_MON).setCorrection( TypicalLEDStrip );
  controllers[3] = &FastLED.addLeds<WS2812B, 9, GRB>(ledsRight, NUM_LEDS_RIGHT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  brightness  );
  //delay(500);
  AnToLedsOn[2] = true;
  for(uint8_t j = 1; j < 100; j++ ) {
    for(uint8_t i = 0; i < NUM_LEDS_MON; i++ ) {
          setPixel(2, i, (byte)j*255/99.0, 0, 0);     
    }
    showLEDs(3);
  }
    
  delay(50000);
  Serial.begin(9600);
  lcd.init(); 
  lcd.noBacklight();
  lcd.setCursor(0,0);
  lcd.print("--------------------");
  lcd.setCursor(0,1);
  lcd.print("----|||------|||----");
   lcd.setCursor(0,2);
  lcd.print("----|||------|||----");
   lcd.setCursor(0,3);
  lcd.print("---------OOO--------");
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
  //irrecv.enableIRIn();
  //irrecv.blink13(true);
  
  delay(500);
}
#define MAXVALUE 500
#define FadeMAXVALUE2 250000
#define MINVALUE 30 //pow(1);
#define MINVALUE2 175 //pow(2);
byte value = 0;



int debug = 0;
void loop() {
  for(int i=0; i<4; i++) {
    AnToLedsOn[i] = true;  
  }
  AnToLedsOn[0] = true; 
  AnToLedsOn[1] = true; 
  /*
  firstFunc();
  delay(4000);*/
  if(debug == 1)Serial.println("first");   
  //fadeToogle(255,160,40);
  if(debug == 1)Serial.println("first END"); 
  //delay(50000); 
  /*
  if(debug == 1)Serial.println("Sec"); 
  
  AnToLedsOn[1] = true;
  AnToLedsOn[2] = true;
  fadeToogle(255,0,40);
  if(debug == 1)Serial.println("sec END"); 
  delay(500);

  if(debug == 1)Serial.println("3th"); 
  AnToLedsOn[0] = true;
  AnToLedsOn[2] = false;
  AnToLedsOn[3] = true;
  fadeToogle(255,40,255);
  if(debug == 1)Serial.println("3th END"); 
  delay(500);
  */

  byte red = 255;
  byte green = 160;
  byte blue = 40;
  
  for(int j = 98; j >= 0; j-- ) {
    for(uint8_t i = 0; i < NUM_LEDS_MON; i++ ) {
        setPixel(2, i, (byte)j*255/98.0, 0, 0);    
    }
    showLEDs(3); 
  }

  for(uint8_t j = 0; j < 100; j++ ) {
    for(uint8_t i = 0; i < NUM_LEDS_MON; i++ ) {
          setPixel(2, i, (byte)j*red/100.0, (byte)j*green/100.0, (byte)j*blue/100.0);     
    }
    showLEDs(3);
  }
    
    for(uint8_t i = 0; i < 30; i++ ) {
        setPixel(0, i, red, green, blue);
        showLEDs(33);
    }

    
   
   int value = 0; 
    for(uint8_t i = 30; i < 87; i++ ) {
      setPixel(0, i, red, green, blue);
      value = 144-i+30-1;
      setPixel(0, value, red, green, blue);
      Serial.print(i,DEC); 
      Serial.print("//");
      Serial.println(value,DEC);  
      showLEDs(33);
    }
    

    for(int i = 148; i > 0; i-=2 ) {
      setPixel(1, i, red, green, blue);
      Serial.println(i,DEC); 
      showLEDs(33);
    }

  for(uint8_t i = 0; i < 240; i++ ) delay(50000); 
  AnToLedsOnOld[0]=true;
  AnToLedsOnOld[1]=true;
  AnToLedsOnOld[2]=true;
}

void showLEDs(int delayI) {
  showStrip();
  delay(delayI);
}


#define FadeMAXVALUE 500
#define FadeMAXVALUE2 250000
#define FadeMINVALUE 30
bool change1[] = {false, false, false, false};
bool change2[] = {false, false, false, false};
void fadeToogle(uint8_t red, uint8_t green, uint8_t blue) {
  int16_t value = 0;
  for(int i=FadeMINVALUE; i<FadeMAXVALUE; i+=3) {
      for(int j=0; j<4; j++) {
        if(AnToLedsOn[j] == AnToLedsOnOld[j]) {
          continue;
        } else if(AnToLedsOn[j] == true) { //FADE IN
          change1[j] = true;
          value = (double)(pow(i,2)/(double)FadeMAXVALUE2)*255;
          if(value<15) continue;
          fill_solid(leds[j], ledsLenght[j], CRGB(value*red/255,value*green/255,value*blue/255));
        } else { //FADE OUT
          
          change2[j] = true;
          value = (double)(pow((FadeMAXVALUE)-i+FadeMINVALUE,2)/(double)FadeMAXVALUE2)*255;
          if(value > 255) value = 255;
          if(FadeMAXVALUE-i>FadeMINVALUE+5 && value<15) {continue;}
          if(FadeMAXVALUE-i<FadeMINVALUE+5) value = 0;
          fill_solid(leds[j], ledsLenght[j], CRGB(value*red/255,value*green/255,value*blue/255));
        }
        if(debug == 2 && j== 2 ) Serial.println(value);
      }
      showStrip();
      delay(3);
   }
   if(debug == 1) {
     for(int i=0; i<4; i++) {
      if(change1[i] == true) {
        Serial.print("change detected FADING IN : ");   
        Serial.println(i); 
        change1[i] = false;    
      }
      if(change2[i] == true) {
        Serial.print("change detected FADING OUT : ");   
        Serial.println(i);     
        change2[i] = false;
      }
   }
  }
    
    for(uint8_t i=0; i<4; i++) {
    AnToLedsOnOld[i] = AnToLedsOn[i];   
   }
}

void firstFunc() {
  for(int k=2; k<4; k++) {
    for(int i=MINVALUE; i<MAXVALUE; i+=3) {
      value = (double)(pow(i,2)/pow(MAXVALUE,2))*255;
      if(value<5*(k+1)) continue;
      Serial.println(value);
      for(int j=0; j<4; j++) {
        fill_solid(leds[j], ledsLenght[j], CRGB(value,value,value));
      }
      showStrip();
      delay(1);
    }
    delay(1000);
    for(int i=MAXVALUE; i>MINVALUE; i-=3) {
      value = (double)(pow(i,2)/pow(MAXVALUE,2))*255;
      if(i>MINVALUE+5 && value<5*(k)) { continue;}
      if(i<MINVALUE+5) value = 0;
      Serial.println(value);
      for(int j=0; j<4; j++) {
        fill_solid(leds[j], ledsLenght[j], CRGB(value,value,value));
      }
      showStrip();
      delay(1);
      if(i<MINVALUE+5) break;
    }
    delay(4000);
  } 
}


int j,k,i;
void RGBLoop() {
  for(j = 0; j < 7; j++ ) {
    // Fade IN
    for(k = 0; k < 255; k++) {
      switch(j) {
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
        case 3: setAll(0,k,k); break;
        case 4: setAll(k,k,0); break;
        case 5: setAll(k,0,k); break;
        case 6: setAll(k,k,k); break;
      }
      showStrip();
      delay(3);
    }
    // Fade OUT
    for(k = 255; k >= 0; k--) {
      switch(j) {
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
        case 3: setAll(0,k,k); break;
        case 4: setAll(k,k,0); break;
        case 5: setAll(k,0,k); break;
        case 6: setAll(k,k,k); break;
      }
      showStrip();
      delay(3);
    }
  }
}

void voidsetAllAnimated(byte red, byte green, byte blue) {
  for(uint8_t i=0; i<300; i+=8) {
    byte value = (double)i*255/300.0;
    setAll(value, value, value);
    showStrip();
    delay(3);
  }
}

void setAll(byte red, byte green, byte blue) {
  for(uint8_t j=0; j<4; j++) {
    for(uint8_t i = 0; i < ledsLenght[j]; i++ ) {
      setPixel(j, i, red, green, blue);
    }
  }
}

CRGB *p;
void setPixel(uint8_t field, uint8_t Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED=
  p = leds[field];
  if(AnToLedsOn[field] == true) {
     p[Pixel].r = red;
     p[Pixel].g = green;
     p[Pixel].b = blue;
  } else {
     p[Pixel].r = 0;
     p[Pixel].g = 0;
     p[Pixel].b = 0; 
  }
 #endif
}
