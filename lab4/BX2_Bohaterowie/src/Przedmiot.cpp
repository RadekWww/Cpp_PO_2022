///////////////////////////////////////////////////////////
//  Przedmiot.cpp
//  Implementation of the Class Przedmiot
//  Created on:      09-cze-2022 17:25:23
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Przedmiot.h"


Przedmiot::Przedmiot(){

}



Przedmiot::~Przedmiot(){

}





Przedmiot::Przedmiot(string nazwa){
    this->nazwa = nazwa;
    this->typ = 0;
    cout << "konstruktor przedmiotu: " << nazwa << endl;
}


void Przedmiot::dajDzwiekBezVirtual(){
    cout << nazwa << " Przedmiot robi brzdek BezVirtual" << endl;
}


void  Przedmiot::dajDzwiekZVirtual(){
    cout << nazwa << " Przedmiot robi brzdek ZVirtual" << endl;
}
