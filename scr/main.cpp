#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main() { //Testa o método 'colisao'
    cursor a;
    jogador b;
    peca S;
    int r = 2; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine

    b.selecionar(S, r);

    gotoxy(0, 0);
    a.printarTabuleiro();
    while (true) {
        b.mover(S);
        gotoxy(0, 0);
        a.printarTabuleiro();
    }

    return 0;
}