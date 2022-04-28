#include "Czlowiek.h"

//#include <iostream>
using namespace std;

//Czlowiek::Czlowiek(std::string nazwa)
Czlowiek::Czlowiek(string nazwa)
{
    imie = nazwa;
    wiek = 1;
    //ctor
}

////konstruktor z listš inline inicjalziator z listy
//Czlowiek::Czlowiek(std::string nazwa, int liczbaLat) : imie(nazwa), wiek(liczbaLat)
//{
//    imie = "X" + imie + "X"; //przecišzenie tej wartosci
//}

Czlowiek::Czlowiek(string nazwa, int wiek)
{
    this->imie = nazwa;
    this->wiek = wiek;
    //(*this).wiek = wiek + 1;
    //ctor
}


void Czlowiek::przedstawSie()
{
    std::cout << "Jestem " << imie << " mam lat " << wiek << std::endl;
}

Czlowiek* Czlowiek::utworzIZwrocNowyObiekt(){

    Czlowiek* wskaznik = new Czlowiek("DynamicznyCzlowiek");
    return wskaznik;
}
