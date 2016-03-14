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
int led = 11;    //la led
bool go = false;//instancier dans les variables lobal


void setup() {
  pinMode(A0, INPUT);//le capteur de lumiere
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  myservo.attach(6);//le moteur servo
  
}


  void loop() {
    int potency = analogRead(A0);
    Serial.println(potency);
    
    if (potency < 320 ) {//si le capteur pass a une intensité lumineuse a 320 le compteur demarre.
      go = true;
    }
    
    if (go) {
    unsigned long int chrono = millis();
    int alogene = map(chrono,0,180000,0,255);
    int pos = map(chrono,0,180000,0,180);
    
      analogWrite(led,alogene);
      myservo.write(pos);
      delay(999);
   
    }
}





