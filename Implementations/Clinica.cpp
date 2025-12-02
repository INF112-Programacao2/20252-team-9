//Includes
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <algorithm>

//Construtor
Clinica::Clinica(std::string nome)
    :saldo{0}{
        Plano plano_vazio("Nenhum", 0.0);
        this->adicionarPlano(std::make_unique<Plano>(plano_vazio));
        if(stringVazia(nome))
        throw std::invalid_argument("Nome invalido");

        this->nome = nome;
        this->atendente = nullptr;
    }

//Destrutor
Clinica::~Clinica(){}

//Getters
double Clinica::getSaldo() const {return saldo;}
std::string Clinica::getNome() const {return nome;}
const std::vector<std::unique_ptr<Paciente>>& Clinica::getPacientes() const {return pacientes;}
const std::vector<std::unique_ptr<Medico>>& Clinica::getMedicos() const {return medicos;}
const std::vector<std::unique_ptr<Agendamento>>& Clinica::getAgendamentos() const {return agendamentos;}
const std::vector<std::unique_ptr<Servico>>& Clinica::getServicos() const {return servicos;}
const std::vector<std::unique_ptr<Plano>>& Clinica::getPlanos() const {return planos;}
Atendente* Clinica::getAtendente() const {return atendente;}

//Setters
void Clinica::setSaldo(double saldo){
    if(saldo<0)
        throw std::invalid_argument("Saldo nao pode ser negativo");

    this->saldo = saldo;
}

void Clinica::setNome(std::string nome){
    if(stringVazia(nome))
       throw std::invalid_argument("Nome invalido");

    this->nome = nome;
}

void Clinica::setAtendente(Atendente &atendente){
    this->atendente = &atendente;
}


//Controle dos pacientes
void Clinica::adicionarPaciente(std::unique_ptr<Paciente> paciente){
    if(!paciente)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    pacientes.push_back(std::move(paciente));
}

void Clinica::removerPaciente(Paciente* paciente){
    if(!paciente)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(long unsigned int i=0; i<pacientes.size(); i++){
        if(pacientes[i].get() == paciente){
            pacientes.erase(pacientes.begin() + i);
            break;
        }
    }

    //Remove tambem os agendamentos associados a ele
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getPaciente() == paciente){
            agendamentos.erase(agendamentos.begin() + i);
        }
    }
}

//Controle dos medicos
void Clinica::adicionarMedico(std::unique_ptr<Medico> medico){
    if(!medico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    medicos.push_back(std::move(medico));
}

void Clinica::removerMedico(Medico* medico){
    if(!medico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(long unsigned int i=0; i<medicos.size(); i++){
        if(medicos[i].get() == medico){
            medicos.erase(medicos.begin() + i);
            break;
        }
    }

    //Remove tambem os agendamentos associados a ele
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico() == medico){
            agendamentos.erase(agendamentos.begin() + i);
        }
    }
}

//Controle dos agendamentos
void Clinica::adicionarAgendamento(std::unique_ptr<Agendamento> agendamento){
    if(!agendamento)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    agendamentos.push_back(std::move(agendamento));
    std::sort(agendamentos.begin(), agendamentos.end(), orderAgendamentosByDate);
}

void Clinica::removerAgendamento(Agendamento* agendamento){
    if(!agendamento)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get() == agendamento){
            agendamentos.erase(agendamentos.begin() + i);
            break;
        }
    }
}

//Controle dos serviços
void Clinica::adicionarServico(std::unique_ptr<Servico> servico){
    if(!servico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    servicos.push_back(std::move(servico));
}

void Clinica::removerServico(Servico* servico){
    if(!servico)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(long unsigned int i=0; i<servicos.size(); i++){
        if(servicos[i].get() == servico){
            servicos.erase(servicos.begin() + i);
            break;
        }
    }

    //Remove tambem os agendamentos associados a ele
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getServico() == servico)
            agendamentos.erase(agendamentos.begin() + i);
    }
}

//Controle dos planos
void Clinica::adicionarPlano(std::unique_ptr<Plano> plano){
    if(!plano)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    planos.push_back(std::move(plano));
}

void Clinica::removerPlano(Plano* plano){
    if(!plano)
        throw std::invalid_argument("Ponteiros de objetos vazios sao invalidos");

    for(long unsigned int i=0; i<planos.size(); i++){
        if(planos[i].get() == plano){
            planos.erase(planos.begin() + i);
            break;
        }
    }
}

