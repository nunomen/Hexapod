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

using namespace std;


//iniciador do state
State::State()
{
    tracker = 0;
    memset(this->buffer, '\0', sizeof(this->buffer));
    memset(this->legs, '\0', sizeof(this->legs));
    robot = new Robot(90,90,90);
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
Na interpretacao do header guarda as pernas que vao mexer em legs.
Devolve true se passar no teste de verificacao de pacote, false caso contrario.
*/
bool State::decryptheader()
{
    //nao criar variaveis quando nao sao necessarias
    if(header())
    {
        Serial.println("*** Decryptheader called ***");

        Serial.println("BEGINNER FOUND");
        int nlegs = 0;
        int i = 0;

        while(i < NUMBER_OF_LEGS)
        {
            if(is_flag_set(i))
            {
                legs[nlegs] = i+1;
                nlegs++;
            }
            i++;
        }

        Serial.print("TRACKER = ");
        Serial.println(tracker);
        Serial.print("TOTAL BYTE COUNT = ");
        Serial.println(INITIATOR_PLUS_HEADER + nlegs * NUMBER_OF_ANGLES_PER_LEG);

        if(tracker == INITIATOR_PLUS_HEADER + nlegs * NUMBER_OF_ANGLES_PER_LEG){
            Serial.println("PASSOU NO TESTE");
            Serial.println("*** Decryptheader end ***");
            return true;

        }
        else{
            Serial.println("FALHOU NO TESTE");
            Serial.println("*** Decryptheader end ***");
            return false;

        }
    }
}

/*
Metodo que, apos todas as verificacoes e baseado nas pernas que irao mexer, coloca os servos de cada pata nos angulos indicados
*/
void State::moveRobot(){
    if(decryptheader()){
        Serial.println("ENTREI NO IF");
        int i = 0;
        int j = 0;
        resetpins();
        while(legs[i] != '\0'){
            Serial.println(legs[i]);
            robot->moveLeg(legs[i],getangles(4+j), getangles(5+j), getangles(6+j));
            i++;
            j = j + 3;

        }
    }
}

void State::resetpins(){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW); 

    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);

    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);

    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);

    digitalWrite(A0,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);

    digitalWrite(A3,LOW);
    digitalWrite(A4,LOW);
    digitalWrite(A5,LOW);
}

/*
Descodifica cada bit do header, baseado no index dado
*/
bool State::is_flag_set(uint8_t index)
{
    return (this->flags & (1 << index)) != 0;
}

/*
Retorna o angulo existente no buffer
*/
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

