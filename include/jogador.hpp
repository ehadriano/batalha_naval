#ifndef JOGADOR_HPP
#define JOGADOR_HPP

struct coord{ //Coordenadas

    int x, y;

};

struct peca{ //Era para ser 'Peça'

    coord original;
    coord perifericos [3];
    char D;

};

class jogador{ //Tentativa de tornar o código menor

    public:

        void printar(peca &);

};

#endif // JOGADOR_HPP
