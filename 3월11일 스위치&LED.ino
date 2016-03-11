int sum=0;
int state = 0;
int pinNo[3] = {8,6,4};

void setup() {
  pinMode(10,INPUT);
  pinMode(8,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pinValue =  digitalRead(10);
  //Serial.println(pinValue);
  Serial.println("state");
  Serial.println(state);
  delay(200);
/*  if(pinValue = 0)
  {
    sum++;
  }
  if(sum%2 == 1)
    digitalWrite(8,HIGH);
  else if(sum%2 == 0)
    digitalWrite(8,LOW);

*/
  if(pinValue ==0)
  {
    digitalWrite(pinNo[state],LOW);
    state = random(0,3);
    digitalWrite(pinNo[state],HIGH);
  }

}
