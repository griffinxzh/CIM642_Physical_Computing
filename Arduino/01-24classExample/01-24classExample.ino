void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);  //set pin 13 as an output pin
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);  //pin 13 turned on (HIGH = ON)
  delay (100); //1000 millis = 1 sec
  digitalWrite(13,LOW);
  delay (500);
  }
