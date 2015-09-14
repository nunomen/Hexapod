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
        void reset();
        void moveRobot();
        

        //***TESTE COM LEDS***//
        void resetpins();
        void ON();
        void OFF();


    protected:
    	
    private:
        uint8_t legs[6];
        uint8_t buffer[30];
        int tracker;
        uint8_t flags;
        Robot* robot;
        bool findbeginner();
        bool header();
        bool decryptheader();
        int getangles(int);
        uint8_t getlegs(int);
        bool is_flag_set(uint8_t);

        

};

#endif // STATE_H