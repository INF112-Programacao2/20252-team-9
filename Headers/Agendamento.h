#ifndef PROJETO_FINAL_INF_112_AGENDAMENTO_H
#define PROJETO_FINAL_INF_112_AGENDAMENTO_H

#include "Agendamento.h"
#include "Medico.h"
#include "Servico.h"
#include "Plano.h"

#include <string>

class Agendamento{
    
    private:
        std::string data;
        std::string horario;
        std::string feedback;

        Paciente *paciente;  //Ponteiro para o paciente do agendamento
        Medico *medico; //Ponteiro para o medico do agendamento
        Servico *servico;   //Serviço do agendamento

    public:

        Agendamento(std::string data, std::string horario, Paciente* paciente, Medico* medico, Servico* servico);  //Construtor que instancia agendamento com todos os seus atributos

        ~Agendamento(); //Destrutor

        //Getters 
        std::string getData() const;
        std::string getHorario() const;
        std::string getFeedback() const;
        Paciente* getPaciente() const;
        Medico* getMedico() const;
        Servico* getServico() const;

        //Setters 
        void setData(std::string data);
        void setHorario(std::string horario);
        void setFeedback(std::string feedback);
        void setPaciente(Paciente* paciente);
        void setMedico(Medico* medico);
        void setServico(Servico* servico);

        void imprimir() const; //Método que imprime todos os dados do agendamento
};

#endif