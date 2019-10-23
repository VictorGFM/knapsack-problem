#ifndef ILHA_H
#define ILHA_H

class Ilha {
    public:
        int custoMaximo;
        int custoDiario;
        int pontuacao;
        float custoPorPontuacao;
        //Modificador do operador '<' a fim de realizar ordenacao com base nos atributos de Ilha.
        bool operator<(const Ilha &object) const {
            return (custoPorPontuacao < object.custoPorPontuacao) || 
                   (custoPorPontuacao == object.custoPorPontuacao && custoMaximo%custoDiario <= custoMaximo%object.custoDiario);
        }
        //Funcao responsavel por calcular o custo por pontuacao da ilha.
        void calculaCustoPorPontuacao();        
};

#endif