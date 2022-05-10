#include <iostream>

using namespace std;


class Pojazd
{
public:
    string nazwa = "NN";

    Pojazd() { cout << "Konstrukotr klasy Pojazd" << endl;}

    Pojazd(string n) {
        nazwa = n;
        cout << "Konstrukotr klasy Pojazd z parametrem " << n << endl;
    }

    void metodaPubliczna(){ cout << "metodaPubliczna" << endl; }

    virtual void dajSygnal(){ cout << "Pojazd: Bip pip..." << endl; }


    void obslugaInkluzyjnaDoPorownywaniaNazw(Pojazd* p){

        if(this->nazwa == p->nazwa)
        {
            cout << "obslugaInkluzyjnaDoPorownywaniaNazw: Tak" << endl;
        }
        else
        {
             cout << "obslugaInkluzyjnaDoPorownywaniaNazw: Nie" << endl;
        }

    }


    void uzyjMetod()
    {
        metodaPubliczna();
        metodaChroniona();
        metodaPrywatna();
    }

protected:
    void metodaChroniona(){ cout << "metodaChroniona" << endl; }

private:
    void metodaPrywatna(){ cout << "metodaPrywatna" << endl; }

};

class Silnik
{
public:
    int pojemnosc;
};

class Silnik2
{
public:
    int pojemnosc2;
};

class Samochod : public Pojazd, public Silnik {
public:
    Silnik2* silniczek;
    //string nazwa;
    Samochod() { cout << "Konstrukotr klasy Samochod" << endl;}
    Samochod(string n) : Pojazd(n)  {
        ////silniczek = new Silnik2();
        //nazwa = n;
        cout << "Konstrukotr klasy Samochod z parametrem " << n << endl;
    }

    void metodaPubliczna(){ cout << "metodaPubliczna z samochodu" << endl; }

    void uzyjMetod()
    {
        Pojazd::metodaPubliczna();
        metodaChroniona();
    }

    virtual void dajSygnal(){ cout << "Samochod: Trabi..." << endl; }

    void jedz(){ cout << "Samochod jedzie..." << endl; }
protected:


private:

};

class SamochodSportowy : public Samochod {

public:
    void dajSygnal(){ cout << "SamochodSportowy: Bzium..." << endl; }

};



int main()
{
    cout << "Dziedziczenie" << endl;

    Pojazd* p1 = new Pojazd();
    cout << p1->nazwa << endl;

    Pojazd* p2 = new Pojazd("Pojazd2");
    cout << p2->nazwa << endl;


    Samochod* s1 = new Samochod();
    cout << s1->nazwa << endl;

    Samochod* s2 = new Samochod("Samochod2");
    cout << s2->nazwa << endl;

    p1->metodaPubliczna();
    //p1->metodaChroniona();
    //p1->metodaPrywatna();

    p1->uzyjMetod();

    s1->metodaPubliczna();
    s1->uzyjMetod();

    cout << "polimorizm" << endl << endl;

    p1->dajSygnal();
    s1->dajSygnal();
    s1->Pojazd::dajSygnal();


    Pojazd* p3 = new Pojazd();
    Pojazd* p4 = new Samochod();
    Samochod* s3 = new Samochod();
    //Samochod* s4 = new Pojazd();

    p3->dajSygnal();
    p4->dajSygnal();
    //s3->dajSygnal();

    Pojazd* p5 = new SamochodSportowy();

    p5->dajSygnal();


    Pojazd* tablica[] = { p3, p4, p5 };

    cout << "polimorizm, talbica obiektow" << endl << endl;
    for(int i=0; i< 3; i++)
    {
        tablica[i]->dajSygnal();
    }


    p3->obslugaInkluzyjnaDoPorownywaniaNazw(p4);
    p3->obslugaInkluzyjnaDoPorownywaniaNazw(s3);
    p3->obslugaInkluzyjnaDoPorownywaniaNazw(s2);

    s2->pojemnosc;
    s2->silniczek->pojemnosc2;

    return 0;
}
