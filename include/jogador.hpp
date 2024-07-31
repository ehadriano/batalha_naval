#ifndef JOGADOR_HPP
#define JOGADOR_HPP

struct coord{ //Coordenadas

    int x, y;

};

struct peca{ //Peça

    coord original;
    coord perifericos [3];
    char D;

};

class jogador{ 

    public:

        void printar(peca &);
        void rotacionar(peca &); //Função responsável pela rotação da peça
        coord rotacionar(coord &); //Embora tenha um nome parecido com void rotaciona, é outra função completamente diferente

};

#endif // JOGADOR_HPP
