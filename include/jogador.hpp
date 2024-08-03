@@ -1,27 +1,29 @@
#ifndef JOGADOR_HPP
#define JOGADOR_HPP

//jogador.hpp
struct coord { //Coordenadas
struct coord{ //Coordenadas

    int x, y;

};
struct peca{ //Peça

struct peca { //Peça
    coord original;
    coord perifericos[3];
    coord perifericos [3];
    char D;
    coord posicao(int n); //Posição

};
class jogador{ //Tentativa de tornar o código menor

    public:

        void printar(peca &);
        void rotacionar(peca &);
        coord rotacionar(coord &);
        void selecionar(peca &, int);
        void mover(peca &);

class jogador { //Tentativa de tornar o código menor
public:
    void printar(peca &);
    void limpar(peca &); //Limpa a posição anterior do navio
    void rotacionar(peca &);
    coord rotacionar(coord &);
    void selecionar(peca &, int);
    void mover(peca &);
    bool dentroDoTabuleiro(peca &, char); //Garante que os navios só se possam se mover dentro do Tabuleiro
};

#endif // JOGADOR_HPP