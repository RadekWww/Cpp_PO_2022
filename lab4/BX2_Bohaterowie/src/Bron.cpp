///////////////////////////////////////////////////////////
//  Bron.cpp
//  Implementation of the Class Bron
//  Created on:      09-cze-2022 17:25:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Bron.h"


Bron::Bron(){

}



Bron::~Bron(){

}





Bron::Bron(string nazwa, int atak1, int atak2) : Przedmiot(nazwa){
        //this->nazwa = nazwa;
        typ = 1;
        //typ = bron;
        atakMin = atak1;
        atakMax = atak2;
        cout << "konstruktor Bron: " << this->nazwa<< endl;
}


void Bron::dajDzwiekBezVirtual(){
    cout << nazwa << " Bron robi pif paf BezVirtual" << endl;
}


void Bron::dajDzwiekZVirtual(){
     cout << nazwa << " Bron robi pif paf ZVirtual" << endl;
}
