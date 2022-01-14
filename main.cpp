#include <iostream>
#include <cstring>
#include <cstdio>

#include "mapa.h"
#include "policko.h"
#include "hrac.h"
#include "predmet.h"
#include "prikazy.h"


using namespace std;

class prubehHra{
public:
    void inicializaceHry(Mapa mapa){
        mapa.inicializujMapu(mapa.mapa);
    }
    void herniKolo(){

    }
};


int main()
{
    Hrac hrac;
    Mapa mapa;
    mapa.velikost = 2;
    hrac.poloha.x = 0;
    hrac.poloha.y = 0;
    hrac.win = false;


    Prikazy prikazy;

    //deklarovani promenych pouzivanych v akcni casti
    string akce;
    string co;
    string jak;




    cout << "Vitej ve hre draci hrad!" << endl;

    mapa.inicializujMapu(mapa.mapa);

    hrac.jmeno = "Ondra";
    hrac.zdravi.zivoty = 12;
    hrac.zdravi.maxZivotu = 20;
    hrac.sila = 4;
    hrac.inventar[0].nazev = "Mecoun";
    hrac.inventar[1].nazev = "Kozene brneni";

    //základní kód hry, dokud hráč nevyhraje bude se pohybovat a checkovat jeho polohu, jestli uz neni u princezny
    while(hrac.win == false){
        //pohybova cast
        //mapa.pohybovaCast(hrac);
        hrac.poloha = mapa.pohyb(hrac.poloha, mapa.velikost);
        cout <<hrac.poloha.x<<" "<<hrac.poloha.y<<endl;

        mapa.polohaCheck(mapa.mapa, hrac.poloha.x, hrac.poloha.y, hrac.win);
        mapa.generujMapu(mapa.mapa, mapa.velikost);
        cout<<hrac.poloha.x<<hrac.poloha.y<<endl;
        //akcni cast

        prikazy.akcniCast(hrac, mapa);
        /*bool hotovo = false;
        while(hotovo == false){
        cout << "Cas na tvoji akci!"<< endl;
        getline(cin >> ws, akce);
        prikazy.rozdelAkci(akce, co, jak);
        Prikazy::prikaz zadani = prikazy.rozhodniPrikaz(co);
        hotovo = prikazy.prehrajPrikaz(zadani, jak, hrac, mapa, mapa.velikost);
        co = "";
        jak = "";
        }*/
    }
    cout<< "Vyhral jsi!"<<endl;

    return 0;
}
