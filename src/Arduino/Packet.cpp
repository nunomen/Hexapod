#include <string.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "Packet.h"

using namespace std;

Packet::Packet()
{
    this->data= NULL;
    this->flags= '\0';
    this->size= 0;
}

Packet::Packet(void *data, uint8_t dataSize)
{
    this->data= malloc(dataSize);
    memcpy(this->data, data, dataSize);

    this->flags= 0;
    this->size= dataSize;
}

Packet::~Packet()
{
    free(this->data);
}

uint8_t Packet::get_size(void)
{
    return this->size;
}

void Packet::set_size(uint8_t size)
{
    this->size= size;
}

bool Packet::set_flag(uint8_t index)
{
    //flag must be between 0 and 7
    if(index < 0 || index > 7)
    {
        cout << "a" << endl;
        return false;
    }

    //if flag is already set proceed
    if(is_flag_set(index)){
        cout << "a" << endl;
        return true;
    }
    else{
    //if flag is not set, set it
        cout << "c" << endl;
        this->flags+= pow(2, index);
        return true;
    }
}

bool Packet::reset_flag(uint8_t index)
{
    //flag must be between 0 and 7
    if(index < 0 || index > 7)
        return false;

    //if flag is already reset proceed
    if(!is_flag_set(index))
        return true;
    else{
    //if flag is not reset, reset it
        this->flags-= pow(2,index);
        return true;
    }
}

bool Packet::is_flag_set(uint8_t index)
{
    return (this->flags & (1 << index)) != 0;
}

uint8_t Packet::get_flags(void)
{
    return this->flags;
}


void *Packet::get_data(void)
{
    void *data;

    data= malloc(this->size);
    memcpy(data, this->data, this->size);

    return data;
}

