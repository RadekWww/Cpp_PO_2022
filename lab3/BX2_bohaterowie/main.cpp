#include <iostream>
#include <vector>

using namespace std;

class Przedmiot
{
public:
    string nazwa;
    int typ;


    Przedmiot(string nazwa)
    {

        this->nazwa = nazwa;
        typ = 0; // 0 to przemiot
        cout << "konstruktor Przedmiot" << endl;
    }

    //virtual
    virtual void dajDzwiekVirtual()
    {
        cout << "Przedmiot robi brzdek Virtual" << endl;

    }
    void dajDzwiekBezVirtual()
    {
        cout << "Przedmiot robi brzdek BezVirtual" << endl;

    }
protected:
    int cena;
};


class Bron : public Przedmiot
{
public:
    int atakMin;
    int atakMax;

    Bron(string nazwa, int atak1, int atak2) : Przedmiot(nazwa)
    {

        typ = 1; // 1 to bron
        atakMin = atak1;
        atakMax= atak2;
        cout << "konstruktor Bron" << endl;
    }

    void PokazCene()
    {
        cout << "Bron cena" << this->cena << endl;

    }

    void dajDzwiekVirtual()
    {
        cout << "Bron robi pif-paf Virtual" << endl;

    }
    void dajDzwiekBezVirtual()
    {
        cout << "Bron robi pif-paf BezVirtual" << endl;

    }

};


class Postac
{
public:
    vector<Przedmiot*> plecak;
    Przedmiot* rekaPrawa;
    Przedmiot* rekaLewa;

    string nazwa;
    int pktAtakuMin;
    int pktAtakuMax;
    int pktZycia;

    Postac(string n, int pktMin, int pktMax, int pktZ )
    {
        nazwa= n;
        pktAtakuMin = pktMin;
        pktAtakuMax = pktMax;
        pktZycia = pktZ;

        rekaPrawa= NULL;
        rekaLewa= NULL;

    }

    void pokazPrzedmioty()
    {

        for(int i = 0; i< this->plecak.size(); i++)
        {

            cout << "element: " << this->plecak[i]->nazwa << " typ " <<  this->plecak[i]->typ  << endl;
            if( this->plecak[i]->typ == 1)
            {
                cout<< "T: min: " << ((Bron*)this->plecak[i])->atakMin << " max: " << ((Bron*)this->plecak[i])->atakMax << endl;
            }

        }
    }

    void dodajPrzemiotyDoPlecaka(Przedmiot* przedmiocik)
    {

        if(this->plecak.size() < 3)
        {

           this->plecak.push_back(przedmiocik);
        }
        else{
            cout << "brak miejsca" << endl;
        }

    }

    int obliczPktAtaku()
    {

        int atak = 0;

        if(rekaLewa != NULL)
        {
            //...atak++;
            if(rekaLewa->typ == 1)
            {
                Bron* bron =  (Bron*)rekaLewa;
                atak += bron->atakMax;
            }
        }
        if(rekaPrawa != NULL)
        {
            //...atak++;
            if(rekaPrawa->typ == 1)
            {
                Bron* bron =  (Bron*)rekaPrawa;
                atak += bron->atakMax;
            }
        }


        //if(atak == 0)
        //{

            atak += this->pktAtakuMax;
        //}
        cout << "oblicznone pkt ataku to: " << atak;
        return atak;

    }

};



int main()
{
    cout << "BX2 bohaterowie" << endl;

    Przedmiot* p1 = new Przedmiot("lina");
    Przedmiot* p2 = new Przedmiot("klejnot");
    Przedmiot* p3 = new Przedmiot("mikstura");

    Przedmiot* b1 = new Bron("miecz", 10, 15);
    Przedmiot* b2 = new Bron("katana", 12, 17);
    Przedmiot* b3 = new Bron("laska", 5, 7);


    p1->dajDzwiekVirtual();
    p1->dajDzwiekBezVirtual();

    b1->dajDzwiekVirtual();
    b1->dajDzwiekBezVirtual();

    ((Bron*)b1)->dajDzwiekBezVirtual();



    vector<Przedmiot*> skrzynia;

    skrzynia.push_back(p1);
    skrzynia.push_back(p2);
    skrzynia.push_back(p3);
    skrzynia.push_back(b1);
    skrzynia.push_back(b2);
    skrzynia.push_back(b3);

    for(int i = 0; i< skrzynia.size(); i++)
    {

        cout << "element: " << skrzynia[i]->nazwa << " typ " <<  skrzynia[i]->typ  << endl;
        if( skrzynia[i]->typ == 1)
        {
            cout<< "T: min: " << ((Bron*)skrzynia[i])->atakMin << " max: " << ((Bron*)skrzynia[i])->atakMax << endl;
        }
        //to use dynamic_cast<Bron*>(rekaPrawa)) add-make A polymorphic, which you can do by adding a virtual destructor or any virtual function:
        if(  auto* derived = dynamic_cast<Bron*>(skrzynia[i])   )
        {
            cout<< "D: min: " << ((Bron*)skrzynia[i])->atakMin << " max: " << ((Bron*)skrzynia[i])->atakMax << endl;
        }

    }

    cout<< "\n######## POSTACIE" << endl;
    Postac* janusz = new Postac("Janusz", 1,2, 100);

//    janusz->plecak.push_back(p1);
//    janusz->plecak.push_back(p2);
//    janusz->plecak.push_back(b1);
//    janusz->plecak.push_back(b2);

    janusz->dodajPrzemiotyDoPlecaka(p1);
    janusz->dodajPrzemiotyDoPlecaka(p2);
    janusz->dodajPrzemiotyDoPlecaka(new Bron("nowaBron", 5,6));
    janusz->dodajPrzemiotyDoPlecaka(b2);



    janusz->pokazPrzedmioty();

    janusz->rekaPrawa = b3;
    //janusz->rekaLewa = b2;

    //b3->cena = 11;

    Bron* b4 = new Bron("nowaBron", 5,6);

    //b4->cena = 11;
    b4->PokazCene();

    janusz->obliczPktAtaku();


    return 0;
}
