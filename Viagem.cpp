#include <vector>
#include <algorithm>
#include "Viagem.h"

int max(int valorA, int valorB);

//Calcula viagem com repeticao de ilhas.
void viagemComRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoComRepeticao, int* qtdDiasComRepeticao) {
    //Ordena elementos em uma performance O(n log n)
    sort(ilhas.begin(), ilhas.end());
    
    //Calcula melhor pontuacao com base no custo total. 
    int custoTotalEstadia = 0;
    for(int i=0; i<qtdIlhas; i++) {
        if(ilhas[i].custoDiario <= (custoMaximo - custoTotalEstadia)) {
            //Calcula quantidade de dias na ilha selecionada.
            int qtdDias = (custoMaximo - custoTotalEstadia)/ilhas[i].custoDiario;
            custoTotalEstadia += ilhas[i].custoDiario*qtdDias;
            //Calcula pontuacao total.
            *pontuacaoComRepeticao += ilhas[i].pontuacao*qtdDias;
            //Calcula quantidade de dias total.
            *qtdDiasComRepeticao += qtdDias;
        }
    }
}

//Calcula viagem sem repeticao de ilhas.
void viagemSemRepeticaoIlha(vector<Ilha> ilhas, int qtdIlhas, int custoMaximo, int* pontuacaoSemRepeticao, int* qtdDiasSemRepeticao) {
    //Cria matriz para mapear os valores de pontuacao das ilhas e inicializa as posicoes com 0.
    vector<vector<int>> pontuacoes;
    pontuacoes.resize(qtdIlhas+1, std::vector<int>(custoMaximo+1, 0));
    
    //Realiza o algoritmo da mochila pela abordagem bottom-up, preenchendo a matriz de pontuacoes.
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
    
    //Define pontuacao total.
    *pontuacaoSemRepeticao = pontuacoes[qtdIlhas][custoMaximo];

    int copiaResultadoPontuacao = *pontuacaoSemRepeticao;
    int dinheiroRestante = custoMaximo;
    //Percorre a matriz de pontuacoes a fim de encontrar as ilhas selecionadas, e entao define a quantidade a quantidade de dias.
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

//Funcao para calcular o maximo entre dois valores.
int max(int valorA, int valorB) {
    return (valorA > valorB) ? valorA : valorB;
}