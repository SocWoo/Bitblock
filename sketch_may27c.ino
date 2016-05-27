long duration,Cm,In;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(9,INPUT);
  digitalWrite(10,LOW);
 

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(10,HIGH);
  delayMicroseconds(10);
  digitalWrite(10,LOW);
  duration = pulseIn(9,HIGH);

  Cm = duration / 29.1 /2;
  In =  duration / 74 /2;


  Serial.print("Cm=");
  Serial.print(Cm);
  Serial.print("   ln =");
  Serial.println(In);
  delay(1000);
}
