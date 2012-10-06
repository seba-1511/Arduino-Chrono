/*
 * Here is the code for the chronometer's start, knowing that we are currently using an IR beam.
 * We are using  Ken Shirriff's IRremote library, https://github.com/shirriff/Arduino-IRremote
 */
 
 #include <IRremote.h>
 
 //Here are the main variables
 const int pinIRSensor = 2; //pin of IR Sensor's out-data
 const int pinIRLed = 3; //pin of IR LED (Can't change, because of IRremote)
 const char startCharacter = 'a'; //The character to send to start the chronometer
 const int timeToWait = 5000; //The time to wait after the start impulse is given
 
 IRsend irsend;
 
 void setup () {
  initializeSerialCommunication();
  initializePins();
  initializeIR();
 }
 
 void loop () {
   while (!digitalRead(pinIRSensor));
   sendStartSignal();
   delay(timeToWait);
 }
 
 //Initializing the communication with the other component of the chronometer
 void initializeSerialCommunication () {
  Serial.begin(9600);
 }
 
 //Initialize the I/O pins
 void initializePins () {
   pinMode(pinIRLed, OUTPUT);
   pinMode(pinIRSensor, INPUT);
 }
 
 //Initialize the Infra-Red library and pins
 void initializeIR () {
   irsend.enableIROut(38);
   irsend.mark(0);
 }
 
 //Send the signal to start the chronometer
 void sendStartSignal () {
   Serial.println(startCharacter);
 }
