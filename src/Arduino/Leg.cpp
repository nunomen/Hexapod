#include <Servo.h>
#include <Arduino.h>
#include "Leg.h"

Leg::Leg(int coxapos, int femurpos, int tibiapos, int initcoxa, int initfemur, int inittibia){
	coxa.attach(initcoxa);
	femur.attach(initfemur);
	tibia.attach(inittibia);
	coxa.write(coxapos);
	femur.write(femurpos);
	tibia.write(tibiapos);
}

Leg::~Leg(){
}

void Leg::move(int posCoxa, int posFemur, int posTibia){
	coxa.write(posCoxa);
	femur.write(posFemur);
	tibia.write(posTibia);
}

