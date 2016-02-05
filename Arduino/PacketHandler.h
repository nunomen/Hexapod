#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include <stdint.h>
#include <queue>
#include <vector>
#include <Leg.h>


class PacketHandler
{
    public:
        // Implements the common behaviour between objects of
        // PacketHandler class.
        PacketHandler();

        // Method reads data from serial port and adds commands to the FIFO
        // queue. This should
        void receive();


    private:
        uint8_t findHeader(uint8_t current_byte, uint8_t header_bytes_found);
        std::queue <Leg> command_queue;
        std::vector<Leg>* findFlags(uint8_t incoming_byte);
        uint8_t findLength(uint8_t incoming_byte);
        void updateLeg(uint8_t incoming_byte, uint8_t tracker, Leg* legs_ptr);
}


#endif
