#include <iostream>
#include "Packet.h"

using namespace std;

int main()
{
    Packet *p1;
    int *revec;

    int vec[3];
    for(int i=0; i < 3; i++){
        vec[i]=i+2;
    }

    p1= new Packet(&vec, sizeof(vec));

    revec= (int*) p1->get_data();

    for(int i=0; i < 3; i++){
        cout << revec[i] << endl;
    }

    cout << "flag2 " << p1->is_flag_set(2) << endl;
    p1->set_flag(2);
    cout << "flag2 " << p1->is_flag_set(2) << endl;
    cout << "flags " << (int) p1->get_flags() << endl;
    p1->reset_flag(2);
    p1->reset_flag(2);
    cout << "flag2 " << p1->is_flag_set(2) << endl;


    cout << (int) p1->get_size() << endl;
    delete p1;
    cout << (int) p1->get_size() << endl;
}
