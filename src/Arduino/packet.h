#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>


class Packet
{
    public:
        Packet(void);
        Packet(void *data, uint8_t dataSize);
        virtual ~Packet(void);
        uint8_t get_size(void);          //receives void, returns the packet size in bytes
        void set_size(uint8_t size); //receives data size, returns void
        uint8_t get_flags(void);         //receives void, returns the flags byte
        bool set_flag(uint8_t index);     //receives the flag index [0-7], returns true on success
        bool reset_flag(uint8_t index);   //receives the flag index [0-7], returns true on success
        bool is_flag_set(uint8_t index);  //receives the flag index [0-7], returns the flag
        void *get_data(void);


    protected:
    private:
        uint8_t size;
        uint8_t flags;
        void *data;

};

#endif // PACKET_H
