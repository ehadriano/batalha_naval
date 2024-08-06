#ifndef UTILITARIOS_HPP
#define UTILITARIOS_HPP

#include <windows.h>

// Declaração de funções utilitárias para manipulação do cursor no console
// Função para posicionar o cursor na coordenada (x, y) no console
// x: Coordenada x (coluna)
// y: Coordenada y (linha)
void gotoxy(int x, int y);

// Função para ocultar o cursor no console
void ocultarCursor();

#endif // UTILITARIOS_HPP
