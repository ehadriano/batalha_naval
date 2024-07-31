#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main(){

    cursor a;
    jogador b;
    peca c = { {2,10}, { {2,0}, {4,0}, {6,0} }, 'P' }; //original, perifericos, char

    int q1=2, w1=3;
    int q2=2, w2=10; //coodenadas de AO no Tabuleiro 2 (Não tenho ideia de como ela começa em 2,10 e não em 2,28)

    b.printar(c);

    /*
    gotoxy(0,0);
    a.printarTabuleiro();
    gotoxy(0,25);
    a.printarTabuleiro();
    */

return 0;
}