// C++ code
//
#include <Servo.h>

void setup()
{
  pinMode(5, OUTPUT); // --> LED VERMELHO
  pinMode(4, OUTPUT); // --> LED AMARELO
  pinMode(3, OUTPUT); // --> LED VERDE
  pinMode(A0, INPUT); // --> POTENCIADOR
}

void loop()
{
  if (analogRead(A0) <= 250){
  	digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    
  } else if(analogRead(A0) > 250 and analogRead(A0) <= 350) {
  	digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  
  } else {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  }
  
  delay(10); // Delay a little bit to improve simulation performance
}