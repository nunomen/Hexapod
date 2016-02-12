#include <Servo.h>
#include <Arduino.h>
#include "Leg.h"
#include <stdint.h>

// Class constructor of the packet.
Leg::Leg(uint8_t id) {
	leg_id = id;
}

Leg::~Leg() {

}

void Leg::setFoot(uint8_t angle) {
	foot_angle = angle;
}

void Leg::setElbow(uint8_t angle) {
	elbow_angle = angle;
}

void Leg::setShoulder(uint8_t angle) {
	shoulder_angle = angle;
}

void Leg::actuate(Servo *shoulder_servo, Servo *elbow_servo, Servo *foot_servo) {
	shoulder_servo->write(shoulder_angle);
	elbow_servo->write(elbow_angle);
	foot_servo->write(foot_angle);
}
