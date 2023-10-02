// Copyright (c) 2023 Seu Alan Henrique Rangel Ferreira

#ifndef velha_hpp
#define velha_hpp
#include <iostream>
#include <vector>
using namespace std;

int verifica_vencedor(const vector<vector<int>> &jogo){
    int soma_jog = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma_jog += jogo[i][j];
        }
    }

    int qntd1 = 0;
    int qntd2 = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (jogo[i][j] == 1){ 
                qntd1++;
            }
            else if (jogo[i][j] == 2){
                qntd2++;
            }
        }
    }

    if (abs(qntd1 - qntd2) > 1){// Foi feita a cotagem de numeros 1 e de numeros 2 se a diferença absoluata entre eles for maior que 1 significa quem alguem jogou duas vezes
        return -2;
        }

    if (soma_jog == 18 || (soma_jog == 9 && abs(qntd1 - qntd2) > 1 )){ // Caso teste 1 todas as casa cotém o número 1 ou 2 e suas somas respectivamente são 9 e 18
        return -2;
    }
    

    if ((qntd1 == 0 && qntd2 > 0) || (qntd2 == 0 && qntd1 > 0)){ // Jogo indefinido
        return -1;
    }

    bool testZeroeUm =  jogo[0][0] == jogo[1][1];
    bool testUmeDois =  jogo[1][1] == jogo[2][2];
    bool testDifZeroUmDois = (jogo[0][0] + jogo[1][1] + jogo[2][2]) >= 3;

    if (testZeroeUm && testUmeDois && testDifZeroUmDois ){ //Diagonal principal
        return jogo[0][0];
    }

    bool testDoiseUm =  jogo[0][2] == jogo[1][1];
    bool testUmeZero =  jogo[1][1] == jogo[2][0];
    bool testDifDoisUmZero = jogo[0][2] + jogo[1][1] + jogo[2][0] >= 3;
    
    if (testDoiseUm && testUmeZero && testDifDoisUmZero ){ // Diagonal secundaria
        return jogo[0][2];
    }

    for (int i = 0; i < 3; i++){
        if ((jogo[i][0] == jogo[i][1]) && (jogo[i][1]== jogo[i][2]) && ((jogo[i][0] + jogo[i][1] + jogo[i][2]) >= 3)){ // vencedor da linha
            return jogo[i][0];
        }
        if ((jogo[0][i] == jogo[1][i]) && (jogo[1][i] == jogo[2][i]) && ((jogo[0][i] + jogo[1][i] + jogo[2][i]) >= 3)){ // vencedor da coluna
            return jogo[0][i];
        }
    }
    return 0;
}

#endif
