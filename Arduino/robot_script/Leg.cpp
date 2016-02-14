#include <Servo.h>
#include <Arduino.h>
#include "Leg.h"
#include <stdint.h>

#define SERIAL_ID 190

#define SHOULDER_LEFT_LIM 30
#define SHOULDER_RIGHT_LIM 150
#define ELBOW_UPPER_LIM 15
#define ELBOW_LOWER_LIM 165
#define FOOT_UPPER_LIM 165
#define FOOT_LOWER_LIM 20

// Class constructor of the packet.
Leg::Leg(uint8_t id) {
	leg_id = id;
}

Leg::~Leg() {

}

uint8_t Leg::getID() {
	return leg_id;
}

void Leg::setFoot(uint8_t angle) {
	if(angle < FOOT_LOWER_LIM){
		foot_angle = FOOT_LOWER_LIM;
		Serial.write(249);
	}
	else if(angle > FOOT_UPPER_LIM) {
		foot_angle = FOOT_UPPER_LIM;
		Serial.write(249);
	}
	else {
		foot_angle = angle;
	}
}

void Leg::setElbow(uint8_t angle) {
	if(angle < ELBOW_UPPER_LIM) {
		elbow_angle = ELBOW_UPPER_LIM;
		Serial.write(249);
	}
	else if(angle > ELBOW_LOWER_LIM) {
		elbow_angle = ELBOW_LOWER_LIM;
		Serial.write(249);
	}
	else {
		elbow_angle = angle;
	}
}

void Leg::setShoulder(uint8_t angle) {
	if(angle < SHOULDER_LEFT_LIM) {
		shoulder_angle = SHOULDER_LEFT_LIM;
		Serial.write(249);
	}
	else if(angle > SHOULDER_RIGHT_LIM) {
		shoulder_angle = SHOULDER_RIGHT_LIM;
		Serial.write(249);
	}
	else {
		shoulder_angle = angle;
	}
}

uint8_t Leg::getFoot() {
	return foot_angle;
}

uint8_t Leg::getElbow() {
	return elbow_angle;
}

uint8_t Leg::getShoulder() {
	return shoulder_angle;
}

void Leg::simulate_actuate() {
	Serial.write(SERIAL_ID + leg_id);
	Serial.write(shoulder_angle);
	Serial.write(elbow_angle);
	Serial.write(foot_angle);
}

void Leg::actuate(Servo *shoulder_servo, Servo *elbow_servo, Servo *foot_servo) {
	shoulder_servo->write(shoulder_angle);
	elbow_servo->write(elbow_angle);
	foot_servo->write(foot_angle);
}
