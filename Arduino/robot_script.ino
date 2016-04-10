#include "PacketHandler.h"
#include "Leg.h"

// Digital pins assigned to each servo of the robot.
const uint8_t c_shoulder_pins[] = { 44, 34, 42, 36, 40, 38 };
const uint8_t c_elbow_pins[] = { 48, 30, 43, 37, 46, 32 };
const uint8_t c_foot_pins[] = { 52, 26, 41, 39, 50, 28 };

// Calibration of servo motor offsets.
const int8_t c_shoulder_offsets[] = { 0, 0, 0, 0, 0, 0 };
const int8_t c_elbow_offsets[] = { -5, 5, -5, -5, 0, 0 };
const int8_t c_foot_offsets[] = { 0, 0, 0, 15, 0, 0 };

// Assigning origin angles for the servo motors.
const uint8_t c_shoulder_home(90);
const uint8_t c_elbow_home(100);
const uint8_t c_foot_home(120);

// Digital pins assigned to the relay.
const uint8_t c_ground(7);
const uint8_t c_vcc(5);
const uint8_t c_relay_pin(6);

// Change this constant to true if relay is supposed to be activated.
const bool c_relay(false);

// Servo objects for the robot joints.
Servo shoulder[6];
Servo elbow[6];
Servo foot[6];

uint8_t packet_received;
PacketHandler handler;

void setup() {
  if(c_relay) activateRelay;

  Serial.begin(9600);

  // Attach all the digital pins to the servos of the robot.
  for(int leg = 0; leg < 6; leg++){
    shoulder[leg].attach(c_shoulder_pins[leg]);
    elbow[leg].attach(c_elbow_pins[leg]);
    foot[leg].attach(c_foot_pins[leg]);
  }
  // Added a delay to prevent disasters while setting things up.
  delay(1000);

  // Send all servos to their home positions as a default power on procedure.
  for(int leg = 0; leg < 6; leg++){
    shoulder[leg].write(c_shoulder_home + c_shoulder_offsets[leg]);
    elbow[leg].write(c_elbow_home + c_elbow_offsets[leg]);
    foot[leg].write(c_foot_home + c_foot_home[leg]);
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
        command_list[i]->addOffset(c_shoulder_offsets[id], c_elbow_offsets[id], c_foot_offsets[id]);
        command_list[i]->actuate(&shoulder[id],&elbow[id],&foot[id]);
      }
  }
}
