#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;


class Postac
{

public:

    Postac(string nazwa, int z, int p, int amin, int amax){
        this->nazwa = nazwa;
        pktZycia = z;
        poziom = p;
        pktAtakuMin = amin;
        pktAtakuMax = amax;
    }


    void przywitajSie()
    {
        string przuywitanko = generujPrzywitanie();
        cout << przuywitanko << endl;
    }

    void przedstawSie()
    {

        cout << "Jestem " << nazwa << endl;
    }

    void zaprosDoWalki(Postac* obiekPostaci)
    {

        cout << "Zapraszam do Walki, Ciebie " << obiekPostaci->pobierzNazwe() << endl;;
    }

    void ustawNazwe(string nowaNazwa){
        nazwa = nowaNazwa;
    }
    string pobierzNazwe()
    {
        return nazwa;
    }

    void pokazStatystyki()
    {
        cout << "STATS: nazwa: " << nazwa<< " pktZycia: " << pktZycia<< " poziom: " <<poziom<< " pktAtakuMin: " <<pktAtakuMin<< " pktAtakuMax: " <<pktAtakuMax<< endl;
    }


    void zaatakuj(Postac* przeciwnik)
    {

        int los = rand() % 100 +1;

        if(los > 20)
        {
            cout << this->pobierzNazwe() << " TRAFIL " << przeciwnik->pobierzNazwe() <<endl;
            przeciwnik->przujmijUderzenie(generujPktAtaku());
            przeciwnik->pokazStatystyki();
        }
        else
        {
             cout << this->pobierzNazwe() << " SPUDLOWAL " <<endl;
        }


    }

    bool czyZyje()
    {
        if(pktZycia > 0)
        {
            return true;
        }
        else return false;
    }

protected:
    string nazwa;
    int pktZycia;
    int poziom;
    int pktAtakuMin;
    int pktAtakuMax;

    void przujmijUderzenie(int silaUderzenia){
        this->pktZycia -= silaUderzenia;
    }

    int generujPktAtaku()
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


private:

    string generujPrzywitanie(){
        string tablica[] = { "Dzien dobry", "Witaj", "Ahoj", "Czesc", "Grrr"};

        int rozmiarTablicy = sizeof(tablica)/sizeof(string);

        int liczbaLosowa = rand() % rozmiarTablicy;

        return tablica[liczbaLosowa];
    }


};

class Wojownik : public Postac
{

public:
    Wojownik(string nazwa, int z, int p, int amin, int amax) : Postac(nazwa, z, p, amin, amax)
    {

    }
protected:
private:

};


int main()
{
    srand(time(NULL));

    cout << "Bohaterowie - opowiadanie - gra - walka!" << endl;


    Postac* postac1 = new Postac("Jaskier", 100, 3, 10, 12);
    //postac1->ustawNazwe("Jaskier");

    Postac* wojownik1 = new Wojownik("Gerald", 125, 5, 5, 15);
    //wojownik1->ustawNazwe("Gerald");

    Postac* postac2 = new Postac("Golem", 1000, 3, 1, 2);

    Postac* wojownik2 = new Wojownik("Triss", 50, 1, 5, 25);


    Postac* tablica[] = { postac1, postac2, wojownik1, wojownik2};

    int rozmiarTablicy = sizeof(tablica) / sizeof(Postac*);

    int i = rand() % rozmiarTablicy;
    int j = rand() % rozmiarTablicy;


    tablica[i]->przywitajSie();
     tablica[i]->przedstawSie();

    tablica[j]->przywitajSie();
    tablica[j]->przedstawSie();

     tablica[i]->zaprosDoWalki(tablica[j]);

    while(  tablica[i]->czyZyje() && tablica[j]->czyZyje() )
    {

        int los = rand() % 2;
        if(los % 2 == 0){
             tablica[i]->zaatakuj(tablica[j]);
        }
        else
        {
            tablica[j]->zaatakuj( tablica[i]);
        }
        this_thread::sleep_for(chrono::milliseconds(500) );

    }

    cout <<  tablica[i]->pobierzNazwe() << " - " <<  tablica[i]->czyZyje() << endl;
    cout << tablica[j]->pobierzNazwe() << " - " << tablica[j]->czyZyje() << endl;

//    postac1->przywitajSie();
//    postac1->przedstawSie();
//
//    wojownik1->przywitajSie();
//    wojownik1->przedstawSie();
//
//    postac1->zaprosDoWalki(wojownik1);
//
//    while( postac1->czyZyje() && wojownik1->czyZyje() )
//    {
//
//        int los = rand() % 2;
//        if(los % 2 == 0){
//            postac1->zaatakuj(wojownik1);
//        }
//        else
//        {
//            wojownik1->zaatakuj(postac1);
//        }
//
//
//    }
//
//    cout << postac1->pobierzNazwe() << " - " << postac1->czyZyje() << endl;
//    cout << wojownik1->pobierzNazwe() << " - " << wojownik1->czyZyje() << endl;







    return 0;
}
