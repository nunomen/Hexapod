#include <Servo.h>

//shoulder, elbow ,foot

int shoulder_pin[] = {44,34,42,36,40,38};
int elbow_pin[] = {48,30,43,37,46,32};
int foot_pin[] = {52,26,41,39,50,28};

#define SHOULDER_HOME 90
#define ELBOW_HOME 90
#define FOOT_HOME 125

#define SHOULDER_DEF_1 70
#define ELBOW_DEF_1 70
#define FOOT_DEF_1 70

Servo shoulder[6];
Servo elbow[6];
Servo foot[6];

int leg=0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for(int i=0;i<3;i++){
    shoulder[i].attach(shoulder_pin[i]);
    elbow[i].attach(elbow_pin[i]);
    foot[i].attach(foot_pin[i]);
  }
  shoulder[1].write(110);
  shoulder[2].write(70);
  delay(1000);
  shoulder[leg].write(SHOULDER_HOME);
  elbow[leg].write(ELBOW_HOME);
  foot[leg].write(FOOT_HOME);
  delay(500);
}


void loop() {

  // home
  elbow[leg].write(60);
  foot[leg].write(10); //should be 5
  delay(50);
  shoulder[leg].write(120);
  delay(250);
  //2nd move
  elbow[leg].write(90);
  foot[leg].write(45); //should be 5
  delay(100);
  shoulder[leg].write(60);
  delay(250);

  /*
    for(int leg=0;leg<1;leg++){
    shoulder[leg].write(SHOULDER_DEF_1);
    elbow[leg].write(ELBOW_DEF_1);
    foot[leg].write(FOOT_DEF_1);
    delay(500);
  }
  */

}
