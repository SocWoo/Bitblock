
#include<SoftwareSerial.h>

SoftwareSerial BTSerial(2,3); // SoftwareSerial의 함수들은 Serial 클래스
int ledPin = 7;

void setup() {
  // put your setup code here, to run once;
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   int value = BTSerial.read();
  
  if(BTSerial.available()) {
    Serial.write(BTSerial.read()); // 블루투스 모듈에서 받은 데이터를 PC전송
  }
  if(Serial.available()) {
    BTSerial.write(Serial.read()); // PC에서 바은 데이터를 블루투스로 모듈로 전송
  }

  if(value == '1')
  {
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
  }
  
}
