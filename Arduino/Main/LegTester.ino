
#include <Servo.h>

//shoulder, elbow ,foot

int shoulder_pin[] = {44,34,42,36,40,38};
int elbow_pin[] = {48,30,43,37,46,32};
int foot_pin[] = {52,26,41,39,50,28};

#define SHOULDER_HOME 90
#define ELBOW_HOME 90
#define FOOT_HOME 125

Servo shoulder[6];
Servo elbow[6];
Servo foot[6];

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for(int i=0;i<6;i++){
    shoulder[i].attach(shoulder_pin[i]);
    elbow[i].attach(elbow_pin[i]);
    foot[i].attach(foot_pin[i]);
  }
}

// the loop function runs over and over again forever
void loop() {
  shoulder[5].write(SHOULDER_HOME);
  elbow[5].write(ELBOW_HOME);
  foot[5].write(FOOT_HOME);
}
