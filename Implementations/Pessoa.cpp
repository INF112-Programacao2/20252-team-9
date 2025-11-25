#include "../Headers/Pessoa.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

//Construtor
Pessoa :: Pessoa(std::string nome, std::string cpf, std::string senha, std::string telefone)
: nome(nome), cpf(cpf), senha(senha), telefone(telefone){

}

//Destrutor
Pessoa :: ~Pessoa(){}
        
//Gets
std::string Pessoa :: getNome() const{
    return nome;
}

std::string Pessoa :: getCpf() const{
    return cpf;
}

std::string Pessoa :: getSenha() const{
    return senha;
}
std::string Pessoa :: getTelefone() const{
    return telefone;
}
        

//Sets
void Pessoa :: setNome( std::string nome){
    this->nome = nome;
}

void Pessoa :: setSenha(std::string senha){
    this->senha = senha;
}

void Pessoa :: setTelefone(std::string telefone){
    this->telefone = telefone;
}
        
//Métodos
//Impressão dos dados do usuário:
void Pessoa :: VizualizaDados(){ // Versão genérica com só os dados de pessoa 
    std::cout << "---------------- Impressao de Dados ---------------\n\n";
    std::cout << "Nome: " << nome << std ::endl;
    std::cout << "CPF: " << cpf <<std::endl;
    std::cout << "Contato: " << telefone <<std::endl;

}
