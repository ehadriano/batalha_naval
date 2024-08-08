#include "../include/utilitarios.hpp"
#include <conio.h>

/**
 * @file utilitarios.cpp
 * @brief Implementação de funções utilitárias.
 */
/**
 * @brief Move o cursor para a posição especificada no console.
 *
 * @param x Coordenada x para onde o cursor deve ser movido.
 * @param y Coordenada y para onde o cursor deve ser movido.
 */
void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

/**
 * @brief Oculta o cursor no console.
 *
 * Torna o cursor do console invisível para melhorar a aparência durante a execução do jogo.
 */
void ocultarCursor() {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hcon, &cci);
}
