#include "hrac.h"
#include "predmet.h"

using namespace std;

//vraci info o uspesnosti hledani a v pripade uspesnosti i referenci index hledaneho predmetu
bool Hrac::prohledejInventar(Hrac hrac, string argument, int& indexPredmetu, bool prohledatCast){
    short pocatek = 0;
    if(prohledatCast){pocatek = 2;}
    for(short i = pocatek; i < hrac.velikostInventare; i++){
        if(hrac.inventar[i].nazev == argument){
            indexPredmetu = i;
            return true;
        }
    }
    cout<<"Tento predmet nemate v inventari"<<endl;

    return false;
}

void Hrac::seradInventar(Predmet inventar[], short velikostInventare){
    Predmet prechodnyPredmet;
    for(short i = 2; i < (velikostInventare +1); i++){
        if(inventar[i].nazev == ""){
            for(short j = i; j < (velikostInventare + 1); j++){
                if(!(inventar[j].nazev == "")){
                    prechodnyPredmet = inventar[i];
                    inventar[i] = inventar[j];
                    inventar[j] = prechodnyPredmet;
                }
            }
        }
    }
}

void Hrac::Zdravi::leceni(short vyleceneZivoty, Zdravi zdravi){
    zdravi.zivoty = zdravi.zivoty + vyleceneZivoty;
    if(zdravi.zivoty < zdravi.maxZivotu){zdravi.zivoty = zdravi.maxZivotu;}
}
