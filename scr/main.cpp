#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main(){

    cursor a;
    jogador b;

    peca S;
    int r = 0; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine

    b.selecionar(S,r);

    //gotoxy(0,0);
    //a.printarTabuleiro();

    b.printar(S);
    gotoxy(0,25);
    a.printarTabuleiro();

    //b.rotacionar(c);

    //b.printar(c);

return 0;
}