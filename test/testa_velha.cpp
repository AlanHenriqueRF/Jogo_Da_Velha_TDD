// Copyright (c) 2023 Seu Alan Henrique Rangel Ferreira

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../include/velha.hpp"

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

TEST(VelhaTests, winnerO) {
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 0}, {0, 2, 1}, {0, 1, 2}})
        , 2);  // Diagonal Principal
    EXPECT_EQ(
        verifica_vencedor({{0, 1, 2}, {0, 2, 1}, {2, 1, 0}})
        , 2);  // Diagonal Secundaria
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 0}, {2, 1, 0}, {2, 0, 1}}), 2);  // Coluna 1
    EXPECT_EQ(
        verifica_vencedor({{0, 2, 1}, {1, 2, 0}, {1, 2, 0}}), 2);  // Coluna 2
    EXPECT_EQ(
        verifica_vencedor({{1, 0, 2}, {1, 1, 2}, {2, 1, 2}}), 2);  // Coluna 3
    EXPECT_EQ(
        verifica_vencedor({{2, 2, 2}, {1, 1, 0}, {0, 1, 0}}), 2);  // Linha 1
    EXPECT_EQ(
        verifica_vencedor({{1, 0, 0}, {2, 2, 2}, {0, 1, 1}}), 2);  // Linha 2
    EXPECT_EQ(
        verifica_vencedor({{1, 1, 2}, {1, 1, 0}, {2 , 2, 2}}), 2);  // Linha 3
}

TEST(VelhaTests, ForcedDraw) {
    EXPECT_EQ(
        verifica_vencedor({{1, 2, 1}, {2, 2, 1}, {1, 1, 2}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{1, 0, 1}, {2, 2, 1}, {1, 0, 2}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{1, 2, 1}, {2, 2, 1}, {1, 0, 2}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 2}, {0, 1, 0}, {1, 2, 1}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 2}, {2, 1, 0}, {1, 2, 1}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 2}, {0, 1, 2}, {1, 2, 1}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 2}, {2, 1, 1}, {1, 2, 1}}), 0);
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 2}, {1, 1, 2}, {1, 2, 1}}), 0);
}

TEST(VelhaTests, Indefined) {
    EXPECT_EQ(
        verifica_vencedor({{1, 2, 0}, {0, 0, 0}, {0, 0, 0}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 0}, {0, 0, 1}, {0, 0, 0}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 2}, {0, 0, 1}, {0, 0, 0}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 2}, {1, 2, 1}, {0, 0, 0}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 0}, {0, 0, 0}, {0, 1, 0}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 0}, {0, 0, 2}, {1, 1, 2}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 0}, {0, 0, 2}, {1, 2, 1}}), -1);
    EXPECT_EQ(
        verifica_vencedor({{2, 1, 2}, {1, 0, 0}, {0, 0, 0}}), -1);
}

TEST(VelhaTests, Impossible) {
    EXPECT_EQ(
        verifica_vencedor({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}), -2);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 0}, {0, 0, 2}, {0, 0, 0}}), -2);
    EXPECT_EQ(
        verifica_vencedor({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}), -2);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 2}, {1, 2, 1}, {2, 0, 0}}), -2);
    EXPECT_EQ(
        verifica_vencedor({{0, 0, 0}, {0, 2, 2}, {0, 1, 0}}), -2);
    EXPECT_EQ(
        verifica_vencedor({{1, 0, 0}, {0, 1, 2}, {1, 1, 2}}), -2);
}
