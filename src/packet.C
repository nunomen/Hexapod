#include <iostream>
#include "packet.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Constructors

Packet::Packet() //Default constructor

{

	data = NULL;
	data_size=0;
	flag='\0';

}

Packet::Packet(void *data, unsigned int data_size)

{	

	this->data= malloc(data_size);
	memcpy(this->data,data,data_size);

	this->data_size=data_size;


	//leitura de teste
	for(int i=0;i<5;i++){
	cout << ((double*) this->data) [i] << endl;
	
	}

}

Packet::~Packet()
{

	free(this->data);


}


