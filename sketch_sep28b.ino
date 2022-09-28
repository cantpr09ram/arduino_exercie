void setup() {
  // put your setup code here, to run once:
  int i;
  for(int i = 4; i < 8; i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 4; i < 8; i++){
    for(int j = 0; j < 257; j += 10){
      analogWrite(i, j);
      delay(50);
    }
  }
}
