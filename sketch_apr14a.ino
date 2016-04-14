int ledPin[3] = {9,10,11};// red green blue
int pPin = 0;
int swi = 4;

int state = 0;
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  for(int i=0;i<3;i++)
  {
    pinMode(ledPin[i],OUTPUT);
  }
  pinMode(swi,INPUT);
  Serial.begin(9600);
}

void loop() {
  int pValue = analogRead(pPin);
  int ledValue = map(pValue,0,1023,0,255);
  int swiValue = digitalRead(swi);
  Serial.println(swiValue);
  
  if(swiValue == 0)
  {
    state = (state+1)%3;
  }
/*  
  if(state == 0)
  {
    analogWrite(ledPin[0],ledValue);
    analogWrite(ledPin[1],0);
    analogWrite(ledPin[2],0);
  }
  else if(state == 1)
  {
    analogWrite(ledPin[0],0);
    analogWrite(ledPin[1],ledValue);
    analogWrite(ledPin[2],0);
  }
  else
  {
    analogWrite(ledPin[0],0);
    analogWrite(ledPin[1],0);
    analogWrite(ledPin[2],ledValue);
  }
*/
  switch(state)
  {
    case 0:
      red = map(pValue,0,1023,0,255);
      analogWrite(ledPin[0],red);
      break;
    case 1:
      green = map(pValue,0,1023,0,255);
      analogWrite(ledPin[1],green);

      break;
    case 2:
      blue = map(pValue,0,1023,0,255);
      analogWrite(ledPin[2],blue);
      break;
  }
  delay(200);

  
}



