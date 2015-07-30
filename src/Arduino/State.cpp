#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "State.h"

#define FIRST_CHAR 222
#define SECOND_CHAR 230
#define THIRD_CHAR 222

using namespace std;


//iniciador do state
State::State()
{
    tracker = 0;
    memset(this->buffer, '\0', sizeof(this->buffer));
    robot = new Robot(coxainit, femurinit, femurinit);
}

State::~State()
{

}

//apaga o buffer
void State::reset()
{
    tracker = 0;
    memset(this->buffer, '\0', sizeof(this->buffer));
}


/*
Escreve no buffer todo o conteudo do buffer do arduino
*/
void State::writebuffer()
{
    while(Serial.available())
    {
        buffer[tracker] = Serial.read();
        tracker++;
        Serial.println("22222222222222"); //impressao desta linha por cada serial.read efectuado
    }
}

/*
Verifica se estamos na presença do iniciador de pacote
*/
bool State::findbeginner()
{
    if(buffer[0] == FIRST_CHAR && buffer[1] == SECOND_CHAR && buffer[2] == THIRD_CHAR){
        teste = "OK";
        return true;
    }
    else{
        Serial.println("zzzzzzzzzz");
        return false;
    }
}

/*
Guarda o header na variavel flags, caso tenha encontrado o iniciador de pacote.
*/
bool State::header()
{
    bool ready = false;
    if(findbeginner())
    {
        flags = buffer[3];
        ready = true;
    }
    return ready;
}

/*
Baseado no header, verifica se estamos na presenca de um pacote valido.
Se estivermos, podemos comecar a interpretar o header.
*/
void State::decryptheader()
{
    if(header())
    {
        Serial.println(teste);
        int nlegs = 0;
        int i = 0;
        while(i<6)
        {
            if(is_flag_set(i))
            {
                legs[i] = i+1;
                nlegs++;
            }
            i++;
        }
        Serial.println(tracker);
        Serial.println(4 + nlegs * 3);
        if(tracker == 4 + nlegs * 3){
            Serial.println("PASSOU NO TESTE");

        }
        else{
            Serial.println("FALHOU NO TESTE");
        }
    }
}

bool State::is_flag_set(uint8_t index)
{
    return (this->flags & (1 << index)) != 0;
}

void State::getangles()
{

}

/*
int* Packet::readangles()
{
    int i = 0;
    int flags = decryptheader();

    while(i < flags)
    {
        angles = malloc(flags*3*sizeof(int));

    }
}

void Packet::decrypt()
{
    int i = 3;
    int j = 5;
    char* temp = (char*)data;
    while(i < 9)
    {
        if(is_flag_set(i))
        {
            //angulos da leg
            *angles = temp[j];
            angles++;
            *angles = temp[j+1];
            angles++;
            *angles = temp[j+2];
            angles++;

            //leg 
            *legs = 8 - i;
        }
        i++;
        j = j + 3;
    }
}

void *Packet::getLegs(void)
{
    return legs;
}

void *Packet::getAngles(void)
{
    return angles;
}
    
uint8_t Packet::get_size(void)
{
    return this->size;
}

void Packet::set_size(uint8_t size)
{
    this->size= size;
}

/*bool Packet::set_flag(uint8_t index)
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
}*/

