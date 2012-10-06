/*
Here is the sketch for the chronometer's end.

Firstly we have to calibrate the light sensor.
Then we wait for a signal from the start cell. (Through Serial Communication)
After that, we wait for the light sensor to change its value.
Finally we sto the chrono and write the time in the SD card.

TODO :
-Find a way for multiple skiers to race at the same time
-Include the video camera that starts and end when the chrono is on.
*/
#include <SD.h> 
 
const int lightSensorPin = A0; // Pin where the light sensor is attached
const int sensorThreshold = 50; //The threshold to be sure that the sensor is not too sensitive
const char startCharacter = 'a' ;//The character to send to start the chronometer
 
int sensorValue = 0; //The actual value of the sensor
int sensorMin = 1023; //The minimum value when the laser is on the sensor
int startTime = 0; //The time when the chrono starts
int endTime = 0; //The time when the chrono ends
int finalTime = 0; //The time of the actual skier

void setup () {
  initializeSerialCommunication();
  calibrateSensor();
}

void loop () {
  waitForStart();
  startChrono();
  waitForStop();
  stopChrono();
  writeTimeInSD();
}

void initializeSerialCommunication () {
  Serial.begin(9600);
}

void calibrateSensor () {
  while (millis() < 5000) {
    sensorValue = analogRead(lightSensorPin);
    if (sensorMin > sensorValue) {
      sensorMin = sensorValue;
    }
  }
}

void waitForStart () {
  while (Serial.Read() != startCharacter); //Barrier waiting for the start character
}

void waitForStop () {
  while (sensorMin > analogRead(lightSensorPin) + sensorThreshold); //Barrier waiting for the laser to be cut
}

void startChrono() {
  startTime = millis();
}

void stopChrono () {
  endTime = millis();
  finalTime = endTime - startTime;
}

void writeTimeInSD () {
  //To implement thanks to ReadWrite example from Aduino
}

