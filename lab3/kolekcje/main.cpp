#include <iostream>
#include <vector>

using namespace std;

class Produkt
{
public:
    string nazwa;
    int cena;

//    Produkt(string n, int c){
//        nazwa = n;
//        cena = c;
//    }
    Produkt(string n, int c) : nazwa(n), cena (c)
    {
    }

    Produkt(const Produkt& other) {
        cout << "Obcject copied" << endl;
        nazwa = other.nazwa;
        cena = other.cena;
    }

};


int main()
{
    cout << "Kolekcje!" << endl;

//
//    const int tabSize = 10;
//
//    int tab5[tabSize];
//
//    int tab[tabSize] = { 0 };
//
//    cout << "tab loop" << endl;
//    for(int i = 0; i < tabSize; i++ )
//    {
//        cout <<  "index="<< i << " value=" << tab[i] << endl;
//    }
//
//    float tab2[] = {  2.3, 1.2, 0, 3, 4.2, 1.1, 9.8 };
//
//    int len = sizeof(tab2)/sizeof(float);
//
//
//    cout << tab2[0] << endl;
//    cout << tab2[1] << endl;
//    cout << tab2[2] << endl;
//
//    cout << "tab2 loop" << endl;
//    for(int i = 0; i < len; i++ )
//    {
//        cout <<  "index="<< i << " value=" << tab2[i] << endl;
//    }


    //vector<float> vectorTab; // pusty wektor
    //vector<float> vectorTab(5, 2.0); //[0]=2 [1]=2 [2]=2 [3]=2 [4]=2

    vector<float> vectorTab = {  2.3, 1.2, 0, 3, 4.2, 1.1, 9.8 };
    cout << "vectorTab size= " << vectorTab.size() << endl;
    for(int i = 0; i < vectorTab.size(); i++ )
    {
        cout <<  "["<< i << "]=" << vectorTab[i] << " ";
    }
    cout <<  endl;

    vectorTab[0] = 111;

    for(int i = 0; i < vectorTab.size(); i++ )
    {
        cout <<  "["<< i << "]=" << vectorTab[i] << " ";
    }
    cout <<  endl;

    vectorTab.push_back(112);
    vectorTab.push_back(223);

    for(int i = 0; i < vectorTab.size(); i++ )
    {
        cout <<  "["<< i << "]=" << vectorTab[i] << " ";
    }
    cout <<  endl;

    bool isNumber = false;
    int x = 3;
    for(int i = 0; i < vectorTab.size(); i++ )
    {
        if(vectorTab[i] == x)
        {
             cout <<  "liczba "<< x<<" jest w wektorze, idnex =" << i<<  endl;
             isNumber = true;
        }
    }
    if(isNumber == false)
    {
        cout << "brak liczby "<< x <<endl;
    }



    vector<Produkt*> listaProduktow;

    listaProduktow.push_back(new Produkt("chleb", 5));
    listaProduktow.push_back(new Produkt("bulka", 1));

    Produkt* p1 =  new Produkt("ciasto", 10);

    listaProduktow.push_back(p1);

    p1->cena = 11;


    listaProduktow.push_back(p1);

    Produkt* p2 = new Produkt(*p1);
    p2->cena = 12;

    listaProduktow.push_back(p2);

    cout << "listaProduktow size= " << listaProduktow.size() << endl;
    for(int i = 0; i < listaProduktow.size(); i++ )
    {
        cout <<  "["<< i << "]=" << listaProduktow[i]->nazwa << " " << listaProduktow[i]->cena << " " << listaProduktow[i] << endl;
    }
    cout <<  endl;


    cout << listaProduktow.front()->nazwa << endl;
    cout << listaProduktow.back()->nazwa << endl;

    Produkt* p3 =  new Produkt("rogalik", 6);
    listaProduktow.insert(listaProduktow.begin(), p3);

    cout << "listaProduktow size= " << listaProduktow.size() << endl;
    for(int i = 0; i < listaProduktow.size(); i++ )
    {
        cout <<  "["<< i << "]=" << listaProduktow[i]->nazwa << " " << listaProduktow[i]->cena << " " << listaProduktow[i] << endl;
    }
    cout <<  endl;



    return 0;
}
