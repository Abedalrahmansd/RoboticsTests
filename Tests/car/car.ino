#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
RH_ASK driver;
=int pin1motor1  6;
int pin1motor2 = 12;

int pin2motor2 = 10;
int pin2motor1 = 9;

int trigPin = 8;
int echoPin = 7;

int btn1 = 5;
int btn2 = 3;

String readString;

void setup() {
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  
  
  // put your setup code here, to run once:
  pinMode(pin1motor1, OUTPUT);
  pinMode(pin1motor2, OUTPUT);
  pinMode(pin2motor1, OUTPUT);
  pinMode(pin2motor2, OUTPUT);
  Serial.begin (9600);
  if (!driver.init())
         Serial.println("init failed");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("serial on/off test 0021"); // so I can keep track
}
void loop() {
  Serial.println(digitalRead(btn1));
/////////////////////////////////////////////////////////////////
   uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i; 
      readString = (char*)buf;                 
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);
      ///////////////////////////////
      if (readString == "u")     
    {
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, HIGH);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, HIGH);
      Serial.println("FORWARD");
    }
    if (readString == "d")
    {
  digitalWrite(pin1motor1, HIGH);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, HIGH);
  digitalWrite(pin2motor1, LOW);
      Serial.println("DOWN");
    }
    if (readString == "r")
    {
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, HIGH);
  digitalWrite(pin2motor1, HIGH);
      Serial.println("RIGHT");
    }
    if (readString == "l")
    {
  digitalWrite(pin1motor1, HIGH);
  digitalWrite(pin1motor2, HIGH);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, LOW);
      Serial.println("LEFT");
    }
    if (readString == "s")
    {
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, LOW);
      Serial.println("STOPPED");
    }
      ///////////////////////////////
    }
    
//////////////////---ULTRASONIC---//////////////////////
  /**
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
   Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
 if(cm > 20){
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, HIGH);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, HIGH);
  } else{
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, HIGH);
  digitalWrite(pin2motor1, HIGH);
    }
  **/
 ////////////////////---BLUETOOTH---/////////////////////////
  /**
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }

  if (readString.length() >0) {
    Serial.println(readString);

    if (readString == "u")     
    {
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, HIGH);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, HIGH);
      Serial.println("FORWARD");
    }
    if (readString == "d")
    {
  digitalWrite(pin1motor1, HIGH);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, HIGH);
  digitalWrite(pin2motor1, LOW);
      Serial.println("DOWN");
    }
    if (readString == "r")
    {
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, HIGH);
  digitalWrite(pin2motor1, HIGH);
      Serial.println("RIGHT");
    }
    if (readString == "l")
    {
  digitalWrite(pin1motor1, HIGH);
  digitalWrite(pin1motor2, HIGH);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, LOW);
      Serial.println("LEFT");
    }
    if (readString == "s")
    {
  digitalWrite(pin1motor1, LOW);
  digitalWrite(pin1motor2, LOW);
  digitalWrite(pin2motor2, LOW);
  digitalWrite(pin2motor1, LOW);
      Serial.println("STOPPED");
    }
    readString="";
  } 
  **/
 ///////////////////////////////////////////////////////////////////

}
