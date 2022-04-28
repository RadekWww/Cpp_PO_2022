#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include <iostream>
//using namespace std;


class Czlowiek
{
    public:
        std::string imie;
        int wiek;
        Czlowiek(std::string nazwa);

        Czlowiek(std::string nazwa, int wiek);

        void przedstawSie();

        static Czlowiek* utworzIZwrocNowyObiekt();

    protected:

    private:
};

#endif // CZLOWIEK_H
