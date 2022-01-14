#ifndef PRIKAZY_H
#define PRIKAZY_H
#include <iostream>

#include "hrac.h"
#include "mapa.h"

class Prikazy
{
    public:
        enum prikaz{info, pouzij, pomoc, konec, error};

        void rozdelAkci(std::string source, std::string& prvniSlovo, std::string& druheSlovo);
        bool prehrajPrikaz(Prikazy::prikaz zadani, std::string argument, Hrac hrac, Mapa mapaPrikazy, int velikost);
        void rozhodniPrikazInfo(std::string argument, Hrac hrac, Mapa mapaPrikazy, int velikost);
        void prikazInfoMapa(Hrac hrac, Mapa mapaPrikazy, int velikost);
        Prikazy::prikaz rozhodniPrikaz(std::string source);
        void akcniCast(Hrac hrac, Mapa mapa);
        void prikazPouzij(std::string argument, Hrac hrac, Mapa mapa);
        void pouzitiKonzumovatelnychPredmety(Predmet konzumovatelnyPredmet, Hrac::Poloha poloha, Policko mapa[][2], Hrac::Zdravi zdravi);


    protected:

    private:
};

#endif // PRIKAZY_H
