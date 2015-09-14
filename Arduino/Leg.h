#ifndef LEG_H
#define LEG_H

#include <Servo.h>
#include <Arduino.h>
#include <stdint.h>

class Leg{
	
	private:

		Servo coxa,femur,tibia;
		uint8_t coxapos,femurpos,tibiapos;

	public:
	
		Leg(uint8_t coxa,uint8_t femur,uint8_t tibia); //Constructor of the Leg class
		
		~Leg(); //Destructor of the Leg class

		void move(uint8_t posCoxa,uint8_t posFemur,uint8_t posTibia);
};

#endif