#include <Servo.h> 
#include "State.h"


State st;
int led;
int prevMillis=0;
int timer =100;

void setup() 
{ 
 Serial.begin(9600);
 for(led=4; led<13;led++)
   pinMode(led,OUTPUT);
 
} 

void loop() 
{
  
 st.writebuffer();
 st.decryptheader();
 st.ON();
 st.reset();

 
 
}
