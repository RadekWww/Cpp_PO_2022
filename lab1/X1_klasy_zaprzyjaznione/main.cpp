#include <iostream>

using namespace std;


class Adam {
  friend class Bartek;

private:
    int kasa;

public:
    Adam() { kasa = 1; }
    int getKasa(){ return kasa; }
};

class Bartek {
  public:
   void setKasa(Adam* obiekt, int newVal) {
     obiekt->kasa = newVal;
  }
    void setKasaBezWskaznika(Adam obiekt, int newVal) {
     obiekt.kasa = newVal;
  }
};

class Czarek {
  public:
   void setKasa(Adam* obiekt, int newVal) {
        cout << "Klasa Czarek nie jest zaprzyjazniona z klasa Adam" << endl;
//     obiekt->kasa = newVal;
  }
};


int main()
{
    cout << "Klasy zaprzyjaznione!" << endl;

    Adam* a = new Adam();
    Bartek* b = new Bartek();
    Czarek* c = new Czarek();

    cout << a->getKasa() << endl; // Wypisuje 1
    b->setKasa(a, 11);
    cout << a->getKasa() << endl; // Wypisuje 11
    c->setKasa(a, 22);
    cout << a->getKasa() << endl; // xxxx

    Adam a1;
    Bartek b1;
    Czarek c1;

    cout << a1.getKasa() << endl; // Wypisuje 1
    b1.setKasaBezWskaznika(a1, 11);
    cout << a1.getKasa() << endl; // Wypisuje 11
    c1.setKasa(&a1, 22);
    cout << a1.getKasa() << endl; // xxxx



    return 0;

}
