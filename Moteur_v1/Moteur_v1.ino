/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

#include <Servo.h>

Servo myservo;

int led = 11;           // the PWM pin the LED is attached to
int potar = A5;
int fadeAmount = 5;    // how many points to fade the LED by
int value=0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);//initialisation de la console
  myservo.attach(9);//assignation du moteur a la pin 9
}


  void loop() {
    unsigned long int chrono = millis();//creation d'un compteur qui evolue en miliseconde
    int alogene = map(chrono,0,180000,0,255);//alogene et moteur a evolution progressive selon le compteur
    int pos = map(chrono,0,180000,0,180);
    
    
    Serial.println(chrono);
    
    analogWrite(led,alogene);//ecriture alogene
    myservo.write(pos);//ecriture moteur

    




}
//faire des boucle while pour gerer une incrementation propre ou for aussi ...





