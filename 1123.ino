const int buttonPin[3] = {A0, A1,A2};
const int led[5] = {13, 12, 11, 10, 9};
const int analogInPin = A3;
int buttonState[3] = {0, 0, 0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<5;i++){
    pinMode(led[i],OUTPUT);
  }
  for(int i=0;i<3;i++){
    pinMode(buttonPin[i],INPUT);
  }
}
int led_add = 9;

void loop() {
  // put your main code here, to run repeatedly:
  int Range = 0;
  
  int buttonState = digitalRead(A0);
  
  //Serial.println(buttonState);
  if (buttonState == 0)
    Range = 1;
    
  buttonState = digitalRead(A1);
 
  if (buttonState == 0)
    Range = 2;
    
  int buttonState2 = digitalRead(A0);
  int buttonState3 = digitalRead(A1);
  delay(1);
  Serial.println(buttonState3);
  if((buttonState2 == 0) && (buttonState3 == 0)){
    Range = 3;
  }
  
  switch(Range)
  {
   case 1:
   // 單獨按下按鈕一時，每快速按下一次，則LED的亮燈會跳到下一個燈1->2->....->8->1->2.... .->8
    digitalWrite(led_add,LOW);
    led_add += 1;
    if(led_add == 14)
      led_add = 9;
    digitalWrite(led_add,HIGH);
    delay(500);
    break;
    
  case 2:
    digitalWrite(led_add,LOW);
    led_add += 1;
    if(led_add == 14)
      led_add = 9;
    digitalWrite(led_add,HIGH);
    delay(50);
    break;
    
  case 3:
    for(int i=0;i<5;i++){
      digitalWrite(led[i],HIGH);
    }
    delay(200);
    for(int i=0;i<5;i++){
      digitalWrite(led[i],LOW);
    }
    delay(200);
    break;
  }
}
