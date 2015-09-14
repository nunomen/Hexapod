#ifndef ROBOT_H
#define ROBOT_H

#include <Servo.h>
#include <Arduino.h>
#include "Leg.h"
#include <stdint.h>


class Robot{
	
	private:

		Leg* legs[6];

	public:
	
		Robot(uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos); //Constructor of the Robot class
		
		~Robot(); //Destructor of the Robot class

		void moveLeg(int leg, uint8_t coxapos, uint8_t femurpos, uint8_t tibiapos);

};

#endif