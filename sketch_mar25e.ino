#include <Servo.h>

int servoPin = 6;
int switchPin = 5;
int pPin = 0;
int state = 0;

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
    state = (state+1)%2;
  }
  if(state == 1)
  {
    moter.write(180);
    delay(100);
  }
  else if(state == 0)
  {
    moter.write(0);
    delay(100);
  }
  delay(200);

}
