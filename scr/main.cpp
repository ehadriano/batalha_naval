#include "../include/jogador.hpp"
#include "../include/inimigo.hpp"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
int main() {
    srand(time(NULL));
    jogador a;
    inimigo b;
    peca S, S1;
    int r = 0; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine
    int t = 0;
    a.passarTabuleiro();
    a.selecionar(S, r);
    b.inicializarNavios(S1);
    gotoxy(0, 0); a.desenharMapaju();
    gotoxy(0, 25); b.desenharMapaen();
    while(true){
        gotoxy(0, 0); a.desenharMapaju();
        gotoxy(0, 25); b.desenharMapaen();
        if(t == 0){
            a.mover(S, r);
            if(r == 4) t = 1;
        }
        if(t == 1){
            b.mover(S1, r, t);
        }

        if(t == 2){
            a.gerenciarIA(S,t,r);
        }


    }

    return 0;
}