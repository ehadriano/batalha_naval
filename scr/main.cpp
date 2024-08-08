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
 * @file main.cpp
 * @brief Implementação da função main.
 */
/**
 * @brief Função principal do jogo de batalha naval.
 *
 * Inicializa os objetos do jogo, configura o console e controla o loop principal do jogo.
 *
 * @return int Código de retorno do programa.
 */
int main() {
    srand(time(NULL));
    bool playAgain = true;

    while (playAgain) {
        inimigo a;
        jogador b;
        menu a1;
        configurarConsole();
        inicializarJogo(a, b, a1);

        int q1 = 2, w1 = 3, q2 = 2, w2 = 28;
        int Nave1 = 1, Nave = 1, cam = 0;
        int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 1;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        int c1, c2, c3, c4;
        int op;
        bool gameover = true;

        while (gameover) {
            if (Nave1 >= 2 && Nave1 <= 7) Nave = Nave1;

            if (verificarVitoria(a, op, gameover) || verificarDerrota(b, op, gameover)) {
                if (!gameover) break;
                if (op == 1) {
                    system("cls");
                    break; // Sai do loop interno para reiniciar o jogo
                } else {
                    playAgain = false;
                    break;
                }
            }

            atualizarNavios(b, p1, p2, p3, p4, p5, x1, y1, c1, x2, y2, c2, x3, y3, c3, x4, y4, c4);

            if (kbhit()) {
                char tecla = getch();
                processarTecla(tecla, cam, Nave, b, q2, w2, p1, p2, p3, p4, Nave1, x1, y1, c1, x2, y2, c2, x3, y3, c3, x4, y4, c4, a, q1, w1);
            }

            moverNavios(b, Nave, q2, w2, cam);
            realizarAcoes(a, b, Nave, p5, Nave1, q1, w1, b);

            Sleep(20);
        }
    }
}