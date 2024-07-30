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

//cursor.cpp
void::cursor::printarCursor(int x, int y){

    gotoxy(x,y);cout << "0";

}
void::cursor::apagarCursor(int x, int y){ //Posiciona um espaço em branco logo atrás da posição atual do cursor

    gotoxy(x,y) ; cout << " ";

}
void::cursor::moverCursor(int &x, int &y){ //Usa da lib conio.h para mover o cursor no console

    if(kbhit()){
        cursor::apagarCursor(x,y);
        char tecla = getch();
        if(tecla == 'a') x--;
        if(tecla == 'd') x++;
        if(tecla == 'w') y--;
        if(tecla == 's') y++;
        cursor::printarCursor(x,y);
    }
}