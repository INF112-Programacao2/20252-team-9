#include "Servico.h"
#include "../Headers/Utils.h"
#include <stdexcept>

//Construtor
Servico::Servico(std::string nome, std::string id, double valor, std::string duracao, std::string tipo)
    : nome(nome), id(id), valor(valor), duracao(duracao), tipo(tipo) {
}

//Destrutor
Servico::~Servico() {
}

//Getters
std::string Servico::getNome() const { 
    return nome; 
}

std::string Servico::getId() const { 
    return id; 
}

double Servico::getValor() const { 
    return valor; 
}

std::string Servico::getDuracao() const { 
    return duracao; 
}

std::string Servico::getTipo() const {return tipo;}

//Setters
void Servico::setNome(std::string nome) {
    this->nome = nome;
}

void Servico::setValor(double valor) {
    this->valor = valor;
}

void Servico::setDuracao(std::string duracao) {
    this->duracao = duracao;
}

void Servico::setTipo(std::string tipo){
    if(stringVazia(tipo))
        throw std::invalid_argument("Tipo de servico invalido");

    this->tipo = tipo;
}
