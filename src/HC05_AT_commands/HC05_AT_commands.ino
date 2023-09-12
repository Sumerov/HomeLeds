/*

AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)


HC-05 GND --- Arduino GND Pin
 HC-05 VCC (5V) --- Arduino 5V
 HC-05 TX --- Arduino Pin 10 (soft RX)
 HC-05 RX --- Arduino Pin11 (soft TX)
 HC-05 Key (PIN 34) --- Arduino Pin 9

  Wire the HC-05 and Arduino Uno per instructions.
 BEFORE YOU CONNECT THE ARDUINO TO THE USB remove the VCC (power) red wire from the HC-05 so it's not getting any power from the Arduino. All other wires are still connected.
 Now connect the Arduino Uno to the USB cable extended from your PC.
 Make sure the HC-05 module is NOT PAIRED with any other Bluetooth device.
 Re-connect the Arduino Uno 5V wire to the HC-05's VCC (5V power) pin.
 The HC-05 LED will blink on and off at about 2 second intervals. Now the HC-05 is in AT command mode ready to accept commands to change configuration and settings.
 To test if everything is wired correctly,  open the Serial Monitor from the Arduino IDE and type "AT" and click SEND. You should see an "OK"
 If you don't see an "OK" check your wiring.
*/


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
