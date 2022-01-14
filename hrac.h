#ifndef HRAC_H
#define HRAC_H
#include <iostream>

#include "predmet.h"

class Hrac
{
    public:
        Hrac(){
            zdravi.maxZivotu = 10;
            zdravi.zivoty = zdravi.maxZivotu;
            win = false;
            sila = 1;
            poloha.x = 0;
            poloha.y = 0;
            ochrana = 0;
        }
        std::string jmeno;

        struct Zdravi{
            short zivoty;
            short maxZivotu;
            void leceni(short vyleceneZivoty, Zdravi zdravi);
        };
        Zdravi zdravi;

        bool win;
        int sila;
        int ochrana;

        struct Poloha{
            int x;
            int y;
        };
        Poloha poloha;

        int konto;
        short velikostInventare;
        Predmet inventar[7];
        bool prohledejInventar(Hrac hrac, std::string argument, int& indexPredmetu, bool prohledatCast);
        void seradInventar(Predmet inventar[], short velikostInventare);

    protected:

    private:
};

#endif // HRAC_H
