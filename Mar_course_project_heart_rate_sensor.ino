#define USE_ARDUINO_INTERRUPTS true // low level interrupts for most accurate BPM
#include <PulseSensorPlayground.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 11, 5, 6, 7, 8);

//variables
const int PulseWire = 0; // connected to ANALOG PIN 0
const int LED13=10;
int Threshold = 550; // determine which signal to "count as beat" and which to ignore

PulseSensorPlayground pulseSensor; // creates an instance of the library object


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
    
    // Configure the PulseSensor object, by assigning our variables to it.
pulseSensor.analogInput(PulseWire);
pulseSensor.blinkOnPulse(LED13); // blinks Arduino's LED with heartbeat.
pulseSensor.setThreshold(Threshold);
 
 if (pulseSensor.begin()) {
     lcd.setCursor(0,0);
     lcd.print("Heart");
 }


}

void loop() {
  // put your main code here, to run repeatedly:
  int myBPM=pulseSensor.getBeatsPerMinute(); // calls function on our pulseSensor object to return BPM as an integer
if (pulseSensor.sawStartOfBeat());{ // tests to see if beats happened
lcd.setCursor(0,0);
lcd.print("Heartbeat"); //when test comes true
lcd.setCursor(3,1);
lcd.print("BPM: ");
lcd.print(myBPM);
}
delay(100);
}
  
