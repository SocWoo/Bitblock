int findPin[4]={8,9,10,11};
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
                        
void setup() {
  
  for(int i=0;i<4;i++)
  {
    pinMode(findPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<10;i++)
  {
//    for(int j = 0;j<4;j++)
//    {
//      digitalWrite(findPin[j],findData[num][j]);
//    }
    displayNum(i);
    delay(500);
  }
}

void displayNum(int num){
  for(int j = 0;j<4;j++)
  {
    digitalWrite(findPin[j],findData[num][j]);
  }
}

