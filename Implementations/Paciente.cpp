#include "../Headers/Paciente.h"
#include "../Headers/Pessoa.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

Paciente :: Paciente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string dataDeNascimento, char sexo, std::string observacoes, Plano* plano)
    : Pessoa(nome, cpf, senha, telefone), dataDeNascimento(dataDeNascimento), sexo(sexo), observacoes(observacoes), plano(plano) {}

Paciente :: ~Paciente(){}
        
//Gets
std::string Paciente :: getDataDeNascimento() const{
    return dataDeNascimento;
}

char Paciente :: getSexo() const{
    return sexo;
}

std::string Paciente :: getObservacoes() const{
    return observacoes;
}

Plano* Paciente :: getPlano() const{
    return plano;
}
        
        
//Sets
void Paciente :: setObservacoes(std::string observacoes){
    (this->observacoes) = observacoes;

}

void Paciente :: setSexo(char sexo){
    (this->sexo)=sexo;

}

void Paciente :: setPlano(Plano &plano){
    (this->plano)=&plano;
}
        

//Métodos
//Impressão dos dados do usuário:
void Paciente :: AlteraDados(){ //Abre um menu, em que o paciente seleciona usando números qual atributo 
                            // ele deseja alterar, e o método chama o método set correspondente.
    int escolha;

    std::cout <<"------------------Menu de Ajuste dos Dados------------------"<<std::endl;
    std::cout << "1 - Nome\n";
    std::cout << "2 - Senha\n";
    std::cout << "3 - Telefone\n";
    std::cout << "4 - Observações\n";
    std::cout << "5 - Sexo\n";
    std::cout << "6 - Plano de saude\n";
    std::cout <<"\n Digite o numero do dado que deseja alterar:";
    std::cin>> escolha;
    std::cout << std::endl;
}


void Paciente :: VizualizaDados(){} // Sobreescrita do método da superclasse, além dos dados de pessoa
                                       // imprime também data de nascimento, sexo, as observações e plano de saúde

//Impressão dos agendamentos:
void Paciente :: VizualizaAgendamentos(Clinica &clinica){} //Reescrita do método de pessoa, imprime todos os agendamentos já
                                      // realizados e os previstos para esse paciente.
        
void Paciente :: Agendar(Clinica &clinica){} //Preenche os dados e cria um agendamento, e o adiciona no vetor agendamentos

void Paciente :: CancelarAgendamento(Clinica &clinica){} // Cancela um agendamento 
