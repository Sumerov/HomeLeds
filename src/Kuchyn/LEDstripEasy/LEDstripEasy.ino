#include <FastLED.h>
#define NUM_LEDS 122
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


int brightness = 255;
int distanceGlobal = 6;
bool buttonStatus = false;
bool blinkWarning = false;
bool LEDon = false;
CRGB warmColor = CRGB(255,200,100);
//CRGB warmColor1Row = CRGB(255*0.8,200,100);

CRGB leds[NUM_LEDS];
void setup() { 
  FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS); 
  FastLED.setBrightness(  brightness  );

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

  pinMode(8,INPUT); 
}
void showAll(int delayC) {
  FastLED.show(); 
  delay(delayC); 
}

void warningLight(int count, int delayMs) {
  FastLED.setBrightness(  5  );
    for(int k=0; k<count; k++) {
      for(int i=0;i<5; i++) {
          leds[i] = 0; 
      }
      showAll(delayMs);
      for(int i=0;i<5; i++) {
          leds[i] = CRGB(255,0,0); 
      }
      showAll(delayMs);
    } 
    FastLED.setBrightness(  brightness  );
    for(int i=0;i<NUM_LEDS; i++) {
          leds[i] = 0; 
    }
    showAll(3);
}

bool checkForContact() {
  /* Trigrovat lze jak tlacitkem, tak radarem + zablika ledka když je pin ve shortu */
  bool statusRead = digitalRead(8);
  if(statusRead != buttonStatus) {
    if(LEDon == true && statusRead == true) blinkWarning = true;
    buttonStatus = statusRead;
    Serial.print("BUTTON IS PRESSED! \n");
    return true; 
  }
 
  // button check
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if(distance < distanceGlobal) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    if(buttonStatus == true && LEDon!=false) blinkWarning = true;
    return true; 
  }  
  return false;
  
}
bool checkForContact2() {
  /* Tlacitko zapina natvrdo svetlo, to nejde vypnout jinak nez tlacitkem */
  bool statusRead = digitalRead(8);
  if(buttonStatus != statusRead) {
    buttonStatus = statusRead;
    if(LEDon != statusRead) return true; 
  } else if(!statusRead) {
    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    if(distance < distanceGlobal) {
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      //if(buttonStatus == true && LEDon!=false) blinkWarning = true;
      return true; 
    }    
  }
  /*
  if(statusRead != buttonStatus) {
    if(LEDon == true && statusRead == true) blinkWarning = true;
    buttonStatus = statusRead;
    Serial.print("BUTTON IS PRESSED! \n");
    return true; 
  }*/
  return false;
}


void lightToogle() {
   if(!LEDon) {
      for(int i=1;i<NUM_LEDS; i++) {
        leds[i] = warmColor;
        showAll(8);
      }  
      LEDon = true;
   } else {
    for(int i=1;i<NUM_LEDS; i++) {
        leds[i] = CRGB(0,0,0); 
        showAll(8);
      }
      LEDon = false;
   }
   if(blinkWarning) {
    blinkWarning = false;
    warningLight(3, 300);
    buttonStatus = digitalRead(8);
   } 
}
  
void loop() {
  if(checkForContact2()) {
    //leds[0] = CRGB::Green;
    lightToogle();
    delay(1000);
  } else {
    //leds[0] = CRGB::Red; 
    //showAll(30);
  }
  delay(100);
}
