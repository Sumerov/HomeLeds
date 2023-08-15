
// importování knihovny IR
#include <IRremote.h>
// připojení knihovny SoftwareSerial
#include <SoftwareSerial.h>



// nastavení propojovacích pinů Bluetooth
#define RX 0
#define TX 1
#define COUNTERLIMIT 20
// připojení knihovny SoftwareSerial
#include <SoftwareSerial.h>
// inicializace Bluetooth modulu z knihovny SoftwareSerial
SoftwareSerial bluetooth(TX, RX);


// definování pinu přijímače IR
int const receiver = 11;
IRrecv irrecv(receiver); 
// definování pinu LEDky
int const tlac1 = 15;
int const tlac2 = 2;
int const tlac3 = 3;
int const tlac4 = 4;
int const tlac5 = 5;
int const tlac6 = 6;
int const tlac7 = 7;
int const tlac8 = 8;
int const tlac9 = 9;
int const tlac10 = 10;
int const tlac11 = 12;
int const tlac12 = 16;
int tlacitka[12] = { 15, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 16};
bool tlacitkaStatus[12];
bool turnOn = false;
int delayDef = 10;
int timeCounter = 0;

// uložení signálu do proměné "results"
decode_results results; 

void turnOffAll(int ledCH) {
    if( !turnOn || (timeCounter >= COUNTERLIMIT)) {
      timeCounter = 0;
      for(int i=0; i < 12; i++) {
        if( tlacitkaStatus[i] && (!turnOn || i != ledCH) ) {
          digitalWrite(tlacitka[i], HIGH);
        }
      }
      delay(delayDef);
      for(int i=0; i < 12; i++) {
        if( tlacitkaStatus[i] && (!turnOn || i != ledCH) ) {
            digitalWrite(tlacitka[i], LOW);
            tlacitkaStatus[i] = false;
        }
      }
    }
}

void turnOnLED(int ledCH)
{ 
    if(ledCH >= 0 && ledCH < 12){
      //if (!tlacitkaStatus[ledCH]) {
        tlacitkaStatus[ledCH] = !tlacitkaStatus[ledCH];
        digitalWrite(tlacitka[ledCH], HIGH);
        delay(100);
        digitalWrite(tlacitka[ledCH], LOW);
      //}
    }
}

void setup()
{
  turnOn = true;
  for(int i=0; i< 12; i++) {
      tlacitkaStatus[i]=false;
    }
    
  bluetooth.begin(9600);
  bluetooth.println("---------------------------------------------------------");
  bluetooth.println("Lachtrup box - CAN exersizer");
  bluetooth.println("Bluetooth remote control");
  bluetooth.println("Created by J. Retych");
  bluetooth.println("---------------------------------------------------------");
  bluetooth.println("for help, please send letter: h");
  bluetooth.println("---------------------------------------------------------");
 
  // start přijímače
  irrecv.enableIRIn();
  // definování digitálního ledPinu jako výstup
    pinMode(tlac1, OUTPUT);
  // nastavení digitálního ledPinu na LOW (vypnutí diody)
  digitalWrite(tlac1, LOW); 
    pinMode(tlac2, OUTPUT);
  digitalWrite(tlac2, LOW);
    pinMode(tlac3, OUTPUT);
  digitalWrite(tlac3, LOW);
    pinMode(tlac4, OUTPUT);
  digitalWrite(tlac4, LOW);
    pinMode(tlac5, OUTPUT);
  digitalWrite(tlac5, LOW);
    pinMode(tlac6, OUTPUT);
  digitalWrite(tlac6, LOW);
    pinMode(tlac7, OUTPUT);
  digitalWrite(tlac7, LOW);
    pinMode(tlac8, OUTPUT);
  digitalWrite(tlac8, LOW);
    pinMode(tlac9, OUTPUT);
  digitalWrite(tlac9, LOW);
    pinMode(tlac10, OUTPUT);
  digitalWrite(tlac10, LOW);
    pinMode(tlac11, OUTPUT);
  digitalWrite(tlac11, LOW);
    pinMode(tlac12, OUTPUT);
  digitalWrite(tlac12, LOW);


}

void switchCaseCall(int ledCH) {
  turnOffAll(ledCH);
  delay(delayDef);
  timeCounter = 0;
  if(turnOn) turnOnLED(ledCH); 
  turnOn = true; 
}

