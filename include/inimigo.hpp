#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "../include/jogador.hpp"

// Classe que representa um inimigo no jogo de batalha naval, herda da classe jogador
class inimigo : public jogador {
private:

    // Variáveis privadas da classe inimigo
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    int c1, c2, c3, c4;
    int x, y, c;
    int d;
    int vidaIN = 0;

public:
    
    // Retorna a vida atual do inimigo
    int retornarVidaIN() { return vidaIN; }
    
    // Imprime o tabuleiro do inimigo
    void printarTabuleiro();

    // Imprime o tabuleiro interno do inimigo
    void printarTabuleiroIN();

     // Funções para manipular a posição e estado de disparo
    void printar(int &, int &);
    void apagar(int &, int &);
    void mover(int &, int &);

    // Funções para obter coordenadas e direção
    int obterX(int, int);
    int obterY(int, int);
    int obterC();

    // Função para imprimir todos os navios do inimigo
    void printarNavios();

    // Funções para imprimir navios específicos
    void printarCARRIER(int, int, int);
    void printarTANKER(int, int, int);
    void printarDESTROYER(int, int, int);
    void printarSUBMARINE(int, int, int);

    // Função para registrar disparo
    void disparo(int, int);
};

#endif // INIMIGO_HPP
