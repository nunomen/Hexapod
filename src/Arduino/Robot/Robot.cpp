#include <Servo.h>
#include <Arduino.h>
#include <stdint.h>
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


//Dependendo do caso, mexe a perna escolhida para a posicao indicada
void Robot::moveLeg(uint8_t leg, uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos){
	switch(leg)
	case 1: leg[0].move(coxapos, femurpos, tibiapos); break;
	case 2: leg[1].move(coxapos, femurpos, tibiapos); break;
	case 3: leg[2].move(coxapos, femurpos, tibiapos); break;
	case 4: leg[3].move(coxapos, femurpos, tibiapos); break;
	case 5: leg[4].move(coxapos, femurpos, tibiapos); break;
	case 6: leg[5].move(coxapos, femurpos, tibiapos); break;
	default: break;
}