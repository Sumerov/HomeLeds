#line 1 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V2\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
#include <Wire.h>
#include "Arduino.h"
#include "controlFunctions.h"
#include "coreFunctions.h"
#include "lcdFunctions.h"

#define RELAYPIN 3

extern bool controlOn;
extern IRrecv irrecv;
extern decode_results results;
extern LiquidCrystal_I2C lcd;
extern CLEDController *controllers[];
extern uint8_t brightness;
extern CRGB ledsLeft[NUM_LEDS_LEFT];
extern CRGB ledsMid[NUM_LEDS_MID];
extern CRGB ledsMon[NUM_LEDS_MON];
extern CRGB ledsRight[NUM_LEDS_RIGHT];
extern CRGB *leds[];
extern uint8_t newRGB[];
extern uint8_t AnValChanged[];
extern uint8_t AnVal[];
extern Adafruit_PWMServoDriver pwm;
extern uint8_t controlVal;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
#line 27 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V2\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void setup();
#line 56 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V2\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void loop();
#line 27 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V2\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
void setup() {
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
  
  irrecv.enableIRIn();
  irrecv.blink13(true);

  lcd.init();
  lcd.setBacklight(1);
  setupLCD();
  
  Serial.begin(9600);
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t IRvalue = 0;
int16_t value;
bool controlApplied = false;
void loop() {
  if (irrecv.decode(&results)) {
     IRvalue = getIrValue();
     controlOn = getControlValue(IRvalue);
     if(controlOn) controlOn = getControlAction(newRGB);
  }

  getAnalogValues(controlOn);
  if(AnValChanged[3] && AnVal[3] > 230) controlOn = false; 
  if(controlOn) controlCheckOut();
  else analogCheckOut();
  delay(20);
}


