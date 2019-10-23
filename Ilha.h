#ifndef ILHA_H
#define ILHA_H

class Ilha {
    public:
        int custoMaximo;
        int custoDiario;
        int pontuacao;
        float custoPorPontuacao;
        bool operator<(const Ilha &object) const {
            return (custoPorPontuacao < object.custoPorPontuacao) || 
                   (custoPorPontuacao == object.custoPorPontuacao && custoMaximo%custoDiario <= custoMaximo%object.custoDiario);
        }

        void calculaCustoPorPontuacao();        
};

#endif