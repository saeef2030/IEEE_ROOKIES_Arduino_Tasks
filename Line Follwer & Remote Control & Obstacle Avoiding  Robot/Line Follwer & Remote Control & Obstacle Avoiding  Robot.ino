
#define enA 6
#define enB 10
#define in1 5
#define in2 4
#define in3 3
#define in4 2
#define echo A2    //Echo pin
#define trigger A3 //Trigger pin
#define servo A4
#define LS 8 //ir sensor Left
#define RS 9 //ir sensor Right

int Ldistance, Rdistance;
long distance;
int state = 20;
int dis = 30;
int Speed = 130;  
int mode=0;
char command; // variable to receive data from the serial port and IRremote
bool shot; // flag to get out any mode we get into

void setup()
{ 
pinMode(RS, INPUT);   
pinMode(LS, INPUT); 
pinMode(echo, INPUT );
pinMode(trigger, OUTPUT);   
pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT);  
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);    
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT); 

Serial.begin(9600); 


pinMode(servo, OUTPUT);
 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
 for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }

 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }
delay(500);
}


void loop()
{  Stop();
while(Serial.available() > 0){      
command = Serial.read(); 
     
if(command == '7'){mode=0; Speed=255;}    //Remote Control moode   
else if(command == '8'){mode=1; Speed=130;} //Line Follower moode
else if(command =='9'){mode=2; Speed=255;} // Obstacle Avoiding moode

analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

if(mode==0){shot=1;
while(shot){
  char s=Serial.read();     
//===============================================================================
//                          Remote Control moode 
//=============================================================================== 
     if(s == '1'){forword(); delay(5);break; }  // if command is '1'  motor will go forward
else if(s == '2'){backword();  delay(5);break;}  // if command is '2'  motor will backword
else if(s == '3'){turnLeft();  delay(5);break;}  // if command is '3'  motor will turn left
else if(s == '4'){turnRight();  delay(5);break;}  // if command is '4'  motor will turn right
else if(s == '5'){Stop(); delay(5);break; }     // if command is '5'  motor will Stop
else if(s=='0'){
shot=0;  
}
}
}

if(mode==1){ shot=1;
while(shot){
//===============================================================================
//                         Line Follower moode
//===============================================================================     
if((digitalRead(RS) == 0)&&(digitalRead(LS) == 0)){forword();}  //if Right Sensor and Left Sensor are at White color then it will call forword function
if((digitalRead(RS) == 1)&&(digitalRead(LS) == 0)){turnRight();}//if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
if((digitalRead(RS) == 0)&&(digitalRead(LS) == 1)){turnLeft();} //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
if((digitalRead(RS) == 1)&&(digitalRead(LS) == 1)){Stop();}     //if Right Sensor and Left Sensor are at Black color then it will call Stop function
char x=Serial.read();
if(x=='0'){
  shot=0;
}
} 
}
if(mode==2){    shot=1;
while(shot){
//===============================================================================
//                          Obstacle Avoiding moode
//===============================================================================     
 dis = Ultrasonic_read();
 Serial.print("S=");Serial.println(dis);
  if (dis > state){
    forword();}
   else{
     Check_side();}
char z=Serial.read();
if(z=='0'){
  shot=0;
}
}
}
}
}
//*********************************our functions********************************

void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500;      // Convert the angle to microseconds
 digitalWrite(pin, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(pin, LOW);
 delay(50);                   // Refresh cycle of servo
}


//**********************Ultrasonic_read function****************************
long Ultrasonic_read(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  distance = pulseIn (echo, HIGH);
  return distance / 29 / 2;     //covert the distance to cm
}
//****************************compare Distance function**************
void compareDistance(){
  if (Ldistance > Rdistance){
  turnLeft();
  delay(350);
  }
  else if (Rdistance > Ldistance){
  turnRight();
  delay(350);
  }
  else{
  backword();
  delay(300);
  turnRight();
  delay(600);
  }
}
//**************************Check side funtion************
void Check_side(){
  Stop();
  delay(100);
 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
    delay(300);
    Ldistance = Ultrasonic_read();
    delay(100);
  for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }
    delay(500);
    Rdistance = Ultrasonic_read();
    delay(100);
 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }
    delay(300);
    compareDistance();
}
//********************forword funtion***********
void forword()
{  
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}
//********************backword funtion***********
void backword()
{ 
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}
//********************turn Right funtion***********
void turnRight()
{ 
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}
//********************turn Left funtion***********
void turnLeft()
{ 
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}
//*********************stop function*************
void Stop()
{ 
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
