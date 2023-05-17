#define sw 9
#define motor 6
int x;
void setup() {
  pinMode(sw, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  x=digitalRead(sw);
  if(x==1){
    digitalWrite(motor,HIGH);
  }
   else if (x==0){
     digitalWrite(motor,LOW);
   }

}
