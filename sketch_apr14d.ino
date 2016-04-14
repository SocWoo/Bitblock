int dcMoterPin[] = {9,10,11};
int swi = 4;
int state = 0;

void setup() {
  
  pinMode(dcMoterPin[0],OUTPUT);
  pinMode(dcMoterPin[1],OUTPUT);
  pinMode(swi,INPUT);
  
}

void loop() {
  int swiValue = digitalRead(swi);

  if(swiValue == 0)
  {
    state = (state+1)%4;
  }

  switch(state)
  {
   case 0:
    digitalWrite(dcMoterPin[0],LOW);
    digitalWrite(dcMoterPin[1],LOW);
    analogWrite(dcMoterPin[2],0);
    break;
    case 1:
    digitalWrite(dcMoterPin[0],LOW);
    digitalWrite(dcMoterPin[1],HIGH);
    analogWrite(dcMoterPin[2],85);
    break;
   case 2:
    digitalWrite(dcMoterPin[0],LOW);
    digitalWrite(dcMoterPin[1],HIGH);
    analogWrite(dcMoterPin[2],170);
    break;
   case 3:
    digitalWrite(dcMoterPin[0],LOW);
    digitalWrite(dcMoterPin[1],HIGH);
    analogWrite(dcMoterPin[2],255);
    break;
}
}
