#ifndef PROJETO_FINAL_INF_112_MEDICO_H
#define PROJETO_FINAL_INF_112_MEDICO_H

#include <string>
#include <vector>
#include "Pessoa.h" 

class Agendamentos{};

class Medico : public Pessoa {

    private:
        std::string crm;
        std::string ocupacao;
        double saldo;
        std::vector<Agendamentos*> agendamentos; 

    public:
        // Construtor e destrutor:
        Medico(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string crm, std::string ocupacao, double saldo);
        ~Medico();

        // Gets
        std::string getCrm() const;
        std::string getOcupacao() const;
        double getSaldo() const;

        // Sets
        void setOcupacao(std::string ocupacao);
        void setSaldo(double saldo);

        // Métodos
        virtual void VizualizaDados() override; // Reescrita do método de pessoa, 
                                                // imprime todos os dados de pessoa e também os dados especificos do médico 

        virtual void VizualizaAgendamentos() override; // Reescrita do método de pessoa, 
                                                       // imprime todos os agendamentos já realizados e os previstos para esse médico

        void CancelarAgendamento(); // Cancela um agendamento 
        
        void AdicionarFeedBack(); // Adiciona um comentário a um agendamento que já ocorreu  

};

#endif //PROJETO_FINAL_INF_112_MEDICO_H
