int sum=0;
int state = 0;

void setup() {
  pinMode(10,INPUT);
  pinMode(8,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pinValue =  digitalRead(10);
  Serial.println(pinValue);
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
    if(state ==0)
    {
      digitalWrite(4,LOW);
      digitalWrite(8,HIGH);
      state = 1;
    }else if(state ==1)
    {
      digitalWrite(8,LOW);
      digitalWrite(6,HIGH);
      state = 2;
    }else if(state == 2)
    {
      digitalWrite(6,LOW);
      digitalWrite(4,HIGH);
      state = 0;  
    }
  }

}

 
