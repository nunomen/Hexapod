#include <Servo.h>
#include <Arduino.h>
#include "Robot.h"
#include "Leg.h"
#include "Packet.h"

Robot::Robot(int coxapos, int femurpos, int tibiapos){
	legs[0] = new Leg(pin1, pin2, pin3, coxapos, femurpos, tibiapos);
	legs[1] = new Leg(pin1, pin2, pin3, coxapos, femurpos, tibiapos);
	legs[2] = new Leg(pin1, pin2, pin3, coxapos, femurpos, tibiapos);
	legs[3] = new Leg(pin1, pin2, pin3, coxapos, femurpos, tibiapos);
	legs[4] = new Leg(pin1, pin2, pin3, coxapos, femurpos, tibiapos);
	legs[5] = new Leg(pin1, pin2, pin3, coxapos, femurpos, tibiapos);
}

Robot::~Robot(){
}


//modificar primeiro o packet
void Robot::move(Packet packet){
	int* numlegs = packet.getLegs();
	int i = 0;
	while(numlegs[i] != '\0'){
		int* angles = packet.getAngles();
		int j = 0;
		while(angles[j] != '\0'){
			if(angles[j] < 30 || angles[j] > 150)
			{
				legs[numlegs[i]].move(angles[j],angles[j+1],angles[j+2]);
			}
			j++;
		}
		i++;
	}
}

