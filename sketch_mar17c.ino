int pinNo[3] = {4,6,8};
int state =0;

void setup() {
  Serial.begin(9600);
  pinMode(10,INPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  int Value = analogRead(0);
  int pinValue = digitalRead(10);
  Serial.println(Value);
  delay(200);

  if(pinValue == 0)
  {
    state = (state+1)%3;
  }
  
  if(Value >700)
  digitalWrite(pinNo[state],HIGH);
  else
  digitalWrite(pinNo[state],LOW);
  digitalWrite(pinNo[(state+1)%3],LOW);
  digitalWrite(pinNo[(state+2)%3],LOW);
}

