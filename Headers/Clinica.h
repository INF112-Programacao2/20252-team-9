#ifndef PROJETO_FINAL_INF_112_CLINICA_H
#define PROJETO_FINAL_INF_112_CLINICA_H

#include "Paciente.h"
#include "Medico.h"
#include "Atendente.h"
#include "Agendamento.h"
#include "Servico.h"
#include "Plano.h"
#include <vector>
#include <memory>

class Clinica{
    //Atributos
    private:
        double saldo;
        std::string nome;

        std::vector<std::unique_ptr<Paciente>> pacientes; //Vector que contém todos pacientes da clínica
        std::vector<std::unique_ptr<Medico>> medicos;  //Vector que contém todos os médicos da clínica
        std::vector<std::unique_ptr<Agendamento>> agendamentos; //Vector que contém todos agendamentos da clínica
        std::vector<std::unique_ptr<Servico>> servicos; //Vector que contém todos serviços ofertados pela clínica
        std::vector<std::unique_ptr<Plano>> planos; //Vector que contém todos convênios que a clínica tem contrato
        std::unique_ptr<Atendente>& atendente; //Clinica só irá possuir uma atendente

    public:
        //Construtor
        Clinica(std::string nome, std::unique_ptr<Atendente> atendente);

        //Destrutor
        ~Clinica();

        //Getters
        double getSaldo() const;
        std::string getNome() const;
        std::vector<std::unique_ptr<Paciente>> getPacientes() const;
        std::vector<std::unique_ptr<Medico>> getMedicos() const;
        std::vector<std::unique_ptr<Agendamento>> getAgendamentos() const;
        std::vector<std::unique_ptr<Servico>> getServicos() const;
        std::vector<std::unique_ptr<Plano>> getPlanos() const;
        std::unique_ptr<Atendente>& getAtendente() const;

        //Setters
        void setSaldo(double saldo); 
        void setNome(std::string nome);                                         
        void setAtendente(Atendente &atendente); //Recebe como parametro um objeto do tipo atendente
        
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

        //Controle dos planos(Recebe como parâmetro um objeto do tipo Plano, seja para adicionar ou remover)
        void adicionarPlano(Plano &plano);
        void removerPlano(Plano &plano);

        //Organizar clinica
        void organizarClinica(); //Faz a população da clínica atráves dos dados lidos de um determinado arquivo.
                                 //Dados = Médicos, pacientes, agendamentos, planos e servicos.

};

#endif //PROJETO_FINAL_INF_112_CLINICA_H