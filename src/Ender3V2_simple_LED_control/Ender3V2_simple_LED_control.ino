#include <FastLED.h>
#include <Wire.h>


#define ONOFFPIN 4
#define NUM_LEDS   13
#define STEPS   50.0
#define MINVALUE 30 //pow(1);
#define MINVALUE2 175 //pow(2);
#define MAXVALUE 500
#define FadeMAXVALUE2 250000
uint8_t ledsLenght[] = {NUM_LEDS};
CRGB ledsString[NUM_LEDS];
CRGB *leds[] = {ledsString};
CLEDController *controllers[1];
bool AnToLedsOn[] = {false};
bool AnToLedsOnOld[] = {false};


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
byte brightness = 150;
void firstFunc();
void voidsetAllAnimated(byte red, byte green, byte blue);
void setPixel(uint8_t field, uint8_t Pixel, byte red, byte green, byte blue);
void setAll(byte red, byte green, byte blue);
void RGBLoop();
void showLEDs(int delayI) ;

byte value = 0;
bool pinOnOffState;
byte red = 255;
byte green = 220;
byte blue = 80;
byte counter = 0;
void setup() {
  Serial.begin(9600);
    
  delay(5000);
  pinMode(ONOFFPIN, INPUT);
  for(int i=0; i<1; i++) {
    AnToLedsOn[i] = true;  
  }
  
  //delay(45000);
  controllers[0] = &FastLED.addLeds<WS2812B, 11, GRB>(ledsString, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  brightness  );
  for(uint8_t i = 0; i < NUM_LEDS; i++ ) setPixel(0, i, 0, 0, 0);
  showLEDs(33);
  pinOnOffState = false;
  Serial.print("Hello world");  
}


void loop() {
  if(pinOnOffState != digitalRead(ONOFFPIN)) {
    Serial.print("I am here:");  
    Serial.println(counter);  
    if(counter<10) {
      counter++;
      delay(100);
    }
    if(counter>=10) {
      
      Serial.println("I am here 2 "); 
      pinOnOffState=digitalRead(ONOFFPIN);
      Serial.println(pinOnOffState);
      counter=0;
      if(pinOnOffState) {
          for(uint8_t j = 0; j < STEPS; j++ ) {
            for(uint8_t i = 0; i < NUM_LEDS; i++ ) setPixel(0, i, (byte)red/STEPS*j, (byte)green/STEPS*j, (byte)blue/STEPS*j);
          showLEDs(33);
        } 
      } else {
        for(int8_t j = STEPS; j >= 0; j-- ) {
          for(uint8_t i = 0; i < NUM_LEDS; i++ ) setPixel(0, i, (byte)red/STEPS*j, (byte)green/STEPS*j, (byte)blue/STEPS*j);
          showLEDs(33);
        }
      }
    }
  } else {
    counter=0;
  }
  delay(50); 
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
        
      }
      showStrip();
      delay(3);
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
