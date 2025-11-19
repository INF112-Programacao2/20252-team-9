//Includes
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include <stdexcept>

//Construtor
Clinica::Clinica(std::string nome, std::unique_ptr<Atendente> atendente)
    :saldo{0}, atendente(atendente){
        if(stringVazia(nome))
        throw std::invalid_argument("Nome invalido");

        this->nome = nome;
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
std::unique_ptr<Atendente>& Clinica::getAtendente() const {return atendente;}

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

