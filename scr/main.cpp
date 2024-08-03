#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"
using namespace std;
int main() {
    jogador a;
    peca S;
    int r = 0; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine
    a.passarTabuleiro();
    a.selecionar(S, r);
    gotoxy(0, 0);
    a.desenharMapaju();
    while (true) {
        a.mover(S);
        gotoxy(0, 0);
        a.desenharMapaju();
        a.mover(S,r);
    }

    return 0;
}