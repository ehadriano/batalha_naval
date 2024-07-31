#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cursor.hpp"

using namespace std;

void jogador::printar(peca &P){

    gotoxy(P.original.x, P.original.y); cout << P.D;

    for(int i=0; i<3; i++){ //Controla o número de casas que um navio pode ocupar
        gotoxy(P.original.x + P.perifericos[i].x, P.original.y + P.perifericos[i].y); cout << P.D;
    }
}
coord jogador::rotacionar(coord &c){

    coord ret ={c.y,c.x};

    return ret;
}
void jogador::rotacionar(peca &P){

    for(int i=0; i<3; i++){
        P.perifericos[i] = jogador::rotacionar(P.perifericos[i]);
    }

}