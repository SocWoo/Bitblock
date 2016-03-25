int pPin = 0;
int buzzerPin = 4;
int sound[] = {512,587,659,699,740,784,880,988,1047,1175};
int index = 0;

void setup() {
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int bValue;
  int pValue = analogRead(pPin);
  int pValue2 = map(pValue,0,1023,20,4000);
  Serial.println(pValue2);

    tone(buzzerPin,pValue,500);
}
