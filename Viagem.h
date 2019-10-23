#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>
#include "Ilha.h"

using namespace std;

//Funcao responsavel por calcular viagem com repeticao de ilhas.
void viagemComRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoComRepeticao, int* qtdDiasComRepeticao);
//Funcao responsavel por calcular viagem sem repeticao de ilhas.
void viagemSemRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoSemRepeticao, int* qtdDiasSemRepeticao);

#endif