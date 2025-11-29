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
        Atendente* atendente; //Clinica só irá possuir uma atendente

    public:
        //Construtor
        Clinica(std::string nome);

        //Destrutor
        ~Clinica();

        //Getters
        double getSaldo() const;
        std::string getNome() const;
        const std::vector<std::unique_ptr<Paciente>>& getPacientes() const;
        const std::vector<std::unique_ptr<Medico>>& getMedicos() const;
        const std::vector<std::unique_ptr<Agendamento>>& getAgendamentos() const;
        const std::vector<std::unique_ptr<Servico>>& getServicos() const;
        const std::vector<std::unique_ptr<Plano>>& getPlanos() const;
        Atendente* getAtendente() const;

        //OBS: Unique_prts não permitem cópia em nenhum contexto, inclusive no loop que forem fazer para percorrer esses vetores
        //Por isso olhem na implementação como percorre esses vetores e como obtem as referencias desses ponteiros

        //Setters
        void setSaldo(double saldo); 
        void setNome(std::string nome);                                         
        void setAtendente(Atendente &atendente); //Recebe como parametro um objeto do tipo atendente
        
        /*Métodos*/

        //Exemplo de chamada para os métodos abaixo!
        //Plano plano = Plano("UNIMED", 0.5);
        //clinica.adicionarPlano(std::make_unique<Plano>(plano));
        //OU
        //Clinica.adicionarPlano(std::make_unique<Plano>("UNIMED", 0.5))
        //Da segunda forma você evita criar um objeto na stack, por mais que provavelmente ele seja destruido logo após a chamada
        //Para remover basta realmente só passar um ponteiro que contenha o endereço do objeto

        //Controle dos pacientes(Recebe como parâmetro um objeto do tipo Paciente, seja para adicionar ou remover)
        void adicionarPaciente(std::unique_ptr<Paciente> paciente); 
        void removerPaciente(Paciente* paciente);

        //Controle dos médicos(Recebe como parâmetro um objeto do tipo Medico, seja para adicionar ou remover)
        void adicionarMedico(std::unique_ptr<Medico> medico);
        void removerMedico(Medico* medico);

        //Controle dos agendamentos(Recebe como parâmetro um objeto do tipo Agendamento, seja para adicionar ou remover)
        void adicionarAgendamento(std::unique_ptr<Agendamento> agendamento);
        void removerAgendamento(Agendamento* agendamento);

        //Controle dos serviços(Recebe como parâmetro um objeto do tipo Servico, seja para adicionar ou remover)
        void adicionarServico(std::unique_ptr<Servico> servico);
        void removerServico(Servico* servico);

        //Controle dos planos(Recebe como parâmetro um objeto do tipo Plano, seja para adicionar ou remover)
        void adicionarPlano(std::unique_ptr<Plano> plano);
        void removerPlano(Plano* plano);

        //Organizar clinica
        void popularClinica(std::string arquivo); //Faz a população da clínica atráves dos dados lidos de um determinado arquivo.
                                 //Dados = Médicos, pacientes, agendamentos, planos e servicos.

};

#endif //PROJETO_FINAL_INF_112_CLINICA_H