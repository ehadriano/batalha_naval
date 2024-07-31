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