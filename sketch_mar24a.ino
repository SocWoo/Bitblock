int piazzoPin = 4;
int switchPin = 5;
int sound[] = {261,294,330,349,392,440,494,542,590,630};
int index = 0;
int count = 10;
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(piazzoPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  int swi = digitalRead(switchPin);
  Serial.println(swi);

  if(swi == LOW)
  {
    state = (state+1)%2;
  }
  if(state == 1)
  {
      tone(piazzoPin,sound[index],500);
      index = (index+1)%10;
  }
  delay(200);
}






