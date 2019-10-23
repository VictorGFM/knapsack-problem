#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>
#include "Ilha.h"

using namespace std;

void viagemComRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoComRepeticao, int* qtdDiasComRepeticao);
void viagemSemRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoSemRepeticao, int* qtdDiasSemRepeticao);

#endif