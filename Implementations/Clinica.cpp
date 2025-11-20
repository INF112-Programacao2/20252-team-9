//Includes
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include <stdexcept>

//Construtor
Clinica::Clinica(std::string nome)
    :saldo{0}{
        if(stringVazia(nome))
        throw std::invalid_argument("Nome invalido");

        this->nome = nome;
        this->atendente = nullptr;
    }

//Destrutor
Clinica::~Clinica(){}

//Getters
double Clinica::getSaldo() const {return saldo;}
std::string Clinica::getNome() const {return nome;}
std::vector<std::unique_ptr<Paciente>> Clinica::getPacientes() const {return pacientes;}
std::vector<std::unique_ptr<Medico>> Clinica::getMedicos() const {return medicos;}
std::vector<std::unique_ptr<Agendamento>> Clinica::getAgendamentos() const {return agendamentos;}
std::vector<std::unique_ptr<Servico>> Clinica::getServicos() const {return servicos;}
std::vector<std::unique_ptr<Plano>> Clinica::getPlanos() const {return planos;}
Atendente* Clinica::getAtendente() const {return atendente;}

//Setters
void Clinica::setSaldo(double saldo){
    if(saldo<0)
        throw std::invalid_argument("Saldo nao pode ser negativo");

    this->saldo = saldo;
}

void Clinica::setNome(std::string nome){
    if(stringVazia(nome))
       throw std::invalid_argument("Nome invalido");

    this->nome = nome;
}

void Clinica::setAtendente(Atendente &atendente){
    this->atendente = &atendente;
}


//Controle dos pacientes
void Clinica::adicionarPaciente(std::unique_ptr<Paciente> paciente){
    if(!paciente)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    pacientes.push_back(std::move(paciente));
}

void Clinica::removerPaciente(Paciente* paciente){
    if(!paciente)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(int i=0; i<pacientes.size(); i++){
        if(pacientes[i].get() == paciente){
            pacientes.erase(pacientes.begin() + i);
            break;
        }
    }

    //Remove tambem os agendamentos associados a ele
    for(int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getPaciente() == paciente){
            agendamentos.erase(agendamentos.begin() + i);
        }
    }
}

//Controle dos medicos
void Clinica::adicionarMedico(std::unique_ptr<Medico> medico){
    if(!medico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    medicos.push_back(std::move(medico));
}

void Clinica::removerMedico(Medico* medico){
    if(!medico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(int i=0; i<medicos.size(); i++){
        if(medicos[i].get() == medico){
            medicos.erase(medicos.begin() + i);
            break;
        }
    }

    //Remove tambem os agendamentos associados a ele
    for(int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico() == medico){
            agendamentos.erase(agendamentos.begin() + i);
        }
    }
}

//Controle dos agendamentos
void Clinica::adicionarAgendamento(std::unique_ptr<Agendamento> agendamento){
    if(!agendamento)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    agendamentos.push_back(std::move(agendamento));
}

void Clinica::removerAgendamento(Agendamento* agendamento){
    if(!agendamento)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get() == agendamento){
            agendamentos.erase(agendamentos.begin() + i);
            break;
        }
    }
}

//Controle dos serviços
void Clinica::adicionarServico(std::unique_ptr<Servico> servico){
    if(!servico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    servicos.push_back(std::move(servico));
}

void Clinica::removerServico(Servico* servico){
    if(!servico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(int i=0; i<servicos.size(); i++){
        if(servicos[i].get() == servico){
            servicos.erase(servicos.begin() + i);
            break;
        }
    }
}

//Controle dos planos
void Clinica::adicionarPlano(std::unique_ptr<Plano> plano){
    if(!plano)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    planos.push_back(std::move(plano));
}

void Clinica::removerPlano(Plano* plano){
    if(!plano)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(int i=0; i<planos.size(); i++){
        if(planos[i].get() == plano){
            planos.erase(planos.begin() + i);
            break;
        }
    }
}