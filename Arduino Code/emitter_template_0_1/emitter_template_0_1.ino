/*
That's how you see if a beam is interrupted or not.
The line enableIROut(38) modulate the IT beam to 38 KHz, which is the frequence where the 
works best.
*/
#include <IRremote.h>

#define PIN_IR 3//LED IR
#define PIN_DETECT 2//data out of the IR sensor
#define PIN_STATUS 13//LED normal

IRsend irsend;
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_DETECT, INPUT);
  pinMode(PIN_STATUS, OUTPUT);
  irsend.enableIROut(38);
  irsend.mark(0);
}

void loop() {
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT));
  Serial.println(digitalRead(PIN_DETECT));
}
