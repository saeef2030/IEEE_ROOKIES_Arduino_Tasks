#include <Servo.h>
Servo myservo; 
int res = 0;  
int x;    
void setup() 
{
  myservo.attach(11); 
  pinMode(res,INPUT);
}

void loop()
 {
  x = analogRead(res);            
  x = map(x, 0, 1023, 0, 180);     
  myservo.write(x);                  
  delay(50);                           
}