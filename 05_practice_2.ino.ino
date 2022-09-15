void setup() {
  pinMode(7, OUTPUT);
}

void loop() {
  
  digitalWrite(7, LOW);
  delay(1000);
  
  int i = 0;
  while(i<5) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    i++;
  }

  while(1) {
    digitalWrite(7, HIGH);
  }
}
