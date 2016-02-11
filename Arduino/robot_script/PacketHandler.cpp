#include "PacketHandler.h"
#include <Arduino.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define FIRST_CHAR 222
#define SECOND_CHAR 230
#define THIRD_CHAR 222
#define TERMINAL_CHAR 233


// Class constructor of the packet.
PacketHandler::PacketHandler(){
}

void PacketHandler::receive()
{
    bool terminal_found = false;
    uint8_t header_bytes_found = 0;
    uint8_t tracker = 0;
    uint8_t expected_length = 0;
    Vector<Leg> legs;
    while(Serial.available() && !terminal_found)
    {
        uint8_t incoming_byte = Serial.read();
        // This function returns the number of header bytes found so far
        header_bytes_found = this->findHeader(incoming_byte, header_bytes_found);
        if(header_bytes_found == 3)
        {
            if(tracker == 0){
                // Returns a pointer to the Leg array
                // (initially contains empty Leg objects)
                legs  = this->findFlags(incoming_byte);
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
                // The leg to be updated is given by 'floor(tracker / 3)'
                // The joint to be updated is given by 'tracker % 3'
                this->updateLeg(incoming_byte, tracker, legs);
            }
            // Increment tracker
            tracker++;
        }
    }
}

uint8_t PacketHandler::findHeader(uint8_t incoming_byte, uint8_t header_bytes_found)
{
    /*
    This method will receive the incoming byte from serial, and the number of
    bytes of the header found until this this point.
    It should return the header bytes found if everything runs as expected, and
    -1 otherwise.
    */
    if(header_bytes_found == 3)
    {
        return 3;
    }
    else if(header_bytes_found == 0 && incoming_byte == FIRST_CHAR)
    {
        return 1;
    }
    else if(header_bytes_found == 1 && incoming_byte == SECOND_CHAR)
    {
        return 2;
    }
    else if(header_bytes_found == 2 && incoming_byte == THIRD_CHAR)
    {
        return 3;
    }
    else return -1;
}

Vector<Leg> PacketHandler::findFlags(uint8_t incoming_byte)
{
    /*
    This method receives the incoming byte for the header, and makes bitwise
    operations to find the leg indexes that are active in the incoming packet.
    It returns a pointer to an array of active leg objects.
    */
    Vector<Leg> legs;
    for(int i = 0; i < 8; i++){
        if(incoming_byte & (1 << i) != 0){
            // Create Leg object with id=i and insert it into the legs array.
            legs.push_back(Leg myleg(i));
        }
    }
    return legs;
}

uint8_t PacketHandler::findLength(uint8_t incoming_byte)
{
    /*
    This method receives the header byte and returns the number of active legs.
    */
    uint8_t counter = 0;
    for(int i = 0; i < 8; i++){
        if(incoming_byte & (1 << i) != 0){
            counter++;
        }
    }
    return counter;
}

void PacketHandler::updateLeg(uint8_t incoming_byte, uint8_t tracker, Vector<Leg> &legs)
{
    /*

    */
    uint8_t index = tracker - 1;
    if(index % 3 == 0){
        legs[index/3].setShoulder(incoming_byte);
    }
    else if(index % 3 == 1){
        legs[index/3].setElbow(incoming_byte);
    }
    else if(index % 3 == 2){
        legs[index/3].setFoot(incoming_byte);
    }
}
