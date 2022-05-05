#include <iostream>

using namespace std;

//Abstrakcjonizm

class Osoba
{
public:
    string imie;
    string nazwisko;
    int wiek;

    void przedstawSie(){
        cout << "Jestem " << imie << ", mam lat " << this->wiek << " jestem " << plec <<"\n";
    }

    void ustaPlec(string nazwa)
    {
        plec = nazwa;
    }

private:
    string plec;

public:
    /////

};
//Abstrakcjonizm (w programowaniu obiektowym) jest programowym przybli¿eniem interesuj¹cej nas rzeczywistoœci;
// enkapsulacja

class Konto {

public:
    int pobierzStan()
    {
        return stan;
    }
    void wyswietlStanIWalute()
    {
        cout << "Stan konta: " << stan << waluta << endl;
    }
    void wyplac(int kwota)
    {
        cout << "Kwota: " << kwota << endl;
        if( kwota > 0)
        {
            if( kwota <= stan)
            {
                //stan = stan - kwota;
                stan -= kwota;
                cout << "Wyplacono: " << kwota << waluta << endl;
            }
            else{
                cout << "brak takich srodkow! " << endl;
            }
        }
        else
        {
            cout << "operacja niemozliwa! " << endl;
        }


    }
    void wplac(int kwotaDoWplaty)
    {
        stan = stan + kwotaDoWplaty;
        cout << "Wplacono: " << kwotaDoWplaty << endl;
    }

private:
    int stan = 500;
    string waluta = "PLN";

};

int main()
{
    cout << "Klasy wstep!" << endl;

    cout << "1. OSOBA" << endl;

    int liczba1 = 1;
    float liczba2 = 2.1;

    Osoba obiekt1;
    obiekt1.imie = "Radek";
    obiekt1.nazwisko = "Woz";
    obiekt1.wiek = 32;

    cout << "Mam na imie " << obiekt1.imie << ", mam lat " << obiekt1.wiek << "\n";

    obiekt1.przedstawSie();
    obiekt1.ustaPlec("M");
    obiekt1.przedstawSie();

    cout << endl <<"2. KONTO" << endl; //"\n";

    Konto konto1;
    cout << konto1.pobierzStan() << endl;
    konto1.wyswietlStanIWalute();

    konto1.wyplac(200);
    konto1.wyswietlStanIWalute();
    konto1.wyplac(500);
    konto1.wyswietlStanIWalute();

    konto1.wplac(1000);
    konto1.wyswietlStanIWalute();

    konto1.wyplac(-2500);
    konto1.wyswietlStanIWalute();
    konto1.stan = 10000000;
    //konto1.waluta = "Kolumbijs PEsos";
    //konto1.wyswietlStanIWalute();


    return 0;
}
