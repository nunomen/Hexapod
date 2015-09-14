#ifndef STATE_H
#define STATE_H

#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>
#include "Robot.h"


class State
{
    public:
        State(void);
        virtual ~State(void);
        void writebuffer();
        bool findbeginner();
        bool header();
        bool decryptheader();
        bool is_flag_set(uint8_t);
        int getangles(int);
        uint8_t buffer[30];
        void reset();
        uint8_t getlegs(int);
        void moveRobot();

        //***TESTE COM LEDS***//

        void ON();
        void OFF();


    protected:
    	
    private:
        
        uint8_t legs[6];
        int tracker;
        uint8_t flags;
        Robot* robot;

        

};

#endif // STATE_H