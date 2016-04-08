int joyPin[2] = {0,1};
int green = 4; //위
int red = 5; // 오른
int blue = 6; //아래
int yellow = 7; //왼
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

void setup() {
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(yellow,OUTPUT);
  for(int i=0;i<4;i++)
  {
    pinMode(findPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void displayNum(int num){
  for(int j = 0;j<4;j++)
  {
    digitalWrite(findPin[j],findData[num][j]);
  }
}

void loop() {
  int x,y;
  x = (analogRead(joyPin[0]) - 508)/10;
  y = (analogRead(joyPin[1]) - 508)/10;
  
  float mValue = sqrt(x*x + y*y);
  int mValue2;

  if(abs(x) + abs(y) <= 52)
  {
    mValue2 = map(mValue,0,50,0,9);
  }
  else
  {
    mValue2 = map(mValue,0,71,0,9);
  }
  displayNum(mValue2);
  
  Serial.println(mValue);
  Serial.print("x = ");
  Serial.print(x,DEC);
  Serial.print(",");
  Serial.print("y = ");
  Serial.println(y, DEC);
 
  if(x < -5 && y< - 5) digitalWrite(green,HIGH);
  else digitalWrite(green,LOW);
  if(x > 5 && y > 5) digitalWrite(blue,HIGH);
  else digitalWrite(blue,LOW);
  if(y < -5 && x > 5) digitalWrite(red,HIGH);
  else digitalWrite(red,LOW);
  if(y > 5 && x < -5) digitalWrite(yellow,HIGH);
  else digitalWrite(yellow,LOW);

  delay(200);
}
