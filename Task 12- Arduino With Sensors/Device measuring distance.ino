#define ech 9
#define tri 10
#define yellow 1
#define red 2
#define green 3
float distance=0;
float dis=0;
void setup(){
pinMode(ech,INPUT);
pinMode(tri,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
}
void loop(){
  digitalWrite(tri,LOW);
  delayMicroseconds(2);
  digitalWrite(tri,HIGH);
  delayMicroseconds(10);
  digitalWrite(tri,LOW);
  distance=pulseIn(ech,HIGH);
  dis=distance/58;
  if(dis > 15){
    alloff();
  }
  else if(dis < 5){
    redd();
  }
  else if((5 < dis) && (dis < 10)){
    yell();
  }
  else if ((10 < dis) && (dis < 15)){
    gren();
  }

}
void alloff(){
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
}
void redd(){
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
}
void yell(){
  digitalWrite(yellow,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
}
void gren(){
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
}