#include <iostream>
#include <vector>

using namespace std;


enum rodzajPrzedmiotu { prosty, bron, superCos};

class Przedmiot
{
public:

    string nazwa;
    //int typ;
    rodzajPrzedmiotu typ;

    Przedmiot(string nazwa) {
        //typ = 0;
        typ = prosty;
        this->nazwa = nazwa;
        cout << "konstruktor Przedmiot" << endl;
    }
    //virtual
    virtual void dajDzwiek()
    {
        cout << "PRzedmiot robi brzed" << endl;

    }

    virtual ~Przedmiot() {}
protected:
private:
};

class Bron : public Przedmiot
{
public:
    int atakMin;
    int atakMax;



    Bron(string nazwa, int atak1, int atak2) : Przedmiot(nazwa) {
        //this->nazwa = nazwa;
        //typ = 1;
        typ = bron;
        atakMin = atak1;
        atakMax = atak2;
        cout << "konstruktor Bron" << endl;
    }

    void dajDzwiek()
    {
        cout << "Bron robi pif paf" << endl;

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
    int pktZycia = 100;


    void dodajDoPlecaka( Przedmiot* p )
    {
        if( plecak.size() < 3)
        {
            cout << "dodano do plecaka " << p->nazwa << endl;
            //this->plecak.push_back(p);
            plecak.push_back(p);
        }
        else cout << "brak miejsca w plecaku " << endl;

    }

    void wyswietlOpisPostacZPrzedmiotami(){

        cout << "nazwa " << nazwa << endl;
        cout << "pktAtakuMin:" << pktAtakuMin << endl;
        cout << "pktAtakuMax:" << pktAtakuMax << endl;
        if(rekaPrawa != NULL){
            cout << "rekaPrawa:" << rekaPrawa->nazwa << endl;
        }
        else {  cout << "rekaPrawa: brak przedmiotu" << endl; }
        if(rekaLewa != NULL){
            cout << "rekaLewa:" << rekaLewa->nazwa << endl;
        }
        else {  cout << "rekaLewa: brak przedmiotu" << endl; }


        for(int i = 0; i< plecak.size(); i = i+1 ){

            cout << "Plecak: " << plecak[i]->nazwa << endl;
            if(plecak[i]->typ == bron){
                Bron* b = (Bron*)plecak[i];
                cout << "min: " << b->atakMin << endl;
                cout << "max: " << b->atakMax << endl;
            }
        }
    }

    int obliczPktAtaku()
    {
        int x = 0;

        if(rekaLewa != NULL)
        {
            if(rekaLewa->typ == bron){
                Bron* b = (Bron*)rekaLewa;
                //losownie pomiedzy min a max
                x += b->atakMax;
            }
        }

        if(rekaPrawa != NULL)
        {
            if(rekaPrawa->typ == bron){
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


    void zaatakuj( Postac* przeciwnik)
    {
        int silaAtaku = this->obliczPktAtaku();
        przeciwnik->przyjmijUderzenie(silaAtaku);
    }

    void przyjmijUderzenie(int silaAtaku)
    {
        this->pktZycia -= silaAtaku;
    }

};



//void wyzwietlPrzedmioty( )

int main()
{
    cout << "Bohaterowie przedmioty!" << endl;

    Przedmiot* p1 = new Przedmiot("lina");
    Przedmiot* p2 = new Przedmiot("klejnot");
    Przedmiot* p3 = new Przedmiot("mikstura");

//    Bron* b1 = new Bron("miecz", 10, 15);
//    Bron* b2 = new Bron("katana", 12, 17);
//    Bron* b3 = new Bron("laska", 5, 7);
    Przedmiot* b1 = new Bron("miecz", 10, 15);
    Przedmiot* b2 = new Bron("katana", 12, 17);
    Przedmiot* b3 = new Bron("laska", 5, 7);

    p1->dajDzwiek();
    b1->dajDzwiek();
    ((Bron*)b1)->dajDzwiek();

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

    //int j;
    //j = 5;
    //cout << j <<endl;
    //Postac postac1;

    Postac* postac1 = new Postac();
    postac1->nazwa = "Janusz";
    postac1->pktAtakuMin = 1;
    postac1->pktAtakuMax = 2;

//    postac1->plecak.push_back(p1);
//    postac1->plecak.push_back(p2);
//    postac1->plecak.push_back(b1);
//    postac1->plecak.push_back(b2);
    postac1->dodajDoPlecaka(p1);
    postac1->dodajDoPlecaka(p2);
    postac1->dodajDoPlecaka(b1);
    postac1->dodajDoPlecaka(b2);


    postac1->rekaPrawa = b3;
    postac1->rekaLewa = b1;


    postac1->wyswietlOpisPostacZPrzedmiotami();


    postac1->obliczPktAtaku();







    return 0;
}
