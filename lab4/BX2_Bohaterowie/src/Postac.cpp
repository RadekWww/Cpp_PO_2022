///////////////////////////////////////////////////////////
//  Postac.cpp
//  Implementation of the Class Postac
//  Created on:      09-cze-2022 17:25:20
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Postac.h"
#include "Bron.h"
#include "Wojownik.h"

Postac::Postac()
{

}



Postac::~Postac()
{

}





Postac::Postac(string nazwa, int z, int p, int amin, int amax)
{

    this->nazwa = nazwa;
    pktZycia = z;
    poziom = p;
    pktAtakuMin = amin;
    pktAtakuMax = amax;
    rekaPrawa = NULL;
    rekaLewa = NULL;
}


bool Postac::czyZyje()
{

    if(pktZycia > 0)
    {
        return true;
    }
    else return false;
}


void Postac::dodajDoPlecaka(Przedmiot* p)
{
    if( plecak.size() < 3)
    {
        cout << "dodano do plecaka " << p->nazwa << endl;
        //this->plecak.push_back(p);
        plecak.push_back(p);
    }
    else cout << "brak miejsca w plecaku " << endl;
}

void Postac::ustawBron(Przedmiot* p, bool CzyPrawaReka)
{
    if(CzyPrawaReka == true)
    {
        rekaPrawa = p;
    }
    else
    {
        rekaLewa = p;
    }

}


int Postac::generujPktAtaku()
{

    //int x= pktAtakuMax;
    //int x= pktAtakuMin;
    /* generate secret number between:
    v1 = rand() % 100;         // v1 in the range 0 to 99
    v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
    v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 */

    int x = (rand() % pktAtakuMax - pktAtakuMin) + pktAtakuMin;

    cout << "wylosowano " << x << " pkt Ataku !";
    return x;
}


string Postac::generujPrzywitanie()
{

    string tablica[] = { "Dzien dobry", "Witaj", "Ahoj", "Czesc", "Grrr"};

    int rozmiarTablicy = sizeof(tablica)/sizeof(string);

    int liczbaLosowa = rand() % rozmiarTablicy;

    return tablica[liczbaLosowa];
}


int Postac::obliczPktAtaku()
{
    int x = 0;

    if(rekaLewa != NULL)
    {
        if(rekaLewa->typ == 1)
        {
            Bron* b = (Bron*)rekaLewa;
            //losownie pomiedzy min a max
            x += b->atakMax;
        }
    }
    if(rekaPrawa != NULL)
    {
        if(rekaPrawa->typ == 1)
        {
            Bron* b = (Bron*)rekaPrawa;
            //losownie pomiedzy min a max
            x += b->atakMax;
        }
    }

    if(x == 0)
    {
        x = this->pktAtakuMax;
    }

    cout << "wygenerowano " << x << " pkt ataku" << endl;

    return x;

}


string Postac::pobierzNazwe()
{
    return nazwa;
}


void Postac::pokazStatystyki()
{
    cout << "STATS: nazwa: " << nazwa<< " pktZycia: " << pktZycia<< " poziom: " <<poziom<< " pktAtakuMin: " <<pktAtakuMin<< " pktAtakuMax: " <<pktAtakuMax<< endl;

}


void Postac::przedstawSie()
{
    cout << "Jestem " << nazwa << endl;
}

void Postac::przywitajSie()
{
    string przuywitanko = generujPrzywitanie();
    cout << przuywitanko << endl;
}

void Postac::ustawNazwe(string n)
{
    this->nazwa = n;
}


void Postac::wyswietlOpisPostacZPrzedmiotami()
{
    cout << "################# " << endl;
    cout << "nazwa " << nazwa << endl;
    cout << "pktAtakuMin:" << pktAtakuMin << endl;
    cout << "pktAtakuMax:" << pktAtakuMax << endl;
    if(rekaPrawa != NULL)
    {
        cout << "rekaPrawa:" << rekaPrawa->nazwa << endl;
    }
    else
    {
        cout << "rekaPrawa: brak przedmiotu" << endl;
    }
    if(rekaLewa != NULL)
    {
        cout << "rekaLewa:" << rekaLewa->nazwa << endl;
    }
    else
    {
        cout << "rekaLewa: brak przedmiotu" << endl;
    }

    for(int i = 0; i< plecak.size(); i = i+1 )
    {

        cout << "Plecak: " << plecak[i]->nazwa << endl;
        if(plecak[i]->typ == 1)
        {
            Bron* b = (Bron*)plecak[i];
            cout << "min: " << b->atakMin << endl;
            cout << "max: " << b->atakMax << endl;
        }
    }
    cout << "atak: " << obliczPktAtaku() <<endl;
}


void Postac::zaatakuj(Postac* przeciwnik)
{
    int los = rand() % 100 +1;

    if(los > 20)
    {
        cout << this->pobierzNazwe() << " TRAFIL " << przeciwnik->pobierzNazwe() <<endl;

        int silaAtaku = this->obliczPktAtaku();
        przeciwnik->pktZycia -= silaAtaku;
        //przeciwnik->przyjmijUderzenie(silaAtaku);
        //przeciwnik->przujmijUderzenie(generujPktAtaku());
        przeciwnik->pokazStatystyki();
    }
    else
    {
        cout << this->pobierzNazwe() << " SPUDLOWAL " <<endl;
    }
}


void Postac::zaprosDoWalki(Postac* przeciwnik)
{
    cout << "Zapraszam do Walki, Ciebie " << przeciwnik->pobierzNazwe() << endl;;
}


Postac* Postac::generujPostac()
{

    cout << "@@@@@@@@@@@@ GenerowaniePostaci " << endl;


    int poziomZyciaMin =50;
    int poziomZyciaMax =200;
    int poziomZycia = (rand() % (poziomZyciaMax - poziomZyciaMin)) + poziomZyciaMin;


    int czyPostacCzyWojownik = rand() % 2;

    Postac* postac = NULL;
    if(czyPostacCzyWojownik == 0)
    {
        cout << "wygenrowano Wojownika: " << poziomZycia << endl;
        postac = new Wojownik("WojownikX", poziomZycia, 10, 3, 5);
    }
    else
    {
        cout << "wygenrowano Postac " << poziomZycia << endl;
        postac = new Postac("PostacX", poziomZycia, 10, 1, 2);
    }

    int czyMaMiecBron = rand() % 3;

    if(czyMaMiecBron >= 1)
    {
        cout << "wygenrowano MieczX" << endl;
        int poziomMin =5;
        int poziomMax =15;
        //int poziom = (rand() % (poziomMax - poziomMin)) + poziomMin;
        Przedmiot* b1 = new Bron("mieczX", poziomMin, poziomMax);
        postac->ustawBron(b1, true);
    }
    if(czyMaMiecBron == 2)
    {
        cout << "wygenrowano palkaX" << endl;
        int poziomMin =4;
        int poziomMax =8;
        //int poziom = (rand() % (poziomMax - poziomMin)) + poziomMin;
        Przedmiot* b1 = new Bron("palkaX", poziomMin, poziomMax);
        postac->ustawBron(b1, false);
    }
    cout << "@@@@@@@@@@@@ Koniec GenerowaniePostaci " << endl;

    return postac;
}
