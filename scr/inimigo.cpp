#include "../include/inimigo.hpp"
#include "../include/matrizes.hpp"
#include "../include/config.hpp"
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iostream>

using namespace std;


/*Imprime o estado atual do tabuleiro de batalha do inimigo (MA) na tela, iterando através de uma matriz de 22x22 e imprimindo cada valor. */
void inimigo::printarTabuleiro() {
    for (int i = 0; i < 22; i++) {
        cout << endl;
        for (int j = 0; j < 22; j++) {
            cout << MA[i][j];
        }
    }
}

/* Imprime o estado atual do tabuleiro interno do inimigo (en) na tela, semelhante à função anterior, mas para a matriz en. */
void inimigo::printarTabuleiroIN() {
    for (int i = 0; i < 22; i++) {
        cout << endl;
        for (int j = 0; j < 22; j++) {
            cout << en[i][j];
        }
    }
}

/* Apaga o caractere na posição (x, y) do cursor no tabuleiro movendo o cursor para essa posição e imprimindo um espaço. */
void inimigo::apagar(int &x, int &y) {
    gotoxy(x, y); cout << " ";
}

/* Imprime o caractere '>' na posição (x, y) do cursor no tabuleiro, representando a posição atual do cursor. */
void inimigo::printar(int &x, int &y) {
    gotoxy(x, y); cout << ">";
}

/* Move o cursor pelo tabuleiro baseado nas entradas do teclado (setas de direção). Se uma tecla for pressionada (kbhit()), 
a função apaga a posição anterior do cursor e atualiza a nova posição baseada na tecla pressionada. */
void inimigo::mover(int &x, int &y) {
    if (kbhit()) {
        int d = y - 1;
        if (en[d][x] != 'X' && en[d][x] != 'O') apagar(x, y);
        char tecla = getch();
        if (tecla == ESQUERDA && x > 2) x = x - 2;
        if (tecla == DIREITA && x < 20) x = x + 2;
        if (tecla == CIMA && y > 3) y = y - 2;
        if (tecla == BAIXO && y < 20) y = y + 2;
        d = y - 1;
        if (en[d][x] != 'X' && en[d][x] != 'O') printar(x, y);
    }
}

/* Gera e retorna uma coordenada X aleatória par entre 2 e 20 usando rand(). Continua gerando números até encontrar um par. */
int inimigo::obterX(int c, int v) {
    (void)c;
    (void)v;
    int x;
    do {
        x = rand() % 19 + 2;
    } while (x % 2 != 0);
    return x;
}

/* Gera e retorna uma coordenada Y aleatória par entre 2 e 20 usando rand(). Continua gerando números até encontrar um par. */
int inimigo::obterY(int c, int v) {
    (void)c;
    (void)v;
    int y;
    do {
        y = rand() % 19 + 2;
    } while (y % 2 != 0);
    return y;
}

/* Retorna uma direção aleatória (0 ou 1) usando rand(), onde 0 representa vertical e 1 representa horizontal. */
int inimigo::obterC() {
    return rand() % 2;
}

/* Imprime o porta-aviões (Carrier) no tabuleiro na posição (x, y) e direção c. 
Se c for 0, o navio é colocado verticalmente; 
se for 1, horizontalmente. O porta-aviões ocupa 4 posições. */
void inimigo::printarCARRIER(int x, int y, int c) {
    for (int i = 0; i < 4; ++i) {
        if (c == 0) {
            en[y + 2*i][x] = 'C';
        } else {
            en[y][x + 2*i] = 'C';
        }
    }
}

/* mprime o navio tanque (Tanker) no tabuleiro na posição (x, y) e direção c. 
Se c for 0, o navio é colocado verticalmente; 
se for 1, horizontalmente. O navio tanque ocupa 3 posições. */
void inimigo::printarTANKER(int x, int y, int c) {
    for (int i = 0; i < 3; ++i) {
        if (c == 0) {
            en[y + 2*i][x] = 'T';
        } else {
            en[y][x + 2*i] = 'T';
        }
    }
}

