int joyPin[2] = {0,1};
int green = 4; //위
int red = 5; // 오른
int blue = 6; //아래
int yellow = 7; //왼

void setup() {
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(yellow,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int x,y;
  x = analogRead(joyPin[0]) - 508;
  y = analogRead(joyPin[1]) - 508;
  Serial.print("x = ");
  Serial.print(x,DEC);
  Serial.print(",");
  Serial.print("y = ");
  Serial.println(y, DEC);
  delay(200);

  if(x < -5) digitalWrite(green,HIGH);
  else digitalWrite(green,LOW);
  if(x > 5) digitalWrite(blue,HIGH);
  else digitalWrite(blue,LOW);
  if(y < -5) digitalWrite(red,HIGH);
  else digitalWrite(red,LOW);
  if(y > 5) digitalWrite(yellow,HIGH);
  else digitalWrite(yellow,LOW);

}
