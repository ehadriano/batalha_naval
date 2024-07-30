#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cursor.hpp"

using namespace std;

//jogado.cpp
void jogador::printar_Carrier(int x, int y, int c){ //Se c=0, Carrier na vertical
    for (int i = 0; i < 4; ++i) {
        if (c == 0) { // Vertical
            gotoxy(x, y + 2 * i);
        } else { // Horizontal
            gotoxy(x + 2 * i, y);
        }
        cout << "C";
    }
}