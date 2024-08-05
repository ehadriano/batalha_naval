#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/inimigo.hpp"


void inimigo::desenharMapaen(){
    for(int i = 0; i < 22; i++){
        cout << endl;
        for(int j = 0; j < 22; j++){
            cout << en[i][j];
#include "inimigo.hpp"
#include "jogador.hpp"
#include <iostream>

// Implementação dos métodos
void inimigo::desenharMapaen() {
    for (int i = 0; i < 22; i++) {
        std::cout << std::endl;
        for (int j = 0; j < 22; j++) {
            std::cout << en[i][j];
        }
    }
}
void inimigo::printar(peca &P, int r){
    if(r == 1){
       for(int i=0; i<4; i++){ //Controla o número de casas que um navio pode ocupar

void inimigo::printar(peca &P, int r) {
    if (r == 1) {
        for (int i = 0; i < 4; i++) { // Controla o número de casas que um navio pode ocupar
            coord c = P.posicao(i);
            if(r == 1)en[c.y][c.x] = P.d;
            if (r == 1) en[c.y][c.x] = P.d;
            else en[c.y][c.x] = P.D;
        }
    }
}
void inimigo::apagar(peca &P){
    for(int i=0; i<4; i++){

void inimigo::apagar(peca &P) {
    for (int i = 0; i < 4; i++) {
        coord c = P.posicao(i);
        en[c.y][c.x] = ' '; // Substitui a posição do navio por um espaço em branco
    }
}
void inimigo::mover(peca &P, int &r){

void inimigo::mover(peca &P, int &r) {
    if (kbhit()) {
        peca copia = P;
        char tecla = getch();

        // Processa a entrada do usuário para mover a peça
        if(tecla == 'a') P.original.x -=2;
        if(tecla == 'd') P.original.x +=2;
        if(tecla == 'w') P.original.y -=2;
        if(tecla == 's') P.original.y +=2;
        if (tecla == 'a') P.original.x -= 2;
        if (tecla == 'd') P.original.x += 2;
        if (tecla == 'w') P.original.y -= 2;
        if (tecla == 's') P.original.y += 2;

        if(inimigo::colisao(P)){
            P=copia;
        if (colisao(P)) {
            P = copia;
        }

        inimigo::apagar(copia);
        inimigo::printar(P,1);
        }
        apagar(copia);
        printar(P, 1);
    }
}

bool inimigo::colisao(peca &P) {
    for (int i = 0; i < 4; i++) {
        coord c = P.posicao(i);

        if (c.x < 2 || c.x > 20) return true;
        if (c.y < 2 || c.y > 20) return true;

        //if(ju[c.y][c.x] == 'C' || ju[c.y][c.x] == 'T' || ju[c.y][c.x] == 'D' || ju[c.y][c.x] == 'S' ) return true;
        if (en[c.y][c.x] == 'C' || en[c.y][c.x] == 'T' || en[c.y][c.x] == 'D' || en[c.y][c.x] == 'S') return true;
    }
return false;
    return false;
}
void inimigo::selecionaMapa(peca &P, int r){
    while(true){
        inimigo::selecionar(P,r);
        if(!inimigo::colisao(P)) break;

void inimigo::selecionaMapa(peca &P, int r) {
    while (true) {
        selecionar(P, r); // Chama o método da classe base jogador
        if (!colisao(P)) break;
    }
}
}

int inimigo::obterRot() {
    return rand() % 2;
}

void inimigo::inicializarNavios(peca &P) {
    for (int i = 0; i < 4; i++) {
        while (true) {
            selecionar(P, i); // Chama o método da classe base jogador
            if (obterRot() == 0) rotacionar(P); // Chama o método da classe base jogador
            if (!colisao(P)) {
                printar(P, 2);
                break;
            }
        }
    }
}