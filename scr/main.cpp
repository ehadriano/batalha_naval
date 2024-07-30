#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

//Testa movimentação na Horizontal
int main(){

    cursor a;
    jogador b;
    int q1=2, w1=3;
    int q2=2, w2=10; //coodenadas de AO no Tabuleiro 2

    gotoxy(0,0);
    a.printarTabuleiro();
    gotoxy(0,25);
    a.printarTabuleiro();

    //.printar_Carrier(2,10,1);//Por algum motivo, A0 tem coordenada (2,10), não (2,28) como esperado

    while(true){
        b.mover_Carrier(q2,w2,1);
    }

return 0;
}