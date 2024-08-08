#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "../include/jogador.hpp"

/**
 * @file inimigo.hpp
 * @brief Declaração da classe inimigo, que representa um inimigo no jogo de batalha naval.
 *
 * A classe inimigo herda da classe jogador e inclui funcionalidades adicionais
 * específicas para o comportamento do inimigo no jogo.
 */

/**
 * @class inimigo
 * @brief Classe que representa um inimigo no jogo de batalha naval.
 *
 * A classe inimigo herda da classe jogador e adiciona métodos e variáveis
 * específicas para gerenciar o comportamento do inimigo.
 */
class inimigo : public jogador {
private:
    
    // Variáveis privadas da classe inimigo
    int x1, x2, x3, x4; ///< Coordenadas X dos navios do inimigo
    int y1, y2, y3, y4; ///< Coordenadas Y dos navios do inimigo
    int c1, c2, c3, c4; ///< Variáveis de controle para os navios do inimigo
    int x, y, c; ///< Coordenadas e variável de controle para operações diversas
    int d; ///< Variável auxiliar
    int vidaIN = 0; ///< Contador de vida (número de acertos nos navios do inimigo)

public:
    /**
     * @brief Retorna a vida atual do inimigo.
     * @return A vida atual do inimigo.
     */
    int retornarVidaIN() { return vidaIN; }

    /**
     * @brief Imprime o tabuleiro do inimigo.
     */
    void printarTabuleiro();

    /**
     * @brief Imprime o tabuleiro interno do inimigo.
     */
    void printarTabuleiroIN();

    /**
     * @brief Imprime a posição do disparo no tabuleiro do inimigo.
     * @param x Referência à coordenada X do disparo.
     * @param y Referência à coordenada Y do disparo.
     */
    void printar(int &x, int &y);

    /**
     * @brief Apaga a posição do disparo no tabuleiro do inimigo.
     * @param x Referência à coordenada X do disparo.
     * @param y Referência à coordenada Y do disparo.
     */
    void apagar(int &x, int &y);

    /**
     * @brief Move a posição do disparo no tabuleiro do inimigo.
     * @param x Referência à coordenada X do disparo.
     * @param y Referência à coordenada Y do disparo.
     */
    void mover(int &x, int &y);

    /**
     * @brief Obtém a coordenada X para a jogada do inimigo.
     * @param x Coordenada X base.
     * @param c Variável de controle.
     * @return A coordenada X calculada.
     */
    int obterX(int x, int c);

    /**
     * @brief Obtém a coordenada Y para a jogada do inimigo.
     * @param y Coordenada Y base.
     * @param c Variável de controle.
     * @return A coordenada Y calculada.
     */
    int obterY(int y, int c);

    /**
     * @brief Obtém a variável de controle para a jogada do inimigo.
     * @return A variável de controle.
     */
    int obterC();

    /**
     * @brief Verifica se a posição é válida para colocar um navio.
     * @param x Coordenada X inicial.
     * @param y Coordenada Y inicial.
     * @param c Comprimento do navio.
     * @param d Direção do navio.
     * @param tipo Tipo do navio.
     * @return true se a posição for válida, false caso contrário.
     */
    bool posicaoValida(int x, int y, int c, int d, char tipo);

    /**
     * @brief Método para imprimir todos os navios do inimigo.
     */
    void printarNavios();

    /**
     * @brief Imprime o navio CARRIER no tabuleiro do inimigo.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio CARRIER.
     */
    void printarCARRIER(int x, int y, int c);

    /**
     * @brief Imprime o navio TANKER no tabuleiro do inimigo.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio TANKER.
     */
    void printarTANKER(int x, int y, int c);

    /**
     * @brief Imprime o navio DESTROYER no tabuleiro do inimigo.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio DESTROYER.
     */
    void printarDESTROYER(int x, int y, int c);

    /**
     * @brief Imprime o navio SUBMARINE no tabuleiro do inimigo.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio SUBMARINE.
     */
    void printarSUBMARINE(int x, int y, int c);

    /**
     * @brief Método para registrar um disparo no tabuleiro do inimigo.
     * @param x Coordenada X do disparo.
     * @param y Coordenada Y do disparo.
     */
    void disparo(int x, int y);

};

#endif // INIMIGO_HPP
