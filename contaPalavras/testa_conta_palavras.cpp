// Copyright [2024] <Adriano Wiedmann>
/**
 * \file testa_conta_palavras.cpp
 */

#include "./conta_palavras.hpp"
#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "./catch.hpp"

TEST_CASE("Teste 1: conversão da string para lowercase") {
    std::string text = "ExEMpLo de TexTO CoNVERtER PaRA LoWERCasE";
    REQUIRE(toLowerCase(text) == "exemplo de texto converter para lowercase");
}

TEST_CASE("Teste 2: convertendo a string para um vector") {
    std::string text = "Separando palavras para vector";
    auto result = ContaPalavras(text);

    REQUIRE(result.size() == 4);
}

TEST_CASE("Teste 3: contando quantidade de palavras iguais") {
    std::string text = "esta Esta esta";
    auto result = ContaPalavras(text);

    REQUIRE(result[0].second == 3);
}

TEST_CASE("Teste 4: remover acentuação") {
    std::string text = "cesta cestá cestà césta cêsta cèsta çesta";
    auto result = removerAcentos(text);

    REQUIRE(result == "cesta cesta cesta cesta cesta cesta cesta");
}

// Função toLowerCase
TEST_CASE("Teste 5: maiusculo com acento para minusculo com acento") {
    std::string text = "Árvore";
    auto result = ContaPalavras(text);

    REQUIRE(result[0].first == "árvore");
}

TEST_CASE("Teste 6: ordenação e ocorrências") {
    std::string text = "Este texto é o texto que será utilizado";
    auto result = ContaPalavras(text);

    REQUIRE(result[0].first == "é");
    REQUIRE(result[0].second == 1);
    REQUIRE(result[1].first == "este");
    REQUIRE(result[0].second == 1);
    REQUIRE(result[2].first == "o");
    REQUIRE(result[2].second == 1);
    REQUIRE(result[3].first == "que");
    REQUIRE(result[3].second == 1);
    REQUIRE(result[4].first == "será");
    REQUIRE(result[4].second == 1);
    REQUIRE(result[5].first == "texto");
    REQUIRE(result[5].second == 2);
    REQUIRE(result[6].first == "utilizado");
    REQUIRE(result[6].second == 1);
    REQUIRE(result.size() == 7);
}

TEST_CASE("Teste 7: ordenação e ocorrências a partir de um texto de um txt") {
    std::string fileName = "arquivoTexto.txt";
    auto text = readFile(fileName);
    auto result = ContaPalavras(text);

    REQUIRE(result[0].first == "é");
    REQUIRE(result[0].second == 1);
    REQUIRE(result[1].first == "este");
    REQUIRE(result[0].second == 1);
    REQUIRE(result[2].first == "o");
    REQUIRE(result[2].second == 1);
    REQUIRE(result[3].first == "que");
    REQUIRE(result[3].second == 1);
    REQUIRE(result[4].first == "será");
    REQUIRE(result[4].second == 1);
    REQUIRE(result[5].first == "texto");
    REQUIRE(result[5].second == 2);
    REQUIRE(result[6].first == "utilizado");
    REQUIRE(result[6].second == 1);
    REQUIRE(result.size() == 7);
}

TEST_CASE("Teste 8: Arquivo que possui só quebra de linha entre palavras") {
    std::string fileName = "arquivoTexto2.txt";
    auto text = readFile(fileName);
    auto result = ContaPalavras(text);

    REQUIRE(result[0].first == "é");
    REQUIRE(result[0].second == 1);
    REQUIRE(result[1].first == "este");
    REQUIRE(result[0].second == 1);
    REQUIRE(result[2].first == "o");
    REQUIRE(result[2].second == 1);
    REQUIRE(result[3].first == "que");
    REQUIRE(result[3].second == 1);
    REQUIRE(result[4].first == "será");
    REQUIRE(result[4].second == 1);
    REQUIRE(result[5].first == "texto");
    REQUIRE(result[5].second == 2);
    REQUIRE(result[6].first == "utilizado");
    REQUIRE(result[6].second == 1);
    REQUIRE(result.size() == 7);
}

TEST_CASE("Teste Final: ordenação e contador com arquivo e listar") {
    std::string fileName = "arquivoTexto3.txt";
    auto text = readFile(fileName);
    auto result = ContaPalavras(text);

    REQUIRE(result[0].first == "é");
    REQUIRE(result[0].second == 3);
    REQUIRE(result[1].first == "este");
    REQUIRE(result[0].second == 3);
    REQUIRE(result[2].first == "o");
    REQUIRE(result[2].second == 3);
    REQUIRE(result[3].first == "que");
    REQUIRE(result[3].second == 3);
    REQUIRE(result[4].first == "será");
    REQUIRE(result[4].second == 3);
    REQUIRE(result[5].first == "texto");
    REQUIRE(result[5].second == 6);
    REQUIRE(result[6].first == "utilizado");
    REQUIRE(result[6].second == 3);
    REQUIRE(result.size() == 7);
}
