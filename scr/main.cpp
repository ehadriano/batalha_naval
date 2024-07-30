#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

//Teste do Carrier na Vertical c==0
int main(){

    cursor a;
    jogador b;
    int q1=2, w1=3;
    int q2=2, w2=28; //coodenadas de AO no Tabuleiro 2

    gotoxy(0,0);
    a.printarTabuleiro();
    gotoxy(0,25);
    a.printarTabuleiro();

    b.printar_Carrier(2,10,0);//Por algum motivo, A0 tem coordenada (2,10), não (2,28) como esperado

    while(true){
        a.moverCursor(q1,w1);
    }

return 0;
}