#ifndef PROJETO_FINAL_INF_112_MEDICO_H
#define PROJETO_FINAL_INF_112_MEDICO_H

#include <string>
#include "Pessoa.h" 

class Medico : public Pessoa {
    //Atributos
    private:
        std::string crm;
        std::string ocupacao;
        double saldo;

    //Metodos
    public:
        //Construtor e destrutor:
        Medico(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string crm, std::string ocupacao);
        ~Medico();

        //Getters
        std::string getCrm() const;
        std::string getOcupacao() const;
        double getSaldo() const;

        //Setters
        void setOcupacao(std::string ocupacao);
        void setSaldo(double saldo);

        //Demais métodos
        virtual void VizualizaDados() override; // Reescrita do método de pessoa, 
                                                // imprime todos os dados de pessoa e também os dados especificos do médico 

        virtual void VizualizaAgendamentos(Clinica* clinica) override; // Reescrita do método de pessoa, 
                                                       // imprime todos os agendamentos já realizados e os previstos para esse médico

        void CancelarAgendamento(Clinica* clinica); // Cancela um agendamento 
        
        void AdicionarFeedBack(Clinica* clinica); // Adiciona um comentário a um agendamento que já ocorreu  
};

#endif //PROJETO_FINAL_INF_112_MEDICO_H
