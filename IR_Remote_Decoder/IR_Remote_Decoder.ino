#include <IRremote.h>

int Receive_Pin = 2;
IRrecv IR_Receive(Receive_Pin);
decode_results Results;

void setup()
{
  Serial.begin(9600);
  IR_Receive.enableIRIn();
}

void loop() 
{
   if (IR_Receive.decode( & Results)) 
     {
       Serial.println(Results.value, HEX);
       IR_Receive.resume();
     }
     delay(100);
}
