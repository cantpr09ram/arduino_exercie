int brightness = 0;
int fadeamount = 64;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3, brightness);
  brightness += fadeamount;
  if(fadeamount == 0 || fadeamount == 192){
    fadeamount = -fadeamount;
  }
  delay(10);
}
