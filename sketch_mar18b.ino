int pinNo[4] = {4,5,6,7};
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);//적
  pinMode(5,OUTPUT);//황
  pinMode(6,OUTPUT);//초
  pinMode(7,OUTPUT);//파
  pinMode(8,INPUT);//스위치
}

void loop() {
  int Res = analogRead(0);
  int Swi = digitalRead(8);
  Serial.println(Res);
  delay(200);
  if(Swi == 0)
  {
    state = (state+1)%2;
  }
  if(state == 1)
  {
   if(Res <= 250)
    {
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
    else if(Res <= 500)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
    else if(Res <= 750)
    {
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
   }
    else
      digitalWrite(7,HIGH);
  }
   else
    {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
}
