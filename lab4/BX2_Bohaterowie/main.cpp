#include <iostream>
#include <time.h>
#include <Postac.h>
#include <Bron.h>
#include <Wojownik.h>

using namespace std;



int main()
{
    srand(time(NULL));

    cout << "BX2_Bohaterowie!" << endl;


    Postac* test1 = new Postac();

    test1->ustawNazwe("Piotrek");

    test1->przedstawSie();
    test1->pokazStatystyki();


    Postac* test2 = new Postac("Janek", 100, 5, 5,6);
    test2->przedstawSie();
    test2->pokazStatystyki();

    cout << "Bohaterowie przedmioty!" << endl;

    Przedmiot* p1 = new Przedmiot("lina");
    Przedmiot* p2 = new Przedmiot("klejnot");
    Przedmiot* p3 = new Przedmiot("mikstura");

    Przedmiot* b1 = new Bron("miecz", 10, 15);
    Przedmiot* b2 = new Bron("katana", 12, 17);
    Przedmiot* b3 = new Bron("laska", 5, 7);

    Bron* b4 = new Bron("toporek", 10, 11);

    p1->dajDzwiekBezVirtual();
    b1->dajDzwiekBezVirtual();

    p1->dajDzwiekZVirtual();
    b1->dajDzwiekZVirtual();

    ((Bron*)b1)->dajDzwiekBezVirtual();
    ((Bron*)b1)->dajDzwiekZVirtual();

    cout << "####################### Skrzynia\n";

    vector<Przedmiot*> skrzynia;

    skrzynia.push_back(p1);
    skrzynia.push_back(p2);
    skrzynia.push_back(p3);
    skrzynia.push_back(b1);
    skrzynia.push_back(b2);
    skrzynia.push_back(b3);
    skrzynia.push_back(b4);

    for( int i = 0; i < skrzynia.size(); i++)
    {
        cout << i << " ";
        cout << skrzynia[i]->nazwa << endl;

        if(skrzynia[i]->typ == 1){
            Bron* b = (Bron*)skrzynia[i];
            cout << "min: " << b->atakMin;
            cout << " max: " << b->atakMax << endl;
        }
        //to use dynamic_cast<Bron*>(rekaPrawa)) add-make A polymorphic, which you can do by adding a virtual destructor or any virtual function:
         if (auto* derived = dynamic_cast<Bron*>(skrzynia[i])){
            cout << "min: " << derived->atakMin;
            cout << "max: " << derived->atakMax << endl;
        }


    }

//    cout << skrzynia[0]->nazwa << endl;
//    cout << skrzynia[1]->nazwa << endl;
//    cout << skrzynia[2]->nazwa << endl;
//    cout << skrzynia[3]->nazwa << endl;

 cout << "####################### Postac\n";
     Postac* postac1 = new Postac("Jaskier", 100, 3, 1, 2);
    //    postac1->ustawNazwe("Janusz");
    //    postac1->pktAtakuMin = 1;
    //    postac1->pktAtakuMax = 2;






//    postac1->plecak.push_back(p1);
//    postac1->plecak.push_back(p2);
//    postac1->plecak.push_back(b1);
//    postac1->plecak.push_back(b2);


//    for( int i = 0; i < postac1->plecak.size(); i++)
//    {
//        cout << i << " ";
//        cout << postac1->plecak[i]->nazwa << endl;
//
//        if(postac1->plecak[i]->typ == 1){
//            Bron* b = (Bron*)postac1->plecak[i];
//            cout << "min: " << b->atakMin;
//            cout << " max: " << b->atakMax << endl;
//        }
//    }
    postac1->wyswietlOpisPostacZPrzedmiotami();

    postac1->dodajDoPlecaka(p1);
    postac1->dodajDoPlecaka(p2);
    postac1->dodajDoPlecaka(b1);
    postac1->dodajDoPlecaka(b2);

    //postac1->rekaPrawa = b2;
    postac1->ustawBron(b2, true);
    postac1->ustawBron(b4, false);
    //postac1->rekaLewa = b1;

    postac1->wyswietlOpisPostacZPrzedmiotami();



    postac1->przywitajSie();
    postac1->przedstawSie();

//    Postac* wojownik1 = new Wojownik("Gerald", 12500, 5, 5, 15);

    Postac* wojownik1 =  Postac::generujPostac();




    wojownik1->przywitajSie();
    wojownik1->przedstawSie();

//    wojownik1->ustawBron(b2, true);
//    wojownik1->ustawBron(b2, false);

    wojownik1->wyswietlOpisPostacZPrzedmiotami();


    postac1->zaprosDoWalki(wojownik1);

    while( postac1->czyZyje() && wojownik1->czyZyje() )
    {

        postac1->zaatakuj(wojownik1);

        wojownik1->zaatakuj(postac1);

    }

    cout << postac1->pobierzNazwe() << " - " << postac1->czyZyje() << endl;
    cout << wojownik1->pobierzNazwe() << " - " << wojownik1->czyZyje() << endl;



    vector<Postac*> listaPostaci;

    for(int i=0; i< 100; i ++)
    {

        listaPostaci.push_back( Postac::generujPostac() );
    }

    for(int i=0; i< listaPostaci.size(); i ++)
    {
        listaPostaci[i]->wyswietlOpisPostacZPrzedmiotami();
    }

    return 0;
}
