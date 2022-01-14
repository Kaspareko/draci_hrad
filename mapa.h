#ifndef MAPA_H
#define MAPA_H

#include "policko.h"
#include "hrac.h"

class Mapa
{
    public:
        int velikost;
        Policko mapa[2][2];

        void pohybovaCast(Hrac hrac);

        void generujMapu(Policko mapa[][2], int velikost);
        Hrac::Poloha pohyb(Hrac::Poloha hrac, short velikost);
        void inicializujMapu(Policko mapa[][2]);
        void polohaCheck(Policko mapa[][2], int polohax, int polohay, bool &win);
    protected:

    private:
};

#endif // MAPA_H
