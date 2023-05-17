#define enA 6
#define enB 1
#define in1 5
#define in2 4
#define in3 3
#define in4 2
#define sen1 8
#define sen2 9

 void setup() {
 pinMode(sen1, INPUT); 
 pinMode(sen2, INPUT); 
 pinMode(enA, OUTPUT); 
 pinMode(in1, OUTPUT); 
 pinMode(in2, OUTPUT); 
 pinMode(in3, OUTPUT); 
 pinMode(in4, OUTPUT); 
 pinMode(enB, OUTPUT);

 digitalWrite(enA, HIGH); 
 digitalWrite(enB, HIGH); 

}

void loop() {

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


void goahead()
{
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW);  
digitalWrite(in4, HIGH); 
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