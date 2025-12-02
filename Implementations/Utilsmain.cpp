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
    std::cout << "4 - Sair do programa\n";
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
}

bool dadosValidos(std::string &nome, std::string &cpf, std::string &senha, std::string &telefone, std::string &dataDeNascimento, char &sexo, std::string &observacoes, Plano* &plano, Clinica* clinica){
    while (true){
        std::cout << "Nome: ";
        std::getline(std::cin, nome);
        if(stringVazia(nome) || !somenteLetras(nome)){
            std::cout << "O paciente deve ter algum nome.\n";
            enterParaContinuar();
            continue;
        }
        enterParaContinuar();
        break;
    }
    

    while(true) {
        std::cout << "CPF: ";
        getline(std::cin, cpf);
        if(!validaCpf(cpf)){
            std::cout << "CPF inválido, deve seguir o modelo XXX.XXX.XXX-XX, tente novamente\n";
            enterParaContinuar();
            continue;
        }
        if(!(clinica->validarAtendente(cpf, "-1") == -1 && clinica->validarMedico(cpf, "-1") == -1 && clinica->validarPaciente(cpf, "-1") == -1)){
            std::cout << "CPF inválido, esse CPF já está cadastrado.\n";
            enterParaContinuar();
            continue;
        }
        enterParaContinuar();
        break;
    }

    while(true){
        std::cout << "Senha: ";
        std::getline(std::cin, senha);
        if(stringVazia(senha)){
            std::cout << "Senha para criar paciente invalida, nao pode ser vazia. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        enterParaContinuar();
        break;
    }

    while(true){
        std::cout << "Telefone (XX) XXXXX-XXXX: ";
        std::getline(std::cin, telefone);
        if(!validaTelefone(telefone)){
            std::cout << "Telefone invalido, deve seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX, tente novamente\n";
            enterParaContinuar();
            continue;
        }
        enterParaContinuar();
        break;
    }

    while (true){
        std::cout << "Informe a sua data de nascimento: ";
        getline(std::cin, dataDeNascimento);
        if(!validaData(dataDeNascimento)){
            std::cout << "Data inválida, deve seguir o modelo DD/MM/AAAA";
            enterParaContinuar();
            continue; 
        }
        enterParaContinuar();
        break;
    }

    std::string aux;
    while(true) {
        std::cout << "(M) Masculino\n(F) Feminino\nInforme seu sexo: ";
        getline(std::cin, aux);
        sexo = aux[0];
        if(sexo != 'M' && sexo != 'F'){
            std::cout << "Sexo inválido, informe (F) ou (M)";
            enterParaContinuar();
            continue;
        }
        enterParaContinuar();
        break;
    }

    while(true) {
        std::cout << "Informe observações importantes sobre você (Ex: Alergias, Comorbidades): ";
        getline(std::cin, observacoes);
        enterParaContinuar();
        break;
    }

    int cont = 0;
    for(auto &plano : clinica->getPlanos()) {
        cont ++;
        std::cout << "(" << cont << ")" << plano.get()->getNome() << " Desconto(%): " << plano.get()->getDesconto()* 100 << "\n";
    }

    int escolha = lerInteiro("Escolha o seu plano: ", 1, cont);
    

    plano = clinica->getPlanos()[escolha - 1].get();

    return true;
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

void acharMedico(Clinica *clinica, const std::string& cpf, Medico*& medico){
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica->getMedicos();
    
    for(long unsigned int i=0; i<medicos.size(); i++){
        if(medicos[i].get()->getCpf() == cpf){
            medico = medicos[i].get();
            return;
        }
    }
}

void acharPaciente(Clinica *clinica, const std::string& cpf, Paciente*& paciente){
    const std::vector<std::unique_ptr<Paciente>>& pacientes = clinica->getPacientes();

    for(long unsigned int i=0; i<pacientes.size(); i++){
        if(pacientes[i].get()->getCpf() == cpf){
            paciente = pacientes[i].get();
            return;
        }
    }
}