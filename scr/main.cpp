#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main(){ //Testa limites na movimentação para Carrier Vertical

    cursor a;
    jogador b;
    int q1=2, w1=3;
    int q2=2, w2=10; //coodenadas de AO no Tabuleiro 2 (Não tenho ideia de como ela começa em 2,10 e não em 2,28)

    gotoxy(0,0);
    a.printarTabuleiro();
    gotoxy(0,25);
    a.printarTabuleiro();

    while(true){
        b.mover_Carrier(q2,w2,0);
    }

return 0;
}