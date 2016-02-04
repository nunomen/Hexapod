#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "State.h"
#include "Robot.h"

#define FIRST_CHAR 222
#define SECOND_CHAR 230
#define THIRD_CHAR 222
#define INITIATOR_PLUS_HEADER 4
#define NUMBER_OF_ANGLES_PER_LEG 3
#define NUMBER_OF_LEGS 6
#define TERMINAL_CHAR 233

using namespace std;

// Class constructor of the packet.
PacketHandler::PacketHandler()
{
    // Current index of the buffer.

    // Clean buffer and reset tracker index.
    this->reset();
}

PacketHandler::~PacketHandler()
{
    // Should it behave like this?
    memset(this->buffer, '\0', sizeof(this->buffer));
    memset(this->legs, '\0', sizeof(this->legs));
}

PacketHandler::receive()
{
    bool terminal_found = false;
    uint8_t header_found = 0;
    uint8_t tracker = 0;
    uint8_t expected_length = 0;
    while(Serial.available() || !terminal_found)
    {
        uint8_t incoming_byte = Serial.read();
        // This function returns the number of header bytes found so far
        header_found = this->findHeader(incoming_byte, header_found);
        if(header_found == 3)
        {
            if(tracker == 0){
                // Returns a pointer to the Leg array
                // (initially contains empty Leg objects)
                Leg* legs_ptr  = this->findFlags(incoming_byte);
                expected_length = findLength(incoming_byte) * 3;
            }
            else if(incoming_byte == TERMINAL_CHAR)
            {
                // If the packet does not have expected length
                if(tracker != expected_length){
                    return;
                }
                else{
                    // TODO Add leg nodes to the queue
                }
            }
            // If the packet length exceeds the expected
            else if( tracker > expected_length){
                return;
            }
            if(tracker > 0){
                // This function updates the respective angle of the respective
                // leg, given by incoming_byte
                // The leg to be updated is given by floor(tracker/3)
                // The joint to be updated is given by tracker%3
                this->updateLeg(incoming_byte, tracker, legs_ptr);
            }
            // Increment tracker
            tracker++;
        }
    }
}
