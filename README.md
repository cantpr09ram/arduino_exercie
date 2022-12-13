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
