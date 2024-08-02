#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/jogador.hpp"

using namespace std;

int main() {

    jogador a;
    inimigo b;

    peca S;
    int r = 0; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine
    int t=0;

    a.passarTabuleiro();
    a.selecionar(S, r);

    gotoxy(0, 0); a.desenharMapaju();

    gotoxy(0, 25); b.desenharMapaen();

    while (true) {
        gotoxy(0, 0); a.desenharMapaju();
        gotoxy(0, 25); b.desenharMapaen();

        if(t==0){
            a.mover(S,r);
            if(r==4) t=1;
        }
        if(t == 1){
            b.mover(S,r);
        }
    }

    return 0;
}
