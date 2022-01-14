#ifndef PREDMET_H
#define PREDMET_H
#include <iostream>

class Predmet
{
    public:
        enum konzumovatelny{lektvar, louce};
        std::string nazev;
        int cena;
        std::string popis;

        char typ;

        int sila;

        int ochrana;

        short lecivostZivotu;

    protected:

    private:
};

#endif // PREDMET_H
