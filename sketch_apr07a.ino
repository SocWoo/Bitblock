int pPin = 0;
int findPin[4] = {4,5,6,7};
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
    Serial.begin(9600);
  }
}
void displayNum(int num){
  for(int j = 0;j<4;j++)
  {
    digitalWrite(findPin[j],findData[num][j]);
  }
}

void loop() {
  int pValue = analogRead(pPin);
  int pValue2 = map(pValue,0,1023,0,9);
  Serial.println(pValue2);
  displayNum(pValue2);
}



