#include "prikazy.h"

#include <iostream>
#include "hrac.h"
#include "mapa.h"
#include "predmet.h"

using namespace std;

void Prikazy::rozdelAkci(string source, string& prvniSlovo, string& druheSlovo){
    short i;
    for(i = 0; i < source.length(); i++){
        if(source[i] == ' '){
            break;
        }
    }


    char prvniPole[i];



    for(short l = 0; l < (i); l++){
        prvniPole[l] = source[l];
    }

    for(short x = 0; x < (i); x++){
        prvniSlovo = prvniSlovo + prvniPole[x];
    }

    char druhePole[source.length() - prvniSlovo.length()];

    short n = 0;
    short m;
    for(m = (i+1); m < source.length(); m++){druhePole[n] = source[m];
        n++;
    }

    for(short o = 0; o < n; o++){
        druheSlovo = druheSlovo + druhePole[o];
    }
}

bool Prikazy::prehrajPrikaz(Prikazy::prikaz zadani, string argument, Hrac hrac, Mapa mapaPrikazy, int velikost){
    switch(zadani){
    case Prikazy::pouzij:
        cout<<"pouzij"<<endl;
        return false;
        break;
    case Prikazy::info:
        rozhodniPrikazInfo(argument, hrac, mapaPrikazy, velikost);
        return false;
        break;
    case Prikazy::pomoc:
        cout<<"pomoc"<<endl;
        return false;
        break;
    case Prikazy::konec:
        cout<<"konec"<<endl;
        return true;
        break;
    default:
        cout<<"neznamy prikaz"<<endl;
        return false;
    }

}

void Prikazy::prikazPouzij(string argument, Hrac hrac, Mapa mapa){
    int indexPredmetu;
    Predmet prechodnyPredmet;
    if(hrac.prohledejInventar(hrac, argument, indexPredmetu, true)){
        switch(hrac.inventar[indexPredmetu].typ){
        case 'Z':
            //vymeni predmety
            prechodnyPredmet = hrac.inventar[0];
            hrac.inventar[0] = hrac.inventar[indexPredmetu];
            hrac.inventar[indexPredmetu] = prechodnyPredmet;
            cout<<"Nyni jako zbran predmet s nazvem "<<hrac.inventar[0].nazev<<endl;

            //aktualizuje silu
            hrac.sila = hrac.sila - hrac.inventar[indexPredmetu].sila;
            hrac.sila = hrac.sila + hrac.inventar[0].sila;
            cout<<"Vase momentalni sila je: "<<hrac.sila;
            break;
        case 'B':
            //vymeni predmety
            prechodnyPredmet = hrac.inventar[1];
            hrac.inventar[1] = hrac.inventar[indexPredmetu];
            hrac.inventar[indexPredmetu] = prechodnyPredmet;
            cout<<"Nyni jako zbran predmet s nazvem "<<hrac.inventar[1].nazev<<endl;

            //aktualizuje ochranu
            hrac.ochrana = hrac.ochrana - hrac.inventar[indexPredmetu].ochrana;
            hrac.ochrana = hrac.ochrana + hrac.inventar[1].ochrana;
            cout<<"Vase momentalni ochrana je: "<<hrac.ochrana;
            break;
        case 'K':
            pouzitiKonzumovatelnychPredmety(hrac.inventar[indexPredmetu], hrac.poloha, mapa.mapa, hrac.zdravi);
            break;
        }
    }

}

Predmet::konzumovatelny rozhodniKonzumovatelny(Predmet konzumovatelnyPredmet){
    if(konzumovatelnyPredmet.nazev == "louce"){return Predmet::louce;}
    else if(konzumovatelnyPredmet.nazev == "lektvar"){return Predmet::lektvar;}
}

//updatuj parametry (velikost pole)
void Prikazy::pouzitiKonzumovatelnychPredmety(Predmet konzumovatelnyPredmet, Hrac::Poloha poloha, Policko mapa[][2], Hrac::Zdravi zdravi){
    switch(rozhodniKonzumovatelny(konzumovatelnyPredmet)){
    case Predmet::louce:
        mapa[poloha.y + 1][poloha.x].odhalene = true;
        mapa[poloha.y - 1][poloha.x].odhalene = true;
        mapa[poloha.y][poloha.x + 1].odhalene = true;
        mapa[poloha.y][poloha.x - 1].odhalene = true;
    case Predmet::lektvar:
        zdravi.leceni(konzumovatelnyPredmet.lecivostZivotu, zdravi);
    }
}

//aktualizuj parametry (velikost pole)
void Prikazy::rozhodniPrikazInfo(string argument, Hrac hrac, Mapa mapaPrikazy, int velikost){
    if(argument == "mapa"){
        prikazInfoMapa(hrac, mapaPrikazy, velikost);
    }
    else if(argument == "hrac"){
        cout<<"Jmeno: "<<hrac.jmeno<<endl;
        cout<<"Zdravi: "<<hrac.zdravi.zivoty<<"/"<<hrac.zdravi.maxZivotu<<endl;
        cout<<"Sila: "<<hrac.sila<<endl;
        cout<<"Nasazena zbran: "<<hrac.inventar[0].nazev<<endl;
        cout<<"Nasazene brneni: "<<hrac.inventar[1].nazev<<endl;
    }
    else if(argument == "inventar"){
        cout<<"Obsah inventare:\n";
        for(short i = 0; i < hrac.velikostInventare; i++){
            cout<<(i+1)<<".  "<<hrac.inventar[i].nazev<<endl;
        }
    }
    else{
        int indexpredmetu;
        if(hrac.prohledejInventar(hrac, argument, indexpredmetu, false)){
            cout<<"Nazev: "<<hrac.inventar[indexpredmetu].nazev<<endl;
            cout<<"Popis: \""<<hrac.inventar[indexpredmetu].popis<<"\""<<endl;
            switch(hrac.inventar[indexpredmetu].typ){
            case 'Z':
                cout<<"Sila: "<<hrac.inventar[indexpredmetu].sila<<endl;
                break;
            case 'B':
                cout<<"Ochrana: "<<hrac.inventar[indexpredmetu].ochrana<<endl;
            }
        }
    }
}

void Prikazy::prikazInfoMapa(Hrac hrac, Mapa mapaPrikazy, int velikost){
    mapaPrikazy.generujMapu(mapaPrikazy.mapa, velikost);
    cout<<"Nachazis se na "<<(char)(hrac.poloha.y + 65)<<(hrac.poloha.x + 1)<<endl;
    mapaPrikazy.polohaCheck(mapaPrikazy.mapa, hrac.poloha.x, hrac.poloha.y, hrac.win);
}

Prikazy::prikaz Prikazy::rozhodniPrikaz(string source){
    Prikazy::prikaz vysledek;

    if(source == "pouzij"){vysledek = Prikazy::pouzij;}
    else if(source == "info"){vysledek = Prikazy::info;}
    else if(source == "pomoc"){vysledek = Prikazy::pomoc;}
    else if(source == "konec"){vysledek = Prikazy::konec;}
    else{vysledek = Prikazy::error;}

    return vysledek;
}

void Prikazy::akcniCast(Hrac hrac, Mapa mapa){
    bool hotovo = false;
    while(hotovo == false){
        string akce;
        string co = "";
        string jak = "";
        cout << "Cas na tvoji akci!"<< endl;
        getline(cin >> ws, akce);
        rozdelAkci(akce, co, jak);
        Prikazy::prikaz zadani = rozhodniPrikaz(co);
        hotovo = prehrajPrikaz(zadani, jak, hrac, mapa, mapa.velikost);
    }
}
