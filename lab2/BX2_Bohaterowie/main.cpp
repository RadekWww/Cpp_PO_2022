#include <iostream>
//#include <ctime>
#include <time.h>
#include <chrono>
#include <thread>


using namespace std;

class Postac{

public:

    Postac(string nazwa, int zycie, int mana, int poziom, int pktAtakuMin, int pktAtakuMax)
    {
        this->nazwa = nazwa;
        pktZycia = zycie;
        pktMany = mana;
        this->poziom= poziom;
        this->pktAtakuMin = pktAtakuMin;
        this->pktAtakuMax = pktAtakuMax;
    }

    void zaatakuj(Postac* przeciwnik)
    {
        if(pktMany > 0)
        {
            int los = rand() % 100 +1;
            if( los > 80 )
            {
                pktMany -= 10;
                atakZaawansowany(przeciwnik);
                cout << "Ale mo¿e uzyc podwojnego Ataku" << endl;
                atakPodstawowy(przeciwnik);
                atakPodstawowy(przeciwnik);
            }
            else{
                atakPodstawowy(przeciwnik);
            }
        }
        else atakPodstawowy(przeciwnik);
    }

    void atakPodstawowy(Postac* przeciwnik){
        cout << this->nazwa << " Uzywa ataku podstawowego!" << endl;
        sumaAtak++;
        if(czyTrafiono(przeciwnik)){
            cout << this->nazwa << " TRAFIL " << przeciwnik->nazwa << endl;
            przeciwnik->pktZycia -= this->wylosujSileAtaku();
            przeciwnik->pokazStatystyki();

            sumaCelnyAtak +=1;
        }
        else cout << "PUDLO" << endl;



    }

    int wylosujSileAtaku()
    {
        int sila = rand() % pktAtakuMax + pktAtakuMin;
        return sila;
    }

    void przyjmijUderzenie(int silaAtaku){
        this->pktZycia -= silaAtaku;
    }

    virtual void atakZaawansowany(Postac* przeciwnik){
         cout << this->nazwa << " Nie ma ataku zaawansowanego!" << endl;
    }

    void przywitajSie(string imieKogos){
        string przywitanie = generujPrzywitanie();
        cout << this->nazwa << ": " << przywitanie << " " << imieKogos << endl;

    }


    void zaprosDoWalki(){
        cout << this->nazwa << ": Zapraszam do walki ...." << endl;

    }

    string przedstawSie(){
        cout <<  this->nazwa << ":" << generujJestem() << nazwa << endl;
        return nazwa;
    }

    string wezImie(){
        return nazwa;
    }

    void pokazStatystyki(){
        cout << "STATS: nazwa: " << nazwa<< " pktZycia: " << pktZycia<< " pktMany: " <<pktMany<< " poziom: " <<poziom<< " pktAtakuMin: " <<pktAtakuMin<< " pktAtakuMax: " <<pktAtakuMax<< " Atak: "<<(float)sumaCelnyAtak/sumaAtak<< endl;
    }

    bool czyZyje()
    {
        bool wynik = pktZycia > 0;
        return wynik;
    }


protected:
    string nazwa;
    int pktZycia;
    int pktMany;
    int poziom;

    int pktAtakuMin;
    int pktAtakuMax;
    int sumaCelnyAtak =0;
    int sumaAtak =0;

    bool czyTrafiono(Postac* przeciwnik){
        int losowanie = rand() % 100 + 1;
        if(this->poziom > przeciwnik->poziom && losowanie > 20)
        {
            return true;
        }

        if(this->poziom = przeciwnik->poziom)
        {
            if(losowanie > 50) return true;
            return false;
        }
        if(this->poziom < przeciwnik->poziom)
        {
            if(losowanie > 70) return true;
            return false;
        }
    }

private:

    string generujPrzywitanie(){
        string tablica[] = { "Dzien dobry", "Witaj", "Ahoj", "Czesc", "Grrr"};
        /* generate secret number between 1 and 10:
        v1 = rand() % 100;         // v1 in the range 0 to 99
        v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
        v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 */
        //int rozmiarTablicy = sizeof(tablica)/sizeof(string);
        int rozmiarTablicy = 5;
        int liczbaLosowa = rand() % rozmiarTablicy;
        cout<< "#wylosowano:" << liczbaLosowa <<endl;
        return tablica[liczbaLosowa];
    }

    string generujJestem(){
        string tablica[] = { "Jestem ", "Mam na imie ", "Jam jest ", "Zwa mnie "};
        //int rozmiarTablicy = sizeof(tablica)/sizeof(string);
        int rozmiarTablicy = 4;
        int los = rand() % rozmiarTablicy;
        cout<< "#wylosowano:" << los <<endl;
        return tablica[los];
    }
};





class Wojownik : public Postac
{
public:

