#include <IRremote.h>
#define IR_TOLERANCE 17
const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
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
    irrecv.resume(); // get the next signal 
    return x;
}

void IRdecodeType() {
  Serial.println(results.value, HEX);
  switch (results.decode_type){
      case NEC: Serial.println("NEC"); break ;
      case SONY: Serial.println("SONY"); break ;
      case RC5: Serial.println("RC5"); break ;
      case RC6: Serial.println("RC6"); break ;
      case DISH: Serial.println("DISH"); break ;
      case SHARP: Serial.println("SHARP"); break ;
      case JVC: Serial.println("JVC"); break ;
      case SANYO: Serial.println("SANYO"); break ;
      case MITSUBISHI: Serial.println("MITSUBISHI"); break ;
      case SAMSUNG: Serial.println("SAMSUNG"); break ;
      case LG: Serial.println("LG"); break ;
      case WHYNTER: Serial.println("WHYNTER"); break ;
      case AIWA_RC_T501: Serial.println("AIWA_RC_T501"); break ;
      case PANASONIC: Serial.println("PANASONIC"); break ;
      case DENON: Serial.println("DENON"); break ;
    default:
      case UNKNOWN: Serial.println("UNKNOWN"); break ;
    }
}

void loop(){
  if (irrecv.decode(&results)) {
     IRdecodeType();
     //IRvalue = getIrValue();

     if(IRvalue != 0 ) {
    
    }
    irrecv.resume();
  }
    
  
  delay(20);
}
