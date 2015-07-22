#ifndef ROBOT_H
#define ROBOT_H

#include <Servo.h>
#include <Arduino.h>

class Robot{
	
	private:

		Leg[6] legs;

	public:
	
		Robot(int coxapos, int femurpos, int tibiapos); //Constructor of the Joint class
		
		~Robot(); //Destructor of the Joint class

		move(Packet packet);

};

#endif

