#ifndef PROJETO_FINAL_INF_112_CLINICA_H
#define PROJETO_FINAL_INF_112_CLINICA_H
#include "Paciente.h"
#include "Medico.h"
#include "Atendente.h"
#include "Agendamento.h"
#include "Servico.h"

#include <string>
#include <vector>

class Clinica{
    //Atributos
    private:
        double saldo;

        std::vector <Paciente>* pacientes; //Vector que contém todos pacientes da clínica
        std::vector <Medico>* medicos;  //Vector que contém todos os médicos da clínica
        std::vector <Agendamento>* agendamentos; //Vector que contém todos agendamentos da clínica
        std::vector <Servico>* servicos;
        Atendente* atendente; //Clinica só irá possuir uma atendente

    public:
        //Construtor
        Clinica();

        //Destrutor
        ~Clinica();

        //Getters
        double getSaldo() const;
        std::vector <Paciente>* getPacientes() const;
        std::vector <Medico>* getMedicos() const;
        std::vector <Agendamento>* getAgendamentos() const;
        Atendente* getAtendente() const;

        //Setters
        void setAtendente(Atendente* atendente); 
        void setSaldo(double saldo);                                          
        
        /*Métodos*/

        //Controle dos pacientes(Recebe como parâmetro um objeto do tipo Paciente, seja para adicionar ou remover)
        void adicionarPaciente(Paciente &paciente); 
        void removerPaciente(Paciente &Paciente);

        //Controle dos médicos(Recebe como parâmetro um objeto do tipo Medico, seja para adicionar ou remover)
        void adicionarMedico(Medico &medico);
        void removerMedico(Medico &medico);

        //Controle dos agendamentos(Recebe como parâmetro um objeto do tipo Agendamento, seja para adicionar ou remover)
        void adicionarAgendamento(Agendamento &agendamento);
        void removerAgendamento(Agendamento &agendamento);

        //Controle dos serviços(Recebe como parâmetro um objeto do tipo Servico, seja para adicionar ou remover)
        void adicionarServico(Servico &servico);
        void adicionarServico(Servico &servico);

        //Organizar clinica
        void organizarClinica(); //Faz a população da clínica atráves dos dados lidos de um determinado arquivo.
                                 //Dados = Médicos, pacientes, agendamentos e servicos.

};

#endif //PROJETO_FINAL_INF_112_CLINICA_H