int joyPin[2] = {0,1};
int green = 4; //2사분면
int red = 5; //1사분면
int blue = 6; //4사분면
int yellow = 7; //3사분면
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
  
 // 조이스틱 값의 정확도가 좋지 않기때문에 값을 나눠서 정확도를 높임
  if(abs(x) + abs(y) <= 52)
  {
    mValue2 = map(mValue,0,50,0,9);
  }
  else if (abs(x) + abs(y) >=52 && abs(x) + abs(y) <=60)
  {
    mValue2 = map(mValue,0,60,0,9);
  }
  else
  {
    mValue2 = map(mValue,0,70,0,9);
  }
  if(mValue >70) displayNum(9);
  else displayNum(mValue2);
  
  Serial.println(mValue);
  Serial.print("x = ");
  Serial.print(x,DEC);
  Serial.print(",");
  Serial.print("y = ");
  Serial.println(y, DEC);
 
  if(x < -5 && y< - 5) digitalWrite(red,HIGH); //1사분면
  else digitalWrite(red,LOW);
  if(x > 5 && y > 5) digitalWrite(yellow,HIGH); //3사분면
  else digitalWrite(yellow,LOW);
  if(y < -5 && x > 5) digitalWrite(blue,HIGH); //4사분면
  else digitalWrite(blue,LOW);
  if(y > 5 && x < -5) digitalWrite(green,HIGH); //2사분면
  else digitalWrite(green,LOW);

  delay(200);
}
