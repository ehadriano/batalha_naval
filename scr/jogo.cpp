#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "../include/utilitarios.hpp"
#include "../include/jogador.hpp"
#include "../include/inimigo.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

using namespace std;

/**
 * @file jogo.cpp
 * @brief Implementação das funções responsáveis pelo funcionamento do jogo.
 */
/**
 * @brief Configura o console para o jogo.
 *
 * Define a cor do console e oculta o cursor.
 */
void configurarConsole() {
    system("color 90");
    ocultarCursor();
}

/**
 * @brief Inicializa o jogo.
 *
 * Exibe as telas iniciais e de objetivo, imprime os tabuleiros e exibe as instruções.
 *
 * @param a Referência ao objeto inimigo.
 * @param b Referência ao objeto jogador.
 * @param a1 Referência ao objeto menu.
 */
void inicializarJogo(inimigo& a, jogador& b, menu& a1) {
    a1.TELA_INICIAL();
    system("cls");
    a1.OBJETIVO();
    system("cls");
    a.printarTabuleiro();
    gotoxy(0, 25);
    a.printarTabuleiro();
    a1.INSTRUCOES();
}

/**
 * @brief Verifica se o jogador ganhou o jogo.
 *
 * Verifica a vida do inimigo e, se for igual a 11, exibe a mensagem de vitória e pergunta se o jogador deseja jogar novamente.
 *
 * @param a Referência ao objeto inimigo.
 * @param op Referência à opção de reiniciar o jogo.
 * @param gameover Referência à variável que indica se o jogo acabou.
 * @return true se o jogador deseja jogar novamente, false caso contrário.
 */
bool verificarVitoria(inimigo& a, int& op, bool& gameover) {
    if (a.retornarVidaIN() == 11) {
        system("cls");
        gotoxy(10, 10); cout << "VOCE GANHOU!";
        gotoxy(10, 12); cout << "DESEJA JOGAR NOVAMENTE?";
        gotoxy(10, 14); cout << "1. sim  / 2. nao";
        cin >> op;
        if (op == 1) return true;
        else gameover = false;
    }
    return false;
}

/**
 * @brief Verifica se o jogador perdeu o jogo.
 *
 * Verifica a vida do jogador e, se for igual a 11, exibe a mensagem de derrota e pergunta se o jogador deseja jogar novamente.
 *
 * @param b Referência ao objeto jogador.
 * @param op Referência à opção de reiniciar o jogo.
 * @param gameover Referência à variável que indica se o jogo acabou.
 * @return true se o jogador deseja jogar novamente, false caso contrário.
 */
bool verificarDerrota(jogador& b, int& op, bool& gameover) {
    if (b.retornarVidaJO() == 11) {
        system("cls");
        gotoxy(10, 10); cout << "VOCE PERDEU!";
        gotoxy(10, 12); cout << "DESEJA JOGAR NOVAMENTE?";
        gotoxy(10, 14); cout << "1. sim  / 2. nao";
        cin >> op;
        if (op == 1) return true;
        else gameover = false;
    }
    return false;
}

/**
 * @brief Processa a tecla pressionada pelo jogador.
 *
 * Processa as teclas 'c', 'x' e 'z' para alternar a direção do navio, colocar um navio e disparar, respectivamente.
 *
 * @param tecla A tecla pressionada.
 * @param cam Referência à variável que indica a direção do navio.
 * @param Nave Referência à variável que indica o tipo de navio.
 * @param b Referência ao objeto jogador.
 * @param q2 Coordenada x do navio.
 * @param w2 Coordenada y do navio.
 * @param p1 Estado do primeiro navio.
 * @param p2 Estado do segundo navio.
 * @param p3 Estado do terceiro navio.
 * @param p4 Estado do quarto navio.
 * @param Nave1 Referência à variável que controla a sequência do jogo.
 * @param x1 Coordenada x do primeiro navio.
 * @param y1 Coordenada y do primeiro navio.
 * @param c1 Direção do primeiro navio.
 * @param x2 Coordenada x do segundo navio.
 * @param y2 Coordenada y do segundo navio.
 * @param c2 Direção do segundo navio.
 * @param x3 Coordenada x do terceiro navio.
 * @param y3 Coordenada y do terceiro navio.
 * @param c3 Direção do terceiro navio.
 * @param x4 Coordenada x do quarto navio.
 * @param y4 Coordenada y do quarto navio.
 * @param c4 Direção do quarto navio.
 * @param a Referência ao objeto inimigo.
 * @param q1 Coordenada x do disparo.
 * @param w1 Coordenada y do disparo.
 */
