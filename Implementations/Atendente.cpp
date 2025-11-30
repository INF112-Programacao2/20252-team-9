#include "../Headers/Atendente.h"
#include "../Headers/Utils.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <iomanip>

//Construtor e Destrutor
Atendente::Atendente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string matricula):
    Pessoa(nome, cpf, senha, telefone)
    {
        if(stringVazia(matricula))
            throw std::invalid_argument("Matricula inválida.\n");

        this->matricula = matricula;
    };

Atendente::~Atendente() {};

//Gets e Sets
std::string Atendente::getMatricula() const {return matricula;}

void Atendente::setMatricula(std::string nova_matricula) {
    if(stringVazia(nova_matricula))
        throw std::invalid_argument("Matricula Inválida");
    this->matricula = nova_matricula;
}

void Atendente::ConsultaSaldoDaClinica(Clinica* clinica){
    std::cout << "Saldo da Clínica (R$): " << std::fixed << std::setprecision(2) << clinica->getSaldo() << "\n";
}


//Metodos

void Atendente::VizualizaDados(){
    std::cout << "Dados do(a) Atendente:\n";
    Pessoa::VizualizaDados();

    std::cout << "Matrícula: " << this->getMatricula() << "\n";
}

void Atendente::VizualizaAgendamentos(Clinica* clinica){
    int n;
    do{
        std::cout << "Você deseja visualizar os agendamentos de: \n (1)Paciente \n(2)Médico\n";
        std:: cin >> n;

        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            n = 0;
        }

    } while(n != 1 && n != 2);

    if(n == 1){
        std::cout << "Lista dos Médicos que deseja ver os agendamentos: \n";
        const auto &listaMedicos = clinica->getMedicos();
        int cont = 0;
        for(auto &med : listaMedicos) {
            cont++;
            std::cout << "(" << cont << ")" << med->getNome() << " CRM: " << med->getCrm() << "\n";
        }

        int escolha;

        do {
            std::cout << "Digite o identificador do Médico que deseja visualizar as consultas: ";
            std::cin >> escolha;
            
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                escolha = -1;
            }

        } while(escolha <= 0 || escolha > cont);

        listaMedicos[escolha-1]->VizualizaAgendamentos(clinica);

    }
    else {
        std::cout << "Lista dos pacientes que deseja ver os agendamentos: \n";
        const auto &listaPacientes = clinica->getPacientes();
        int cont = 0;
        for(auto &pac : listaPacientes){
            cont++;
            std::cout << "(" << cont << ")" << pac->getNome() << " CPF: " << pac->getCpf() << "\n";
        }

        int escolha;

        do {
            std::cout << "Digite o identificador do Paciente que deseja visualizar as consultas: ";
            std::cin >> escolha;

            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                escolha = -1;
            }
        } while (escolha <= 0 || escolha > cont);

        listaPacientes[escolha-1]->VizualizaAgendamentos(clinica);

    }

}

