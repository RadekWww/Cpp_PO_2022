#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>


class Persona
{
    public:
        Persona();

        std::string imie;
        std::string nazwisko;
        int wiek;

        void przedstawSie();

    protected:

    private:
};

#endif // PERSONA_H
