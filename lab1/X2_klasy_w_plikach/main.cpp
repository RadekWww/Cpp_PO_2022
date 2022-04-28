#include <iostream>

#include "Czlowiek.h"

using namespace std;

int main()
{
    cout << "Klasy w plikach" << endl;


    Czlowiek czlowiek("Janusz");
    czlowiek.przedstawSie();


    Czlowiek czlowiek2("Marek", 20);
    czlowiek2.przedstawSie();



    Czlowiek* czlowiek3 = new Czlowiek("RadekDynamiczny", 32);
    czlowiek3->przedstawSie();


    Czlowiek* czlowiek4 = Czlowiek::utworzIZwrocNowyObiekt();
    czlowiek4->przedstawSie();

    return 0;
}
