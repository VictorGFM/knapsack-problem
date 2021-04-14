#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "Viagem.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* nomeArquivo = argv[1];

    //Verifica se parametro de nome do arquivo foi passado corretamente na entrada.
    if(nomeArquivo == nullptr) {
        cout << "Parametro de arquivo de entrada nao informado!" << endl;
    }
    
    //Verifica se arquivo foi aberto corretamente.
    ifstream arquivoEntrada;
    arquivoEntrada.open(nomeArquivo);
    if(!arquivoEntrada) {
        cout << "Erro ao tentar abrir o arquivo!" << endl;
    }

    int custoMaximo, qtdIlhas;
    //Realiza leitura dos parametros da primeira linha do arquivo.
    arquivoEntrada >> custoMaximo >> qtdIlhas;

    //Inicializa vetor de ilhas com base na leitura dos parametros do arquivo.
    vector<Ilha> ilhas(qtdIlhas);
    for(int i=0; i<qtdIlhas; i++) {
        arquivoEntrada >> ilhas[i].custoDiario >> ilhas[i].pontuacao;
        ilhas[i].custoMaximo = custoMaximo;
        ilhas[i].calculaCustoPorPontuacao();
    }

    //Termina leitura e fecha o arquivo.
    arquivoEntrada.close();

    //Realiza chamada a funcao de viagem com repeticao de ilha e imprime resultado.
    int pontuacaoComRepeticao = 0, qtdDiasComRepeticao = 0;
    viagemComRepeticaoIlha(ilhas, qtdIlhas, custoMaximo, &pontuacaoComRepeticao, &qtdDiasComRepeticao);
    cout << pontuacaoComRepeticao << " " << qtdDiasComRepeticao << endl;

    //Realiza chamada a funcao de viagem sem repeticao de ilha e imprime resultado.
    int pontuacaoSemRepeticao = 0, qtdDiasSemRepeticao = 0;
    viagemSemRepeticaoIlha(ilhas, qtdIlhas, custoMaximo, &pontuacaoSemRepeticao, &qtdDiasSemRepeticao);
    cout << pontuacaoSemRepeticao << " " << qtdDiasSemRepeticao << endl;

    return 1;
}