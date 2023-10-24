/*
 RC PulseIn Joystick
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */

int ch1; // Here's where we'll keep our channel values
int ch2;
int ch3;

void setup() {

pinMode(3, INPUT); // Set our input pins as such


Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {
  
 
  ch2 = pulseIn(3, HIGH, 25000); // each channel

Serial.print(ch3);

Serial.println(); //make some room

delay(100);// I put this here just to make the terminal 
           // window happier
}