/* Imprime o Destroyer no tabuleiro na posição (x, y) e direção c. 
Se c for 0, o navio é colocado verticalmente; 
se for 1, horizontalmente. O destruidor ocupa 3 posições.*/
void inimigo::printarDESTROYER(int x, int y, int c) {
    for (int i = 0; i < 3; ++i) {
        if (c == 0) {
            en[y + 2*i][x] = 'D';
        } else {
            en[y][x + 2*i] = 'D';
        }
    }
}

/* Imprime o Submarino no tabuleiro na posição (x, y) e direção c. O submarino ocupa 2 posições, com a segunda posição dependendo da direção c.*/
void inimigo::printarSUBMARINE(int x, int y, int c) {
    en[y][x] = 'S';
}

/* Imprime todos os navios do inimigo no tabuleiro em posições válidas, evitando sobreposição. 
Coloca cada tipo de navio (Carrier, Tanker, Destroyer, Submarine) em posições aleatórias usando as funções obterX, obterY e obterC.*/
void inimigo::printarNavios() {
    // Coloca o porta-aviões (Carrier)
    int c1 = obterC();
    int x1 = obterX(c1, 1);
    int y1 = obterY(c1, 1);
    printarCARRIER(x1, y1, c1);


    // Coloca o navio tanque (Tanker)
    while (true) {
        int c2 = obterC();
        int x2 = obterX(c2, 2);
        int y2 = obterY(c2, 2);
        if ((c2 == 0 && en[y2][x2] != 'P' && en[y2 + 2][x2] != 'P' && en[y2 + 4][x2] != 'P') ||
            (c2 == 1 && en[y2][x2] != 'P' && en[y2][x2 + 2] != 'P' && en[y2][x2 + 4] != 'P')) {
            printarTANKER(x2, y2, c2);
            break;
        }
    }

    // Coloca o destruidor (Destroyer)
    while (true) {
        int c3 = obterC();
        int x3 = obterX(c3, 2);
        int y3 = obterY(c3, 2);
        if ((c3 == 0 && en[y3][x3] != 'P' && en[y3 + 2][x3] != 'P' && en[y3 + 4][x3] != 'P' && 
             en[y3][x3] != 'S' && en[y3 + 2][x3] != 'S' && en[y3 + 4][x3] != 'S') ||
            (c3 == 1 && en[y3][x3] != 'P' && en[y3][x3 + 2] != 'P' && en[y3][x3 + 4] != 'P' && 
             en[y3][x3] != 'S' && en[y3][x3 + 2] != 'S' && en[y3][x3 + 4] != 'S')) {
            printarDESTROYER(x3, y3, c3);
            break;
        }
    }

    // Coloca o submarino (Submarine)
    while (true) {
        int c4 = obterC();
        int x4 = obterX(c4, 0);
        int y4 = obterY(c4, 0);
        if ((c4 == 0 && en[y4][x4] != 'P' && en[y4][x4] != 'S' && en[y4][x4] != 'D') ||
            (c4 == 1 && en[y4][x4] != 'P' && en[y4][x4] != 'S' && en[y4][x4] != 'D')) {
            printarSUBMARINE(x4, y4, c4);
            break;
        }
    }
}


/* Registra um disparo no tabuleiro do inimigo na posição (x, y). 
Se um navio for atingido, a posição é marcada como 'O' e a vida do inimigo (vidaIN) é incrementada. 
Se o disparo não atingir um navio, a posição é marcada como 'X'. */
void inimigo::disparo(int x, int y) {
    y = y - 1;
    if (en[y][x] == 'C' || en[y][x] == 'T' || en[y][x] == 'D' || en[y][x] == 'S' || en[y][x] == 'O') {
        en[y][x] = 'O';
        y = y + 1;
        gotoxy(x, y); std::cout << "O";
        vidaIN = vidaIN + 1;
    } else {
        en[y][x] = 'X';
        y = y + 1;
        gotoxy(x, y); std::cout << "X";
    }
}
