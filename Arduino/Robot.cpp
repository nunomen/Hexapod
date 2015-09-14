#include <Servo.h>
#include <Arduino.h>
#include <stdint.h>
#include "Robot.h"
#include "Leg.h"

//inicializador de robot
//MODIFICAR OS PINS PARA USO NORMAL!!!!!!!!!!!!!!!
Robot::Robot(uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos){	
	legs[0] = new Leg( coxapos, femurpos, tibiapos);
	legs[1] = new Leg( coxapos, femurpos, tibiapos);
	legs[2] = new Leg( coxapos, femurpos, tibiapos);
	legs[3] = new Leg( coxapos, femurpos, tibiapos);
	legs[4] = new Leg( coxapos, femurpos, tibiapos);
	legs[5] = new Leg( coxapos, femurpos, tibiapos);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);    
	pinMode(4, OUTPUT);    
	pinMode(5, OUTPUT);    
	pinMode(6, OUTPUT);    
	pinMode(7, OUTPUT);    
	pinMode(8, OUTPUT);    
	pinMode(9, OUTPUT);    
	pinMode(10, OUTPUT);        
	pinMode(A0, OUTPUT);    
	pinMode(A1, OUTPUT);    
	pinMode(A2, OUTPUT);    
	pinMode(A3, OUTPUT);    
	pinMode(A4, OUTPUT);    
	pinMode(A5, OUTPUT);    
}

Robot::~Robot(){
}


//Dependendo do caso, mexe a perna escolhida para a posicao indicada
void Robot::moveLeg(int leg, uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos){
	switch(leg){
		case 1: legs[0]->move(coxapos, femurpos, tibiapos);
			Serial.println("PASSOU NA PATA 1");
			digitalWrite(2,HIGH);
			digitalWrite(3,HIGH);
			digitalWrite(4,HIGH); 
			break;
		case 2: legs[1]->move(coxapos, femurpos, tibiapos); 
			Serial.println("PASSOU NA PATA 2");
			digitalWrite(5,HIGH);
			digitalWrite(6,HIGH);
			digitalWrite(7,HIGH);
			break;
		case 3: legs[2]->move(coxapos, femurpos, tibiapos); 
			Serial.println("PASSOU NA PATA 3");
			digitalWrite(8,HIGH);
			digitalWrite(9,HIGH);
			digitalWrite(10,HIGH);
			break;
		case 4: legs[3]->move(coxapos, femurpos, tibiapos); 
			Serial.println("PASSOU NA PATA 4");
			digitalWrite(11,HIGH);
			digitalWrite(12,HIGH);
			digitalWrite(13,HIGH);
			break;
		case 5: legs[4]->move(coxapos, femurpos, tibiapos); 
			Serial.println("PASSOU NA PATA 5");
			digitalWrite(A3,HIGH);
			digitalWrite(A4,HIGH);
			digitalWrite(A5,HIGH);
			break;
		case 6: legs[5]->move(coxapos, femurpos, tibiapos); 
			break;
		default: 
			break;
	}
}
	
