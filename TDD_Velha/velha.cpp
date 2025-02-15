// Copyright [2024] <Adriano Wiedmann>
/**
 * \file  velha.cpp
 */

#include "./velha.hpp"

/** 
 * @brief Verifica se um jogador venceu o jogo
 * 
 * Esta função percorre uma matrix 3x3 e verifica se um jogador, representado por um símbolo,
 * venceu o jogo através da linha, coluna ou diagonal.
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * @param simbolo Inteiro representado o símbolo do jogador que chamou a esta função.
 *                - Por exemplo, '1' para jogador X e '2' para jogador O.
 * 
 * @return bool Retorna 'true' se o jogador representado pelo simbolo fornecido
 *              venceu o jogo; caso contrário, 'false'.
 */
bool venceu(int velha[3][3], int simbolo) {
    for (int i = 0; i < 3; i++) {
        if (velha[0][i] == simbolo && velha[1][i] == simbolo
            && velha[2][i] == simbolo) {
            return true;
        } else if (velha[i][0] == simbolo && velha[i][1] == simbolo
            && velha[i][2] == simbolo) {
            return true;
        }
    }
    if ((velha[0][0] == simbolo && velha[1][1] == simbolo
        && velha[2][2] == simbolo)
        || (velha[0][2] == simbolo && velha[1][1] == simbolo
        && velha[2][0] == simbolo)) {
        return true;
    }
    return false;
}

/** 
 * @brief Verifica se X venceu o jogo
 * 
 * Esta função utiliza a lógica de outra função, 'venceu', para determinar
 * se o jogador X venceu.
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return bool Retorna 'true' se o jogador X venceu o jogo; caso contrário, 'false'.
 */
bool vencedorX(int velha[3][3]) {
    if (venceu(velha, 1)) {
        return true;
    }
    return false;
}

/** 
 * @brief Verifica se O venceu o jogo
 * 
 * Esta função utiliza a lógica de outra função, 'venceu', para determinar
 * se o jogador O venceu.
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return bool Retorna 'true' se o jogador O venceu o jogo; caso contrário, 'false'.
 */
bool vencedorO(int velha[3][3]) {
    if (venceu(velha, 2)) {
        return true;
    }
    return false;
}

/** 
 * @brief Conta as posições ocupados por X e O.
 * 
 * Esta função percorre o tabuleiro e conta o número de posições
 * ocupadas por X ou O.
 * Os valores são armazenados em um Array dinâmico de tamanho 2.
 * Índice 0 representa X e o índice 1 representa O
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return int* Um ponteiro para um array dinâmico de tamanho 2.
 */
int* contaPosicoes(int velha[3][3]) {
	int* contador = new int[2];
	for (int i = 0; i < 2; i++) {
		contador[i] = 0;
	}
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (velha[i][j] == 1) {
                contador[0]++;
            } else if (velha[i][j] == 2) {
                contador[1]++;
            }
        }
    }
    return contador;
}

/** 
 * @brief Verifica se o jogo é impossivel
 * 
 * O jogo é considerado impossível se:
 * - A diferença entre os contadores de jogadas dos jogadores for maior que 1
 * ou menor que 0.
 * - Ambos os jogadores são vencedores simultaneamente.
 * - X vence, mas não teve um movimento a mais que O.
 * - O vence, mas não teve mesma quantidade de movimentos que X.
 * 
 * @param contador Array de dois inteiros onde:
 *                 - 'contador[0]' representa o número de jogadas de X.
 *                 - 'contador[1]' representa o número de jogadas de O.
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return bool Retorna 'true' se o estado do jogo for impossível; caso contrário, 'false'.
 */
bool ehImpossivel(int contador[2], int velha[3][3]) {
    if ((contador[0] - contador[1] > 1) ||
        (contador[0] - contador[1] < 0)) {
        return true;
    } else if (vencedorO(velha) && vencedorX(velha)) {
        return true;
    } else if (vencedorX(velha) && contador[0] != contador[1] + 1) {
        return true;
    } else if (vencedorO(velha) && contador[0] != contador[1]) {
        return -2;
    }
    return false;
}

/** 
 * @brief Verifica se há espaços vazios no tabuleiro.
 * 
 * Se houver uma posição com o valor '0', o jogo é empate.
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return bool Retorna 'true' houver uma posição com o valor '0'; caso contrário, 'false'.
 */
bool posicaoVazia(int velha[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (velha[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

/** 
 * @brief Verifica se o jogo é indefinido
 * 
 * O jogo é considerado indefinido se:
 * - Não há um vencedor e ainda há espaços vazios
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return bool Retorna 'true' se o estado do jogo for indefinido; caso contrário, 'false'.
 */
bool ehIndefinido(int velha[3][3]) {
    if (!vencedorO(velha) && !vencedorX(velha)
        && posicaoVazia(velha)) {
        return true;
    }
    return false;
}

/** 
 * @brief Verifica se o jogo é empate
 * 
 * O jogo é considerado empatado quando:
 * - Não há um vencedor e não há espaços vazios
 * 
 * @param velha Matriz 3x3 representando o tabuleiro do jogo da velha.
 * 
 * @return bool Retorna 'true' se o estado do jogo é de empate; caso contrário, 'false'.
 */
bool ehEmpate(int velha[3][3]) {
    if (!vencedorO(velha) && !vencedorX(velha)
        && !posicaoVazia(velha)) {
        return true;
    }
    return false;
}

/** 
 * @brief Avalia estado atual do jogo da velha e retorna o resultado
 * 
 * O jogo é considerado empatado quando:
 * - Não há um vencedor e não há espaços vazios
 * 
 * @param velha Matriz 3x3 representando o estado atual do tabuleiro do jogo da velha. 
 *              Cada célula contém:
 *              - '0' para uma célula vazia,
 *              - '1' para uma célula ocupada pelo jogador X,
 *              - '2' para uma célula ocupada pelo jogador O.
 * 
 * @return int Inteiro que descreve o estado do jogo:
 *         - '-2': O estado do jogo é impossível.
 *         - '-1': O jogo está indefinido.
 *         - '0': O jogo terminou em empate.
 *         - '1': O jogador X venceu.
 *         - '2': O jogador O venceu.
 *         - '100': Código de teste.
 */
int VerificaVelha(int velha[3][3]) {
    int* contador = contaPosicoes(velha);
    if (ehImpossivel(contador, velha)) {
        return -2;
		delete[] contador;
    } else if (ehIndefinido(velha)) {
        return -1;
    } else if (ehEmpate(velha)) {
        return 0;
    } else if (vencedorX(velha)) {
        return 1;
    } else if (vencedorO(velha)) {
        return 2;
    }
    return 100; /*!< retorna zero para teste */
}