void processarTecla(char tecla, int& cam, int& Nave, jogador& b, int& q2, int& w2, int& p1, int& p2, int& p3, int& p4, int& Nave1, int& x1, int& y1, int& c1, int& x2, int& y2, int& c2, int& x3, int& y3, int& c3, int& x4, int& y4, int& c4, inimigo& a, int& q1, int& w1) {
    if (tecla == 'c') {
        b.apagarNavio(q2, w2, cam, Nave);
        cam = !cam;
        q2 = 2;
        w2 = 28;
    }
    if (tecla == 'x' && Nave < 5) {
        b.apagarNavio(q2, w2, cam, Nave);
        q2 = 2;
        w2 = 28;
        if (Nave == 1) { p1 = 1; x1 = b.capturaX(); y1 = b.capturaY(); c1 = cam; }
        if (Nave == 2) { p2 = 2; x2 = b.capturaX(); y2 = b.capturaY(); c2 = cam; }
        if (Nave == 3) { p3 = 3; x3 = b.capturaX(); y3 = b.capturaY(); c3 = cam; }
        if (Nave == 4) { p4 = 4; x4 = b.capturaX(); y4 = b.capturaY(); c4 = cam; }
        Nave1++;
    }
    if (tecla == 'z') {
        a.disparo(q1, w1);
        Nave1 = 7;
    }
}

/**
 * @brief Atualiza a posição dos navios no tabuleiro do jogador.
 *
 * @param b Referência ao objeto jogador.
 * @param p1 Estado do primeiro navio.
 * @param p2 Estado do segundo navio.
 * @param p3 Estado do terceiro navio.
 * @param p4 Estado do quarto navio.
 * @param p5 Estado do quinto navio.
 * @param x1 Coordenada x do primeiro navio.
 * @param y1 Coordenada y do primeiro navio.
 * @param c1 Direção do primeiro navio.
 * @param x2 Coordenada x do segundo navio.
 * @param y2 Coordenada y do segundo navio.
 * @param c2 Direção do segundo navio.
 * @param x3 Coordenada x do terceiro navio.
 * @param y3 Coordenada y do terceiro navio.
 * @param c3 Direção do terceiro navio.
 * @param x4 Coordenada x do quarto navio.
 * @param y4 Coordenada y do quarto navio.
 * @param c4 Direção do quarto navio.
 */
void atualizarNavios(jogador& b, int p1, int p2, int p3, int p4, int p5, int x1, int y1, int c1, int x2, int y2, int c2, int x3, int y3, int c3, int x4, int y4, int c4) {
    if (p5 == 1) {
        if (p1 == 1) b.printarCARRIER_Permanente(x1, y1, c1);
        if (p2 == 2) b.pintarTANKER_Permanente(x2, y2, c2);
        if (p3 == 3) b.printarDESTROYER_Permanente(x3, y3, c3);
        if (p4 == 4) b.printarSUBMARINE_Permanente(x4, y4, c4);
    }
}

/**
 * @brief Move os navios no tabuleiro do jogador.
 *
 * @param b Referência ao objeto jogador.
 * @param Nave Tipo do navio.
 * @param q2 Coordenada x do navio.
 * @param w2 Coordenada y do navio.
 * @param cam Direção do navio (0 para vertical, 1 para horizontal).
 */
void moverNavios(jogador& b, int Nave, int& q2, int& w2, int cam) {
    if (Nave == 1) b.moverCARRIER(q2, w2, cam);
    if (Nave == 2) b.moverTANKER(q2, w2, cam);
    if (Nave == 3) b.moverDESTROYER(q2, w2, cam);
    if (Nave == 4) b.moverSUBMARINE(q2, w2, cam);
}

/**
 * @brief Realiza ações do jogo como posicionar navios e processar jogadas da IA.
 *
 * @param a Referência ao objeto inimigo.
 * @param b Referência ao objeto jogador.
 * @param Nave Tipo do navio.
 * @param p5 Estado do quinto navio.
 * @param Nave1 Referência à variável que controla a sequência do jogo.
 * @param q1 Coordenada x do disparo.
 * @param w1 Coordenada y do disparo.
 * @param j Referência a um segundo objeto jogador (possivelmente para multiplayer).
 */
void realizarAcoes(inimigo& a, jogador& b, int& Nave, int& p5, int& Nave1, int& q1, int& w1, jogador& j) {
    if (Nave == 5) {
        a.printarNavios();
        p5 = 2;
        Nave1 = 6;
    }
    if (Nave == 6) {
        a.mover(q1, w1);
        gotoxy(0, 25);
        a.printarTabuleiroJO();
    }
    if (Nave == 7) {
        b.IAgeneral();
        gotoxy(0, 25);
        a.printarTabuleiroJO();
        Sleep(30);
        Nave1 = 6;
    }
}
