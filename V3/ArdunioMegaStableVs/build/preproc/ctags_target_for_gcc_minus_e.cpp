# 1 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V3\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino"
# 2 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V3\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino" 2
# 3 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V3\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino" 2
# 4 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V3\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino" 2
# 5 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V3\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino" 2
# 6 "r:\\DOWNLOAD\\škola\\ardunio\\HomeLedsprojects\\V3\\ArdunioMegaStableVs\\ArdunioMegaStableVs.ino" 2



extern bool controlOn;
extern IRrecv irrecv;
extern decode_results results;
extern LiquidCrystal_I2C lcd;
extern CLEDController *controllers[];
extern uint8_t brightness;
extern CRGB ledsLeft[60 /*60  */];
extern CRGB ledsMid[80 /*80*/];
extern CRGB ledsMon[109 /*109 */];
extern CRGB ledsRight[70 /*70 */];
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
  pinMode(3, 0x1);
  digitalWrite(3, 0x0);

  irrecv.enableIRIn();
  irrecv.blink13(true);

  lcd.init();
  lcd.setBacklight(1);
  setupLCD();

  Serial.begin(9600);
  controllers[0] = &FastLED.addLeds<WS2812B, 6, GRB>(ledsLeft, 60 /*60  */).setCorrection( TypicalLEDStrip );
  controllers[1] = &FastLED.addLeds<WS2812B, 10, GRB>(ledsMid, 80 /*80*/).setCorrection( TypicalLEDStrip );
  controllers[2] = &FastLED.addLeds<WS2812B, 11, GRB>(ledsMon, 109 /*109 */).setCorrection( TypicalLEDStrip );
  controllers[3] = &FastLED.addLeds<WS2812B, 9, GRB>(ledsRight, 70 /*70 */).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( brightness );
  currentBrightness = brightness;
  pwm.begin();
  for(uint8_t j = 0; j<16; j++) {
      pwm.setPWM(j, 0, 0);
  }
  delay(1000);
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
    IRvalue = getIrValue();
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
