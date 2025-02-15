// Copyright [2024] <Adriano Wiedmann>
/**
 * \file testa_velha.cpp
 */

#include "./velha.hpp"

#define CATCH_CONFIG_MAIN
#include "./catch.hpp"

TEST_CASE("Teste 1: se o vencedor é x (1)" ) {
    int teste1[3][3]= {   { 2, 1, 1 },
                          { 0, 0, 1 },
                          { 2, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Teste 2: se o vencedor é x (1)" ) {
    int teste2[3][3]= {   { 2, 1, 2 },
                          { 0, 0, 2 },
                          { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste2) == 1);
}

TEST_CASE("Teste 3: se o vencedor é x (1)" ) {
    int teste3[3][3]= {   { 2, 0, 1 },
                          { 2, 1, 2 },
                          { 1, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste3) == 1);
}

TEST_CASE("Teste 4: se o vencedor é O (2)" ) {
    int teste4[3][3]= {   { 2, 0, 0 },
                          { 2, 1, 1 },
                          { 2, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste4) == 2);
}

TEST_CASE("Teste 5: se o vencedor é O (2)" ) {
    int teste5[3][3]= {   { 1, 0, 0 },
                          { 2, 2, 2 },
                          { 1, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste5) == 2);
}

TEST_CASE("Teste 6: se o vencedor é O (2)" ) {
    int teste6[3][3]= {   { 1, 0, 2 },
                          { 0, 2, 1 },
                          { 2, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste6) == 2);
}

TEST_CASE("Teste 7: Caso impossível se o número de X > n de O + 1") {
    int teste7[3][3]= {   { 1, 1, 2 },
                          { 0, 2, 1 },
                          { 2, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste7) == -2);
}

TEST_CASE("Teste 8: Caso impossível, o número de O é maior que o número de X") {
    int teste8[3][3]= {   { 2, 1, 2 },
                          { 0, 2, 2 },
                          { 2, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste8) == -2);
}

TEST_CASE("Teste 9: Caso impossível se o X e O venceram ao mesmo tempo") {
    int teste9[3][3]= {   { 0, 1, 2 },
                          { 0, 1, 2 },
                          { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste9) == -2);
}

TEST_CASE("Teste 10: Caso impossível se o X vence, X joga mais que O") {
    int teste10[3][3]= {  { 0, 1, 2 },
                          { 2, 1, 0 },
                          { 0, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste10) == -2);
}

TEST_CASE("Teste 11: Caso impossível se O vence, movimentos devem ser iguais") {
    int teste11[3][3]= {  { 2, 1, 1 },
                          { 2, 0, 0 },
                          { 2, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste11) == -2);
}

TEST_CASE("Teste 12: Se o jogo é indefinido") {
    int teste12[3][3]= {  { 2, 1, 1 },
                          { 0, 0, 2 },
                          { 2, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste12) == -1);
}

TEST_CASE("Teste 13: Se o jogo está empatado") {
    int teste13[3][3]= {  { 1, 1, 2 },
                          { 2, 2, 1 },
                          { 1, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste13) == 0);
}
