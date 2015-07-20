#ifndef SPCOM_H
#define SPCOM_H

#include "Packet.h"

//Serial Packet Communication
class SPCom
{
    public:
        SPCom(unsigned int baudrate);
        virtual ~SPCom();

        //void send_packet(Packet packet);	//TODO
        bool peek();				//returns 1 if there is a complete packet to read, else returns 0
        Packet *read_packet();

    protected:
    private:
    	int serial;		//Serial port, in arduino Mega there is Serial1, Serial2 and Serial3
    	uint8_t buffer[260];
    	int tracker;
    	void write_buffer();
    	int find_beginner(void);	//receives void, returns the position of the
    	int find_ender(void);

};

#endif // SPCOM_H
