#include "coreFunctions.h"


bool getBooleansFromAn(uint8_t **control, uint8_t pos, uint8_t pos2, uint8_t *sizes) {
    uint8_t *p = control[pos];
    for(uint8_t i=0; i<sizes[pos]; i++) {
      if(AnVal[pos2] >= p[i]-resultOffset && AnVal[pos2] <= p[i]+resultOffset) {
        if(pos2==0) AnToLedsOn[pos] = true;
        if(pos2==1) AnToPWMOn[pos] = true;
        break;
      }
    }

  // DEBUGGING
  Serial.print("PLEDvals: ");
  for(uint8_t i = 0; i<4; i++) {
    Serial.print(AnToLedsOn[i]);
    if(i<3) Serial.print(", "); 
  } Serial.println(""); 
  Serial.print("PWMvals: "); 
  for(uint8_t i = 0; i<4 ; i++) {
    Serial.print(AnToPWMOn[i]);
    if(i<3) Serial.print(", "); 
  } Serial.println(""); 
  
  Serial.println("//////////////");
  return false;
}

void getAnalogValues(bool controlOn) {
  uint8_t startFrom = 0;
  uint8_t val = 0;
  bool changed = false;
  if(controlOn) startFrom = 3; 
  
  for(uint8_t i=startFrom; i<4; i++) {
    delay(20);
    val = (uint8_t) ((double) analogRead(Analogs[i])/1023.0 * 255.0); 
    if(i<2) {
      if(val >= 50 && ((val <= AnVal[i]-AnalogOffset) || (val >= AnVal[i]+AnalogOffset))) {
        if(counters[i] > 0) {
          counters[i] --;  
        } else {
          AnVal[i] = val;
          AnValChanged[i] = true; 
          changed = true; 
          //counters[i] = 3;
        }
      } 
    } if(i>1) {
      if(val >= 50 && ((val <= AnVal[i]-10*AnalogOffset) || (val >= AnVal[i]+10*AnalogOffset))) {
        if(counters[i] > 0) {
          counters[i] --;  
        } else {
          AnVal[i] = val;
          AnValChanged[i] = true;  
          changed = true; 
          counters[i] = 3;
        }  
      }  
    } 
  } 
  // DEBUGGING
  if(changed) {
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