//Populacao da clinica
void Clinica::popularClinica(std::string arquivo){
    if(stringVazia(arquivo))
        throw std::invalid_argument("Nome do arquivo inválido");

    std::ifstream fin(arquivo);
    if(!fin.is_open())
        throw std::runtime_error("Nao foi possivel abrir o arquivo de populacao");

    //População dos planos
    int numPlanos;
    fin >> numPlanos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i=0; i<numPlanos; i++){
        //Dados do plano
        std::string nome;
        double desconto;

        //Entrada de cada dado
        getline(fin, nome);
        fin >> desconto;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //Armazena no vetor da clínica
        try{
            this->adicionarPlano(std::make_unique<Plano>(nome, desconto));
        }
        catch(std::invalid_argument &e){
            std::cout << "Nao foi possivel popular o plano " << i+1 << "\nErro:" << e.what() << std::endl;
            return;
        }
    }

    //População dos servicos
    int numServicos;
    fin >> numServicos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i=0; i<numServicos; i++){
        //Dados do servico
        std::string nome, ocupacaoRequerida;
        double valor, duracao;

        //Entrada dos dados
        getline(fin, nome);
        fin >> valor;
        fin >> duracao;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(fin, ocupacaoRequerida);

        //Armazena no vetor da clínica
        try{
            this->adicionarServico(std::make_unique<Servico>(nome, valor, duracao, ocupacaoRequerida));
        }
        catch(std::invalid_argument &e){
            std::cout << "Nao foi possivel popular o servico " << i+1 << "\nErro:" << e.what() << std::endl;
        }
    }

    //População dos médicos
    int numMedicos;
    fin >> numMedicos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i=0; i<numMedicos; i++){
        //Dados do medico
        std::string nome, cpf, senha, telefone, crm, ocupacao;

        //Entrada dos dados
        getline(fin, nome);
        getline(fin, cpf);
        getline(fin, senha);
        getline(fin, telefone);
        getline(fin, crm);
        getline(fin, ocupacao);

        //Armazena no vetor da clínica
        try{
            this->adicionarMedico(std::make_unique<Medico>(nome, cpf, senha, telefone, crm, ocupacao));
        }
        catch(std::invalid_argument &e){
            std::cout << "Nao foi possivel popular o medico " << i+1 << "\nErro:" << e.what() << std::endl;
        }
    }

    //População dos pacientes
    int numPacientes;
    fin >> numPacientes;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i=0; i<numPacientes; i++){
        //Dados do paciente
        std::string nome, cpf, senha, telefone, dataDeNascimento, observacoes;
        char sexo;

        //O plano é escolhido de forma aleatória dentro dos que já foram populados anteriormente
        Plano *plano = nullptr;

        if(!planos.empty()){
            int index = std::rand()%planos.size();
            plano = planos[index].get();
        }

        //Entrada dos dados
        getline(fin, nome);
        getline(fin, cpf);
        getline(fin, senha);
        getline(fin, telefone);
        getline(fin, dataDeNascimento);
        fin >> sexo;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(fin, observacoes);

        //Armazenamento no vetor da clinica
        try{
            this->adicionarPaciente(std::make_unique<Paciente>(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano));
        }
        catch(std::invalid_argument &e){
             std::cout << "Nao foi possivel popular o paciente " << i+1 << "\nErro:" << e.what() << std::endl;
        }
    }

    //População dos agendamentos(Versão inicial, não valida ainda se o servico sorteado é compatível com o médico sorteado)
    int numAgendamentos;
    fin >> numAgendamentos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i=0; i<numAgendamentos; i++){
        //Dados do agendamento
        std::string data, horario;

        //Sorteio do servico, médico e paciente
        Servico* servico = nullptr;
        if(!servicos.empty()){
            int index = std::rand()%servicos.size();
            servico = servicos[index].get();
        }
        
        Medico* medico = nullptr;
        if(!medicos.empty()){
            int index = std::rand()%medicos.size();
            medico = medicos[index].get();
        }

        Paciente* paciente = nullptr;
        if(!pacientes.empty()){
            int index = std::rand()%pacientes.size();
            paciente = pacientes[index].get();
        }

        //Entrada dos dados
        getline(fin, data);
        getline(fin, horario);

        //Armazenamento no vetor da clínica
        try{
            this->adicionarAgendamento(std::make_unique<Agendamento>(data, horario, paciente, medico, servico));
        }
        catch(std::invalid_argument &e){
             std::cout << "Nao foi possivel popular o agendamento " << i+1 << "\nErro:" << e.what() << std::endl;
        }
    }
}

int Clinica::validarPaciente(std::string cpf, std::string senha){
    //Inicialmente procura se o cpf está entre os cpfs cadastrados
    for(long unsigned int i = 0; i < pacientes.size(); i++){
        if(pacientes[i]->getCpf() == cpf){  //Encontrou cpf da pessoa
            if(pacientes[i]->getSenha() == senha){
                //Caso entre aqui, encontrou um paciente com cpf e senha correta no sistema
                return 1;   //Tudo correto
            }
            //Se chegou aqui, a senha informada é diferente da senha armazenada no sistema
            return 0; //Usuario registrado mas senha incorreta 
        }
    }
    //Se chegou aqui, não encontrou o usuario na base de dados
    return -1;   //Usuario não cadastrada 
}

int Clinica::validarMedico(std::string cpf, std::string senha){
    //Inicialmente procura se o cpf está entre os cpfs cadastrados
    for(long unsigned int i = 0; i < medicos.size(); i++){
        if(medicos[i]->getCpf() == cpf){    //Encontrou cpf do medico
            if(medicos[i]->getSenha() == senha){
                //Caso entre aqui, encontrou um medico com cpf e senha correta no sistema
                return 1;   //Tudo correto
            }
            //Se chegou aqui, a senha informada é diferente da senha armazenada no sistema
            return 0; //Medico registrado mas senha incorreta
        }
    }
    //Se chegou aqui, não encontrou o medico na base de dados
    return -1;   //medico não cadastrada 
}

int Clinica::validarAtendente(std::string cpf, std::string senha){

    if(this->atendente == nullptr) {
        std::cout << "Ainda não temos atendente.\n";
        return -1;
    }

    if(this->atendente->getCpf() == cpf){
        if(this->atendente->getSenha() == senha){
            //Caso entre aqui, o atendente entrou com cpf e senha correta no sistema
            return 1;   //Tudo correto
        }
        //Se chegou aqui, a senha informada é diferente da senha armazenada no sistema
        return 0; //Atendente registrado mas senha incorreta
    }
    //Se chegou aqui, o atendente não é o da base de dados
    return -1;   //medico não cadastrada 
}