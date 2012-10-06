/*
 * Here is the code for the end of the chronometer. 
 * We are using  Ken Shirriff's IRremote library, https://github.com/shirriff/Arduino-IRremote 
 
 * At the moment there are some piece of code for writing the time into the SD. For example, 
 * at the end I would like that this detector calculate the time and send it to the display, which will print it.
 */
 
 #include <IRremote.h>
 
 //Here are the main variables
 const int pinIRSensor = 2; //pin of IR Sensor's out-data
 const int pinIRLed = 3; //pin of IR LED (Can't change, because of IRremote)
 const char startCharacter = 'a'; //The character to send to start the chronometer
 const char stopCharacter = 'z'; //The character to send to start the chronometer
 const int timeToWait = 5000; //The time to wait after the start impulse is given
 
 long startTime = 0; //timestamp of when the chrono started
 long endTime = 0; //timestamp of when the chrono ended
 long finalTime = 0; //time it took: startTime - endTime
 
 IRsend irsend; //Object for the IR communication
 
 void setup () {
  initializeSerialCommunication();
  initializePins();
  initializeIR();
 }
 
 void loop () {
  //waitForStart();
  startChrono();
  waitForStop();
  stopChrono();
  sendTimeToDisplay();
  writeTimeInSD();
 }
 
 //Initialize the communication with other components of the chronometer.
 void initializeSerialCommunication () {
  Serial.begin(9600);
 }
 
 //Initializing the I/O pins
 void initializePins () {
   pinMode(pinIRLed, OUTPUT);
   pinMode(pinIRSensor, INPUT);
 }
 
 //Initializing the Infra-Red library
 void initializeIR () {
   irsend.enableIROut(38);
   irsend.mark(0);
 }
 
 //A barrier that waits before starting the internal chronometer
 void waitForStart () {
  while (Serial.available() >= 0 && Serial.read() != startCharacter); //Barrier waiting for the start character
 }
 
 //A barrier to wait for the IR beam to be interrupted
 void waitForStop () {
   while (!digitalRead(pinIRSensor));
 }
 
 //Start the chronometer 
 void startChrono () {
   startTime = millis();
 }
 
 //Stop the chronometer, calculate the final time and send the stop character to the display (for its own track of chronometer)
 void stopChrono () {
   endTime = millis();
   finalTime = endTime - startTime;
   Serial.println(stopCharacter);
 }
 
 // Send time to the display device, so that it can print it.
 void sendTimeToDisplay () {
   Serial.println(finalTime);
 }
 
 //Writes the final time at the end of the table in the SD.
 void writeTimeInSD () {
   //To implement thanks to ReadWrite example from Aduino
 }
