// Copyright (c) 2023 Seu Alan Henrique Rangel Ferreira

#include <iostream>
#include <vector>
#include "./velha.hpp"  // Inclua o arquivo de cabeçalho

int main() {
    vector<vector<int>> jogo = {{1, 2, 0}, {0, 2, 1}, {1, 2, 0}};
    cout << verifica_vencedor(jogo) << endl;
}
