int ledPin = 12;
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  Serial.println("serial on/off test 0021"); // so I can keep track
}

void loop() {

  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }

  if (readString.length() >0) {
    Serial.println(readString);

    if (readString == "on")     
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    if (readString == "off")
    {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
    readString="";
  } 
}
