#include "Servico.h"

//Construtor
Servico::Servico(std::string nome, std::string id, double valor, std::string duracao)
    : nome(nome), id(id), valor(valor), duracao(duracao) {
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
