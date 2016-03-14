/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants
const int buttonPin2 = 2;     // the number of the pushbutton pin
const int buttonPin7 = 7;     // the number of the pushbutton pin
const int ledPin =  12;      // the number of the LED pin

// variables
int buttonPin2EtatActuel = HIGH;         // variable for reading the pushbutton status
int buttonPin2EtatAncien = HIGH;
int buttonPin7EtatActuel = HIGH;         // variable for reading the pushbutton status
int buttonPin7EtatAncien = HIGH;
int count = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  // replace INPUT with INPUT_PULLUP to prevent interferences
  // Add serial link
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonPin2EtatActuel  = digitalRead(buttonPin2);
  buttonPin7EtatActuel  = digitalRead(buttonPin7);
  
  // Increment
  if (buttonPin2EtatAncien == LOW && buttonPin2EtatActuel  == HIGH) {
    if (count < 5) {
    Serial.println(++count);    
    }
  }
  buttonPin2EtatAncien = buttonPin2EtatActuel;

  // Decrement
  if (buttonPin7EtatAncien == LOW && buttonPin7EtatActuel  == HIGH) {
    if (count > 0) {
    Serial.println(--count);    
    }
  }
  buttonPin7EtatAncien = buttonPin7EtatActuel;

  //allumage
  if (count == 5) {
      digitalWrite(ledPin, HIGH);
  } else {
      digitalWrite(ledPin, LOW);
  }
 }
 //arduino a deux bouton qui gere l'incrementation(1) et la decrementation(2) d'un comppteur afficher en console , et allume la diode(3)si la valeur arrive a 5
