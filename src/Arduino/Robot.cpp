#include <Servo.h>
#include <Arduino.h>
#include <stdint.h>
#include "Robot.h"
#include "Leg.h"

//inicializador de robot
//MODIFICAR OS PINS PARA USO NORMAL!!!!!!!!!!!!!!!
Robot::Robot(uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos){	
	legs[0] = new Leg(4, 5, 6, coxapos, femurpos, tibiapos);
	legs[1] = new Leg(7, 8, 9, coxapos, femurpos, tibiapos);
	legs[2] = new Leg(10, 11, 12, coxapos, femurpos, tibiapos);
	legs[3] = new Leg(13, 14, 15, coxapos, femurpos, tibiapos);
	legs[4] = new Leg(16, 17, 18, coxapos, femurpos, tibiapos);
	legs[5] = new Leg(19, 20, 21, coxapos, femurpos, tibiapos);
}

Robot::~Robot(){
}


//Dependendo do caso, mexe a perna escolhida para a posicao indicada
void Robot::moveLeg(int leg, uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos){
	switch(leg){
	case 1: legs[0]->move(coxapos, femurpos, tibiapos); break;
	case 2: legs[1]->move(coxapos, femurpos, tibiapos); break;
	case 3: legs[2]->move(coxapos, femurpos, tibiapos); break;
	case 4: legs[3]->move(coxapos, femurpos, tibiapos); break;
	case 5: legs[4]->move(coxapos, femurpos, tibiapos); break;
	case 6: legs[5]->move(coxapos, femurpos, tibiapos); break;
	default: break;
	}
}