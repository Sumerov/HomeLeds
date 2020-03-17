#include "lcdFunctions.h"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
uint8_t LCDcursor = 0;

extern uint8_t AnVal[];
extern uint8_t brightness;
extern uint8_t currentBrightness;
extern bool AnToLedsOn[];
extern bool AnToPWMOn[];
extern bool AnToLedsOnOld[];
extern bool AnToPWMOnOld[];
extern uint8_t controlVal;
extern bool debugLCDswitch;
extern bool backlightLCDswitch;
bool backlightChanged = false;

char *string_table[] = {
                  "|>Brightness: ",
                  "|>ControlVal: ",
                  "|> PWMs:  ",
                  "|>Pleds: ",
                  "|> A0/A1: ",
                  "|> A2/A3: "
                  };
char buffer1[21];
char buffer2[12]; 

void fillUpDisplay(char endSymbol[2]) {
  uint8_t strCount = strlen(buffer1);  
  for(uint8_t j=0; j<20-(strCount+1); j++) {
    strcat(buffer1, " ");
  }
  strcat(buffer1, endSymbol);
}

void debugLCD(bool refreshRows[4], bool oldOrNew) {
  if(backlightChanged != backlightLCDswitch) {
    if(backlightLCDswitch) lcd.backlight();
    else lcd.noBacklight();
    backlightChanged = backlightLCDswitch;
  }

  for(uint8_t i=0; i<4; i++) {
    if(refreshRows[i]) {
      lcd.setCursor(0, i); 
      switch(i) {
        case 0: {
          sprintf(buffer2, "%d", currentBrightness);
          break;
        } 
        case 2: {
          if(debugLCDswitch) {
            if(AnVal[0]<10) sprintf(buffer2, "  %d/%d", AnVal[0], AnVal[1]);
            else if (AnVal[0]<100) sprintf(buffer2, " %d/%d", AnVal[0], AnVal[1]);
            else sprintf(buffer2, "%d/%d", AnVal[0], AnVal[1]);
          }
          else 
            if(oldOrNew) sprintf(buffer2, "%d|%d|%d|%d", AnToLedsOn[0], AnToLedsOn[1], AnToLedsOn[2], AnToLedsOn[3]);
            else sprintf(buffer2, "%d|%d|%d|%d", AnToLedsOnOld[0], AnToLedsOnOld[1], AnToLedsOnOld[2], AnToLedsOnOld[3]);
          break;
        }
        case 3: {
          if(debugLCDswitch) {
            if(AnVal[2]<10) sprintf(buffer2, "  %d/%d", AnVal[2], AnVal[3]);
            else if (AnVal[2]<100) sprintf(buffer2, " %d/%d", AnVal[2], AnVal[3]);
            else sprintf(buffer2, "%d/%d", AnVal[2], AnVal[3]);

          } 
          else 
            if(oldOrNew) sprintf(buffer2, "%d|%d|%d|%d|%d", AnToPWMOn[0], AnToPWMOn[1], AnToPWMOn[2], AnToPWMOn[3], AnToPWMOn[4]);
            else sprintf(buffer2, "%d|%d|%d|%d|%d", AnToPWMOnOld[0], AnToPWMOnOld[1], AnToPWMOnOld[2], AnToPWMOnOld[3], AnToPWMOnOld[4]);
          break;
        } 
        case 1: {
          sprintf(buffer2, "%d", controlVal);
          break;
        }       
      }
      if((i==2 || i==3) && debugLCDswitch) {
        strcpy(buffer1, string_table[i+2]);
      } else {
        strcpy(buffer1, string_table[i]);
      }
      strcat(buffer1, buffer2);
      fillUpDisplay("|");
      lcd.print(buffer1);
    }  
  }
}

void setupLCD() {
  lcd.clear();
  lcd.setCursor(0, 0); 
  for(uint8_t i=0; i<4; i++) {
    strcpy(buffer1, string_table[i]); 
    fillUpDisplay("|");
    lcd.print(buffer1); 
    lcd.setCursor(0, 1+i); 
  }
}