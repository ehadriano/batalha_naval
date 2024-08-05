#ifndef JOGADOR_HPP
#define JOGADOR_HPP
using namespace std;
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
    char d = '*';
    coord posicao(int n); //Posição

};
char ju[22][22];
char ju[22][22];

class jogador{ //Tentativa de tornar o código menor

    public:
        void passarTabuleiro();
        void desenharMapaju();
        void printar(peca &, int);
        void apagar( peca &);
        void rotacionar(peca &);
        coord rotacionar(coord &);
        void selecionar(peca &, int);
        void mover(peca &, int &);
        bool colisao(peca &);
        int obterxy();
        void selecionaMapa(peca &, int);
};
#endif // JOGADOR_HPP