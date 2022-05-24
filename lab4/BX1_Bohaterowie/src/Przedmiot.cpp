///////////////////////////////////////////////////////////
//  Przedmiot.cpp
//  Implementation of the Class Przedmiot
//  Created on:      24-maj-2022 16:53:00
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Przedmiot.h"


Przedmiot::Przedmiot(){

}



Przedmiot::~Przedmiot(){

}





Przedmiot::Przedmiot(string nazwa){
    this->nazwa = nazwa;
}


void Przedmiot::dajDzwiekBezVirtual(){
    cout << "Przedmiot robi brzdek BezVirtual" << endl;
}

void Przedmiot::dajDzwiekZVirtual(){
    cout << "Przedmiot robi brzdek ZVirtual" << endl;
}

