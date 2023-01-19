#include <IRremote.h>
#define IR_TOLERANCE 17
const int RECV_PIN = 2;
decode_results results;


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  printActiveIRProtocols(&Serial);
}
uint32_t IRvalue = 0;
uint32_t getIrValue() {
    uint64_t irVal = 0; 
    IRvalue = 0;
    for(int i=32+3; i<(results.rawlen-1); i++) {
        int Delta = results.rawbuf[i] - results.rawbuf[i+1];
        if (Delta < 0) Delta = -Delta;
        uint8_t b = (Delta < IR_TOLERANCE) ? 0 : 1;
        if ((i-3) < 63) {
            irVal = irVal | ((int64_t)b << (int64_t)(i-3));
        }
    }
    uint32_t x = irVal >> 32;
    if(x !=0) {
    Serial.println("");
    Serial.print(x);
    Serial.print(" /// ");
    Serial.println(x, HEX);
    Serial.println(" /// /// /// /// /// /// /// /// /// /// /// /// ");
    }
    //irrecv.resume(); // get the next signal 
    return x;
}

void IRdecodeType() {
  Serial.println(results.value, HEX);
  switch (results.decode_type){
      case NEC: Serial.println("NEC"); break ;
      case SONY: Serial.println("SONY"); break ;
      case RC5: Serial.println("RC5"); break ;
      case RC6: Serial.println("RC6"); break ;
      //case DISH: Serial.println("DISH"); break ;
      case SHARP: Serial.println("SHARP"); break ;
      case JVC: Serial.println("JVC"); break ;
      //case SANYO: Serial.println("SANYO"); break ;
      //case MITSUBISHI: Serial.println("MITSUBISHI"); break ;
      case SAMSUNG: Serial.println("SAMSUNG"); break ;
      case LG: Serial.println("LG"); break ;
      case WHYNTER: Serial.println("WHYNTER"); break ;
      //case AIWA_RC_T501: Serial.println("AIWA_RC_T501"); break ;
      case PANASONIC: Serial.println("PANASONIC"); break ;
      case DENON: Serial.println("DENON"); break ;
    default:
      case UNKNOWN: Serial.println("UNKNOWN"); break ;
    }
}

void loop(){
  if (IrReceiver.decode()) {

        // Print a short summary of received data
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.printIRSendUsage(&Serial);
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
            // We have an unknown protocol here, print more info
            IrReceiver.printIRResultRawFormatted(&Serial, true);
        }
        Serial.println();

        /*
         * !!!Important!!! Enable receiving of the next value,
         * since receiving has stopped after the end of the current received data packet.
         */
        IrReceiver.resume(); // Enable receiving of the next value

        /*
         * Finally, check the received data and perform actions according to the received command
         */
        if (IrReceiver.decodedIRData.command == 0x10) {
            // do something
        } else if (IrReceiver.decodedIRData.command == 0x11) {
            // do something else
        }
    }
  delay(20);
}
