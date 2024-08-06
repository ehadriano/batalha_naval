#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include <windows.h>

#include "jogador.hpp"

//inimigo.hpp
void gotoxy(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}
struct coord{ //Coordenadas
    int x, y;
};
struct peca{ //Peça
    coord original;
    coord perifericos [3];
    char D;
    char d = '*';
    coord posicao(int n); //Posição
};

char en[22][22];

class inimigo : public jogador {
public:
    void desenharMapaen();
    void printar(peca &p, int r);
    void apagar(peca &p);
    void mover(peca &p, int &r);
    bool colisao(peca &p);
    void selecionaMapa(peca &p, int r);
    void inicializarNavios(peca &p);
    int obterRot();
class inimigo : public jogador{
    public:

        void desenharMapaen();
        void printar(peca &, int);
        void apagar(peca &);
        void mover(peca &, int &, int &);
        bool colisao(peca &, int);
        void selecionaMapa(peca &, int);
        void inicializarNavios(peca &);
        int obterRot();

};

#endif // INIMIGO_HPP