void loop()
{
  // pokud obdržíš signál, tak
  if (irrecv.decode(&results)) 

  {
    
    //1. tlačítko
    if (results.value == 2382491051 && digitalRead(tlac1) == LOW)
    {
        // zapni LEDku
        digitalWrite(tlac1, HIGH);
        delay(100);
        digitalWrite(tlac1, LOW);
        tlacitkaStatus[0] = true;
    }
    // pokud je hodnota signálu "2382491051" a LEDka svití, tak
    else if (results.value == 2382491051 && digitalRead(tlac1) == HIGH)
    {
      // vypni LEDku
      digitalWrite(tlac1, LOW);
    }

      
  // obdrž další hodnotu (pokračuj)
    irrecv.resume(); 

 //2. Tlačítko
    if (results.value == 2576996685 && digitalRead(tlac2) == LOW)
      {
        digitalWrite(tlac2, HIGH);
        delay(100);
        digitalWrite(tlac2, LOW);
        tlacitkaStatus[1] = true;
      }
    else if (results.value == 2576996685 && digitalRead(tlac2) == HIGH)
      {
       digitalWrite(tlac2, LOW);
      }
  irrecv.resume(); 

 //3. Tlačítko
    if (results.value == 1280352691 && digitalRead(tlac3) == LOW)
      {
        digitalWrite(tlac3, HIGH);
        delay(100);
        digitalWrite(tlac3, LOW);
        tlacitkaStatus[2] = true;
      }
    else if (results.value == 1280352691 && digitalRead(tlac3) == HIGH)
      {
       digitalWrite(tlac3, LOW);
      }
  irrecv.resume(); 

   //4. Tlačítko
    if (results.value == 1299670605 && digitalRead(tlac4) == LOW)
      {
        digitalWrite(tlac4, HIGH);
        delay(100);
        digitalWrite(tlac4, LOW);
        tlacitkaStatus[3] = true;
      }
    else if (results.value == 1299670605 && digitalRead(tlac4) == HIGH)
      {
       digitalWrite(tlac4, LOW);
      }
  irrecv.resume(); 

   //5. Tlačítko
    if (results.value == 2522100439 && digitalRead(tlac5) == LOW)
      {
        digitalWrite(tlac5, HIGH);
        delay(100);
        digitalWrite(tlac5, LOW);
        tlacitkaStatus[4] = true;
      }
    else if (results.value == 2522100439 && digitalRead(tlac5) == HIGH)
      {
       digitalWrite(tlac5, LOW);
      }
  irrecv.resume();

   //6. Tlačítko
    if (results.value == 3117600249 && digitalRead(tlac6) == LOW)
      {
        digitalWrite(tlac6, HIGH);
        delay(100);
        digitalWrite(tlac6, LOW);
        tlacitkaStatus[5] = true;
      }
    else if (results.value == 3117600249 && digitalRead(tlac6) == HIGH)
      {
       digitalWrite(tlac6, LOW);
      }
  irrecv.resume(); 

   //7. Tlačítko
    if (results.value == 2347573463 && digitalRead(tlac7) == LOW)
      {
        digitalWrite(tlac7, HIGH);
        delay(100);
        digitalWrite(tlac7, LOW);
        tlacitkaStatus[6] = true;
      }
    else if (results.value == 2347573463 && digitalRead(tlac7) == HIGH)
      {
       digitalWrite(tlac7, LOW);
      }
  irrecv.resume(); 

 //8. Tlačítko
    if (results.value == 1831672569 && digitalRead(tlac8) == LOW)
      {
        digitalWrite(tlac8, HIGH);
        delay(100);
        digitalWrite(tlac8, LOW);
        tlacitkaStatus[7] = true;
      }
    else if (results.value == 1831672569 && digitalRead(tlac8) == HIGH)
      {
       digitalWrite(tlac8, LOW);
      }
  irrecv.resume(); 

   //9. Tlačítko
    if (results.value == 566754219 && digitalRead(tlac9) == LOW)
      {
        digitalWrite(tlac9, HIGH);
        delay(100);
        digitalWrite(tlac9, LOW);
        tlacitkaStatus[8] = true;
      }
    else if (results.value == 566754219 && digitalRead(tlac9) == HIGH)
      {
       digitalWrite(tlac9, LOW);
      }
  irrecv.resume(); 

   //10. Tlačítko
    if (results.value == 1932751932 && digitalRead(tlac10) == LOW)
      {
        digitalWrite(tlac10, HIGH);
        delay(100);
        digitalWrite(tlac10, LOW);
        tlacitkaStatus[9] = true;
      }
    else if (results.value == 1932751932 && digitalRead(tlac10) == HIGH)
      {
       digitalWrite(tlac10, LOW);
      }
  irrecv.resume(); 

 //11. Tlačítko
    if (results.value == 3870377293 && digitalRead(tlac11) == LOW)
      {
        digitalWrite(tlac11, HIGH);
        delay(100);
        digitalWrite(tlac11, LOW);
        tlacitkaStatus[10] = true;
      }
    else if (results.value == 3870377293 && digitalRead(tlac11) == HIGH)
      {
       digitalWrite(tlac11, LOW);
      }
  irrecv.resume(); 

 //12. Tlačítko
    if (results.value == 52889680 && digitalRead(tlac12) == LOW)
      {
        digitalWrite(tlac12, HIGH);
        delay(100);
        digitalWrite(tlac12, LOW);
        tlacitkaStatus[11] = true;
      }
    else if (results.value == 52889680 && digitalRead(tlac12) == HIGH)
      {
       digitalWrite(tlac12, LOW);
      }
  irrecv.resume();    
}
  // proměnná pro ukládání dat z Bluetooth modulu
  byte BluetoothData;
  // kontrola Bluetooth komunikace, pokud je dostupná nová
  // zpráva, tak nám tato funkce vrátí počet jejích znaků
  if (bluetooth.available() > 0) {
    // načtení prvního znaku ve frontě do proměnné
    BluetoothData=bluetooth.read();
    // dekódování přijatého znaku
    switch (BluetoothData) {
      // každý case obsahuje dekódování jednoho znaku
      case '0': {
        bluetooth.println("All OFF");
        turnOn = false;
        switchCaseCall(0); // any channel
        break; }
      case '1': {
        bluetooth.println("LB (Abblendlicht)");
        switchCaseCall(0);
        break; }
      case '2': {
        bluetooth.println("LB+HB (Fernlicht)");
        switchCaseCall(1);
        break; }
      case '3': {
        bluetooth.println("DRL (Tagfahrlicht)");
        switchCaseCall(2);
        break; }
      case '4': {
        bluetooth.println("PO+SML (Positionslicht)");
        switchCaseCall(3);
        break; }
      case '5': {
        bluetooth.println("CL Left (abbiegelicht L)");
        switchCaseCall(4);
        break; }
      case '6': {
        bluetooth.println("CL Right (abbiegelicht R)");
        switchCaseCall(5);
        break; }
      case '7': {
        bluetooth.println("DI-blinking (Warnblinker)");
        switchCaseCall(6);
        break; }
      case '8': {
        bluetooth.println("DI (Blinker Dauerlicht)");
        switchCaseCall(7);
        break; }
      case '9': {
        bluetooth.println("PO+SML (Parklicht)");
        switchCaseCall(8);
        break; }
      case 'a': {
        bluetooth.println("NSI");
        switchCaseCall(9);
        break; }
      case 'b': {
        bluetooth.println("F1: FailSafe / SML");
        switchCaseCall(10);
        break; }
     case 'c': {
        bluetooth.println("F2");
        switchCaseCall(11);
        break; }
     case 'h': {
        bluetooth.println("---------------------------------------------------------");
        bluetooth.println("Lachtrup box - CAN exersizer");
        bluetooth.println("<<HELP menu>>");
        bluetooth.println("---- Created by J. Retych");
        bluetooth.println("---------------------------------------------------------");
        bluetooth.println("How it works: When a command is send the assigned button will be pressed");
        bluetooth.println("1) To turn on multiple functions, simple send next command without 2 seconds. Previous commands are kept.");
        bluetooth.println("2) To turn only 1 function at time just wait 2 seconds between commands. Previous commands are forgotten.");
        bluetooth.println("---------------------------------------------------------");
        bluetooth.println("0 => Turn all OFF");
        bluetooth.println("1 => LB (Abblendlicht)");
        bluetooth.println("2 => LB+HB (Fernlicht)");
        bluetooth.println("3 => DRL (Tagfahrlicht)");
        bluetooth.println("4 => PO+SML (Positionslicht)");
        bluetooth.println("5 => CL Left (abbiegelicht L)");
        bluetooth.println("6 => CL Right (abbiegelicht R)");
        bluetooth.println("7 => DI-blinking (Warnblinker)");
        bluetooth.println("8 => DI (Blinker Dauerlicht)");
        bluetooth.println("9 => PO+SML (Parklicht)");
        bluetooth.println("a => NSI");
        bluetooth.println("b => F1: FailSafe / SML");
        bluetooth.println("c => F2");
        bluetooth.println("h => HELP menu");
        bluetooth.println("-------------------------------------");
        break; }

      case '\r': {
        break; 
      }

      case '\n': {
        break; 
      }
      default: {
        // v případě přijetí ostatních znaků
        // vytiskneme informaci o neznámé zprávě
        bluetooth.println("Not defined command - for help, please send letter: h");
        break; }
    }
    //bluetooth.println("");
  }
  // krátká pauza mezi kontrolami komunikace Bluetooth modulu
  delay(100);
  if(timeCounter < COUNTERLIMIT+1) timeCounter++;
  }
