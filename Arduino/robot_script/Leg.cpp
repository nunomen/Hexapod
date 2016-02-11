#include <Servo.h>
#include <Arduino.h>
#include "Leg.h"
#include <stdint.h>


//inicializador de perna.
Leg::Leg(uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos){
	/*coxa.attach(initcoxa);
	femur.attach(initfemur);
	tibia.attach(inittibia);
	coxa.write(coxapos);
	femur.write(femurpos);
	tibia.write(tibiapos);*/
}

Leg::~Leg(){
}

//posiciona os 3 servos da perna nas posicoes indicadas por posCoxa, posFemur e posTibia
void Leg::move(uint8_t posCoxa, uint8_t posFemur, uint8_t posTibia){
	/*coxa.write(posCoxa);
	femur.write(posFemur);
	tibia.write(posTibia);*/
}
