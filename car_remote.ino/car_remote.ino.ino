
int ch1  = 0;  // Receiver Channel 1 PPM value
int ch2  = 0;  // Receiver Channel 2 PPM value
int ch3  = 0;  // Receiver Channel 3 PPM value
int ch4  = 0;  // Receiver Channel 4 PPM value
int ch5  = 0;  // Receiver Channel 5 PPM value
int ch6  = 0;  // Receiver Channel 6 PPM valu

#define rcPin1 13 // Pin 8 Connected to CH1 of Transmitter;
#define rcPin2 12   // Pin 9 Connected to CH1
#define rcPin3 11   // Pin 9 Connected to CH2
#define rcPin4 10   // Pin 9 Connected to CH2
#define rcPin5 9  // Pin 9 Connected to CH3
#define rcPin6 8  // Pin 9 Connected to CH3

void forward();
void backward();
void left();
void right();
//void stopmotor(){


int maxvalue=2000;
int mid1=1400;
int mid2=1500;
int minvalue=996;


int m11=5;
int m12=4;
int m21=7;
int m22=6;
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200);

  

  //..............remote...............//

  //..............remote...............//

  pinMode(rcPin1, INPUT);
  pinMode(rcPin2, INPUT); 
  pinMode(rcPin3, INPUT);
  pinMode(rcPin4, INPUT);
  pinMode(rcPin5, INPUT);
  pinMode(rcPin6, INPUT);

  
}
void loop() {  
  ch2  = pulseIn(rcPin2, HIGH, 15000);  // (Pin, State, Timeout)

  ch1  = pulseIn(rcPin1, HIGH, 15000);  // (Pin, State, Timeout)
  
 delay(15);
 //Serial.print("ch1 ==");
 //Serial.print(ch1);
 //Serial.print("    ch2== ");
 //Serial.println(ch2);
 
 if(ch2<=mid1 && ch2>=minvalue)
  {
    forward();
    loop();
  }

    else if(ch2>=mid2)
  {
    backward();
    loop();
  }

    else if(ch1<=mid1 && ch1>=minvalue)
  {
    left();
    loop();
  }
      else if(ch1>=mid2)
  {
    right();
    loop();
  
}
else{
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
    loop();
  }

}


 void forward(){
  //  Serial.println("forward");
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
    delay(100);    
    ch2  = pulseIn(rcPin2, HIGH, 15000);  // (Pin, State, Timeout)
    if(ch2<=mid1 && ch2>=minvalue)
  {
    forward();
  }
  
 }
  void backward(){
  
    //Serial.println("back");
    digitalWrite(m11,LOW);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,LOW);
    digitalWrite(m22,HIGH);
    delay(100);   
    ch2  = pulseIn(rcPin2, HIGH, 15000);  // (Pin, State, Timeout) 
    
    if(ch2>=mid2)
  {
    backward();
  }
  }
  void right(){   
    //Serial.println("left");
    digitalWrite(m11,LOW);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
    delay(100);    
    ch1  = pulseIn(rcPin1, HIGH, 15000);  // (Pin, State, Timeout); 
     if(ch1<=mid1 && ch1>=minvalue)
  {
    right();
  }
  }
  void left(){
    
    //Serial.println("right");
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,HIGH);
    delay(100); 
     ch1  = pulseIn(rcPin1, HIGH, 15000);  // (Pin, State, Timeout);   
     if(ch1>=mid2)
    {
    left();
    
  
      }
  }