void Atendente::CadastrarMedico(Clinica* clinica) {
    std::string nome, cpf, senha, telefone, crm, ocupacao;
    std::cout << "Preencha os dados para o novo medico da clinica:\n";

    while(true){
        std::cout << "Nome do medico: ";
        std::getline(std::cin, nome);
        if(stringVazia(nome)){
            std::cout << "Nome para criar medico invalido, nao pode ser vazio. Tente novamente\n";
            continue;
        }
        break;
    }

    while(true){
        std::cout << "CPF do medico: ";
        std::getline(std::cin, cpf);
        if(!validaCpf(cpf)){
            std::cout << "CPF invalido, deve seguir o modelo XXX.XXX.XXX-XX, tente novamente\n";
            continue;
        }
        break;
    }

    while(true){
        std::cout << "Senha do medico: ";
        std::getline(std::cin, senha);
        if(stringVazia(senha)){
            std::cout << "Senha para criar medico invalido, nao pode ser vazia. Tente novamente\n";
            continue;
        }
        break;
    }

    while(true){
        std::cout << "Telefone do medico: ";
        std::getline(std::cin, telefone);
        if(!validaTelefone(telefone)){
            std::cout << "Telefone invalido, deve seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX, tente novamente\n";
            continue;
        }
        break;
    }

    while(true){
        std::cout << "Crm do medico: ";
        std::getline(std::cin, crm);
        if(!validaCrm(crm)){
            std::cout << "Crm para criar medico invalido, tem de seguir o modelo SIGLA/UF NUMERO. Tente novamente\n";
            continue;
        }
        break;
    }

    while(true){
        std::cout << "Ocupacao do medico: ";
        std::getline(std::cin, ocupacao);
        if(stringVazia(ocupacao)){
            std::cout << "Ocupacao para criar medico invalida, nao pode ser vazia. Tente novamente\n";
            continue;
        }
        break;
    }

    for(auto &medicos : clinica->getMedicos())
    {
       if(medicos->getCpf() == cpf)
       {
        std::cout << "Não é possível criar um médico com um cpf já cadastrado.\n";
        return;
       }

       if(medicos->getCrm() == crm)
       {
        std::cout << "Não é possível criar um médico com um crm já cadastrado.\n";
        return;
       }

    }
    try{
        clinica->adicionarMedico(std::make_unique<Medico>(nome, cpf, senha, telefone, crm, ocupacao));
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::DesligarMedico(Clinica* clinica){
    //Recebe a lista de medicos
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica->getMedicos();
    
    if(medicos.empty()){
        std::cout << "Nao há nenhum medico cadastrado ainda. Cadastre pelo menos um antes de tentar excluir\n";
        return;
    }

    //Imprime a lista de medicos
    int lastIndex = 1;
    for(int i=0; i<medicos.size(); i++){
        std::cout << i+1 << ". Nome: " << medicos[i].get()->getNome() << " | CRM: " << medicos[i].get()->getCrm() << " | Ocupacao: " << medicos[i].get()->getOcupacao() << std::endl;
        lastIndex++;
    }

    //Escolhe qual medico excluir
    int escolha = lerInteiro("Digite o medico que se deseja excluir: ", 1, lastIndex);
    
    //Exclui o medico
    try{
        clinica->removerMedico(medicos[escolha-1].get());
        std::cout << "Medico removido com sucesso.";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::CriarServico(Clinica* clinica){
    std::string nome, ocupacaoRequerida;
    double valor;
    int duracao;

    std::cout << "Preencha os dados para o novo servico da clinica:\n";
    
    while(true){
        std::cout << "Nome do servico: ";
        std::getline(std::cin, nome);
        if(stringVazia(nome)){
            std::cout << "Nome para criar servico invalido, nao pode ser vazio. Tente novamente\n";
            continue;
        }
        break;
    }

    valor = lerDouble("Valor(R$): ", 0, 1000000000);
    duracao = lerInteiro("Duracao(min): ", 1, 1000000000);

    std::cout << "Ocupacao requerida: ";
    while(true){
        std::getline(std::cin, ocupacaoRequerida);
        if(stringVazia(ocupacaoRequerida)){
            std::cout << "Ocupacao requerida para criar servico invalida, nao pode ser vazia. Tente novamente\n";
            continue;
        }
        break;
    }

    try{
        clinica->adicionarServico(std::make_unique<Servico>(nome, valor, duracao, ocupacaoRequerida));
        std::cout << "Serviço cadastrado com sucesso!\n";
    }catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::AlterarServico(Clinica *clinica){
    std::cout << "====Lista de Serviços===\n";
    int cont = 0;
    for (auto &serv : clinica->getServicos()) {
        cont++;
        std::cout << "(" << cont << ") " << serv.get()->getNome() << " ID: " << serv.get()->getId() << "\n";
    }
    
    int escolha = lerInteiro("Escolha qual serviço deseja alterar: ", 1, cont);

    Servico *servico_alterar = clinica->getServicos()[escolha-1].get();

    servico_alterar->visualizarDados();

    std::cout << "Escolha qual deseja alterar: \n";
    std::cout << "(1) Nome\n";
    std::cout << "(2) Valor\n";
    std::cout << "(3) Duração\n";
    std::cout << "(4) Ocupação Requerida\n";

    int escolha_alterar = lerInteiro("", 1, 4);

    std::cin.ignore(10000, '\n');

    if(escolha_alterar == 1)
    {
        std::string novo_nome;
        
        std::cout << "Informe o novo nome do serviço: ";

        while (true){
            getline(std::cin, novo_nome);
            if(!stringVazia(novo_nome))
                break;
            std::cout << "O nome não pode ser vazio, digite um nome válido: "; 
        }

        try {
            servico_alterar->setNome(novo_nome);
            std::cout << "Nome do serviço alterado com sucesso!\n";
        }
        catch(std::invalid_argument &e){
            std::cout << e.what() << "\n";
        }


    }
    else if(escolha_alterar == 2)
    {
        double novo_valor = lerDouble("Informe o novo valor do serviço: ", 0.0, 100000.0);
        try{
            servico_alterar->setValor(novo_valor);
            std::cout << "Valor do serviço alterado com sucesso!\n";
        }
        catch(std::invalid_argument &e) {
            std::cout << e.what() << "\n";
        }
    }
    else if(escolha_alterar == 3)
    {
        int nova_duracao = lerInteiro("Informe a nova duração do serviço: ", 0, 10000);
        try{
            servico_alterar->setDuracao(nova_duracao);
            std::cout << "Duração do serviço alterado com sucesso!\n";
        }
        catch (std::invalid_argument &e){
            std::cout << e.what() << "\n";
        }
    }
    else if(escolha_alterar == 4)
    {
        std::cout << "Digite a nova ocupação requerida: ";
        std::string nova_ocupcacao;

        while(true){
            getline(std::cin, nova_ocupcacao);
            if(!stringVazia(nova_ocupcacao))
                break;
            std::cout << "A nova ocupação não pode ser vazia, digite uma ocupação válida: ";
        }

        try {
            servico_alterar->setOcupacaoRequerida(nova_ocupcacao);
            std::cout << "Ocupação requerida do serviço alterado com sucesso!\n";
        }
        catch (std::invalid_argument &e){
            std::cout << e.what() << "\n";
        }
    }


    std::cout << "Novas Informações do Serviço: \n";
    servico_alterar->visualizarDados();
}