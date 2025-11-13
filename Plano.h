#ifndef PROJETO_FINAL_INF_112_PLANO
#define PROJETO_FINAL_INF_112_PLANO
#include "string"

class Plano{
    //Atributos
    private:
        std::string nome;
        double desconto;

    //Metodos
    public:
        //Construtor
        Plano(std::string nome, double desconto);

        //Destrutor
        ~Plano();

        //Getters
        std::string getNome() const;
        double getDesconto() const;

        //Setters
        void setNome(std::string nome);
        void setDesconto(double desconto);
};

#endif