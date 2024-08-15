#include <Servo.h>
Servo myservo;
int pos = 0;
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
myservo.attach(9);
}

void loop() { 
  // put your main code here, to run repeatedly:
   digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
//  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
   Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  //////////
  if(cm>= 60){
  myservo.write(0); 
        
  }
  if(cm <=50){
   myservo.write(90);             
      
  }
    
    }
