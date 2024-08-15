
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
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
  if(cm>= 15{
    digitalWrite(5,1);
    digitalWrite(6,1) ;
    digitalWrite(7,1);
    }
    //
  if(cm >= 10){
    digitalWrite(5,0);
    digitalWrite(6,1);
    digitalWrite(7,1);
    }
    //
  if(cm >= 5){
    digitalWrite(7,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    }
    //

  delay(250);
}
