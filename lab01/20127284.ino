int button = 11;
int red = 2;
int blue = 3;
int white = 4;
int green = 5;
int orange = 6;
int yellow = 7;
unsigned long startTime = 0;
int isOFF = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(red,OUTPUT); 
  pinMode(blue,OUTPUT); 
  pinMode(white,OUTPUT); 
  pinMode(green,OUTPUT); 
  pinMode(orange,OUTPUT); 
  pinMode(yellow,OUTPUT); 
}

void loop() {
  int buttonStatus = digitalRead(button);
 
  if(buttonStatus != isOFF){
   	 startTime = millis();
     isOFF = buttonStatus;
  }
  
  if (buttonStatus == HIGH){
    delay(500);
    if (buttonStatus == HIGH){
      if (millis() - startTime > 12000){
        digitalWrite(red,HIGH);
        digitalWrite(blue,HIGH);
        digitalWrite(white,HIGH);
        digitalWrite(green,HIGH);
        digitalWrite(orange,HIGH);
        digitalWrite(yellow,HIGH);
        if(buttonStatus == LOW){
          startTime = millis();
        }  
    }
      else if(buttonStatus == HIGH){
        for (int i = 2; i<=7 ; i++){
          if (digitalRead(button) == LOW){
            break; 
          }
          else{
          digitalWrite(i,HIGH);
          delay(1000);
          digitalWrite(i,LOW);}
        }
     }
    } 
    if (digitalRead(button) == LOW) {
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(white,LOW);
    digitalWrite(green,LOW);
    digitalWrite(orange,LOW);
    digitalWrite(yellow,LOW);
  }  
  }}