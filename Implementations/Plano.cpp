//Includes
#include "../Headers/Plano.h"
#include "../Headers/Utils.h"
#include <stdexcept>
#include <iostream>

//Construtor
Plano::Plano(std::string nome, double desconto){
    if(stringVazia(nome))
        throw std::invalid_argument("\nNome invalido\n");

    this->nome = nome;

    if(desconto<0 || desconto>=1)
        throw std::invalid_argument("\nDesconto invalido\n");

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
        throw std::invalid_argument("\nNome invalido\n");

    this->nome = nome;
}

void Plano::setDesconto(double desconto){
    if(desconto<=0 || desconto>=1)
        throw std::invalid_argument("\nDesconto invalido\n");

    this->desconto = desconto;

}
void Plano::visualizarDados(){
    
    std::cout << " | Nome: " << nome << std::endl;
    std::cout << " | Desconto: " << desconto*100 << "%\n";
}
