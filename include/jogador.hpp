#ifndef JOGADOR_HPP
#define JOGADOR_HPP

//jogador.hpp
void gotoxy(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}

char ju[22][22];

struct coord{ //Coordenadas

    int x, y;

};
struct peca{ //Peça

    coord original;
    coord perifericos [3];
    char D;
    coord posicao(int n); //Posição

};
class jogador{ //Tentativa de tornar o código menor

    public:

        void passarTabuleiro();
        void desenharMapaju();
        void printar(peca &);
        void apagar( peca &);
        void rotacionar(peca &);
        coord rotacionar(coord &);
        void selecionar(peca &, int);
        void mover(peca &);
        bool colisao(peca &);

};
#endif // JOGADOR_HPP
