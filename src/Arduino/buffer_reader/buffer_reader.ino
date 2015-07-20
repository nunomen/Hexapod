byte lol;
int a=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    /* read the most recent byte */
    lol = Serial.read();
    /*ECHO the value that was read, back to the serial port. */
    Serial.write(lol);
    a++;
  }
}
