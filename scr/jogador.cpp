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
void jogador::apagar_Carrier(int x, int y, int c){ //Mesma lógica da função jogador::printar_Carrier, só que coloca um espaço vazio
    for (int i = 0; i < 4; ++i) {
        if (c == 0) { // Vertical
            gotoxy(x, y + 2 * i);
        } else { // Horizontal
            gotoxy(x + 2 * i, y);
        }
        cout << " ";
    }
}
void jogador::mover_Carrier(int &x, int &y, int c){
    if(kbhit()){
        jogador::apagar_Carrier(x,y,c);
        char tecla = getch();
        if(tecla == 'a' && x>2) x=x-2;
        if(tecla == 'd' && x<20) x=x+2;
        if(tecla == 'w' && y>3) y=y-2;
        if(tecla == 's' && y<21) y=y+2;
        jogador::printar_Carrier(x,y,c);
    }
}