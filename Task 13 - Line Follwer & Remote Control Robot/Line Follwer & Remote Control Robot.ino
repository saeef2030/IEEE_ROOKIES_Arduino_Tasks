#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(13, 12); // RX, TX

#define enA 6
#define enB 1
#define in1 5
#define in2 4
#define in3 3
#define in4 2
#define sen1 8
#define sen2 9
#define sw 7
char command;

 void setup() {
 bluetoothSerial.begin(9600);  
 pinMode(sen1, INPUT); 
 pinMode(sen2, INPUT); 
 pinMode(enA, OUTPUT); 
 pinMode(in1, OUTPUT); 
 pinMode(in2, OUTPUT); 
 pinMode(in3, OUTPUT); 
 pinMode(in4, OUTPUT); 
 pinMode(enB, OUTPUT);
 pinMode(sw, INPUT);

 digitalWrite(enA, HIGH); 
 digitalWrite(enB, HIGH); 

}

void loop() {
  int x;
  x=digitalRead(sw);

 if(x==0){
   linefollwerrobot();
 }
 else if(x==1){
   controllercar();
 }

}


void goahead()
{
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW);  
digitalWrite(in4, HIGH); 
}
void backword()
{
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);  
digitalWrite(in3, HIGH);  
digitalWrite(in4, LOW); 
}
void right()
{
digitalWrite(in1, LOW);  
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW);  
digitalWrite(in4, HIGH);
}

void left()
{
digitalWrite(in1, HIGH);  
digitalWrite(in2, LOW); 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
}

void Stop()
{
digitalWrite(in1, LOW);  
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);
}
void linefollwerrobot(){
 int LEFTSENSOR = digitalRead(sen1);
 int RIGHTSENSOR = digitalRead(sen2);
  if(RIGHTSENSOR==0 && LEFTSENSOR==0) {
    goahead(); 
 } 

  else if(RIGHTSENSOR==1 && LEFTSENSOR==0) {
    right(); 
 }

  else if(RIGHTSENSOR==0 && LEFTSENSOR==1) {
    left(); 
 }

  else if(RIGHTSENSOR==1 && LEFTSENSOR==1) {
    Stop(); 
 }
}
void controllercar(){
Stop(); //initialize motors
  if (bluetoothSerial.available() > 0) 
  {
    command = bluetoothSerial.read();
       if(command == 'F'){
     goahead(); }  
   else if(command == 'B'){
     backword();}  
   else if(command == 'L'){
     left();}  
   else if(command == 'R'){
     right();} 
   else if(command == 'S'){
     Stop();}
  }

}