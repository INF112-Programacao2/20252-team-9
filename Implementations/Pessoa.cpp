#include "../Headers/Pessoa.h"
#include "../Headers/Utils.h"
#include "../Headers/Clinica.h"
#include "../Headers/Utilsmain.h"
#include <string>
#include <iostream>
#include <stdexcept>

//Construtor
Pessoa::Pessoa(std::string nome, std::string cpf, std::string senha, std::string telefone){
    if(stringVazia(nome) || !somenteLetras(nome))
        throw std::invalid_argument("\nNome para pessoa invalido\n");
    this->nome = nome;

    if(!validaCpf(cpf))
        throw std::invalid_argument("\nCPF para pessoa invalido, deve seguir o modelo XXX.XXX.XXX-XX\n");
    this->cpf = cpf;

    if(stringVazia(senha))
        throw std::invalid_argument("\nSenha para pessoa invalida\n");
    this->senha = senha;
    
    if(!validaTelefone(telefone))
        throw std::invalid_argument("\nTelefone para pessoa invalido, deve seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX\n");
    this->telefone = telefone;
}

//Destrutor
Pessoa::~Pessoa(){}
        
//Gets
std::string Pessoa::getNome() const {return nome;}
std::string Pessoa::getCpf() const {return cpf;}
std::string Pessoa::getSenha() const {return senha;}
std::string Pessoa::getTelefone() const {return telefone;}

//Sets
void Pessoa :: setNome( std::string nome){
    if(stringVazia(nome))
        throw std::invalid_argument("\nNome para pessoa invalido\n");
    this->nome = nome;
}

void Pessoa :: setSenha(std::string senha){
    if(stringVazia(senha))
        throw std::invalid_argument("\nSenha para pessoa invalida\n");
    this->senha = senha;
}

void Pessoa :: setTelefone(std::string telefone){
    if(!validaTelefone(telefone))
        throw std::invalid_argument("\nTelefone para pessoa invalido, deve seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX\n");
    this->telefone = telefone;
}
        
//Métodos
//Impressão dos dados do usuário:
void Pessoa :: VisualizaDados(){ // Versão genérica com só os dados de pessoa 
    std::cout << "\n | Nome: " << nome << std ::endl;
    std::cout << " | CPF: " << cpf <<std::endl;
    std::cout << " | Telefone: " << telefone <<std::endl;
}

void Pessoa::alterarDados(Clinica *clinica){
    std::cout << "teste\n";
}