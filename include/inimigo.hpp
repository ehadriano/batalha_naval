#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include <windows.h>

// Função para mover o cursor no console para uma posição específica
void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

struct coord{ //Coordenadas
    int x, y;
};

struct peca{ //Peça
    coord original;
    coord perifericos[3];
    char D;
    char d = '*';
    coord posicao(int n); //Posição
};

char en[22][22];

class inimigo{ //Métodos semelhantes a classe jogador
    public:
        void desenharMapaen();
        void printar(peca &, int);
        void apagar(peca &);
        void selecionar(peca &, int);
        void mover(peca &, int &);
        bool colisao(peca &);
};

#endif // INIMIGO_HPP