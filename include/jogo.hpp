#ifndef JOGO_HPP
#define JOGO_HPP

#include "../include/jogador.hpp"
#include "../include/inimigo.hpp"
#include "../include/menu.hpp"

/**
 * @file jogo.hpp
 * @brief Declaração das funções principais para o jogo de batalha naval.
 *
 * Este arquivo contém a declaração das funções que configuram o console, inicializam o jogo,
 * verificam condições de vitória e derrota, processam entrada de teclas, atualizam e movem navios,
 * e realizam ações principais do jogo.
 */

/**
 * @brief Configura as propriedades do console, como o tamanho da tela e as cores.
 */
void configurarConsole();

/**
 * @brief Inicializa o jogo, configurando os tabuleiros do jogador e do inimigo, e mostrando o menu inicial.
 * 
 * @param a Referência ao objeto inimigo.
 * @param b Referência ao objeto jogador.
 * @param a1 Referência ao objeto menu.
 */
void inicializarJogo(inimigo& a, jogador& b, menu& a1);

/**
 * @brief Verifica se o jogador venceu o jogo ao destruir todos os navios do inimigo.
 * 
 * @param a Referência ao objeto inimigo.
 * @param op Referência à variável de opção para jogar novamente.
 * @param gameover Referência ao estado de término do jogo.
 * @return true Se o jogador venceu.
 * @return false Se o jogo ainda não terminou.
 */
bool verificarVitoria(inimigo& a, int& op, bool& gameover);

/**
 * @brief Verifica se o jogador perdeu o jogo ao ter todos os seus navios destruídos.
 * 
 * @param b Referência ao objeto jogador.
 * @param op Referência à variável de opção para jogar novamente.
 * @param gameover Referência ao estado de término do jogo.
 * @return true Se o jogador perdeu.
 * @return false Se o jogo ainda não terminou.
 */
bool verificarDerrota(jogador& b, int& op, bool& gameover);

/**
 * @brief Processa a tecla pressionada pelo jogador e realiza ações baseadas na tecla.
 * 
 * @param tecla A tecla pressionada pelo jogador.
 * @param cam Referência à variável de controle de movimento.
 * @param Nave Referência ao navio atual do jogador.
 * @param b Referência ao objeto jogador.
 * @param q2, w2 Coordenadas para movimentação.
 * @param p1, p2, p3, p4 Parâmetros adicionais para controle de navios.
 * @param Nave1 Referência ao segundo navio do jogador.
 * @param x1, y1, c1 Coordenadas e contador para o primeiro navio.
 * @param x2, y2, c2 Coordenadas e contador para o segundo navio.
 * @param x3, y3, c3 Coordenadas e contador para o terceiro navio.
 * @param x4, y4, c4 Coordenadas e contador para o quarto navio.
 * @param a Referência ao objeto inimigo.
 * @param q1, w1 Coordenadas adicionais para movimentação.
 */
void processarTecla(char tecla, int& cam, int& Nave, jogador& b, int& q2, int& w2, int& p1, int& p2, int& p3, int& p4, int& Nave1, int& x1, int& y1, int& c1, int& x2, int& y2, int& c2, int& x3, int& y3, int& c3, int& x4, int& y4, int& c4, inimigo& a, int& q1, int& w1);

/**
 * @brief Atualiza a posição dos navios do jogador no tabuleiro.
 * 
 * @param b Referência ao objeto jogador.
 * @param p1, p2, p3, p4, p5 Parâmetros para controle de navios.
 * @param x1, y1, c1 Coordenadas e contador para o primeiro navio.
 * @param x2, y2, c2 Coordenadas e contador para o segundo navio.
 * @param x3, y3, c3 Coordenadas e contador para o terceiro navio.
 * @param x4, y4, c4 Coordenadas e contador para o quarto navio.
 */
void atualizarNavios(jogador& b, int p1, int p2, int p3, int p4, int p5, int x1, int y1, int c1, int x2, int y2, int c2, int x3, int y3, int c3, int x4, int y4, int c4);

/**
 * @brief Move os navios do jogador de acordo com os comandos recebidos.
 * 
 * @param b Referência ao objeto jogador.
 * @param Nave Referência ao navio atual do jogador.
 * @param q2, w2 Coordenadas para movimentação.
 * @param cam Referência à variável de controle de movimento.
 */
void moverNavios(jogador& b, int Nave, int& q2, int& w2, int cam);

/**
 * @brief Realiza as ações principais do jogo, como ataques e movimentações.
 * 
 * @param a Referência ao objeto inimigo.
 * @param b Referência ao objeto jogador.
 * @param Nave Referência ao navio atual do jogador.
 * @param p5 Parâmetro adicional para controle de navios.
 * @param Nave1 Referência ao segundo navio do jogador.
 * @param q1, w1 Coordenadas adicionais para movimentação.
 * @param j Referência ao objeto jogador.
 */
void realizarAcoes(inimigo& a, jogador& b, int& Nave, int& p5, int& Nave1, int& q1, int& w1, jogador& j);

#endif // JOGO_HPP
