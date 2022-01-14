#include <iostream>
#include "mapa.h"
#include "policko.h"
#include "hrac.h"

using namespace std;

//upadtuj parametry (velikost pole)
void Mapa::generujMapu(Policko mapa[][2], int velikost){
    char znackaRadku = 'A';
    for(short i = 0; i < (velikost+1); i++){
        if(i == 0){cout<<"\t";}
        else{cout<<i<<"\t";}
    }
    cout<<endl;
    for(short i = 0; i < 2; i++){
        cout<<(char)(znackaRadku + i)<<"|\t";
        for(short j = 0; j < 2; j++){
            if(mapa[i][j].odhalene){
                cout<<mapa[i][j].typ<<"\t";
            }
            else{
                cout<<"?\t";
            }
        }
        cout << endl;
    }
}

Hrac::Poloha Mapa::pohyb(Hrac::Poloha poloha, short velikost){
    char odpoved;
    bool presmapu = true;

    do{
        do{
        cout<< "Pohyb (s, v, j, z)"<<endl;

        cin>> odpoved;
        }while(!(odpoved == 's' || odpoved == 'v' || odpoved == 'j' || odpoved == 'z'));


        switch(odpoved){
        case 's':
            poloha.y = poloha.y - 1;
            if(poloha.y < 0){
                presmapu = false;
                poloha.y = poloha.y + 1;
                return poloha;}
            else{presmapu = true;}
            break;
        case 'v':
            poloha.x = poloha.x + 1;
            if(poloha.x > (velikost - 1)){
                presmapu = false;
                poloha.x = poloha.x - 1;}
            else{presmapu = true;}
            break;
        case 'j':
            poloha.y = poloha.y + 1;
            if(poloha.y > (velikost - 1)){
                presmapu = false;
                poloha.y = poloha.y - 1;}
            else{presmapu = true;}
            break;
        case 'z':
            poloha.x = poloha.x - 1;
            if(poloha.x < 0){
                presmapu = false;
                poloha.x = poloha.x + 1;}
            else{presmapu = true;}
            break;
        }
    }while(!(presmapu));
    return poloha;
}

//upadtuj parametry (velikost pole)
void Mapa::inicializujMapu(Policko mapa[][2]){
    short velikost = 2;
    //nastavi vsechny prvky pole jako schovane a neporazene
    for(short i = 0; i < velikost; i++){
        for(short j = 0; j < velikost; j++){
            mapa[i][j].odhalene = false;
            mapa[i][j].porazene = false;
        }
    }
    //tvorba samotne mapy
    mapa[0][0].typ = 'S';
    mapa[0][1].typ = 'L';
    mapa[1][0].typ = 'L';
    mapa[1][1].typ = 'P';

    //inicializace startovniho pole
    mapa[0][0].odhalene = true;
    mapa[0][0].porazene = true;
}

//upadtuj parametry (velikost pole)
void Mapa::polohaCheck(Policko mapa[][2], int polohax, int polohay, bool &win){
    mapa[polohay][polohax].odhalene = true;
    switch(mapa[polohay][polohax].typ){
    case 'S':
        cout<<"Jsi na startovnim poli, oh jake dobrodruzstvi na tebe ceka!"<<endl;
        break;
    case 'L':
        cout<<"Lotr plac, davej si bacha"<<endl;
        break;
    case 'P':
        cout<<"Jsi u princezny! Tvoje cesta je u konce"<<endl;
        win = true;
        break;
    default:
        cout<<"Ale ne! Neco se pokazilo! Kontaktuj vyvojare na xkaspa00@jaroska.cz"<<endl;
    }
}

void Mapa::pohybovaCast(Hrac hrac){
    hrac.poloha = pohyb(hrac.poloha, velikost);
    cout<<(char)(65 + hrac.poloha.y)<<" "<<(hrac.poloha.x + 1)<< endl;
    polohaCheck(mapa, hrac.poloha.x, hrac.poloha.y, hrac.win);
    generujMapu(mapa, velikost);
    cout<<hrac.poloha.x<<hrac.poloha.y<<endl;
}

