#include "lcdFunctions.h"

char buffer[13];
char buffer2[9];
const char string_0[] PROGMEM = " Brightness: "; // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "  A0/A1: ";
const char string_2[] PROGMEM = "  A2/A3: ";
const char string_3[] PROGMEM = "/";
const char string_4[] PROGMEM = " ";
const char *const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4};

void debugLCD(uint8_t vals[4], LiquidCrystal_I2C *lcd) {
  for(uint8_t i=0; i<3; i++) {
  lcd->setCursor(0, i); 
  switch(i) {
    case 0: {
      sprintf_P(buffer2, "%d", brightness);
      break;
    } 
    case 1: {
      if(vals[0]<1000) {
        sprintf_P(buffer2, " %d/%d", vals[0], vals[1]);
      }
      else sprintf_P(buffer2, "%d/%d", vals[0], vals[1]);
      break;
    }
    case 2: {
      sprintf_P(buffer2, "%d/%d", vals[2], vals[3]);
      break;
      }    
    }
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
    strcat(buffer, buffer2);
    lcd->print(buffer);
  }  
}

void setupLCD(LiquidCrystal_I2C *lcd) {
  lcd->clear();
  lcd->setCursor(0, 0); 
  for(uint8_t i=0; i<3; i++) {
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i]))); 
    lcd->print(buffer); 
    lcd->setCursor(0, 1+i); 
  }
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[3]))); 
  lcd->setCursor(13, 1); 
  lcd->print(buffer); 
  lcd->setCursor(13, 2);
  lcd->print(buffer); 
}