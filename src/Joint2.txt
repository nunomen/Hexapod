#ifndef JOINT2_H
#define JOINT2_H

#include <Servo.h>
#include <Arduino.h>

class Joint{
	
	private:

		Servo motorH, motorV;


		float spdH = 0.2, spdV = 0.2, steptime=0.1;
		float initH=0,initV=0,endH=180,endV=180, actualH=initH,actualV=initV;
		unsigned long prevMillisH,prevMillisV;;


	public:
	
		Joint(); //Constructor of the Joint class
		
		~Joint(); //Destructor of the Joint class

		void moveTo();

		void right();

		void left();

		void up();

		void down();

		void channelH(int);

		void channelV(int);

		float getSpot(int);

		void printp();
	
		
};

#endif

