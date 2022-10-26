// constants won't change. They're used here to set pin numbers:

const int buttonPin =  4;     // the number of the pushbutton pin

const int ledPin        = 13;      // the number of the LED pin
const int ledPin1      = 12;
const int ledPin2      = 11;

// variables will change:
int  initial    = 0;       //hold current  initial
int oldstate    = 0;       //hold last  initial
int buttonstate = 0;      // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input:
}
void loop(){
  //debouncing routline to read button
  buttonstate = digitalRead(buttonPin);  //state the  initial of button
  if(buttonstate == HIGH){               //check if it has been pressed 
    delay(50);
    buttonstate = digitalRead(buttonPin);//state button again
    if(buttonstate == LOW){              //if it is 0 considered one press
     initial = oldstate + 1;        //increase  initial by 1
    }
  }else{                          //check if it has been NOT pressed
      delay(100);
      }
   switch (initial){               //react to button press a  initial
     case 1:                     //if  initial is 1
       digitalWrite(ledPin, HIGH);//on
       digitalWrite(ledPin1, LOW);//off
       digitalWrite(ledPin2, LOW);//off
       oldstate =  initial;               //set oldstate  initial as current  initial
       break;
     case 2:
       digitalWrite(ledPin, LOW);
       digitalWrite(ledPin1, HIGH);
       digitalWrite(ledPin2, LOW);
       oldstate =  initial;
       break;
     case 3:
       digitalWrite(ledPin, LOW);
       digitalWrite(ledPin1, LOW);
       digitalWrite(ledPin2, HIGH);
       oldstate =  initial;
       break;         
     default:                      //if  initial is not 1 2 3
       digitalWrite(ledPin, LOW);  //off
       digitalWrite(ledPin1, LOW);
       digitalWrite(ledPin2, LOW);
       oldstate = 0;                    //reset to all off/initial 0
       break;         
     }
}
