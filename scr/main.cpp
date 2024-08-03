#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

/*Testa o método jogador::apagar e se a função de rotação
está funcionado igual esperado*/
int main() { 
    cursor a;
    jogador b;
int main() {

    jogador a;

    peca S;
    int r = 0; //r=0 Carrier, r=1 Tanker, r=2 Destroyer, r=3 Submarine

    b.selecionar(S, r);
    a.passarTabuleiro();
    a.selecionar(S, r);

    gotoxy(0, 0);
    a.printarTabuleiro();
    a.desenharMapaju();
    while (true) {
        b.mover(S);
        a.mover(S);
        gotoxy(0, 0);
        a.printarTabuleiro();
        a.desenharMapaju();
    }

    return 0;
}