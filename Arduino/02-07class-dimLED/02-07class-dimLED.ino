int ledPin1 = 10;
int ledPin2 = 11;

//pinMode is only for digtial pin

int pot1 = A0; //potentiometer on analog pin A0
int potRead = 0;


void setup() {
  //  tell Arduino to send signal back to computer
  //   9600 is the setting the speed limit between Arduino and computer
  Serial.begin(9600);

  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);

}

void loop() {
  //  digitalWrite(ledPin1, HIGH);
  //  digitalWrite(ledPin2, HIGH);

  // analogWrite(ledPin1, 10);  //use "analog" signal instead of digital signal
  // analogWrite(ledPin2, 255);
  //0=off   255=100% full brightness
  //the result is one light is dimmer

  potRead = analogRead(pot1)/4;  // 255 instead of 1023
  Serial.println(potRead);
  analogWrite(ledPin1, potRead); //dim one led 0~255
  

//  if (potRead < 512) {  // 512 is half of 1024 (0~1023)
//    analogWrite(ledPin1, 0);
//    analogWrite(ledPin2, 255);
//  } else {
//    analogWrite(ledPin1, 255);
//    analogWrite(ledPin2, 0);
//  }
}
