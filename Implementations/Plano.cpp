//Includes
#include "Plano.h"
#include "Utils.h"
#include <stdexcept>

//Construtor
Plano::Plano(std::string nome, double desconto){
    if(stringVazia(nome))
        throw std::invalid_argument("Nome invalido");

    this->nome = nome;

    if(desconto<=0 || desconto>=1)
        throw std::invalid_argument("Desconto invalido");

    this->desconto = desconto;   
}

//Destrutor
Plano::~Plano(){}

//Getters
std::string Plano::getNome() const {return nome;}
double Plano::getDesconto() const {return desconto;}

//Setters
void Plano::setNome(std::string nome){
    if(stringVazia(nome))
        throw std::invalid_argument("Nome invalido");

    this->nome = nome;
}

void Plano::setDesconto(double desconto){
    if(desconto<=0 || desconto>=1)
        throw std::invalid_argument("Desconto invalido");

    this->desconto = desconto;
}