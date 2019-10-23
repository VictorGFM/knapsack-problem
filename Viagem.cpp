#include <vector>
#include <algorithm>
#include "Viagem.h"

int max(int valorA, int valorB);

void viagemComRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoComRepeticao, int* qtdDiasComRepeticao) {
    sort(ilhas.begin(), ilhas.end());
    int custoTotalEstadia = 0;
    for(int i=0; i<qtdIlhas; i++) {
        if(ilhas[i].custoDiario <= (custoMaximo - custoTotalEstadia)) {
            int qtdDias = (custoMaximo - custoTotalEstadia)/ilhas[i].custoDiario;
            custoTotalEstadia += ilhas[i].custoDiario*qtdDias;
            *pontuacaoComRepeticao += ilhas[i].pontuacao*qtdDias;
            *qtdDiasComRepeticao += qtdDias;
        }
    }
}

void viagemSemRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoSemRepeticao, int* qtdDiasSemRepeticao) {
    vector<vector<int>> pontuacoes;
    pontuacoes.resize(qtdIlhas+1, std::vector<int>(custoMaximo+1, 0));
    
    for(int i=0; i<=qtdIlhas; i++) {
        for(int j=0; j<=custoMaximo; j++) {
            if(i == 0 || j == 0) {
                pontuacoes[i][j] = 0;
            } else if(ilhas[i-1].custoDiario <= j) {
                pontuacoes[i][j] = max(pontuacoes[i-1][j], ilhas[i-1].pontuacao + pontuacoes[i-1][j-ilhas[i-1].custoDiario]);
            } else {
                pontuacoes[i][j] = pontuacoes[i-1][j];
            }
        }
    }
    
    *pontuacaoSemRepeticao = pontuacoes[qtdIlhas][custoMaximo];

    int copiaResultadoPontuacao = *pontuacaoSemRepeticao;
    int dinheiroRestante = custoMaximo;

    for(int i=qtdIlhas; i > 0 && copiaResultadoPontuacao > 0; i--) {
        if(copiaResultadoPontuacao == pontuacoes[i-1][dinheiroRestante]) {
            continue;
        } else {
            (*qtdDiasSemRepeticao)++;
            copiaResultadoPontuacao = copiaResultadoPontuacao - ilhas[i-1].pontuacao;
            dinheiroRestante = dinheiroRestante - ilhas[i-1].custoDiario;
        }
    }
}

int max(int valorA, int valorB) {
    return (valorA > valorB) ? valorA : valorB;
}