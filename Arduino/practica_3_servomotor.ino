// practica 3 tapia
// controlar servomotor con un potenciometro

#include <Servo.h>

Servo myservo; 
int potpin = 0;  
int val;    

void setup() {
  myservo.attach(9);  // pin digital 9 del arduino
}

void loop() {
  val = analogRead(potpin);            // lee loos valores del potenciometro (valores entre 0  y 1023)
  val = map(val, 0, 1023, 0, 180);     // mapea esos valores a una escala entre 0 y 180
  myservo.write(val);                  // envia el valor al servo
  delay(100);                           // delay de 100ms
}
