#include "../Headers/Servico.h"
#include "../Headers/Utils.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>

int Servico::contadorId = 0;

//Construtor
Servico::Servico(std::string nome, double valor, int duracao, std::string ocupacaoRequerida){
    if(stringVazia(nome))
        throw std::invalid_argument("Nome para servico invalido");
    this->nome = nome;

    this->id = gerarNovoId();

    if(valor < 0)
        throw std::invalid_argument("Valor do servico nao pode ser negativo");
    this->valor = valor;

    if(duracao <= 0)
        throw std::invalid_argument("A duracao do servico nao pode ser negativa ou nula");
    this->duracao = duracao;

    if(stringVazia(ocupacaoRequerida))
        throw std::invalid_argument("Ocupacao requerida para o servico invalida");
    this->ocupacaoRequerida = ocupacaoRequerida;
}

//Destrutor
Servico::~Servico(){}

//Getters
std::string Servico::getNome() const {return nome;}
std::string Servico::getId() const {return id;}
double Servico::getValor() const {return valor;}
int Servico::getDuracao() const {return duracao;}
std::string Servico::getOcupacaoRequerida() const {return ocupacaoRequerida;}

//Setters
void Servico::setNome(std::string nome) {
    if(stringVazia(nome))
        throw std::invalid_argument("Nome para servico invalido");
    this->nome = nome;
}

void Servico::setValor(double valor) {
    if(valor < 0)
        throw std::invalid_argument("Valor do servico nao pode ser negativo");
    this->valor = valor;
}

void Servico::setDuracao(int duracao) {
    if(duracao <= 0)
        throw std::invalid_argument("A duracao do servico nao pode ser negativa ou nula");
    this->duracao = duracao;
}

void Servico::setOcupacaoRequerida(std::string ocupacaoRequerida){
    if(stringVazia(ocupacaoRequerida))
        throw std::invalid_argument("Ocupacao requerida para o servico invalida");
    this->ocupacaoRequerida = ocupacaoRequerida;
}

//Metodos

void Servico::visualizarDados(){
    std::cout << "====Dados do Serviço===\n";
    std::cout << "ID: " << this->getId() << std::endl;
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Valor: " << this->getValor() << std::endl;
    std::cout << "Duração: " << this->getDuracao() << std::endl;
    std::cout << "Ocupação Requerida: " << this->getOcupacaoRequerida() << std::endl;
}


//Metodo para gerar novo id para os servicos
std::string Servico::gerarNovoId(){
    contadorId++;

    std::stringstream novoId;
    novoId << "ODO" << std::setfill('0') << std::setw(3) << contadorId;
    return novoId.str();    
}