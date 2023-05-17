#define sensor 2
#define led 12
#define buz 4
void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
}

void loop() {

int sen=digitalRead(sensor);
  if(sen==1){
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
  }
  else if(sen==0)
  {
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
  }

}
