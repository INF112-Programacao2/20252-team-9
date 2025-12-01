#ifndef PROJETO_FINAL_INF_112_SERVICO_H
#define PROJETO_FINAL_INF_112_SERVICO_H

#include <string>

class Servico {

    private:
        std::string nome;
        std::string id;       
        double valor;
        int duracao; //Medica em minutos
        std::string ocupacaoRequerida; 

        static int contadorId; //Garantir que todos os IDS dos servicos adicionados sejam diferentes

    public:
        // Construtor e destrutor:
        Servico(std::string nome, double valor, int duracao, std::string ocupacaoRequerida);
        ~Servico();

        // Gets
        std::string getNome() const;
        std::string getId() const;
        double getValor() const;
        int getDuracao() const;
        std::string getOcupacaoRequerida() const;

        // Sets
        void setNome(std::string nome);
        void setValor(double valor);
        void setDuracao(int duracao);
        void setOcupacaoRequerida(std::string tipo);

        //Metodos
        void visualizarDados();

        //Metodo para gerar um novo id para o servico
        std::string gerarNovoId();
};

#endif //PROJETO_FINAL_INF_112_SERVICO_H
