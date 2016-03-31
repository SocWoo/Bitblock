int trigPin = 4;
int ecoPin = 5;
int buzzerPin = 6;
int swiPin = 8;
int state = 0;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(ecoPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(swiPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int swi = digitalRead(swiPin);
  int receivedTime = pulseIn(ecoPin,HIGH);
  float distance = receivedTime/58.2;

  if(swi == 0)
  {
    state = (state+1)%2;
  }
  if(state == 1)
  {
    if(distance <= 70)
    {
      tone(buzzerPin,250,200);
    }
  }
  Serial.println(swi);
  delay(200);

}
