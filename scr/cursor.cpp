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

void cursor::printarCursor(){

    gotoxy(5,5); cout << "O";

}