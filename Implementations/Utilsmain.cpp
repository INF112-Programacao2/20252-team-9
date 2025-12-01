#include "../Headers/Utilsmain.h"
#include "../Headers/Utils.h"
#include <cstdlib>
#include <iostream>

void exibirMenuInicial(){
    std::cout << "\n<===========>\n";
    std::cout << "Você deseja utilizar o sistema como: \n";
    std::cout << "1 - Paciente\n";
    std::cout << "2 - Médico\n";
    std::cout << "3 - Atendente\n";
    std::cout << "\n<===========>\n\n";
}

void exibirMenuLogin(std::string &cpf, std::string &senha, bool &acertou){
    std::cout << "\n<===========>\n"; 
    std::cout << "CPF: ";
    getline(std::cin, cpf);
    if(!validaCpf(cpf)){
        acertou = false;
        return;
    }
    std::cout << "Senha: ";
    getline(std::cin, senha);   
}

bool tentarNovamente() {
    std::cout << "\n<===========>\n";
    std::cout << "Você deseja tentar novamente ?\n";
    std::cout << "1 - Sim\n";
    std::cout << "2 - Não\n";
    std::cout << "\n<============>\n\n";
    int escolha;
    escolha = lerInteiro("Digite uma opcao: ", 1, 2);
    if(escolha == 1 ) return true;
    else return false;
}

void exibirMenuMedico() {
    std::cout << "\n<===========>\n";
    std::cout << "1 - Visualizar Dados\n";
    std::cout << "2 - Visualizar agendamentos\n";
    std::cout << "3 - Cancelar Agendamento\n";
    std::cout << "4 - Adicionar Feedback\n";
    std::cout << "5 - Sair\n";
    std::cout << "\n<===========>\n\n";
    std::cout << "Digite o que deseja fazer: ";
}

void exibirMenuPaciente() {
    std::cout << "\n<===========>\n";
    std::cout << "1 - Visualizar Dados\n";
    std::cout << "2 - Alterar dados\n";
    std::cout << "3 - Visualizar Agendamento\n";
    std::cout << "4 - Agendar\n";
    std::cout << "5 - Cancelar agendamentos\n";
    std::cout << "6 - Checar notificações\n";
    std::cout << "7 - Sair\n";
    std::cout << "\n<===========>\n\n";
    std::cout << "Digite o que deseja fazer: ";
}

void exibirMenuAtendente(){
    std::cout << "\n<===========>\n";
    std::cout << "1 - Visualizar Dados\n";
    std::cout << "2 - Alterar serviço\n";
    std::cout << "3 - Cadastrar Médico\n";
    std::cout << "4 - Cadastrar Paciente\n";
    std::cout << "5 - Consultar saldo da clínica\n";
    std::cout << "6 - Criar serviço\n";
    std::cout << "7 - Desligar Médico\n";
    std::cout << "8 - Marcar Agendamento\n";
    std::cout << "9 - Sair\n";
    std::cout << "\n<===========>\n\n";
    std::cout << "Digite o que deseja fazer: ";
}


void enterParaContinuar(){
    std::string enter;
    std::cout << "\nDigite enter para continuar\n";
    getline(std::cin, enter);
    system("clear");
}

void limparTela() {
    system("clear");
}