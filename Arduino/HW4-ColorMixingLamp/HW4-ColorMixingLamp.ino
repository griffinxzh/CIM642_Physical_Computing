const int redLEDPin = 11;  // consistent w/ the LED pin
const int blueLEDPin = 10;
const int greenLEDPin = 9;

const int redSensorPin = A0; //transistor + red mask = red light sensor
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//output:color
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

//input: lights
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin); //read red input signal
  delay(5); //allow data processing
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);

  Serial.print("Raw Sensor Values \t Red:");
  Serial.print(redSensorValue);
  Serial.print("\t Green:");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue:");
  Serial.print(blueSensorValue);

  redValue = redSensorValue / 4; // 1024 / 4 = 255
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped sensor values \t Red:");
  Serial.print(redValue);
  Serial.print("\t Green:");
  Serial.print(greenValue);
  Serial.print("\t Blue:");
  Serial.print(blueValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
