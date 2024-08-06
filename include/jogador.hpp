#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../include/utilitarios.hpp"

// Classe que representa um jogador no jogo de batalha naval
class jogador {
private:
    // Variáveis privadas da classe jogador
    int mapa1, mapa = 28;
    int matriz1, matriz = 2;
    int ca;
    int x1, y1;
    int x2, y2, f, f1;
    int x3, y3, r = 1;
    char dato;
    int turno = 1, turno1;
    int ver;
    int vidaJO = 0;

public:
    // Retorna a vida atual do jogador
    int retornarVidaJO() { return vidaJO; }

    // Imprime o tabuleiro do jogador
    void printarTabuleiroJO();
    
    // Captura a coordenada X
    int capturaX() { return x1; }

    // Captura a coordenada Y
    int capturaY() { return y1; }

    // Obtém uma coordenada aleatória
    int obter();
    
    // Métodos para manipulação do navio CARRIER
    void printarCARRIER(int &, int &, int);
    void apagarCARRIER(int &, int &, int);
    void moverCARRIER(int &, int &, int);
    void printarCARRIER_Permanente(int, int, int);

    // Métodos para manipulação do navio TANKER
    void printarTANKER(int &, int &, int);
    void apagarTANKER(int &, int &, int);
    void moverTANKER(int &, int &, int);
    void pintarTANKER_Permanente(int, int, int);

    // Métodos para manipulação do navio DESTROYER
    void printarDESTROYER(int &, int &, int);
    void apagarDESTROYER(int &, int &, int);
    void moverDESTROYER(int &, int &, int);
    void printarDESTROYER_Permanente(int, int, int);

    // Métodos para manipulação do navio SUBMARINE
    void printarSUBMARINE(int &x, int &y, int c);
    void apagarSUBMARINE(int &x, int &y, int c);
    void moverSUBMARINE(int &, int &, int);
    void printarSUBMARINE_Permanente(int, int, int);
    
    // Converte coordenadas da matriz para coordenadas do tabuleiro
    int converterMatriz(int);

    // Converte coordenadas do tabuleiro para coordenadas da matriz
    int converterTabuleiro(int);

    // IA: Obtém coordenadas para jogada automática
    int IAobter();

    // IA: Gera jogadas
    int IAgeneral();

    // IA: Define dificuldade da IA
    int IAdificuldade(char);

    // IA: Verifica a jogada da IA
    int IAverificar(int, int);
};

#endif // JOGADOR_HPP
