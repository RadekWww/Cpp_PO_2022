#include <iostream>
#include <vector>

using namespace std;

class Produkt
{
public:
    string nazwa;
    int cena;

//    Produkt(string n, int c)
//    {
//        nazwa = n;
//        cena = c;
//    }
    Produkt(string n, int c) : nazwa(n), cena(c)
    {

    }

};


class Sklep
{

public:
    string nazwa;



    Sklep() {}


    void pokazProdukty()
    {
        cout << "listaProduktow w Sklepie " << this->nazwa <<endl;

        if(this->lista.size() == 0 )
        {
            cout << "PUSTO!!" <<endl;
        }
        else
        {
            for(int i = 0; i <  this->lista.size(); i++  )
            {
                cout << i << ". " << this->lista[i]->nazwa << " " << this->lista[i]->cena << endl;
            }
        }
    }

    void dodajProduktDosklepu(Produkt* produkick)
    {
        this->lista.push_back(produkick);
    }
private:
    vector<Produkt*> lista;

};


int main()
{
    cout << "BX2 kolekcje" << endl;

    const int tab5Size = 5;

    int tab5[tab5Size] = { 0 };

    cout << "tab5"<< endl;
    for(int i =0; i< tab5Size; i++)
    {
        cout << tab5[i] << endl;
    }

    double tab[] = {  2.3, 1.2, 0, 3, 4.2, 1.1, 9.8 };
    int len = sizeof(tab)/sizeof(double); // 7;

    cout << "\ntab:"<< endl;
    double suma = 0.0;
    for(int i =0; i< len; i++)
    {
        cout << "[" << i << "]="  << tab[i] << " ";
        suma += tab[i];
    }
    cout << endl;
    cout << "[" << 1 << "]="  << tab[1] << " " << endl;
    cout << "[" << 2 << "]="  << tab[2] << " " << endl;
    cout << "[" << 3 << "]="  << tab[3] << " " << endl;

    cout << endl;
    cout << " suma:"<< suma << endl;
    double srednia = 0.0;
    if(len > 0)
    {
        srednia = suma/len;
    }
    cout << " srednia:"<< srednia << endl;

    cout << endl;



    cout << "\nVECTOR"<< endl;

    //vector<double> vectorTab; // pusty wektor;

    //vector<double> vectorTab(5, 0); // 5 x 0 ;

    vector<double> vectorTab = {  2.3, 1.2, 0, 3, 4.2, 1.1, 9.8 };
    vectorTab.push_back(15);
    vectorTab.push_back(7);

    vectorTab[0] = 11;
    vectorTab[7] = 11;

    int x = 0;
    bool isNumber = false;
    for(int i =0; i< vectorTab.size(); i++)
    {
        cout << "[" << i << "]="  << vectorTab[i] << " ";

        if(vectorTab[i] == x)
        {

            isNumber = true;
        }
//        else{
//            cout << "brak liczby " << x << " w tablicy" <<endl;
//        }

    }

    if(isNumber == false)
    {
        cout << "brak liczby " << x << " w tablicy" <<endl;
    }
    else
    {
        cout << "tak jest " << x << " w tablicy" <<endl;
    }


    int zwykaZmienna;
    zwykaZmienna = 5;

    Produkt produkcik1("chleb1", 5);
    Produkt* produkcik2 = new Produkt("chleb2", 5);

    cout << produkcik1.cena << " " <<   produkcik1.nazwa << endl;
    cout << produkcik2->cena << " " <<   produkcik2->nazwa  << endl;

    Produkt* produkcik3 = new Produkt("bulka", 1);
    Produkt* produkcik4 = new Produkt("ciasto", 10);


    cout << "listaProduktow" <<endl;
    vector<Produkt*> listaProduktow;
    listaProduktow.push_back(produkcik2);
    listaProduktow.push_back(produkcik3);
    listaProduktow.push_back(produkcik4);
    listaProduktow.push_back(&produkcik1);

    //dodawanie na koniec
    listaProduktow.push_back(new Produkt("maslo", 3));
    //dodawanie na poczatek
    listaProduktow.insert(listaProduktow.begin(), new Produkt("tort", 50));
    //dodawanie na koniec
    listaProduktow.insert(listaProduktow.end(), new Produkt("lody", 1));

    for(int j=0; j< listaProduktow.size(); j++ )
    {
        cout << j << ". "<< listaProduktow[j]->nazwa << " " << listaProduktow[j]->cena << endl;
    }


    Sklep* sklepik = new Sklep();
    sklepik->nazwa = "aldi";

//    sklepik->lista.push_back(new Produkt("sok", 4));
//    sklepik->lista.push_back(new Produkt("woda", 1));
//    sklepik->lista.push_back(produkcik4);

    sklepik->dodajProduktDosklepu(new Produkt("sok", 4));
    sklepik->dodajProduktDosklepu(new Produkt("woda", 1));
    sklepik->dodajProduktDosklepu(produkcik4);

//    cout << "listaProduktow w Sklepie" <<endl;
//
//    for(int i = 0; i <  sklepik->lista.size(); i++  )
//    {
//        cout << i << ". " << sklepik->lista[i]->nazwa << " " << sklepik->lista[i]->cena << endl;
//    }

    sklepik->pokazProdukty();

    Sklep* sklepik2 = new Sklep();
    sklepik2->nazwa = "biedra";
    sklepik2->pokazProdukty();


    return 0;
}
