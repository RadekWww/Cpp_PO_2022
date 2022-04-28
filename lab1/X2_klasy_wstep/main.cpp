#include <iostream>

using namespace std;

//Abstrakcjonizm
class Osoba
{
public:
    string imie;
    int wiek;

    //--------------

    void przedstawSie()
    {
        cout << "#wywolanie metody - przedstawSie()" << endl;
        cout << "Jestem " << imie << " , mam " << wiek << "\n"; // endl;
    }
private:
    ////

public:
    ///

};
//Abstrakcjonizm, enkapsulacja


class Konto
{
public:
    int pobierzStan()
    {
        return stan;
    }
    int pobierzIwyswietlStanKonntaZWaluta()
    {
        cout << "Stan konta " << stan << " " << waluta << endl;
        //return pobierzStan();
        return stan;
    }

    int wyplac(int kwotaDoWyplaty)
    {
        if(kwotaDoWyplaty > 0)
        {
            if(kwotaDoWyplaty <= stan)
            {
                stan = stan - kwotaDoWyplaty;
                cout << "Wyplacono " << kwotaDoWyplaty << endl;
                return kwotaDoWyplaty;

            }
            else
            {
                cout << "Brak srodkow" << endl;
                return 0;
            }
        }
        else
        {
            cout << "kwota do wyplaty jest ujemna" << endl;
            return 0;
        }
    }

    void wplac(int kwota)
    {
        if(kwota>0)
        {
            stan = stan + kwota;
            cout << "Wplacono " << kwota << endl;
        }
        else{
            cout << "kwota do wplaty jest niedodatnia" << endl;
        }

    }

private:
    int stan = 500;
    string waluta = "PLN";

};

//Abstrakcjonizm, enkapsulacja
//konstruktor (super metoda, metoda specjalna) // przeciazanie konstrukotra, metody

class Persona
{
public:
//    string imie = "NN";
//    int wiek = 0;

    Persona(){
        cout << "#uruchomienie konstruktora nr 1" << endl;
        wiek = 1;
        imie = "Jan";
    }

    Persona(string nazwa){
        cout << "#uruchomienie konstruktora nr 2" << endl;
        wiek = 1;
        imie = nazwa;
    }
    Persona(string nazwa, int liczbaLat){
        cout << "#uruchomienie konstruktora nr 3" << endl;
        wiek = liczbaLat;
        imie = nazwa;
    }

    ~Persona(){
        cout << "#uruchomienie destruktora dla " << imie << endl; // a w zasadzie to sprz¹tanie przed usuniêcie//wtrackie rozpoc¿ecia zwalania pamiêci.
    }

    void przedstawSie()
    {
        cout << "Jestem " << imie << " , mam " << wiek << " lat\n"; // endl;
    }
private:
    string imie = "NN";
    int wiek = 0;
};

int main()
{
    cout << "Klasy wstep!" << endl;
    cout << "### 1. Osoba" << endl; // "\n";

    int liczba;
    liczba = 1;

    Osoba obiektOsoby1;
    cout << "Mam na imie " << obiektOsoby1.imie << " , mam " << obiektOsoby1.wiek << "\n";

    obiektOsoby1.imie = "Radek";
    obiektOsoby1.wiek = 32;
    cout << "Mam na imie " << obiektOsoby1.imie << " , mam " << obiektOsoby1.wiek << endl;
    obiektOsoby1.przedstawSie();



    cout << "\n\n### 2. Konto" << endl; // "\n";

    Konto konto1;
    konto1.pobierzIwyswietlStanKonntaZWaluta();

    konto1.wyplac(100);
    konto1.pobierzIwyswietlStanKonntaZWaluta();

    konto1.wyplac(1000);
    konto1.pobierzIwyswietlStanKonntaZWaluta();

    konto1.wyplac(-100);
    konto1.pobierzIwyswietlStanKonntaZWaluta();

    konto1.wplac(500);
    konto1.pobierzIwyswietlStanKonntaZWaluta();

    cout << "\n\n### 3. Persona" << endl; // "\n";
    Persona persona1;
    persona1.przedstawSie();
    //persona1.imie = "Maciek";
    //persona1.wiek = 20;
    //persona1.przedstawSie();
    //persona1.

    Persona persona2("Patryk");
    persona2.przedstawSie();

    Persona persona3("Marek", 22);
    persona3.przedstawSie();


    return 0;
}
