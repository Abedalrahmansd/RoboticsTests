int lid = 8;
int btn = 9;
int reading = 0;
bool isBtnClicked = false;

void setup() {

  // put your setup code here, to run once:
pinMode(btn,INPUT);
pinMode(lid,OUTPUT);

}

void loop() {
//   put your main code here, to run repeatedly:

isBtnClicked = digitalRead(btn)== 1;
if(isBtnClicked and digitalRead(lid)==1){
reading = 0;

}else if(isBtnClicked and digitalRead(lid)==0){

  reading = 1;
}

digitalWrite(lid,reading);
   delay(150);

}
