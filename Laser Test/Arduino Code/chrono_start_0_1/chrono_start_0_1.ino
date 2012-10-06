/*
Here is the sketch for the chronometer's start. 
Basically what it does is that it waits until the laser signal is disconected. 
Then it sends the start signal (s) through the XBee Module. Waits 5 seconds. And ready again.

First we have to calibrate the Light Sensor, so that it will always work, no matter the time.

TODO :
-Integrate a camera that takes a picture just before the signal is sent.(IR Emitter ?)
-Find a way to differenciate skiers (IR Remote ?)
*/
 
const int lightSensorPin = A0; // Pin where the light sensor is attached
const int sensorThreshold = 50; //The threshold to be sure that the sensor is not too sensitive
const char startCharacter = 'a' ;//The character to send to start the chronometer
const int timeToWait = 5000; //The time to wait after the start impulse is given
 
int sensorValue = 0; //The actual value of the sensor
int sensorMin = 1023; //The minimum value when the laser is on the sensor

void setup () {
  initializeSerialCommunication();
  calibrateSensor();
}

void loop () {
  while(sensorMin > analogRead(lightSensorPin) + sensorThreshold);//Barrier that waits for the laser to be cut. (the threshold ensures that it is not due to the weather)
  sendStartSignal();
  delay(timeToWait);
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

void sendStartSignal () {
  Serial.println(startCharacter);
}

