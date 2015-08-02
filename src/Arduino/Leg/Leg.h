#ifndef LEG_H
#define LEG_H

#include <Servo.h>
#include <Arduino.h>

class Leg{
	
	private:

		Servo coxa,femur,tibia;
		int coxapos,femurpos,tibiapos;

	public:
	
		Leg(int coxa,int femur,int tibia,int initCoxa,int initFemur,int initTibia); //Constructor of the Leg class
		
		~Leg(); //Destructor of the Leg class

		void move(int posCoxa,int posFemur,int posTibia);

		Servo getCoxa();

		Servo getFemur();

		Servo getTibia();
};

#endif