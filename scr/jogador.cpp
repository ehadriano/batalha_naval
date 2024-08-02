#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cursor.hpp"

using namespace std;

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
        ma[c.y][c.x] = P.D; // Marca a posição do navio com o caractere que representa o tipo do navio
    }
}
void jogador::apagar(peca &P){ //Lógica identica ao método jogador::printar

    for(int i=0; i<4; i++){
        coord c = P.posicao(i);
        ma[c.y][c.x] = ' '; // Substitui a posição do navio por um espaço em branco
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
void jogador::mover(peca &P) {
    if (kbhit()) {
        peca copia = P;
        char tecla = getch();

        // Processa a entrada do usuário para mover a peça
       if(tecla == 'a') P.original.x -=2;
        if(tecla == 'd') P.original.x +=2;
        if(tecla == 'w') P.original.y -=2;
        if(tecla == 's') P.original.y +=2;

        // Verifica se a nova posição causa uma colisão
        if (jogador::colisao(P)) {
            P = copia; // Reverte para a posição anterior em caso de colisão
        } else {
            // Atualiza o tabuleiro apenas se o movimento for válido
            jogador::apagar(copia);
            jogador::printar(P);
        }
    }
}
bool jogador::colisao(peca &P) {
    for (int i = 0; i < 4; i++) {
        coord c = P.posicao(i);

        if (c.x < 2 || c.x > 20) return true;
        if (c.y < 2 || c.y > 20) return true;
    }
    return false;
}
