#include <Servo.h>
#include <Arduino.h>
#include "Joint2.h"

Joint::Joint(){

}

Joint::~Joint(){
}

void Joint::moveTo(){

  //Horizontal

  if((actualH <= endH) && (millis() - prevMillisH >= steptime)){
    prevMillisH=millis();
    right();

  }

  if((actualH >= endH) && (millis() - prevMillisH >= steptime)){
  	prevMillisH=millis();
  	left();
  }

  //Vertical
  if((actualV < endV) && (millis() - prevMillisV >= steptime)){
    prevMillisV=millis();
    up();
  }

  if((actualV >= endV) && (millis() - prevMillisV >= steptime)){
  	prevMillisV=millis();
  	down();
  }
  
}
void Joint::right(){

	float step=spdH*steptime;
	motorH.write(actualH+step);
	actualH+=step;\

}

void Joint::left(){

	float step=spdH*steptime;
	motorH.write(actualH-step);
	actualH-=step;

}

void Joint::up(){

	float step=spdV*steptime;
	motorV.write(actualV+step);
	actualV+=step;
}

void Joint::down(){

	float step=spdV*steptime;
	motorV.write(actualV-step);
	actualV-=step;

}

void Joint::channelH(int pin){

	motorH.attach(pin);
	motorH.write(initH);
}

void Joint::channelV(int pin){

	motorV.attach(pin);
	motorV.write(initV);
}

float Joint::getSpot(int flag){

	if(flag==0)
		return initH;

	if(flag==1)
		return endH;

	if(flag==2)
		return initV;

	if(flag==3)
		return endV;
}

void Joint::printp(){
	Serial.println(motorH.read());
}


