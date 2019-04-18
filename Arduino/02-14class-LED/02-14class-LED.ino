int switchPin = 2;
int led1 = 3;
int led2 = 4;

int switchRead = 0;

int counter = 0;

boolean wasPressed = false;

long prevMillis = 0;    //long is a huge int (int:-3200~3200)
int interval = 0;
boolean trigger = false;



void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  switchRead = digitalRead(switchPin);
  Serial.print("switch: ");
  Serial.println(switchRead);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  if (switchRead == HIGH) {
    //  { counter = counter +1; //count how many times the button was pressed
    //    Serial.println(counter);
    wasPressed = true;
  }

  if (switchRead == LOW && wasPressed == true) {
    counter = counter + 1;
    wasPressed = false;
  }

  Serial.print("counter");
  Serial.println(counter);

  if (counter == 0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else if (counter == 1) {
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
  } else if (counter == 2) {
    digitalWrite (led1, LOW);
    digitalWrite (led2, HIGH);
  } else if (counter == 3) {
    if (millis() - prevMillis >= interval) {
      prevMillis = millis();
      // the "print" slows down the arduino, so in line1 the millis = 1, in line2 it might be 2.

      if (trigger == false) {
        trigger == true;
      } else {
        trigger = false;
      }


    }

  }


  //        digitalWrite (led2, HIGH);
  //        delay (2000);
  //        digitalWrite (led LOW);
  //        delay (2000); //there will be 4s sleep (b/c of the delay)

  else {
    counter = 0;
  }

  if (trigger == true) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);

  }



}
