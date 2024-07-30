#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cursor.hpp"

using namespace std;

//Criar classe auxiliar futuramente!!
void gotoxy(int x, int y){ //
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}


//Modelo de tabuleiro ----> Criar uma classe Tabuleiro futuramente
char ma[22][22] =   {{' ',' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H',' ','I',' ','J',' '},
                    {' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' '},
                    {'0','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'1','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'2','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'3','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'4','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'5','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'6','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'7','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'8','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
                    {'9','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
                    {' ',' ','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' '},};


//cursor.cpp
void::cursor::printarTabuleiro(){

    for(int i = 0; i < 22; i++){
        cout << endl;
        for(int j = 0; j < 22; j++){
            cout << ma[i][j];
        }
    }

}
void::cursor::printarCursor(int x, int y){

    gotoxy(x,y);cout << "0";

}
void::cursor::apagarCursor(int x, int y){ //Posiciona um espaço em branco logo atrás da posição atual do cursor

    gotoxy(x,y) ; cout << " ";

}
/*
1) Usa da lib conio.h para mover o cursor no console.
2) Para que o cursos não apague o Tabuleiro, as variáveis x e y devem ser aumentadas ou diminuidas em 2 unidades.
3) Adicionei limites aos movimentos do cursor, agora ele não pode sair do Tabuleiro.
*/
void::cursor::moverCursor(int &x, int &y){

    if(kbhit()){
        cursor::apagarCursor(x,y);
        char tecla = getch();
        if(tecla == 'a' && x>2) x=x-2;
        if(tecla == 'd' && x<20) x=x+2;
        if(tecla == 'w' && y>3) y=y-2;
        if(tecla == 's' && y<21) y=y+2;
        cursor::printarCursor(x,y);
    }
}