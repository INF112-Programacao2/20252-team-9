#ifndef PROJETO_FINAL_INF_112_SERVICO_H
#define PROJETO_FINAL_INF_112_SERVICO_H

#include <string>

class Servico {

    private:
        std::string nome;
        std::string id;       
        double valor;
        std::string duracao;  

    public:
        // Construtor e destrutor:
        Servico(std::string nome, std::string id, double valor, std::string duracao);
        ~Servico();

        // Gets
        std::string getNome() const;
        std::string getId() const;
        double getValor() const;
        std::string getDuracao() const;

        // Sets
        void setNome(std::string nome);
        void setValor(double valor);
        void setDuracao(std::string duracao);
};

#endif //PROJETO_FINAL_INF_112_SERVICO_H
