#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/inimigo.hpp"


#include "inimigo.hpp"
#include "jogador.hpp"
#include <iostream>
#include "../include/jogador.hpp"

void inimigo::desenharMapaen(){
    for(int i = 0; i < 22; i++){
        cout << endl;
        for(int j = 0; j < 22; j++){
            cout << en[i][j];
        }
    }
}
void inimigo::printar(peca &P, int r){
    if(r == 1){
        for(int i = 0; i < 4; i++){ //Controla o número de casas que um navio pode ocupar
            coord c = P.posicao(i);
            if(r == 1) en[c.y][c.x] = P.d;
            else en2[c.y][c.x] = P.D;
        }
    }
}
void inimigo::apagar(peca &P){
    for(int i = 0; i < 4; i++){
        coord c = P.posicao(i);
        en[c.y][c.x] = ' '; // Substitui a posição do navio por um espaço em branco
    }
}
void inimigo::mover(peca &P, int &r, int &t){
    if (kbhit()) {
        peca copia = P;
        char tecla = getch();
        // Processa a entrada do usuário para mover a peça
        if(tecla == 'a') P.original.x -= 2;
        if(tecla == 'd') P.original.x += 2;
        if(tecla == 'w') P.original.y -= 2;
        if(tecla == 's') P.original.y += 2;
        if(inimigo::colisao(P, 2)){
            P = copia;
        }
        inimigo::apagar(copia);
        inimigo::printar(P, 1);
        if(tecla == 'z'){
            inimigo::disparo(P,1);
            inimigo::selecionaMapa(P,r);
            t = 2;
            copia = P;
        }
    }
}
bool inimigo::colisao(peca &P, int q){
    for (int i = 0; i < 4; i++) {
        coord c = P.posicao(i);
        if (c.x < 2 || c.x > 20) return true;
        if (c.y < 2 || c.y > 20) return true;
        if(q == 1){
            if(en2[c.y][c.x] == 'C' || en2[c.y][c.x] == 'T' || en2[c.y][c.x] == 'D' || en2[c.y][c.x] == 'S' ) return true;
        }
        else{
            if(en[c.y][c.x] == 'X' || en[c.y][c.x] == '0') return true;
            if(en[c.y][c.x] == 'X' || en[c.y][c.x] == 'O') return true;
        }
    }
    return false;
}
void inimigo::selecionaMapa(peca &P, int r){
    while(true){
        inimigo::selecionar(P, r);
        if(!inimigo::colisao(P, 2)) break;
    }
}
void inimigo::inicializarNavios(peca &P){
    for(int i = 0; i < 5; i++){
        while(true){
            inimigo::selecionar(P, i);
            if(inimigo::obterRot() == 0) inimigo::rotacionar(P);
            if(!inimigo::colisao(P,1)){
                inimigo::printar(P, 2);
                break;
            }
        }
    }
}
int inimigo::obterRot(){
    int x = rand() % 2;
    return x;
}