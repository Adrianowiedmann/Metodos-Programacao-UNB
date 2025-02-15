// Copyright [2025] <Adriano Wiedmann>
/**
 * \file  conta_palavras.cpp
 */

#include "./conta_palavras.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <locale>
#include <codecvt>
#include <fstream>

/**
 * @brief Lê o conteúdo de um arquivo e retorna como uma string.
 * 
 * @param fileName O nome do arquivo a ser lido.
 * @return String 'text' retorna o conteúdo do arquivo como uma única string.
 *         Retorna uma string vazia se o arquivo não puder ser aberto.
 */
std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error! Não foi possivel abrir o arquivo: "
                    << fileName << std::endl;
        return "";
    }

    std::string text, line;
    while (std::getline(file, line)) {
        text += line + '\n';
    }

    file.close();
    return text;
}

/**
 * @brief Função que converte uma string para lowercase e retorna
 * 
 * Esta função recebe uma string e retorna a string em lowercase
 * 
 * @param text String a ser convertido para lowercase
 * @return String 'lowerText' em lowercase
 */
std::string toLowerCase(const std::string& text) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    const std::wstring maiusculos = L"ÁÀÃÂÉÈÊÍÌÎÓÒÕÔÚÙÛÇ";
    const std::wstring minusculos = L"áàãâéèêíìîóòõôúùûç";
    std::wstring newText = L"";
    const std::wstring convertText = converter.from_bytes(text);
    for (wchar_t letter : convertText) {
        size_t position = maiusculos.find(letter);
        if (position != std::string::npos) {
            newText += minusculos[position];
        } else {
            newText += letter;
        }
    }

    std::string lowerText = converter.to_bytes(newText);
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(),
    [](unsigned char c) {
        return std::tolower(c);
    });
    return lowerText;
}

/**
 * @brief Função que retira os acentos do texto
 * 
 * Esta função recebe uma string e retorna esta string sem acentos
 * 
 * @param text String que será retirado os acentos
 * @return String 'resultado' com a string sem acentos
 */
std::string removerAcentos(const std::string& text) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    const std::wstring acentos = L"áàãâéèêíìîóòõôúùûç";
    const std::wstring semAcentos = L"aaaaeeeiiioooouuuc";
    std::wstring resultado = L"";
    const std::wstring convertText = converter.from_bytes(text);
    for (wchar_t letter : convertText) {
        size_t position = acentos.find(letter);
        if (position != std::string::npos) {
            resultado += semAcentos[position];
        } else {
            resultado += letter;
        }
    }
    return converter.to_bytes(resultado);
}

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
                const std::string& wordCompare) {
    int positionWord = -1;
    for (const auto& word : vectorWords) {
        positionWord++;
        if (word.first == wordCompare) {
            return positionWord;
        }
    }
    return -1;
}

/**
 * Converte uma string em um vetor de pares de palavras e um valor inteiro associado.
 * Cada palavra na string de entrada será armazenada como um par, onde o primeiro 
 * valor do par é a palavra e o segundo valor é um número inteiro que é o contador
 * para cada palavra no vetor.
 * 
 * A função percorre a string caractere por caractere, separando as palavras com base 
 * em espaços e quebras de linha. Cada palavra encontrada será adicionada ao vetor 
 * como um par, com o segundo valor do par sendo 1 inicialmente.
 * 
 * É chamado a função positionWord para verificar se existe uma palavra
 * e também a posição da palavra no vetor, caso a palavra exista
 * Caso a palavra exista, é incrementado o seu contador.
 *
 * @param newText A string de entrada a ser convertida em um vetor de pares. 
 *                A string pode conter várias palavras separadas por espaços ou quebras de linha.
 * 
 * @return Um vetor de pares de palavras e valores inteiros. O vetor contém todas as palavras
 *         encontradas na string de entrada, com o valor inteiro de cada par sendo 0.
 */
std::vector<std::pair<std::string, int>> toVector(const std::string& newText) {
    std::vector<std::pair<std::string, int>> toWords;
    std::string addWord = "";
    for (const char letter : newText) {
        if (letter == ' ' || letter == '\n') {
            if (!addWord.empty()) {
                const int position = positionWord(toWords, addWord);
                if (position != -1) {
                    toWords[position].second++;
                    addWord = "";
                } else {
                    toWords.push_back({addWord, 1});
                    addWord = "";
                }
            }
        } else {
            addWord += letter;
        }
    }
    return toWords;
}

/**
 * Faz merge para duas metades ordenadas
 *
 * @param vec Vector de strings a ser odenado.
 * @param left Índice inicial da primeira metade.
 * @param mid Índice final da primeira metade.
 * @param right Índice final da segunda metade
 */
void merge(std::vector<std::pair<std::string, int>>* vec,
            int left, int mid, int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;
    std::vector<std::pair<std::string, int>> leftVec(n1);
    std::vector<std::pair<std::string, int>> rightVec(n2);

    for (int i = 0; i < n1; ++i)
        leftVec[i] = (*vec)[left + i];
    for (int j = 0; j < n2; ++j)
        rightVec[j] = (*vec)[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
            const auto w1 = removerAcentos(leftVec[i].first);
            const auto w2 = removerAcentos(rightVec[j].first);
            if (w1 <= w2) {
                (*vec)[k++] = leftVec[i++];
            } else {
                (*vec)[k++] = rightVec[j++];
            }
    }

    while (i < n1) (*vec)[k++] = leftVec[i++];
    while (j < n2) (*vec)[k++] = rightVec[j++];
}

/**
 * Ordena recursivamente um vector de strings usando MergeSort
 * 
 * @param vec Vector de strings a ser odenado.
 * @param left Índice inicial do vector.
 * @param right Índice final do vector.
 */
void mergeSort(std::vector<std::pair<std::string, int>>* vec,
                int left, int right) {
    if (left < right) {
        const int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid+1, right);

        merge(vec, left, mid, right);
    }
}

/**
 * @brief Imprimir os valores de um vector
 * 
 * @param vectorWords Vector de palavras que será mostrado
 * 
 */
void printVector(const std::vector<std::pair<std::string, int>> vectorWords) {
    std::cout << "\n" << "Ordem Alfabética: " << std::endl;
    for (const auto& c : vectorWords) {
        std::cout << "Palavra: " << c.first
        << " - Ocorrências: " << c.second << std::endl;
    }
}

/**
 * @brief Conta a ocorrência de cada palavra em um texto e
 *        retorna um vetor de pares com palavras e suas contagens.
 * 
 * @param text Uma string contendo o texto de entrada cujas palavras serão contadas.
 * 
 * @return std::vector<std::pair<std::string, int>> Retorna um vetor de pares onde cada par contém uma palavra
 *         e o número de vezes que ela ocorre no texto.
 * 
 */
std::vector<std::pair<std::string, int>>
ContaPalavras(const std::string& text) {
    std::vector<std::pair<std::string, int>> words;
    const std::string newText = toLowerCase(text) + " ";
    words = toVector(newText);
    mergeSort(&words, 0, words.size() -1);
    printVector(words);
    return words;
}
