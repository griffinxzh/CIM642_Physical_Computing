const int xPin = A0; //test: 250~400
const int yPin = A1; //test: 240~400
const int zPin = A2; //test: 260~410

int lowLimit = 240;
int highLimit = 410;
int tonePin = 8; //?????

void setup() {
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(xPin);
  delay(1);
  int y = analogRead(yPin);
  delay(1);
  int z = analogRead(zPin);
  delay(1);

  Serial.print(x);
  Serial.print("\t");  //tab

  Serial.print(y);
  Serial.print("\t");

  Serial.print(z);
  Serial.print("\n"); //print a new line

  int all = x + y + z;
  Serial.println(all);


  int mapped = map (all, 720, 1230, 31, 4978);
  Serial.print("post-limit: ");
  Serial.print(all);
  Serial.print("map: ");
  Serial.println(mapped);

  tone (tonePin, mapped, 100); //100?????

}
