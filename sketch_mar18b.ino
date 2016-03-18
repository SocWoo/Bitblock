int ledPin[4] = {4,5,6,7}; // LED(적황녹청);
int pPin = 0;//가변저항
int sPin = 9;//스위치
int pState = 0;//LED배열의 인덱스(적녹황청)
int sState = 0; //on,off

void setup() {
  Serial.begin(9600);
  for(int i =0;i<4;i++)
  {
    pinMode(ledPin[i],OUTPUT);
  }
  pinMode(sPin , INPUT);
}

void loop() {
  int sValue = digitalRead(sPin);
  Serial.println(sValue);
  if(sValue == 0){
    if(sState == 0) sState = 1;
    else if(sState == 1) sState = 0;
  }

  int pValue = analogRead(pPin);
  Serial.println(pValue);
  if(pValue<300) pState = 0;
  else if(pValue<600) pState = 1;
  else if(pValue <900) pState = 2;
  else pState = 3;

  for(int i = 0;i<4;i++){
    digitalWrite(ledPin[i],LOW);
  }

  if(sState == 1) digitalWrite(ledPin[pState],HIGH);

  delay(200);

}
