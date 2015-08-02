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
    
}

State::~State()
{

}

//apaga o buffer
void State::reset()
{
    tracker = 0;
    memset(this->buffer, '\0', sizeof(this->buffer));
    memset(this->legs, '\0', sizeof(this->legs));
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
        Serial.println("LI UM BYTE!"); //impressao desta linha por cada serial.read efectuado
    }
}

/*
Verifica se estamos na presença do iniciador de pacote
*/

bool State::findbeginner()
{
    if(buffer[0] == FIRST_CHAR && buffer[1] == SECOND_CHAR && buffer[2] == THIRD_CHAR){
        return true;
    }
    else{
        Serial.println("No byte available...");
        return false;
    }
}

/*
Guarda o header na variavel flags, caso tenha encontrado o iniciador de pacote.
*/

bool State::header()
{
    
    if(findbeginner())
    {
        flags = buffer[3];
        return true;
    }
    else
        return false;
}

/*
Baseado no header, verifica se estamos na presenca de um pacote valido.
Se estivermos, podemos comecar a interpretar o header.
*/
void State::decryptheader()
{
    bool decrypt = header();

    if(decrypt)
    {
        Serial.println("*** Decryptheader called ***");

        Serial.println("BEGINNER FOUND");
        int nlegs = 0;
        int i = 0;

        while(i<6)
        {
            if(is_flag_set(i))
            {
                legs[i] = 1;
                nlegs++;
            }
            i++;
        }

        Serial.print("TRACKER = ");
        Serial.println(tracker);
        Serial.print("TOTAL BYTE COUNT = ");
        Serial.println(4 + nlegs * 3);

        if(tracker == 4 + nlegs * 3){
            Serial.println("PASSOU NO TESTE");

        }
        else{
            Serial.println("FALHOU NO TESTE");
        }

        Serial.println("*** Decryptheader end ***");
    }
}

bool State::is_flag_set(uint8_t index)
{
    return (this->flags & (1 << index)) != 0;
}


int State::getlegs(int i)
{
    return legs[i];
}

int State::getangles(int i)
{
    if(i>3 && i<=tracker)
    return buffer[i];
}


//*** TESTE COM LEDS***///

void State::ON(){
    
for(int i=0;i<6;i++){
    if(legs[i]==1){
        Serial.println(i+1);
        digitalWrite(12-i,HIGH);
    }
    }

}

void State::OFF(){
    
for(int i=0;i<6;i++){
    if(legs[i]==1){
        Serial.println(i+1);
        digitalWrite(12-i,LOW);
    }
    }

}

