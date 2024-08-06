#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/jogador.hpp"


using namespace std;

char ma[22][22] = {
    {' ',' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H',' ','I',' ','J',' '},
    {' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' '},
    {'0','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'1','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'2','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'3','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'4','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'5','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'6','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'7','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'8','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'9','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {' ',' ','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' '}
};

void jogador::passarTabuleiro(){
    for(int i = 0; i < 22; i++){
        cout << endl;
        for(int j = 0; j < 22; j++){
            ju[i][j] = ma[i][j];
            en[i][j] = ma[i][j];
            en2[i][j] = ma[i][j];
        }
    }
}
void jogador::desenharMapaju(){
    for(int i = 0; i < 22; i++){
        cout << endl;
        for(int j = 0; j < 22; j++){
            cout << ju[i][j];
        }
    }
}

coord peris[5][3] = {{{2,0}, {4,0}, {6,0}},  //Carrier
                     {{2,0}, {4,0}, {   }},  //Tanker
                     {{2,0}, {4,0}, {   }},  //Destroyer
                     {{   }, {   }, {   }}, //Submarine
                     {{   }, {   }, {   }}};
char navios[4] = {'C','T','D','S'}; //Representação de cada navio pela letra de sua inicial
coord peca::posicao(int n){ //Posiciona um navio no tabuleiro
    coord ret = {original.x, original.y};
    if(n != 0){
        ret.x += perifericos[n-1].x;
        ret.y += perifericos[n-1].y;
    }
coord peca::posicao(int n){ //Posiciona um navio no tabuleiro
    coord ret = {original.x, original.y};
    if(n != 0){
        ret.x += perifericos[n-1].x;
        ret.y += perifericos[n-1].y;
    }
coord peca::posicao(int n){ //Posiciona um navio no tabuleiro
    coord ret = {original.x, original.y};
    if(n != 0){
        ret.x += perifericos[n-1].x;
        ret.y += perifericos[n-1].y;
    }
coord peca::posicao(int n){ //Posiciona um navio no tabuleiro
    coord ret = {original.x, original.y};
    if(n != 0){
        ret.x += perifericos[n-1].x;
        ret.y += perifericos[n-1].y;
    }
coord peca::posicao(int n){ //Posiciona um navio no tabuleiro
    coord ret = {original.x, original.y};
    if(n != 0){
        ret.x += perifericos[n-1].x;
        ret.y += perifericos[n-1].y;
    }
return ret;
}
void jogador::printar(peca &P, int r){

    if(r == 1){
        for(int i = 0; i < 4; i++){ //Controla o número de casas que um navio pode ocupar
            coord c = P.posicao(i);
            if(r == 1) ju[c.y][c.x] = P.d; // Marca a posição do navio com o caractere que representa o tipo do navio
            else ju[c.y][c.x] = P.D;
        }
    }
}
void jogador::apagar(peca &P){ //Lógica identica ao método jogador::printar
    for(int i = 0; i < 4; i++){
        coord c = P.posicao(i);
        ju[c.y][c.x] = ' '; // Substitui a posição do navio por um espaço em branco
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
    P.original.x = jogador::obterxy();
    P.original.y = jogador::obterxy();
    P.D = navios[r];
    for(int i = 0; i < 3; i++){ //Para mais barcos, mudar o 3
        P.perifericos[i] = peris[r][i];
    }
}
void jogador::mover(peca &P, int &r) {
    if (kbhit()) {
        peca copia = P;
        char tecla = getch();
        // Processa a entrada do usuário para mover a peça
        if(tecla == 'a') P.original.x -= 2;
        if(tecla == 'd') P.original.x += 2;
        if(tecla == 'w') P.original.y -= 2;
        if(tecla == 's') P.original.y += 2;
        if(tecla == 'c'){
            jogador::rotacionar(P);
        }
        // Verifica se a nova posição causa uma colisão
        if (jogador::colisao(P)) {
        if (jogador::colisao(P,1)) {
            P = copia; // Reverte para a posição anterior em caso de colisão
        } else {
            // Atualiza o tabuleiro apenas se o movimento for válido
            jogador::apagar(copia);
            jogador::printar(P, 1);
            if(tecla == 'x'){
                jogador::printar(P,2);
                r++;
                jogador::selecionaMapa(P, r);
                jogador::selecionaMapa(P, r, 1);
            }
        }
    }
}
bool jogador::colisao(peca &P) {
bool jogador::colisao(peca &P, int q){
    for (int i = 0; i < 4; i++) {
        coord c = P.posicao(i);
        if (c.x < 2 || c.x > 20) return true;
        if (c.y < 2 || c.y > 20) return true;

        if(ju[c.y][c.x] == 'C' || ju[c.y][c.x] == 'T' || ju[c.y][c.x] == 'D' || ju[c.y][c.x] == 'S' ) return true;
        if(q == 1){
            if(ju[c.y][c.x] == 'C' || ju[c.y][c.x] == 'T' || ju[c.y][c.x] == 'D' || ju[c.y][c.x] == 'S' ) return true;
        }
        else{
            if(ju[c.y][c.x] == 'X' || ju[c.y][c.x] == 'O') return true;
        }
    }
}
int jogador::obterxy(){
    while(true) {
        int x = rand() % 19 + 2;
        if (x % 2 == 0) return x;
    }
}
void jogador::selecionaMapa(peca &P, int r){
void jogador::selecionaMapa(peca &P, int r, int q){
    while(true){
        jogador::selecionar(P, r);
        if(!jogador::colisao(P)) break;
        if(!jogador::colisao(P,q)) break;
    }
}
void jogador::disparo(peca &P,int q){
    for(int i=0; i<5; i++){
        coord c = P.posicao(i);
        if(q == 1){
            if(en2[c.y][c.x] == 'C' || en2[c.y][c.x] == 'T' || en2[c.y][c.x] == 'D' || en2[c.y][c.x] == 'S') en[c.y][c.x] == '0';
            if(en2[c.y][c.x] == ' ') en[c.y][c.x] = 'X';
        }
        else{
            if(ju[c.y][c.x] == 'C' || ju[c.y][c.x] == 'T' || ju[c.y][c.x] == 'D' || ju[c.y][c.x] == 'S'){
                    if(ju[c.y][c.x] = 'C') P.D = 'C';
                    if(ju[c.y][c.x] = 'T') P.D = 'T';
                    if(ju[c.y][c.x] = 'D') P.D = 'D';
                    ju[c.y][c.x] == '0';
                    turno1 = 1;
            }
            if(ju[c.y][c.x] == ' ') ju[c.y][c.x] = 'X';
        }
    }
}
int jogador::verificar(peca &P){
    for(int i = 2; i < 21; i++){
        for(int j = 2; j < 21; j++){
            if(ju[i][j] == P.D){
                P.original.x = j;
                P.original.y = i;
                return 1;
            }
        }
    }
    return 2;
}
void jogador::mudarTurno(peca &P, int &t, int r){
    jogador::selecionaMapa(P,r,2);
    jogador::disparo(P,2);
    t = 1;
}
void jogador::gerenciarIA(peca &P, int &t, int r){
    if(turno1 == 0) turno = 0;
    if(turno1 == 1) turno = 1;

    if(turno = 0){
        jogador::mudarTurno(P,t,r);
    }

    if(turno = 1){
        if(jogador::verificar(P) == 1){
            jogador::disparo(P, 2);
            t = 1;
        }
        if(jogador::verificar(P) == 2){
            jogador::mudarTurno(P,t,r);
            turno1 = 0;
        }
    }
}