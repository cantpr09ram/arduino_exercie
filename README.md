# arduino_exercie
this repository is used to record my arduino code

### 一般燈亮
```c++
for(i=2;i<=6;i++){
   digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(1000);                       // wait for a second
   digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
   delay(1000); 
  }

```
### 呼吸燈
```c++
for(i=0;i<=250;i=i+50){
    analogWrite(9,i); //(腳位,亮度);  亮度=0-255
	delay(500);
}
```
### 可變電阻
```c++
//設定序列通訊速度為每秒9600 Bits
Serial.begin(9600);

//讀取類比腳位A0上的數值
int senserValue = analogRead(A0);//若數值為0代表輸入的類比電壓0V,數值為1023代表5V
//顯示出您所讀取的數值至序列阜監控視窗
Serial.println(senserValue);
delay(1);
```

### 可變電阻實驗控制LED閃爍的快慢
```c++
void setup() {
  pinMode(9,OUTPUT);
  pinMode(A2,INPUT);
}

void loop() {
  int sensorValue = analogRead(A2);
  int VR_Sensor;

  analogWrite(9,255);
  VR_Sensor=analogRead(A2);
  delay(VR_Sensor);

  analogWrite(9,0);
  delay(VR_Sensor);
}
```

### 可變電阻+呼吸燈
```c++
void setup() {
  pinMode(9,OUTPUT);
  pinMode(A2,INPUT);
}

void loop() {
  int sensorValue = analogRead(A2);
  int a;
  
  a=sensorValue/4;
  analogWrite(9,a);
}
```
### 按鈕  讀取電壓值
```c++
void setup() {
  Serial.begin(9600);
  pinMode(i,INPUT);
}

void loop() {
  int buttonState =digitalRead(i);
  Serial.println(buttonState);
  delay(1);
}
```
### 按鈕 參考
```c++
int buttonState=1;

void setup() {
  pinMode(i,OUTPUT);
  pinMode(j,INPUT);
}

void loop() {
  buttonState =digitalRead(j);
  if(buttonState==HIGH){
    digitalWrite(i,HIGH);
  }
  else{
    digitalWrite(i,LOW);
  }
}
```
### 期中解答
```c++
void setup() {
  for (int i = 2;i < 10;i++) {
    pinMode(i,OUTPUT);
  }
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
}

void Q1() {
  for (int i = 2;i < 10;i+=2) {
    digitalWrite(i,HIGH);
  }
  delay(500);
  for (int i = 2;i < 10;i+=2) {
    digitalWrite(i,LOW);
  }
  for (int i = 3;i < 10;i+=2) {
    digitalWrite(i,HIGH);
  }
  delay(500);
  for (int i = 3;i < 10;i+=2) {
    digitalWrite(i,LOW);
  }
}

void Q2() {
  int VR_Sensor;
  VR_Sensor = analogRead(A2);
  int Led = map(VR_Sensor, 0, 1020, 2, 6);
  for (int i = 2;i < 10;i++) {
    digitalWrite(i,LOW);
  }
  digitalWrite(Led,HIGH);
  for (int i = 2;i < 10;i++) {
    digitalWrite(i,LOW);
  }
}

int tmp = 2;
void Q3() {
  while (tmp >= 2 && tmp <= 10) {
    int delay_Value = map(analogRead(A2),0,1020,100,500);
    digitalWrite(tmp,HIGH);
    delay(delay_Value);
    digitalWrite(tmp,LOW);
    tmp++;
  }
  if (tmp > 10) tmp = 2;
}

void Q4() {
  while (tmp >= 2 && tmp <=10) {
    digitalWrite(tmp,HIGH);
    delay(500);
    digitalWrite(tmp,LOW);
    tmp--;
  }
  if (tmp < 2) tmp = 10;
}

void loop() {
  int ButtonState1,ButtonState2,ButtonValue,VR_Sensor;
  ButtonState1 = digitalRead(A0);
  ButtonState2 = digitalRead(A1);
  if (ButtonState1 == HIGH && ButtonState2 == HIGH) {
    ButtonValue = 4;
  } else if (ButtonState1 == LOW && ButtonState2 == HIGH) {
    ButtonValue = 3;
  } else if (ButtonState1 == HIGH && ButtonState2 == LOW) {
    ButtonValue = 2;
  } else {
    ButtonValue = 1;
  }
  switch(ButtonValue) {
    case 1:
      Q1();
      break;
    case 2:
      Q2();
      break;
    case 3:
      Q3();
      break;
    case 4:
      Q4();
      break;
  }
}
```
