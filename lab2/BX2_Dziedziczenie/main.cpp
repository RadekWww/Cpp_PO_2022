#include <iostream>

using namespace std;

class Pojazd
{
public:
    string nazwa;

    Pojazd(){
        cout << "Pojazd: wywolano konstruktor" << endl;
    }

    Pojazd(string jakasZmienna){
        cout << "Pojazd: wywolano konstruktor z parametrem" << endl;
        nazwa = jakasZmienna;
    }

    void metodaPubliczna() {
        cout << "Pojazd: metodaPubliczna" << endl;
    };
    virtual void dajSygnal() {
        cout << "Pojazd: Bip pip..." << endl;
    };

    void wyswietlNazwe() {
        //cout<< pojazd2->nazwa << endl;
        //cout << "Pojazd: " << nazwa << endl;
        cout << "Pojazd: " << this->nazwa << endl;
    }

    void uzyjMetod(){
        metodaPubliczna();
        metodaChroniona();
        metodaPrywatna();
    }

    void obslugaInkluzyjnaDoPorownywaniaNazw(Pojazd* pojazdDoPorowania){

        if(this->nazwa == pojazdDoPorowania->nazwa)
        {
            cout << "obslugaInkluzyjnaDoPorownywaniaNazw: Tak" << endl;
        }
        else
        {
             cout << "obslugaInkluzyjnaDoPorownywaniaNazw: Nie" << endl;
        }

    }

protected:
    void metodaChroniona() {
        cout << "Pojazd: metodaChroniona" << endl;
    };

private:
    void metodaPrywatna() {
        cout << "Pojazd: metodaPrywatna" << endl;
    };
};

class Silnik{
public:
    int pojemnosc;
    float poziomPaliwa;

    Silnik() {
        cout << "Silnik: wywolano konstruktor" << endl;
    }

    void uruchom(){
        poziomPaliwa = poziomPaliwa - 0.1;
        cout << "Silnik: brum brum..." << endl;
    }

};

class Silnik2{
public:
    int pojemnosc2;

    Silnik2() {
        cout << "Silnik2: wywolano konstruktor" << endl;
    }

    void uruchom(){

        cout << "Silnik2: brum brum..." << endl;
    }

};

class Samochod : public Pojazd, public Silnik {

public:
    string model;

    Silnik2 silniczek;
    Silnik2* silniczekWskaznik;

    Samochod(string zmienna) : Pojazd(zmienna) {
        cout << "Samochod: wywolano konstruktor z parametrem" << endl;
        //nazwa = zmienna;
        silniczekWskaznik = new Silnik2();
    }

    void dajSygnal() {
        cout << "Samochod: trabi..." << endl;
    };

    void jedz() {
        cout << "Samochod: jedzie..." << endl;
    };

    void metodaPubliczna() {
        cout << "Samochod: metodaPubliczna" << endl;
    };


    ~Samochod() {
        cout << "Samochod: wywolano destruktor" << endl;
        delete(silniczekWskaznik);

    }

};

class SamochodSportowy : public Samochod {

public:
    string napisSportowy;


    SamochodSportowy(string zmienna) : Samochod(zmienna) {
        cout << "SamochodSportowy: wywolano konstruktor z parametrem" << endl;
    }

    void dajSygnal() {
        cout << "SamochodSportowy: szybko trabi..." << endl;
    };

};

int main()
{
    cout << "Dziedzczenie" << endl;


    Pojazd pojazd1;

    Pojazd* pojazd2 = new Pojazd("Pojazd nr 2");

    //cout<< pojazd2->nazwa << endl;
    pojazd2->wyswietlNazwe();

    pojazd1.metodaPubliczna();
    pojazd1.dajSygnal();
    //pojazd1.metodaChroniona();
    //pojazd1.metodaPrywatna();

    pojazd2->metodaPubliczna();
    pojazd2->dajSygnal();
    //pojazd2->metodaChroniona();
    //pojazd2->metodaPrywatna();

    pojazd2->uzyjMetod();
    cout << "\n samochod" << endl;

    Samochod* samochod1 = new Samochod(" samochod nr 1" );

    samochod1->dajSygnal();
    samochod1->Pojazd::dajSygnal();
    //samochod1->metodaChroniona();
    samochod1->jedz();
    samochod1->metodaPubliczna();
    samochod1->Pojazd::metodaPubliczna();

    samochod1->uzyjMetod();

    samochod1->wyswietlNazwe();


    samochod1->uruchom();

    samochod1->silniczek.uruchom();
    samochod1->silniczekWskaznik->uruchom();

    cout << "\n SamochodSportowy" << endl;
    SamochodSportowy* samochodSportowy1 = new SamochodSportowy(" samochodSportowy nr 1" );


    cout << "\n pojazdNowy" << endl;

    Pojazd* pojazdNowy = new Samochod("pojazdNowy");

    pojazdNowy->dajSygnal();
    pojazdNowy->metodaPubliczna();
    ((Samochod*)pojazdNowy)->metodaPubliczna();
    pojazdNowy->wyswietlNazwe();

    //((Samochod*)pojazdNowy)->dajSygnal();

    pojazd2->obslugaInkluzyjnaDoPorownywaniaNazw(pojazd2);
    pojazd1.obslugaInkluzyjnaDoPorownywaniaNazw(pojazd2);

    pojazd2->obslugaInkluzyjnaDoPorownywaniaNazw(pojazdNowy);
    pojazd2->obslugaInkluzyjnaDoPorownywaniaNazw(samochodSportowy1);


    Pojazd* tablica[] = { pojazd2, pojazdNowy, samochodSportowy1 };

    for(int i=0; i<3; i++)
    {

        tablica[i]->wyswietlNazwe();
        tablica[i]->dajSygnal();
    }


    delete(pojazd2);
    delete(pojazdNowy);
    delete(samochodSportowy1);


    return 0;
}
