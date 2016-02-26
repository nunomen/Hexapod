#include "PacketHandler.h"
#include "Leg.h"

const uint8_t shoulder_pins[] = { 44, 34, 42, 36, 40, 38 };
const uint8_t elbow_pins[] = { 48, 30, 43, 37, 46, 32 };
const uint8_t foot_pins[] = { 52, 26, 41, 39, 50, 28 };

const int8_t shoulder_offsets[] = { 0, 0, 0, 0, 0, 0 };
const int8_t elbow_offsets[] = { -5, 5, -5, -5, 0, 0 };
const int8_t foot_offsets[] = { 0, 0, 0, 15, 0, 0 };

//#define GND 7
//#define VCC 5
//#define RELAY 6

#define SHOULDER_HOME 90
#define ELBOW_HOME 100
#define FOOT_HOME 120

Servo shoulder[6];
Servo elbow[6];
Servo foot[6];


uint8_t packet_received;
PacketHandler handler;

void setup() {
  //pinMode(GND, OUTPUT);
  //pinMode(VCC, OUTPUT);
  //pinMode(RELAY, OUTPUT);
  //digitalWrite(VCC, HIGH);
  //digitalWrite(GND, LOW);
  //digitalWrite(RELAY, HIGH);
  //delay(1000);
  //digitalWrite(RELAY, LOW);
  Serial.begin(9600);
  for(int leg = 0; leg < 6; leg++){
    shoulder[leg].attach(shoulder_pins[leg]);
    elbow[leg].attach(elbow_pins[leg]);
    foot[leg].attach(foot_pins[leg]);
  }
  delay(1000);
  for(int leg = 0; leg < 6; leg++){
    shoulder[leg].write(SHOULDER_HOME + shoulder_offsets[leg]);
    elbow[leg].write(ELBOW_HOME + elbow_offsets[leg]);
    foot[leg].write(FOOT_HOME + foot_offsets[leg]);
  }
}

void loop() {
  packet_received = handler.receive();
  if(packet_received == 1) {
      handler.simulate_commands();
      Leg** command_list = handler.getCommands();
      actuate(command_list);
      packet_received = 0;
  }
}

void actuate(Leg** command_list) {
  for(int i=0; i<6; i++) {
      // If there is data for leg i
      if(command_list[i] != NULL) {
        uint8_t id = command_list[i]->getID();
        // Actuate servos corresponding to leg id
        command_list[i]->addOffset(shoulder_offsets[id], elbow_offsets[id], foot_offsets[id]);
        command_list[i]->actuate(&shoulder[id],&elbow[id],&foot[id]);
      }
  }
}
