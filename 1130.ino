const int buttonPin[3] = {A0, A1,A2};
const int analogInPin = A3;
int buttonState[3] = {0, 0, 0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=2;i<=5;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=0;i<3;i++){
    pinMode(buttonPin[i],INPUT);
  }
}
int ledRegion;
void loop() {
  // put your main code here, to run repeatedly:
  int range = 0;
  int buttonState = digitalRead(A0);
  if(buttonState == 0){
    range = 1;
  }
  switch(range){
    case 1:
      int sensorValue = analogRead(A2);
      Serial.println(sensorValue);
      ledRegion = (sensorValue+1)/342;
      break;
  }
  for(int i=2;i<=5;i++){
    if((i==(ledRegion+2))||(i==(ledRegion+3)))
      digitalWrite(i,HIGH);
    else
      digitalWrite(i,LOW);
  }
}
