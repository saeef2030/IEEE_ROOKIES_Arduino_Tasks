int green = 2;
int yellow = 3;
int red = 4;
int delaygreen= 2000;
int delayyellow = 1000;
int delayred = 2000;
void setup() 
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() 
{
  greenlight();
  delay(delaygreen);
  yellowlight();
  delay(delayyellow);
  redlight();
  delay(delayred);

}
void greenlight()
{
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
}

void yellowlight()
{
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
}

void redlight()
{
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
}
