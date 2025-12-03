#include "../Headers/Utilsmain.h"
#include "../Headers/Utils.h"
#include <cstdlib>
#include <iostream>

void exibirMenuInicial(){
    std::cout << "================================================\n";
    std::cout << "                      LOGIN                     \n";
    std::cout << "================================================\n";
    std::cout << " 1.: Paciente\n";
    std::cout << " 2.: Médico\n";
    std::cout << " 3.: Atendente\n";
    std::cout << " 4.: Sair do programa\n";
    std::cout << "------------------------------------------------\n";
}
//Paciente Médico Atendente Sair do programa

void exibirMenuLogin(std::string &cpf, std::string &senha, bool &acertou){
    std::cout << "================================================\n";
    std::cout << "                      LOGIN                     \n";
    std::cout << "================================================\n";
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
    std::cout << "\n================================================\n";
    std::cout << "Deseja tentar novamente ?\n";
    std::cout << "1.: Sim\n";
    std::cout << "2.: Não\n";
    std::cout << "================================================\n";
    int escolha;
    escolha = lerInteiro("Digite sua escolha: ", 1, 2);
    if(escolha == 1 ) return true;
    else return false;
}

void exibirMenuMedico() {
    std::cout << "================================================\n";
    std::cout << "                      MENU                      \n";
    std::cout << "================================================\n";
    std::cout << " 1.: Visualizar Dados Pessoais\n";
    std::cout << " 2.: Visualizar Agendamentos\n";
    std::cout << " 3.: Alterar Dados\n";
    std::cout << " 4.: Cancelar Agendamento\n";
    std::cout << " 5.: Adicionar Feedback\n";
    std::cout << " 6.: Sair\n";
    std::cout << "------------------------------------------------\n";
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
        break;
    }

    std::string aux;
    while(true) {
        std::cout << "M.: Masculino\nF.: Feminino\nInforme seu sexo: ";
        getline(std::cin, aux);
        sexo = aux[0];
        if(sexo != 'M' && sexo != 'F'){
            std::cout << "Sexo inválido, informe (F) ou (M)";
            enterParaContinuar();
            continue;
        }
        break;
    }

    while(true) {
        std::cout << "Informe observações importantes sobre você (Ex: Alergias, Comorbidades): ";
        getline(std::cin, observacoes);
        break;
    }

    int cont = 0;
    std::cout << std::endl;
    for(auto &plano : clinica->getPlanos()) {
        cont ++;
        std::cout << cont << ":." << plano.get()->getNome() << " | Desconto(%): " << plano.get()->getDesconto()* 100 << "\n";
    }

    int escolha = lerInteiro("Digite sua escolha: ", 1, cont);
    

    plano = clinica->getPlanos()[escolha - 1].get();

    return true;
}

void exibirMenuPaciente() {
    std::cout << "================================================\n";
    std::cout << "                      MENU                      \n";
    std::cout << "================================================\n";
    std::cout << " 1.: Visualizar Dados Pessoais\n";
    std::cout << " 2.: Alterar Dados\n";
    std::cout << " 3.: Visualizar Agendamentos\n";
    std::cout << " 4.: Agendar\n";
    std::cout << " 5.: Cancelar Agendamento\n";
    std::cout << " 6.: Checar notificações\n";
    std::cout << " 7.: Sair\n";
    std::cout << "------------------------------------------------\n";
}

void exibirMenuAtendente(){
    std::cout << "================================================\n";
    std::cout << "                      MENU                      \n";
    std::cout << "================================================\n";
    std::cout << " 1.: Visualizar Dados Pessoais\n";
    std::cout << " 2.: Visualizar Agendamentos\n";
    std::cout << " 3.: Visualizar Pacientes\n";
    std::cout << " 4.: Visualizar Médicos\n";
    std::cout << " 5.: Visualzar Serviços\n";
    std::cout << " 6.: Visualizar Planos\n";
    std::cout << " 7.: Marcar Agendamento para Paciente\n";
    std::cout << " 8.: Cadastrar Novo Paciente\n";
    std::cout << " 9.: Cadastrar Novo Médico\n";
    std::cout << " 10.: Cadastrar Novo Serviço\n";
    std::cout << " 11.: Cadastrar Novo Plano\n";
    std::cout << " 12.: Alterar Dados Pessoais\n";
    std::cout << " 13.: Alterar Agendamento\n";
    std::cout << " 14.: Alterar Paciente\n";
    std::cout << " 15.: Alterar Médico\n";
    std::cout << " 16.: Alterar Servico\n";
    std::cout << " 17.: Alterar Plano\n";
    std::cout << " 18.: Remover Agendamento\n";
    std::cout << " 19.: Remover Paciente\n";
    std::cout << " 20.: Remover Médico\n";
    std::cout << " 21.: Remover Serviço\n";
    std::cout << " 22.: Remover Plano\n";
    std::cout << " 23.: Consultar Saldo da Clínica\n";
    std::cout << " 24.: Exibir Histórico de Transações da Clínica\n";
    std::cout << " 25.: Sair\n";
    std::cout << "------------------------------------------------\n";
}

//Visualizar dados pessoais
//Visualisar Agendamentos
//Visualizar pacientes
//Visualizar medicos
//Visualizar servicos
//Visualizar planos
//Marcar agendamento para paciente
//Cadastrar Novo Paciente
//Cadastrar Novo Medico
//Cadastrar novo servico
//Cadastrar novo plano
//Alterar dados atendente
//Alterar agendamento
//Alterar paciente
//Alterar Médico
//Alterar servico
//Alterar plano
//Remover  Agendamento
//Remover paciente
//Remover medico
//Remover servico
//Remover plano
//Sair



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