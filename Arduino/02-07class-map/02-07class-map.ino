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


  //MAPPING METHOD #1
  potRead = analogRead(pot1); 
  int mapped = map (potRead,0,80,0,255);
  Serial.println(potRead);
  analogWrite(ledPin1, mapped); //dim one led 0~255

}
