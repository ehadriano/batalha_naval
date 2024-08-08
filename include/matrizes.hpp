#ifndef MATRIZES_HPP
#define MATRIZES_HPP

/**
 * @file matrizes.hpp
 * @brief Declaração de matrizes globais extern.
 *
 * Essas matrizes são definidas em outro arquivo de implementação e são usadas para armazenar o estado do jogo.
 */

/**
 * @var MA
 * @brief Matriz MA para armazenar o estado do tabuleiro principal.
 */
extern char MA[22][22];

/**
 * @var JO
 * @brief Matriz JO para armazenar o estado do tabuleiro do jogador.
 */
extern char JO[22][22];

/**
 * @var en
 * @brief Matriz en para armazenar o estado do tabuleiro do inimigo.
 */
extern char en[22][22];

#endif // MATRIZES_HPP
