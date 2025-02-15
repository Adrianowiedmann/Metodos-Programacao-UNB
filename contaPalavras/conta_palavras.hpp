// Copyright [2025] <Adriano Wiedmann>
#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <utility>

/**
 * @brief Imprimir os valores de um vector
 * 
 * @param vectorWords Vector de palavras que será mostrado
 * 
 */
void printVector(const std::vector<std::pair<std::string, int>> vectorWords);

/**
 * @brief Lê o conteúdo de um arquivo e retorna como uma string.
 * 
 * @param fileName O nome do arquivo a ser lido.
 * @return String 'text' retorna o conteúdo do arquivo como uma única string.
 *         Retorna uma string vazia se o arquivo não puder ser aberto.
 */
std::string readFile(const std::string& fileName);

/**
 * Faz merge para duas metades ordenadas
 *
 * @param vec Vector de strings a ser odenado.
 * @param left Índice inicial da primeira metade.
 * @param mid Índice final da primeira metade.
 * @param right Índice final da segunda metade
 */
void merge(std::vector<std::pair<std::string, int>>* vec,
            int left, int mid, int right);

/**
 * Ordena recursivamente um vector de strings usando MergeSort
 * 
 * @param vec Vector de strings a ser odenado.
 * @param left Índice inicial do vector.
 * @param right Índice final do vector.
 */
void mergeSort(std::vector<std::pair<std::string, int>>* vec,
                int left, int right);

/**
 * @brief Função que retira os acentos do texto
 * 
 * Esta função recebe uma string e retorna esta string sem acentos
 * 
 * @param text String que será retirado os acentos
 * @return String 'resultado' com a string sem acentos
 */
std::string removerAcentos(const std::string& text);

/**
 * Além de verificar se existe uma palavra no vetor, é retornado a posição da palavra
 * no vetor caso a palavra exista.
 *
 * @param vectorWords Um vector preenchida por palavras.
 * @param wordCompare String que representa uma palavra para procurar no vector vectorWords. 
 * 
 * @return -1 caso não exista a palavra 'wordCompare' no vector 'vectorWords'
 * @return 'position' que é a posição da palavra no vector 'vectorWords'
 */
int positionWord(const std::vector<std::pair<std::string, int>> vectorWords,
                const std::string& wordCompare);

/**
 * @brief Função que converte uma string para lowercase e retorna
 * 
 * Esta função recebe uma string e retorna a string em lowercase
 * 
 * @param text String a ser convertido para lowercase
 * @return String 'lowerText' em lowercase
 */
std::string toLowerCase(const std::string& text);

/**
 * @brief Converte uma string em um vetor de pares (palavra, 0).
 * 
 * Separa a string em palavras usando espaços e quebras de linha.
 * 
 * @param newText A string a ser convertida.
 * @return Um vetor de pares (palavra, 0).
 */
std::vector<std::pair<std::string, int>> toVector(const std::string& newText);

std::vector<std::pair<std::string, int>> ContaPalavras(const std::string& text);


#endif  // CONTA_PALAVRAS_HPP_
