const int xPin = A0; //test: 250~400
const int yPin = A1; //test: 240~400
const int zPin = A2; //test: 260~410

int lowLimit = 240;
int highLimit = 410;
int tonePin = 6; 

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
  Serial.print("\t"); //print a new line


  int changeX = abs(x - 500);
  if(changeX > 50 && changeX < 100){
    //play sound
    Serial.println("play sound x");
  }
  int all = x + y + z;
  Serial.println(y);


//if all < 1290

if(all < 1290){
  all = 1290;
}

 if all > 1700{
  all = 1700
  }

  int mapped = map (all, 1290, 1700, 31, 4978);
//  Serial.print("post-limit: ");
//  Serial.print(all);

  Serial.print("  map: ");
  Serial.println(mapped);

  tone (tonePin, mapped, 100); //100?????

}
