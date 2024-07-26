/*Teste de Commit*/
#include <windows.h>



int main()
{
    cursor a; //Variável que vai representar o cursor
    jogador b;
    int q1=2 , w1=3; //Variáveis onde o cursor vai começar no Tabuleiro 1
    int q2=2 , w2=28; //Variáveis onde o cursor vai começar no Tabuleiro 2



    gotoxy(0,0);
    a.printarTabuleiro(); //Imprime Tabuleiro 1
    gotoxy(0,25);
    a.printarTabuleiro(); // Imprime Tabuleiro 2

    b.printar_CARRIER(2, 10, 0); // Por algum motivo, a casa A0 tem y=10, diferente do esperado (y=28)

    while(true){ //Permite mover o cursor "infinitamente"
        a.mover(q1,w1);
    }
}
