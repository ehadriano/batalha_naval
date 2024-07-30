#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/cursor.hpp"

using namespace std;

int main(){

    cursor a;
    int q1=2, w1=3;

    a.printarTabuleiro();

    while(true){
        a.moverCursor(q1,w1);
    }

return 0;
}