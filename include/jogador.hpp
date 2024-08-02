#ifndef JOGADOR_HPP
#define JOGADOR_HPP

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

        void printar(peca &);
        void apagar( peca &);
        void rotacionar(peca &);
        coord rotacionar(coord &);
        void selecionar(peca &, int);
        void mover(peca &);
        bool colisao(peca &);

};

#endif // JOGADOR_HPP
