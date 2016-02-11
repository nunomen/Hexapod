#include "PacketHandler.h"
#include "queue.h"
#include "vector.h"

const uint8_t shoulder_pins[] = { 44, 34, 42, 36, 40, 38 };
const uint8_t elbow_pins[] = { 48, 30, 43, 37, 46, 32 };
const uint8_t foot_pins[] = { 44, 34, 42, 36, 40, 38 };

#define SHOULDER_HOME 90
#define ELBOW_HOME 90
#define FOOT_HOME 125

#define SHOULDER_DEF_1 70
#define ELBOW_DEF_1 70
#define FOOT_DEF_1 70

Servo shoulder[6];
Servo elbow[6];
Servo foot[6];

PacketHandler handler;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int leg = 0; i < 6; i++){
    shoulder[leg].attach(shoulder_pins[leg]);
    elbow[leg].attach(elbow_pins[leg]);
    foot[leg].attach(foot_pins[leg]);
  }
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int leg = 0; leg < 6; leg++){
      shoulder[leg].write(SHOULDER_DEF_1);
      elbow[leg].write(ELBOW_DEF_1);
      foot[leg].write(FOOT_DEF_1);
      delay(500);
    }
}
