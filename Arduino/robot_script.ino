#include "PacketHandler.h"
#include "Leg.h"
#include "robot_constants.h"


// Servo objects for the robot joints.
Servo shoulder[6];
Servo elbow[6];
Servo foot[6];

uint8_t packet_received;
PacketHandler handler;

void setup() {
  if(configs::c_relay) activateRelay;

  Serial.begin(9600);

  // Attach all the digital pins to the servos of the robot.
  for(int leg = 0; leg < 6; leg++){
    shoulder[leg].attach(configs::c_shoulder_pins[leg]);
    elbow[leg].attach(configs::c_elbow_pins[leg]);
    foot[leg].attach(configs::c_foot_pins[leg]);
  }
  // Added a delay to prevent disasters while setting things up.
  delay(1000);

  // Send all servos to their home positions as a default power on procedure.
  for(int leg = 0; leg < 6; leg++){
    shoulder[leg].write(configs::c_shoulder_home + configs::c_shoulder_offsets[leg]);
    elbow[leg].write(configs::c_elbow_home + configs::c_elbow_offsets[leg]);
    foot[leg].write(configs::c_foot_home + configs::c_foot_home[leg]);
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

void activateRelay(){
  // Set the mode of the digital pins for the relay.
  
  using namespace configs;

  pinMode(c_ground, OUTPUT);
  pinMode(c_vcc, OUTPUT);
  pinMode(c_relay_pin, OUTPUT);

  // Emulate virtual ground and vcc from digital pins.
  digitalWrite(c_vcc, HIGH);
  digitalWrite(c_ground, LOW);

  // Set the relay high while waiting for power supply to the arduino.
  digitalWrite(c_relay_pin, HIGH);
  delay(1000);

  // Switch on power to the servos.
  digitalWrite(c_relay_pin, LOW);
}

void actuate(Leg** command_list) {
  for(int i=0; i<6; i++) {
      // If there is data for leg i
      if(command_list[i] != NULL) {
        uint8_t id = command_list[i]->getID();

        // Actuate servos corresponding to leg id
        command_list[i]->addOffset(configs::c_shoulder_offsets[id], configs::c_elbow_offsets[id], configs::c_foot_offsets[id]);
        command_list[i]->actuate(&shoulder[id],&elbow[id],&foot[id]);
      }
  }
}
