int tonePin = 8;
int photoPin = A0;
int photoRead = 0;

int lowLimit = 30;
int highLimit = 600; //don't let input go above the range of a analog sensor



void setup() {
  
  Serial.begin(9600);
  
}

void loop() {
  
  
//don't let input go above the range of a analog sensor, set minimum = 30, max = 600
// 目的是消除安全隐患
  photoRead = analogRead(photoPin);
  Serial.print("pre-limit: ");
  Serial.print(photoRead);
 
  if(photoRead < lowLimit){
    photoRead = lowLimit;}
  if (photoRead > highLimit){
    photoRead = highLimit;}


// input
  int mapped = map (photoRead,0,600, 31,4978);
  Serial.print("post-limit: ");
  Serial.print(photoRead);
  Serial.print("map: ");
  Serial.println(mapped);//pirntln换行

  
  //output
  tone (tonePin, mapped, 100);
}
