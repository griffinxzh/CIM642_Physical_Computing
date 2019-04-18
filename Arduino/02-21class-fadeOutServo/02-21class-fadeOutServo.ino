#include <Servo.h>

//int ledpin1 = 3;
int counter = 0;
int ledpin2 = 5;

long prevMillis = 0;
int interval = 10;

bool flipFlop = true;
//0 to 255, and then 255 to 0

Servo myservo;

void setup() {
  // pinMode(ledpin1, OUTPUT);
  myservo.attach(5);
}

void loop() {
  //analogWrite(ledpin1, counter);

  myservo.write(counter);


  // every 10 millis(interval) do sth
  if (millis() - prevMillis >= interval) {
    prevMillis = millis(); // to save the point when "the last time when 10 millis passed"

    if (flipFlop == true) {
      counter = counter + 1;
    } else {
      counter = counter - 1;
    }
  }


  if (counter >= 180) {
    //counter = 0;
    flipFlop = false;
  }

  if (counter <= 0) {
    flipFlop = true;
  }


  //delay(10);
}
