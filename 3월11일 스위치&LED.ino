int state = 0; // 적6,초4,황8,스위치10
int pinNo[3] = {4 ,6,8};
void setup() {
  pinMode(10,INPUT);  
  pinMode(pinNo[0],OUTPUT);
  pinMode(pinNo[2],OUTPUT);
  pinMode(pinNo[1],OUTPUT);
  Serial.begin(9600);
}  
  
void loop() {
  int pinValue = digitalRead(10);
  delay(200);
  Serial.println(pinValue);
  if(pinValue == 0)
  {
      digitalWrite(pinNo[state],LOW);
      state = (state+1)%3;
      digitalWrite(pinNo[state],HIGH);
  }   
}  
