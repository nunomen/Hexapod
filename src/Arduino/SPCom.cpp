#include <string.h>

#include "SPCom.h"
#include "serial.h"
#include "Packet.h"

SPCom::SPCom(unsigned int baudrate)
{
	//ctor
	tracker= 0;
	memset(this->buffer, '\0', sizeof(this->buffer));
	Serial1.begin(baudrate);
	Serial2.begin(baudrate);
}

SPCom::~SPCom()
{

}

bool SPCom::peek()
{
	int start, end;
	write_buffer();

	for(int i=0; i < sizeof(this->buffer); i++){
		if((start = find_beginner()) != -1
				&& (end=find_ender()) != -1
				&& end > start)
			return true;
	}

	return false;
}

Packet *SPCom::read_packet()
{
	Packet *packet;
	int start, end, psize;

	if((start=find_beginner) == -1)
		return NULL;

	if((end=find_ender()) == -1)
		return NULL;

	//end less start less the 3 from the beginner
	//less 3 from the ender less 1 from the flags byte
	psize= end - start - 3 - 3 - 1;

	packet= new Packet(&buffer[start + 4], psize);

	packet->set_flags(buffer[start+3]);


	return packet;
}

int SPCom::find_beginner(void)
{
	for(int i=0; i < sizeof(buffer); i++){
		if(this->buffer[i] == '%'
						&& i+2 < sizeof(buffer)
						&& buffer[i+1] == '~'
						&& buffer[i+2] == '%')
			return i;
	}

	return -1;
}

int SPCom::find_ender(void)
{
	for(int i=0; i < sizeof(buffer); i++){
		if(this->buffer[i] == '~'
						&& i+2 < sizeof(buffer)
						&& buffer[i+1] == '%'
						&& buffer[i+2] == '~')
			return i;
	}

	return -1;
}

void SPCom::write_buffer()
{
	while(Serial.available() && tracker < sizeof(buffer)){
		buffer[tracker]= Serial.read();
		tracker++;
	}

	return;
}


