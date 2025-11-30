#include "Headers/Atendente.h"
#include "Utils.h"
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

void Atendente::ConsultaSaldoDaClinica(Clinica &clinica){
    std::cout << "Saldo da Clínica (R$): " << std::fixed << std::setprecision(2) << clinica.getSaldo() << "\n";
}


//Metodos

void Atendente::VizualizaDados(){
    std::cout << "Dados do(a) Atendente:\n";
    Pessoa::VizualizaDados();

    std::cout << "Matrícula: " << this->getMatricula() << "\n";
}

void Atendente::VizualizaAgendamentos(Clinica &clinica){
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
        const auto &listaMedicos = clinica.getMedicos();
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

        listaMedicos[escolha-1]->VizualizaAgendamentos(&clinica);

    }
    else {
        std::cout << "Lista dos pacientes que deseja ver os agendamentos: \n";
        const auto &listaPacientes = clinica.getPacientes();
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

void Atendente::CadastrarMedico(Clinica &clinica) {
    //Falta fazer o tratamento de erros ainda
    std::string nome, cpf, senha, telefone, crm, ocupacao;
    std::cout << "Nome: ";
    getline(std::cin, nome);
    std::cout << "CPF: ";
    getline(std::cin, cpf);
    std::cout << "Senha: ";
    getline(std::cin, senha);
    std::cout << "Telefone: ";
    getline(std::cin, telefone);
    std::cout << "CRM: ";
    getline(std::cin, crm);
    std::cout << "Ocupação: ";
    getline(std::cin, ocupacao);

    auto novo_medico = std::make_unique<Medico>(nome, cpf, senha, telefone, crm, ocupacao, 0);

   clinica.adicionarMedico(std::move(novo_medico));

}