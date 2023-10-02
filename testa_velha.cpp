// Copyright (c) 2023 Seu Alan Henrique Rangel Ferreira

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "./velha.hpp"

TEST(VelhaTests, winnerX) {
    EXPECT_EQ(
        verifica_vencedor({{1, 2, 0}, {0, 1, 0}, {0, 2, 1}})
        , 1);  // Diagonal Principal
    EXPECT_EQ(
        verifica_vencedor({{0, 2, 1}, {0, 1, 0}, {1, 2, 0}})
        , 1);  // Diagonal Secundaria
    EXPECT_EQ(
        verifica_vencedor({{1, 2, 0}, {1, 2, 0}, {1, 0, 0}}), 1);  // Coluna 1
    EXPECT_EQ(
        verifica_vencedor({{0, 1, 2}, {0, 1, 0}, {2, 1, 0}}), 1);  // Coluna 2
    EXPECT_EQ(
        verifica_vencedor({{2, 0, 1}, {0, 2, 1}, {1, 2, 1}}), 1);  // Coluna 3
    EXPECT_EQ(
        verifica_vencedor({{1, 1, 1}, {2, 0, 0}, {0, 2, 0}}), 1);  // Linha 1
    EXPECT_EQ(
        verifica_vencedor({{2, 0, 0}, {1, 1, 1}, {0, 2, 0}}), 1);  // Linha 2
    EXPECT_EQ(
        verifica_vencedor({{2, 2, 1}, {0, 2, 0}, {1, 1, 1}}), 1);  // Linha 3
}
