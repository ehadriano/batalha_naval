#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cursor.hpp"

using namespace std;

/*TESTE: essa função me permite comandar a posição inicial do cursor, vou testar inicialmente nas coordenadas 5,5*/
void gotoxy(int x, int y){ //
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}

void::cursor::printarCursor(int x, int y){

    gotoxy(x,y);cout << "0";

}
void::cursor::moverCursor(int x, int y){ //Usa da lib conio.h para mover o cursor no console

    if(kbhit()){
        char tecla = getch();
        if(tecla == 'a') x--;
        if(tecla == 'd') x++;
        if(tecla == 'w') y--;
        if(tecla == 's') y++;
        cursor::printarCursor(x,y);
    }
}