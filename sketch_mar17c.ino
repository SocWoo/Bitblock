void setup() {
  Serial.begin(9600);
  pinMode(6,OUTPUT);
}

void loop() {
  int Value = analogRead(0);
  Serial.println(Value);
  delay(200);
  if(Value >700)
  digitalWrite(6,HIGH);
  else
  digitalWrite(6,LOW);
}
