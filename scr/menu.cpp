#include "../include/menu.hpp"
#include "../include/utilitarios.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

void menu::TELA_INICIAL() {
    char portada[20][100] = {
        "                                                                                                 ",
        "   aaaaaaaaa         aaa    aaaaaaaaaaa    aaa        aaa        aaa      aaa        aaa         ",
        "   aaa    aaa       aaaaa       aaa       aaaaa       aaa        aaa      aaa       aaaaa        ",
        "   aaa    aaa      aaa aaa      aaa      aaa aaa      aaa        aaaaaaaaaaaa      aaa aaa       ",
        "   aaaaaaaaa      aaa   aaa     aaa     aaa   aaa     aaa        aaaaaaaaaaaa     aaa   aaa      ",
        "   aaa    aaa    aaaaaaaaaaa    aaa    aaaaaaaaaaa    aaa        aaa      aaa    aaaaaaaaaaa     ",
        "   aaa    aaa   aaa       aaa   aaa   aaa       aaa   aaaaaaaaa  aaa      aaa   aaa       aaa    ",
        "   aaaaaaaaa   aaa         aaa  aaa  aaa         aaa  aaaaaaaaa  aaa      aaa  aaa         aaa   ",
        "                                                                                                 ",      
        "  ========================================#############========================================  ",
        "  ========================================#############========================================  ",
        "                                                                                                 ",
        "                aaaa     aaa         aaa   aaa         aaa   aaa         aaa                     ",
        "                aaaaa    aaa        aaaaa   aaa       aaa   aaaaa        aaa                     ",
        "                aaa aa   aaa       aaa aaa   aaa     aaa   aaa aaa       aaa                     ",
        "                aaa  aa  aaa      aaa   aaa   aaa   aaa   aaa   aaa      aaa                     ",
        "                aaa   aa aaa     aaaaaaaaaaa   aaa aaa   aaaaaaaaaaa     aaa                     ",
        "                aaa    aaaaa    aaa       aaa   aaaaa   aaa       aaa    aaaaaaaaaaaa            ",
        "                aaa     aaaa   aaa         aaa   aaa   aaa         aaa   aaaaaaaaaaaa            ",
        "                                                                                                 ",

    };
    system("cls");
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 20; i++) {
            gotoxy(j + 5, i + 5); printf("%c", portada[i][j]);
        }
    }
    
    int referenceCenter = 49; // Posição central do sétimo #
    int progressBarWidth = 40; // Largura da barra de progresso
    int loadingTextWidth = 10; // Largura do texto "CARREGANDO"
    int startX = referenceCenter - (progressBarWidth / 2); // Posição inicial para centralizar a barra de progresso
    int loadingTextX = referenceCenter - (loadingTextWidth / 2); // Posição inicial para centralizar o texto "CARREGANDO"
    
    gotoxy(loadingTextX + 5, 27); cout << "CARREGANDO";

    for (int i = 0; i < progressBarWidth; i++) {
        gotoxy(startX + i + 5, 28); 
        printf("%c", 219);
        Sleep(100);
    }

    int creditsX = referenceCenter - 4; // Centralizar "CRIADO POR:" em relação ao sétimo #
    gotoxy(creditsX + 4, 32); cout << "CRIADO POR:";
    gotoxy(creditsX - 1, 34); cout << "Eduardo Hubner Adriano";
    gotoxy(creditsX - 1, 35); cout << "Pedro Bicalho de Sousa";
    gotoxy(creditsX - 1, 36); cout << "Julia Menezes";
    gotoxy(creditsX - 1, 37); cout << "Gabriela Teixeira Santos";

    getch();
}

void menu::INSTRUCOES() {
    char movimiento[11][76] = {
        "          SETINHAS                                                         ",
        "           ______                                                          ",
        "          |      |                                                         ",
        "          |   |  |                                                         ",
        "    ______|______|______      ______       ______          ______          ",
        "   |      |      |      |    |      |     |      |        |      |         ",
        "   | <--  |   |  |  --> |    |   Z  |     |   X  |        |   C  |         ",
        "   |______|______|______|    |______|     |______|        |______|         ",
        "                                                                           ",
        "     TECLAS DE MOVIMIENTO    DISPAROS   COLOCAR NAVIO    ROTACIONAR        ",
    };

    for (int j = 0; j < 76; j++) {
        for (int i = 0; i < 11; i++) {
            gotoxy(j + 22, i + 5); printf("%c", movimiento[i][j]);
        }
    }
    getch();
}

void menu::OBJETIVO() {
    char mision[10][80] = {
        "1. Objetivo do jogo:                                                  ",
        "Afundar os navios inimigos antes que ele afunde os seus.              ",
        "Cada jogador tem um Tabuleiro 10x10.                                  ",
        "Tabuleiro de baixo e o seu territorio, posicione os navios antes da   ",
        "partida comecar.                                                      ",
        "Tabuleiro de cima e o territorio inimigo, onde ele tem sua frota      ",
        "posicionada. Sera aqui onde suas jogadas (Disparos) vao acontecer e   ",
        "voce tentara afundar os navios inimigos                               ",
        "                                                                      ",
        "                Precione 'ESPACO' para comecar                        ",
    };
    gotoxy(45, 32);
    for (int j = 0; j < 80; j++) {
        for (int i = 0; i < 10; i++) {
            gotoxy(j + 5, i + 5); printf("%c", mision[i][j]);
        }
    }
    getch();
}
