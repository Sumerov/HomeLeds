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
extern bool debugLCDswitch;
extern bool backlightLCDswitch;
extern bool AnChanged;
extern uint8_t currentBrightness;
extern bool runLCD;
extern bool LCDRefreshRows[];

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
  
  irrecv.enableIRIn();
  irrecv.blink13(true);

  lcd.init();
  lcd.setBacklight(1);
  setupLCD();
  
  Serial.begin(115200);
  controllers[0] = &FastLED.addLeds<WS2812B, 6, GRB>(ledsLeft, NUM_LEDS_LEFT).setCorrection( TypicalLEDStrip );
  controllers[1] = &FastLED.addLeds<WS2812B, 10, GRB>(ledsMid, NUM_LEDS_MID).setCorrection( TypicalLEDStrip );
  controllers[2] = &FastLED.addLeds<WS2812B, 11, GRB>(ledsMon, NUM_LEDS_MON).setCorrection( TypicalLEDStrip );
  controllers[3] = &FastLED.addLeds<WS2812B, 9, GRB>(ledsRight, NUM_LEDS_RIGHT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  brightness  );
  currentBrightness = brightness;
  
  Serial.println("Setup done...");
  introSetup();
  Serial.println("Loop starting...");
  Serial.println("-------------------");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t IRvalue = 0;
int16_t value;
bool controlApplied = false;

void loop() {
  if (irrecv.decode(&results)) {
    IRvalue = IRdecodeType();
    controlOn = getControlValue(IRvalue);
    if(controlOn) controlOn = getControlAction(newRGB);
    bool LCDRefreshRows[] = {0,1,0,0};
    debugLCD(LCDRefreshRows, true);
  }
  

  getAnalogValues(controlOn);
  if(AnChanged) runLCD=true;
  if(AnValChanged[3] && AnVal[3] > 230) controlOn = false; 
  if(controlOn) controlCheckOut();
  else analogCheckOut();
  if(runLCD) {
    bool LCDRefreshRows[] = {1,1,1,1};
    debugLCD(LCDRefreshRows, false);
    runLCD = false;
  }
  delay(20);
}