    Wojownik(string nazwa, int zycie, int mana, int poziom, int pktAtakuMin, int pktAtakuMax) : Postac( nazwa,  zycie,  mana, poziom,  pktAtakuMin,  pktAtakuMax)
    {
    }

    void zaatakuj(Postac* przeciwnik)
    {
        if(pktMany > 0)
        {
            int los = rand() % 100 +1;
            pktMany -= 10;
            if( los > 80 )
            {
                atakZaawansowany(przeciwnik);
            }
            else{
                atakPodstawowy(przeciwnik);
            }
        }
        else
        {

            atakPodstawowy(przeciwnik);
        }
    }

    void atakZaawansowany(Postac* przeciwnik){
        cout << this->nazwa << " Uzywa ataku zaawansowanego!" << endl;
        sumaAtak++;
        if(czyTrafiono(przeciwnik)){
            cout << this->wezImie() << " TRAFIL " << przeciwnik->wezImie() << endl;
            int silaAtaku = rand() % 4 +1;
            przeciwnik->przyjmijUderzenie(this->wylosujSileAtaku() * silaAtaku);
            przeciwnik->pokazStatystyki();

            sumaCelnyAtak +=1;
        }
        else cout << "PUDLO" << endl;cout << this->nazwa << " Nie ma ataku zaawansowanego!" << endl;
    }


};




int main()
{
     /* initialize random seed: */
    //srand(time(nullptr));
    srand(time(NULL));
    cout << "Gra - Opowiadanie" << endl << endl;


    Postac* p1 = new Postac("Diabolo", 220, 20, 3, 10,13);
    Postac* p2 = new Wojownik("Natanek", 200, 40, 4, 6, 15);
    Wojownik* p3 = new Wojownik("Artur", 200, 40, 4, 6, 15);

    cout << "Narrator: postac wchodzi do pomieszczenia" << endl;
    p1->przywitajSie("");
    string imiePostaciNr1 = p1->przedstawSie();
    cout << "Narrator: druga postac odzwya sie" << endl;

    p2->przywitajSie(imiePostaciNr1);
    p2->przedstawSie();

    p1->zaprosDoWalki();

    int i = 0;
    while( i< 10)
    {

        p1->zaatakuj(p2);

        p2->zaatakuj(p1);

         p2->zaatakuj(p3);

        this_thread::sleep_for(chrono::milliseconds(500) );


        i++;
    }



//    Postac* p1 = new Postac("Jaskier", 220, 20, 3, 10,13);
//    Postac* p2 = new Wojownik("Radek", 200, 40, 4, 6, 15);
//
//    p1->przywitajSie("");
//    string gosc = p1->przedstawSie();
//
//    p2->przywitajSie(gosc);
//    p2->przedstawSie();
//
//    p1->zaprosDoWalki();
//
//    while(p1->czyZyje() && p2->czyZyje())
//    {
//        int los = rand() %2;
//        if(los % 2 == 0){
//            p1->zaatakuj(p2);
//        }
//        else{
//            p2->zaatakuj(p1);
//        }
//        //this_thread::sleep_for(chrono::milliseconds(500) );
//        //this_thread::sleep_for(chrono::milliseconds(500) );
//    }
//
//    cout << p1->wezImie() << " - " << p1->czyZyje() << endl;
//    cout << p2->wezImie() << " - " << p2->czyZyje() << endl;

//    Postac* p1 = new Postac("Jaskier", 220, 20, 3, 10,13);
//    Postac* p2 = new Wojownik("Radek", 200, 40, 4, 6, 15);
//    Postac* p3 = new Wojownik("Tornado", 200, 40, 4, 1, 20);
//    Postac* p4 = new Postac("Tajfun", 220, 40, 4, 12, 12);
//
//    Postac* tablica[] = {p1, p2, p3, p4};
//    int rozmiarTablicy = sizeof(tablica)/sizeof(Postac*);
//
//    int i = rand() % rozmiarTablicy;
//    int j = rand() % rozmiarTablicy;
//
//    tablica[i]->przywitajSie("");
//    string gosc = tablica[i]->przedstawSie();
//
//    tablica[j]->przywitajSie(gosc);
//    tablica[j]->przedstawSie();
//
//    tablica[i]->zaprosDoWalki();
//
//    while(tablica[i]->czyZyje() && tablica[j]->czyZyje())
//    {
//        int los = rand() %2;
//        if(los % 2 == 0){
//            tablica[i]->zaatakuj(tablica[j]);
//        }
//        else{
//            tablica[j]->zaatakuj(tablica[i]);
//        }
//        //this_thread::sleep_for(chrono::milliseconds(500) );
//        //this_thread::sleep_for(chrono::milliseconds(500) );
//    }
//
//    cout << tablica[i]->wezImie() << " - " << tablica[i]->czyZyje() << endl;
//    cout << tablica[j]->wezImie() << " - " << tablica[j]->czyZyje() << endl;





    return 0;
}
