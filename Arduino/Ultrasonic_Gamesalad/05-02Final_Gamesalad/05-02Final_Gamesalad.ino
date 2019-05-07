#include <Keyboard.h>

// test in 3.5v (adafruit feather 32u4)
const int xPin = A0;   //test: 370~600
const int yPin = A1;   //test: 380~600
const int zPin = A2;   //test: 400~610

int switchPin = 11; //input pin: switch
int ledPin = 10;    //output pin: LED

int switchRead;
int prevSwitchRead = 0;
int ledLight = 0;     //led default: off



void setup() {
  Serial.begin (9600);
  Keyboard.begin();

  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  /* switch

    Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
    press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
    a minimum delay between toggles to debounce the circuit (i.e. to ignore
    noise).

    David A. Mellis
    21 November 2006
  */


  switchRead = digitalRead(switchPin);  //pressed: HIGH,  released:LOW

  Serial.print("Light: ");
  Serial.println(ledLight);

  if (switchRead == HIGH) {
    prevSwitchRead = 1;
  }

  if (switchRead == LOW && prevSwitchRead == 1) {
    prevSwitchRead = 0;



    if (ledLight == 0) {
      ledLight = 1;
    } else {
      ledLight = 0;
    }


  }
  if (ledLight == 1) {
    digitalWrite(ledPin, HIGH);
    logic();
  } else {
    digitalWrite(ledPin, LOW);
  }
  //digitalWrite(ledPin, ledLight);
}

void logic(){
  int x = analogRead(xPin);
  delay(1);
  int y = analogRead(yPin);
  delay(1);
  int z = analogRead(zPin);
  delay(1);
  int all = x + y + z; //1330~1660

  //  Serial.print("x:");
  //  Serial.print(x);
  //  Serial.print("\t");  //tab
  //
  //  Serial.print("y:");
  //  Serial.print(y);
  //  Serial.print("\t");
  //
  //  Serial.print("z:");
  //  Serial.print(z);
  //  Serial.print("\t");
  //
  //  Serial.print("all:");
  //  Serial.print(all);
  //  Serial.println("\t"); //print a new line




  if (all < 1330) {
    all = 1330;
  }
  if (all > 1660) {
    all = 1660;
  }




  if (all >= 1330 && all < 1370) {
    Keyboard.press('a');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("A");

  }
  if (all >= 1370 && all < 1410) {
    Keyboard.press('s');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("S");
  }
  if (all >= 1410 && all < 1450) {
    Keyboard.press('d');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("D");
  }
  if (all >= 1450 && all < 1490) {
    Keyboard.press('f');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("F");
  }
  if (all >= 1490 && all < 1530) {
    Keyboard.press('g');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("G");
  }
  if (all >= 1530 && all < 1570) {
    Keyboard.press('h');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("H");
  }
  if (all >= 1570 && all < 1610) {
    Keyboard.press('j');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("J");
  }
  if (all >= 1610 && all < 1660) {
    Keyboard.press('k');
    delay(50);
    Keyboard.releaseAll();
    delay(50);
    Serial.println("K");
  }



}
