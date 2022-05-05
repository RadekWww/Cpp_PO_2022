#include "Persona.h"

#include <iostream>
using namespace std;

Persona::Persona()
{
    cout<< "konstruktor Persony" << endl;
    //ctor
}


void Persona::przedstawSie(){
    cout << "Jestem " << imie << ", mam lat " << this->wiek  <<"\n";
}
