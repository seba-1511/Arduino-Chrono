/*
 * Here is the code for the display of the time of the chronometer.
 /!\ If you want to use an Arduino Uno/2009, you have to change Serial1 by Serial.(Sorial one)
 * Serial1 works only for Arduino Leonardo. And change the pin in the LiquidCrystal initialization line (19)
 */
#include "LiquidCrystal.h" //ajout de la librairie

 //Here are own main variables
 const char startCharacter = 'a'; //The character to receive to start the chronometer
 const char stopCharacter = 'z'; //The character to receive to stop the chronometer
 
 long startTime = 1; //That's the timestamp of when the chrono was started
 long endTime = 1; //The timestamp of when the chrono has ended
 long finalTime = 1; //Basically endTime - startTime
 long chronoTime = 1; //The time from the other arduino, to do a comparison
 
 //If Arduino != Leonardo replace 13 by 11
 LiquidCrystal lcd(13,10,5,4,3,2);
 
 void setup () {
   initializeLCD();
   initializeSerial1();
 }
 
 void loop () {
   displayTime();
   waitForStart();
   startChronometer();
   waitForStopAndDisplay();
   stopChronometer();
 }
 
 //Initializing the LCD library and showing a loading message
 void initializeLCD () {
   lcd.begin(16,2); 
   lcd.write("Initialisation"); 
   lcd.setCursor(0, 1);
   lcd.write("en cours...");
 }
 
 //Starting Serial communication to communicate to the other components of the chrono
 void initializeSerial1 () {
   Serial1.begin(9600);
 }
 
 //Barrier waiting for a signal to start the chronometer
 void waitForStart () {
  while (Serial1.read() != startCharacter);
 }
 
 //Actually starting the chronometer by storing when whe chrono started
 void startChronometer () {
   startTime = millis();
 } 
 
 //While the chrono is running, this function shows the time running.
 void waitForStopAndDisplay () {
  lcd.clear();
  lcd.home(); 
  lcd.write("En course !");
  while ( Serial1.read() != stopCharacter) {
   lcd.setCursor(0, 1);
   //The following 6 lines are awful. I'd like to make a function for them...
   long time = millis() - startTime;
   int centi = (int)(time%1000)/10;
   int sec = (int) ((time%60000) / 1000L);
   int minutes = (int)(time/60000L);
   char message[16] = "";
   char text[7] = "Temps:";
   sprintf(message, "%s %2d.%2d.%2d",text, minutes, sec, centi);
    lcd.write(message);
    delay(100);
  }
  //Not sure if it is really working right...
  chronoTime = Serial1.read();
 }
 
 //Stops the chronometer and calculate the time
 void stopChronometer () {
   endTime = millis();
   finalTime = endTime - startTime;
 }
 
 //Display the time and prints that it waits for a racer to go
 void displayTime () {
   if (chronoTime == startCharacter || chronoTime == ' ') {
     chronoTime = finalTime;
   }
   lcd.clear();
   lcd.home();  
   //Part to modify, because horrible and repeated many times...
   long time = endTime - startTime;
   int centi = (int)(time%1000)/10;
   int sec = (int) ((time%60000) / 1000L);
   int minutes = (int)(time/60000L);
   char message[16] = "";
   char text[7] = "Temps:";
   sprintf(message, "%s %2d.%2d.%2d",text, minutes, sec, centi);
   
   lcd.write(message);
   lcd.setCursor(0, 1);
   lcd.write("Attente depart");
 }
