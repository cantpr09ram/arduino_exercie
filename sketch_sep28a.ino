void setup() {
  // put your setup code here, to run once:
  int i;
  for(int i = 5; i < 10; i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 5; i < 10; i++){
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
  for(int i = 9; i > 4; i--){
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
}

  
