#ifndef STATE_H
#define STATE_H

#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>


class State
{
    public:
        State(void);
        virtual ~State(void);
        void writebuffer();
        bool findbeginner();
        bool header();
        void decryptheader();
        bool is_flag_set(uint8_t index);
        void getangles();
        uint8_t buffer[30];
        char* teste;
        void reset();

    protected:
        int package;
    private:
        
        int legs[6];
        int tracker;
        uint8_t flags;

};

#endif // STATE_H
