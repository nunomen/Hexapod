#ifndef PacketHandler_h
#define PacketHandler_h

#include <stdint.h>
#include "Leg.h"


class PacketHandler
{
    public:
        // Method reads data from serial port and adds commands to the FIFO
        // queue. This should
        uint8_t receive();
        void simulate_commands();
        void resetCommands();

    private:
        uint8_t findHeader(uint8_t current_byte, uint8_t header_bytes_found);
        Leg** command_list;
        Leg** findFlags(Leg** legs, uint8_t incoming_byte);
        uint8_t findLength(uint8_t incoming_byte);
        void updateLeg(uint8_t incoming_byte, uint8_t tracker, Leg** legs_ptr);
        Leg* legs[6];
};

#endif
