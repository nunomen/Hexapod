#ifndef PMOTION_H
#define PMOTION_H

using namespace std;

class Packet {

private:

void *data; //data to transfer
unsigned int data_size;
unsigned char flag; 


public:

Packet();
Packet(void*,unsigned int);
~Packet();

};


#endif