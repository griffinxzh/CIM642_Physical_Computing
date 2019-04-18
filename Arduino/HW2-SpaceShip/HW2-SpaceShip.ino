int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);


    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(250);
  }
}
