#include <iostream>
#include <fstream>
#include <vector>
#include "Viagem.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* nomeArquivo = argv[1];

    if(nomeArquivo == nullptr) {
        cout << "Parametro de arquivo de entrada nao informado!";
    }
    
    ifstream arquivoEntrada;
    arquivoEntrada.open(nomeArquivo);
    if(!arquivoEntrada) {
        cout << "Erro ao tentar abrir o arquivo!" << endl;
    }

    int custoMaximo, qtdIlhas;

    arquivoEntrada >> custoMaximo >> qtdIlhas;

    vector<Ilha> ilhas(qtdIlhas);

    for(int i=0; i<qtdIlhas; i++) {
        arquivoEntrada >> ilhas[i].custoDiario >> ilhas[i].pontuacao;
        ilhas[i].custoMaximo = custoMaximo;
        ilhas[i].calculaCustoPorPontuacao();
    }

    arquivoEntrada.close();

    int pontuacaoComRepeticao = 0, qtdDiasComRepeticao = 0;
    viagemComRepeticaoIlha(ilhas, qtdIlhas, custoMaximo, &pontuacaoComRepeticao, &qtdDiasComRepeticao);
    cout << pontuacaoComRepeticao << " " << qtdDiasComRepeticao << endl;
    int pontuacaoSemRepeticao = 0, qtdDiasSemRepeticao = 0;
    viagemSemRepeticaoIlha(ilhas, qtdIlhas, custoMaximo, &pontuacaoSemRepeticao, &qtdDiasSemRepeticao);
    cout << pontuacaoSemRepeticao << " " << qtdDiasSemRepeticao << endl;

    return 1;
}