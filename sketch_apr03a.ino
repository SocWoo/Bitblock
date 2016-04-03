int trigPin = 4;
int ecoPin = 5;
int swiPin = 6;
int buzzerPin = 7;
int findPin[4] = {8,9,10,11};
byte findData[10][4] = {{0,0,0,0},
                       {0,0,0,1},
                       {0,0,1,0},
                       {0,0,1,1},
                       {0,1,0,0},
                       {0,1,0,1},
                       {0,1,1,0},
                       {0,1,1,1},
                       {1,0,0,0},
                       {1,0,0,1}};
int state = 0;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(ecoPin,INPUT);
  pinMode(swiPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  
  for(int i = 0;i<4;i++)
  {
    pinMode(findPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void displayNum(int num)
{
  for(int j = 0;j < 4; j++)
  {
    digitalWrite(findPin[j],findData[num][j]);
  }
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
    if(distance>=10 && distance<=30)
    {
      tone(buzzerPin,250,200);
      delay(200);
    }
    for(int m = 0;m<10;m++)
    {
      if(m < distance && distance < m+1)
      {
        tone(buzzerPin,250,100 + (m*15));
        displayNum(m);
        delay(10 + m*10);
      }
    }
  }

  Serial.println(distance);
  delay(200);
}





