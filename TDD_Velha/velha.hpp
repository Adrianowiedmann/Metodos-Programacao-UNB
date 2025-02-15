// Copyright [2024] <Adriano Wiedmann>
#ifndef VELHA_HPP_
#define VELHA_HPP_

/** 
 * @brief Avalia estado atual do jogo da velha e retorna o resultado
 * @param velha Matriz 3x3 representando o estado atual do tabuleiro do jogo da velha. 
 * @return int Inteiro que descreve o estado do jogo:
 */
int VerificaVelha(int velha[3][3]);

/** 
 * @brief Verifica se o jogo é empate
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return bool Retorna 'true' se o estado do jogo é de empate; caso contrário, 'false'.
 */
bool ehEmpate(int velha[3][3]);

/** 
 * @brief Verifica se o jogo é indefinido
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return bool Retorna 'true' se o estado do jogo for indefinido; caso contrário, 'false'.
 */
bool ehIndefinido(int velha[3][3]);

/** 
 * @brief Verifica se há espaços vazios no tabuleiro.
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return bool Retorna 'true' houver uma posição com o valor '0'; caso contrário, 'false'.
 */
bool posicaoVazia(int velha[3][3]);

/** 
 * @brief Verifica se o jogo é impossivel
 * @param contador Array de dois inteiros onde:
 *                 - 'contador[0]' representa o número de jogadas de X.
 *                 - 'contador[1]' representa o número de jogadas de O.
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return bool Retorna 'true' se o estado do jogo for impossível; caso contrário, 'false'.
 */
bool ehImpossivel(int contador[2], int velha[3][3]);

/** 
 * @brief Conta as posições ocupados por X e O.
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return int* Um ponteiro para um array dinâmico de tamanho 2.
 */
int* contaPosicoes(int velha[3][3]);

/** 
 * @brief Verifica se O venceu o jogo
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return bool Retorna 'true' se o jogador O venceu o jogo; caso contrário, 'false'.
 */
bool vencedorO(int velha[3][3]);

/** 
 * @brief Verifica se X venceu o jogo
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @return bool Retorna 'true' se o jogador X venceu o jogo; caso contrário, 'false'.
 */
bool vencedorX(int velha[3][3]);

/** 
 * @brief Verifica se um jogador venceu o jogo
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @param simbolo Inteiro representado o símbolo do jogador que chamou a esta função.
 *                - Por exemplo, '1' para jogador X e '2' para jogador O.
 * @return bool Retorna 'true' se o jogador representado pelo simbolo fornecido
 *              venceu o jogo; caso contrário, 'false'.
 */
bool venceu(int velha[3][3], int simbolo);

#endif  // VELHA_HPP_
