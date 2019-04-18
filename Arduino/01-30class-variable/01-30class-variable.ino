int button1 = 2;
int led1 = 11;

//btw in physical world, use your finger to debug

void setup() {
  
  pinMode(button1, INPUT);
  pinMode(led1,OUTPUT);

  //to debug  (9600 is to set the speed limit to the communication
  Serial.begin(9600);
}

void loop() {
  //logic: if pin2 = high, pin11 = high; otherwise pin11 = low 


  
  int button = digitalRead(button1);
  //Serial.println("button1: " + button1); will not work
  
  Serial.print("button1:");
  Serial.println(button);
  digitalWrite(led1,button);  //"button press" = LOW, "button release" = LOW
}
