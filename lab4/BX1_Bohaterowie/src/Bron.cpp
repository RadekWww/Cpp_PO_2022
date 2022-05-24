///////////////////////////////////////////////////////////
//  Bron.cpp
//  Implementation of the Class Bron
//  Created on:      24-maj-2022 16:52:54
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Bron.h"

#include <rodzajPrzedmiotu.h>

Bron::Bron(){

}



Bron::~Bron(){

}





Bron::Bron(string nazwa, int atak1, int atak2) : Przedmiot(nazwa){
    //this->nazwa = nazwa;
        //typ = 1;
        typ = bron;
        atakMin = atak1;
        atakMax = atak2;
        cout << "konstruktor Bron" << endl;
}


void Bron::dajDzwiekBezVirtual(){
    cout << "Bron robi pif paf BezVirtual" << endl;
}

void Bron::dajDzwiekZVirtual(){
    cout << "Bron robi pif paf ZVirtual" << endl;
}
