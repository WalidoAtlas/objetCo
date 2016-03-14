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

int led = 11;           // the PWM pin the LED is attached to
int potar = A5;
int fadeAmount = 5;    // how many points to fade the LED by
int value=0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
  void loop() {
    // set the brightness of pin 9:
    int alogene = analogRead(potar)/4;
    Serial.println(alogene);
    if(alogene<128){
      alogene=map(alogene,0,128,0,255);//le map prend en premier parametre la valeur a modifier . les deux premier nombre serve a determiner un intervalle . les deux derniers definissent le comportement.
      analogWrite(led,alogene);
      }
    else{
      alogene=map(alogene,128,255,255,0);//la les deux dernier nombre determine un comportement degressif .
      analogWrite(led,alogene);
      
      }



}
//alogene progressif jusqu'a 128 puis degressif
