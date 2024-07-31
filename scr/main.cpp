#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main(){

    cursor a;
    jogador b;
    peca c = { {2,10}, { {2,0}, {4,0}, {6,0} }, 'P' }; //original, perifericos, char
    peca v = { {2,10}, { {2,0}, {4,0}, {6,0} }, 'P' };

    gotoxy(0,0);
    a.printarTabuleiro();
    gotoxy(0,25);
    a.printarTabuleiro();

    b.printar(v);

    b.rotacionar(c);

    b.printar(c);

return 0;
}