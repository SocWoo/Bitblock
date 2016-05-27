#include "DHT.h"
#include<SoftwareSerial.h>

DHT dht;

SoftwareSerial BTSerial(2,3); // SoftwareSerial의 함수들은 Serial 클래스

void setup() {
  // put your setup code here, to run once;
  Serial.begin(9600);
  BTSerial.begin(9600);
  dht.setup(8);
}

void loop() {
  // put your main code here, to run repeatedly:

    delay(dht.getMinimumSamplingPeriod());
    float temp = dht.getTemperature();
    float humidity = dht.getHumidity();
 
  if(Serial.available()) {
    Serial.write(BTSerial.read()); // 블루투스 모듈에서 받은 데이터를 PC전송
  }

    if(BTSerial.available()) {
    BTSerial.write(Serial.read()); // 블루투스 모듈에서 받은 데이터를 PC전송
  
    BTSerial.print("temp : ");
    BTSerial.print(temp,2);
    BTSerial.print(" humidity : ");
    BTSerial.print(humidity,2);
    BTSerial.println(" %");
    }
}
