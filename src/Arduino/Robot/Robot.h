#ifndef ROBOT_H
#define ROBOT_H

#include <Servo.h>
#include <Arduino.h>
#include "Leg.h"

class Robot{
	
	private:

		legs = new Leg[6]; // ERRO!!!!

	public:
	
		Robot(int coxapos, int femurpos, int tibiapos); //Constructor of the Robot class
		
		~Robot(); //Destructor of the Robot class

		

};

#endif