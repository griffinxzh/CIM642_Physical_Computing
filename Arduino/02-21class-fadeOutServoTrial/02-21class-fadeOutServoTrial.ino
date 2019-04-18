int ledpin1 = 3;
int counter = 0;
int ledpin2 = 5;

long prevMillis = 0;
int interval = 10;

bool flipFlop = false;
//0 to 255, and then 255 to 0


void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);

}

void loop() {
  analogWrite(ledpin1, counter);
  analogWrite(ledpin2, counter);

  // every 10 millis(interval) do sth
  if (millis() - prevMillis >= interval) {
    prevMillis = millis(); // to save the point when "the last time when 10 millis passed"

    if (flipFlop == false) {
      counter = counter + 1;
    } else {
      counter = counter - 1;
    }
  }

  //the max = 255
  if (counter >= 255) {
    //counter = 0;
    flipFlop = true;
  }

  if (counter <= 0) {
    flipFlop = false;
  }


  //delay(10);
}
