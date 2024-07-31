#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cursor.hpp"

using namespace std;

//jogador.cpp
/*Número de barcos colocados, independe do tipo e tamanho de cada um.
Ex: Carrier   5casas -> {{2,0}, {4,0}, {6,0}, {8,0}}
    Tanker    4casas -> {{2,0}, {4,0}, {6,0}, {   }}
    Destroyer 3casas -> {{2,0}, {4,0}, {   }, {   }}
    Submarine 2casas -> {{2,0}, {   }, {   }, {   }}
*/
coord peris[4][3] = {{{2,0}, {4,0}, {6,0}},  //Carrier
                     {{2,0}, {4,0}, {   }},  //Tanker
                     {{2,0}, {4,0}, {   }},  //Destroyer
                     {{   }, {   }, {   }}}; //Submarine

char navios[4] = {'C','T','D','S'}; //Representação de cada navio pela letra de sua inicial

coord peca::posicao(int n){ //Posiciona um navio no tabuleiro

    coord ret = {original.x, original.y};
    if(n != 0){
        ret.x += perifericos[n-1].x;
        ret.y += perifericos[n-1].y;
    }
return ret;
}
void jogador::printar(peca &P){

    for(int i=0; i<4; i++){ //Controla o número de casas que um navio pode ocupar
        coord c = P.posicao(i);
        ma[c.x][c.y] = P.D;
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
void jogador::selecionar(peca &P, int r){ //Inicia todos e cada um dos Navios

    P.original.x = 2;
    P.original.y = 2;
    P.D = navios[r];
    for(int i=0; i<3; i++){ //Para mais barcos, mudar o 3
            P.perifericos[i] = peris[r][i];
    }
}