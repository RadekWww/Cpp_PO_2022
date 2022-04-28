#include <iostream>

using namespace std;


class Ania
{
    friend class Bartek;
private:
    int kasa = 500;

public:
    int wywietlIZwrocPieniadze(){
        return kasa;
    }

};


class Bartek
{

public:
    void doplacDoKonta(Ania* a, int wplata){
        a->kasa += wplata;
    }
};

class Czarek
{

public:
    void doplacDoKonta(Ania* a, int wplata){
        cout<< "niestety klasa Czarek nie jest przyjacielem kalsy Anny" << endl;
        //a->kasa += wplata;
    }
};



int main()
{
    cout << "klasy zaprzyjaznione!" << endl;

    Ania* a = new Ania();

    cout << a->wywietlIZwrocPieniadze() << endl;

    Bartek* b = new Bartek();
    b->doplacDoKonta(a, 100);

    cout << a->wywietlIZwrocPieniadze() << endl;

    Czarek* c = new Czarek();
    c->doplacDoKonta(a, 100);


    return 0;
}
