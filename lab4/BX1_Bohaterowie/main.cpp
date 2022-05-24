#include <iostream>
#include <time.h>
#include <Postac.h>
#include <Wojownik.h>

#include <Bron.h>

using namespace std;





int main()
{
    srand(time(NULL));
    cout << "BX1_Bohaterowie!" << endl;

    Postac* test1 = new Postac();

    test1->ustawNazwe("Piotrek");

    test1->przedstawSie();

    cout << "Bohaterowie przedmioty!" << endl;

    Przedmiot* p1 = new Przedmiot("lina");
    Przedmiot* p2 = new Przedmiot("klejnot");
    Przedmiot* p3 = new Przedmiot("mikstura");

    Przedmiot* b1 = new Bron("miecz", 10, 15);
    Przedmiot* b2 = new Bron("katana", 12, 17);
    Przedmiot* b3 = new Bron("laska", 5, 7);

    p1->dajDzwiekBezVirtual();
    b1->dajDzwiekBezVirtual();

    p1->dajDzwiekZVirtual();
    b1->dajDzwiekZVirtual();

    ((Bron*)b1)->dajDzwiekBezVirtual();
    ((Bron*)b1)->dajDzwiekZVirtual();

    vector<Przedmiot*> skrzynia;

    skrzynia.push_back(p1);
    skrzynia.push_back(p2);
    skrzynia.push_back(p3);
    skrzynia.push_back(b1);
    skrzynia.push_back(b2);
    skrzynia.push_back(b3);

    for(int i = 0; i< skrzynia.size(); i = i+1 ){

        cout << "element: " << skrzynia[i]->nazwa << endl;
        if(skrzynia[i]->typ == bron){
            Bron* b = (Bron*)skrzynia[i];
            cout << "min: " << b->atakMin << endl;
            cout << "max: " << b->atakMax << endl;
        }
        //to use dynamic_cast<Bron*>(rekaPrawa)) add-make A polymorphic, which you can do by adding a virtual destructor or any virtual function:
        if (auto* derived = dynamic_cast<Bron*>(skrzynia[i])){
            cout << "min: " << derived->atakMin << endl;
            cout << "max: " << derived->atakMax << endl;
        }

    }

     Postac* postac1 = new Postac("Jaskier", 100, 3, 1, 2);
//    postac1->ustawNazwe("Janusz");
//    postac1->pktAtakuMin = 1;
//    postac1->pktAtakuMax = 2;

    //Postac* wojownik1 = new Wojownik("Gerald", 125, 5, 5, 15);

    Postac* wojownik1 = Postac::generujPostac();
    //wojownik1 = wojownik1->generujPostac();

//    postac1->plecak.push_back(p1);
//    postac1->plecak.push_back(p2);
//    postac1->plecak.push_back(b1);
//    postac1->plecak.push_back(b2);
    postac1->dodajDoPlecaka(p1);
    postac1->dodajDoPlecaka(p2);
    postac1->dodajDoPlecaka(b1);
    postac1->dodajDoPlecaka(b2);


    //postac1->rekaPrawa = b2;
    postac1->ustawBron(b2, true);
    //postac1->rekaLewa = b1;
    postac1->ustawBron(b1, false);


    postac1->wyswietlOpisPostacZPrzedmiotami();


    postac1->obliczPktAtaku();


    postac1->przywitajSie();
    postac1->przedstawSie();

    wojownik1->przywitajSie();
    wojownik1->przedstawSie();

    //wojownik1->rekaPrawa = b2;
    //wojownik1->ustawBron(b2, true);
    //wojownik1->ustawBron(b3, false);

    wojownik1->wyswietlOpisPostacZPrzedmiotami();

     postac1->zaprosDoWalki(wojownik1);

    while( postac1->czyZyje() && wojownik1->czyZyje() )
    {

        int los = rand() % 2;
        if(los % 2 == 0){
            postac1->zaatakuj(wojownik1);
        }
        else
        {
            wojownik1->zaatakuj(postac1);
        }


    }

    cout << postac1->pobierzNazwe() << " - " << postac1->czyZyje() << endl;
    cout << wojownik1->pobierzNazwe() << " - " << wojownik1->czyZyje() << endl;


    return 0;
}
