#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../include/utilitarios.hpp"

/**
 * @file jogador.hpp
 * @brief Declaração da classe jogador, que representa um jogador no jogo de batalha naval.
 *
 * A classe jogador contém métodos e variáveis para gerenciar o tabuleiro, navios e ações do jogador no jogo.
 */

/**
 * @class jogador
 * @brief Classe que representa um jogador no jogo de batalha naval.
 *
 * A classe contém métodos para manipulação do tabuleiro do jogador, gerenciamento dos navios e interação com o sistema de jogo.
 */
class jogador {
private:

    // Variáveis privadas da classe jogador
    int mapa1, mapa = 28; ///< Estado do mapa do jogador
    int matriz1, matriz = 2; ///< Estado da matriz do tabuleiro
    int ca; ///< Variável auxiliar para manipulação de coordenadas
    int x1, y1; ///< Coordenadas X e Y para manipulação de navios
    int x2, y2, f, f1; ///< Coordenadas e variáveis auxiliares adicionais
    int x3, y3, r = 1; ///< Coordenadas e variáveis auxiliares adicionais
    char dato; ///< Armazena um caractere temporário
    int turno = 1, turno1; ///< Controle dos turnos do jogo
    int ver; ///< Variável para verificação de estado
    int vidaJO = 0; ///< Contador de vida (número de acertos nos navios do jogador)

public:

    /**
     * @brief Retorna a vida atual do jogador.
     * @return A vida atual do jogador.
     */
    int retornarVidaJO() { return vidaJO; }

    /**
     * @brief Método que contabiliza os disparos no tabuleiro do jogador.
     * 
     * @param x Coordenada X do disparo.
     * @param y Coordenada Y do disparo.
     */
    void disparo(int x, int y);

    /**
     * @brief Imprime o tabuleiro do jogador.
     */
    void printarTabuleiroJO();
    
    /**
     * @brief Captura a coordenada X.
     * @return A coordenada X.
     */
    int capturaX() { return x1; }

    /**
     * @brief Captura a coordenada Y.
     * @return A coordenada Y.
     */
    int capturaY() { return y1; }

    /**
     * @brief Obtém uma coordenada aleatória.
     * @return Uma coordenada aleatória.
     */
    int obter();

    // Métodos para manipulação do navio CARRIER
    /**
     * @brief Imprime o navio CARRIER no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio CARRIER.
     */
    void printarCARRIER(int &x, int &y, int c);

    /**
     * @brief Apaga o navio CARRIER do tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio CARRIER.
     */
    void apagarCARRIER(int &x, int &y, int c);

    /**
     * @brief Move o navio CARRIER no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio CARRIER.
     */
    void moverCARRIER(int &x, int &y, int c);

    /**
     * @brief Imprime permanentemente o navio CARRIER no tabuleiro.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio CARRIER.
     */
    void printarCARRIER_Permanente(int x, int y, int c);

    // Métodos para manipulação do navio TANKER
    /**
     * @brief Imprime o navio TANKER no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio TANKER.
     */
    void printarTANKER(int &x, int &y, int c);

    /**
     * @brief Apaga o navio TANKER do tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio TANKER.
     */
    void apagarTANKER(int &x, int &y, int c);

    /**
     * @brief Move o navio TANKER no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio TANKER.
     */
    void moverTANKER(int &x, int &y, int c);

    /**
     * @brief Imprime permanentemente o navio TANKER no tabuleiro.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio TANKER.
     */
    void pintarTANKER_Permanente(int x, int y, int c);

    // Métodos para manipulação do navio DESTROYER
    /**
     * @brief Imprime o navio DESTROYER no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio DESTROYER.
     */
    void printarDESTROYER(int &x, int &y, int c);

    /**
     * @brief Apaga o navio DESTROYER do tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio DESTROYER.
     */
    void apagarDESTROYER(int &x, int &y, int c);

    /**
     * @brief Move o navio DESTROYER no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio DESTROYER.
     */
    void moverDESTROYER(int &x, int &y, int c);

    /**
     * @brief Imprime permanentemente o navio DESTROYER no tabuleiro.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio DESTROYER.
     */
    void printarDESTROYER_Permanente(int x, int y, int c);

    // Métodos para manipulação do navio SUBMARINE
    /**
     * @brief Imprime o navio SUBMARINE no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio SUBMARINE.
     */
    void printarSUBMARINE(int &x, int &y, int c);

    /**
     * @brief Apaga o navio SUBMARINE do tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio SUBMARINE.
     */
    void apagarSUBMARINE(int &x, int &y, int c);

    /**
     * @brief Move o navio SUBMARINE no tabuleiro.
     * @param x Referência à coordenada X do navio.
     * @param y Referência à coordenada Y do navio.
     * @param c Identificador do navio SUBMARINE.
     */
    void moverSUBMARINE(int &x, int &y, int c);

    /**
     * @brief Imprime permanentemente o navio SUBMARINE no tabuleiro.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param c Identificador do navio SUBMARINE.
     */
    void printarSUBMARINE_Permanente(int x, int y, int c);
    
    /**
     * @brief Apaga um navio do tabuleiro.
     * @param x Coordenada X do navio.
     * @param y Coordenada Y do navio.
     * @param cam Caminho do navio.
     * @param tipo Tipo de navio.
     */
    void apagarNavio(int x, int y, int cam, int tipo);
    
    /**
     * @brief Converte coordenadas da matriz para coordenadas do tabuleiro.
     * @param coord Coordenada na matriz.
     * @return Coordenada correspondente no tabuleiro.
     */
    int converterMatriz(int coord);

    /**
     * @brief Converte coordenadas do tabuleiro para coordenadas da matriz.
     * @param coord Coordenada no tabuleiro.
     * @return Coordenada correspondente na matriz.
     */
    int converterTabuleiro(int coord);

    // IA: Métodos relacionados à inteligência artificial

    /**
     * @brief IA: Obtém coordenadas para jogada automática.
     * @return Coordenada gerada automaticamente.
     */
    int IAobter();

    /**
     * @brief IA: Gera jogadas automáticas.
     * @return Jogada gerada automaticamente.
     */
    int IAgeneral();

    /**
     * @brief IA: Define a dificuldade da IA.
     * @param dificuldade Nível de dificuldade da IA.
     * @return A dificuldade configurada.
     */
    int IAdificuldade(char dificuldade);

    /**
     * @brief IA: Verifica a jogada da IA.
     * @param x Coordenada X da jogada.
     * @param y Coordenada Y da jogada.
     * @return Resultado da verificação.
     */
    int IAverificar(int x, int y);
};

#endif // JOGADOR_HPP
