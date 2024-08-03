#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main(){

int main() {
    cursor a;
    jogador b;

    peca S;
    int r = 0; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine

    b.selecionar(S,r);
    int r = 2; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine

    //gotoxy(0,0);
    //a.printarTabuleiro();
    b.selecionar(S, r);

    b.printar(S);
    gotoxy(0,25);
    gotoxy(0, 0);
    a.printarTabuleiro();
    while (true) {
        b.mover(S);
        gotoxy(0, 0);
        a.printarTabuleiro();
    }

    //b.rotacionar(c);

    //b.printar(c);

return 0;
    return 0;
}