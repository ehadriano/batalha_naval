#ifndef UTILITARIOS_HPP
#define UTILITARIOS_HPP

#include <windows.h>

/**
 * @file utilitarios.hpp
 * @brief Declaração de funções utilitárias para manipulação do cursor no console.
 *
 * Este arquivo contém declarações de funções que permitem posicionar e ocultar o cursor no console.
 */

/**
 * @brief Posiciona o cursor na coordenada (x, y) no console.
 * 
 * @param x Coordenada x (coluna).
 * @param y Coordenada y (linha).
 */
void gotoxy(int x, int y);

/**
 * @brief Oculta o cursor no console.
 */
void ocultarCursor();

#endif // UTILITARIOS_HPP
