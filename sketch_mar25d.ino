#include <Servo.h>

int servoPin = 6;
int switchPin = 5;
int pPin = 0;

Servo moter;

void setup() {
  moter.attach(servoPin);
  Serial.begin(9600);
  
}

void loop() {

  int swi = digitalRead(switchPin);
  Serial.println(swi);

  if(swi == LOW)
  {
      moter.write(180);
      delay(100);
  }
  else
  {
    moter.write(0);
    delay(100);
  }

}
