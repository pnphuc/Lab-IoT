int trig = 2;
int echo = 3;
int piezo = 4;
int led1 = 8;
int led2 = 9;
int led3 = 10;

long getDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  
  long duration = pulseIn(echo, HIGH);
  long distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  int distanceCm = getDistance();
  if(distanceCm > 150){
  	digitalWrite(8, HIGH); //led1
    digitalWrite(9, LOW); //led2
    digitalWrite(10, LOW);//led3
    digitalWrite(4, LOW);//piezo
  }
  else if (distanceCm > 50){
  	digitalWrite(8, LOW);//led1
    digitalWrite(10, LOW);//led3
    digitalWrite(9, HIGH);//led2
    delay(1000);
    digitalWrite(9, LOW);//led2
    digitalWrite(4, HIGH);//piezo
    delay(1000);
    digitalWrite(4, LOW);//piezo
    
  }
  else if (distanceCm <= 50){
    digitalWrite(4, HIGH);//piezo
    delay(1000);
    digitalWrite(4, LOW);//piezo
    
    digitalWrite(8, HIGH); //led1
    digitalWrite(9, HIGH); //led2
    digitalWrite(10, HIGH);//led3
    delay(1000);
    digitalWrite(8, LOW); //led1
    digitalWrite(9, LOW); //led2
    digitalWrite(10, LOW);//led3
  }
  if (distanceCm < 30){
    digitalWrite(4, HIGH);//piezo
    
    digitalWrite(8, HIGH); //led1
    digitalWrite(9, HIGH); //led2
    digitalWrite(10, HIGH);//led3
    delay(100);
    digitalWrite(8, LOW); //led1
    digitalWrite(9, LOW); //led2
    digitalWrite(10, LOW);//led3
 
    }
}